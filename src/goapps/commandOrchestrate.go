package main

import (
	"encoding/json"
	"fmt"
	"io/ioutil"
	"os"
	"os/exec"
	"strings"
	"sync"
	"time"
)

func main() {
	if len(os.Args) != 2 {
		panic(fmt.Errorf("Usage: %s json_file\n", os.Args[0]))
	}

	f, err := os.Open(os.Args[1])
	if err != nil {
		panic(err)
	}
	b, err := ioutil.ReadAll(f)

	if err != nil {
		panic(err)
	}

	f.Close()

	var vint interface{}
	err = json.Unmarshal(b, &vint)
	if err != nil {
		panic(err)
	}

	type nvalue map[string]interface{}
	exmap := make(nvalue)
	exmap["completed"] = make(nvalue)
	exmap["inprogress"] = make(nvalue)
	exmap["pending"] = make(nvalue)
	exmap["error"] = make(nvalue)

	var wg sync.WaitGroup
	var mtx sync.Mutex

	for _, vmap := range vint.([]interface{}) {

		f := vmap.(map[string]interface{})
		mtx.Lock()
//		fmt.Println(f["cmd"])
		exmap[f["cmdid"].(string)] = f["cmd"]     // here you copy the command to command id
		mtx.Unlock()

		if len(f["cmd_depends"].([]interface{})) == 0 {     // what you call this. 
			wg.Add(1)
			go func() {
				defer wg.Done()
				mtx.Lock()
				exmap["inprogress"].(nvalue)[f["cmdid"].(string)] = 1
				time.Sleep(100 * time.Millisecond)
				mtx.Unlock()

				str := strings.Split(f["cmd"].(string), " ")
				byta, err := exec.Command(str[0], str[1:]...).Output()
				if err != nil {
					mtx.Lock()
					delete(exmap["inprogress"].(nvalue), f["cmdid"].(string))
					exmap["error"].(nvalue)[f["cmdid"].(string)] = err.Error()
					mtx.Unlock()
					time.Sleep(100 * time.Millisecond)
					fmt.Println(err.Error())
					return
				}
				mtx.Lock()
				delete(exmap["inprogress"].(nvalue), f["cmdid"].(string))
				exmap["completed"].(nvalue)[f["cmdid"].(string)] = 1
				time.Sleep(100 * time.Millisecond)
				mtx.Unlock()
				fmt.Println(string(byta))
			}()
		} else {
			wg.Add(1)
			go func() {
				defer wg.Done()
				dependency := make(nvalue)
				for _, cmdid := range f["cmd_depends"].([]interface{}) {
					if _, ok := exmap["completed"].(nvalue)[cmdid.(string)]; !ok {

						dependency[cmdid.(string)] = 1
						fmt.Println(dependency)
					}
				}
			JMPHERE:
				if len(dependency) == 0 {
					mtx.Lock()
					exmap["inprogress"].(nvalue)[f["cmdid"].(string)] = 1
					mtx.Unlock()
					str := strings.Split(f["cmd"].(string), " ")
					byta, err := exec.Command(str[0], str[1:]...).Output()
					if err != nil {
						mtx.Lock()
						delete(exmap["inprogress"].(nvalue), f["cmdid"].(string))
						exmap["error"].(nvalue)[f["cmdid"].(string)] = err.Error()
						mtx.Unlock()
						fmt.Println(err.Error())
						return
					}
					mtx.Lock()
					delete(exmap["inprogress"].(nvalue), f["cmdid"].(string))
					exmap["completed"].(nvalue)[f["cmdid"].(string)] = 1
					time.Sleep(100 * time.Millisecond)
					mtx.Unlock()
					fmt.Println(string(byta))
				} else {
					mtx.Lock()
					exmap["pending"].(nvalue)[f["cmdid"].(string)] = 1
					mtx.Unlock()
					for k, _ := range dependency {
						if _, ok := exmap["completed"].(nvalue)[k]; ok {
							mtx.Lock()
							delete(dependency, k)
							mtx.Unlock()
						}
					}
					mtx.Lock()
					delete(exmap["pending"].(nvalue), f["cmdid"].(string))
					time.Sleep(100 * time.Millisecond)
					mtx.Unlock()
					goto JMPHERE
				}
			}()
		}
	}
	done := make(chan interface{})
	go func() {
		for {
			select {
			case <-done:
				return
			default:
				mtx.Lock()
				fmt.Println("In Progress Tasks --> ", exmap["inprogress"])
				fmt.Println("Pending Tasks --> ", exmap["pending"])
				fmt.Println("Completed Tasks --> ", exmap["completed"])
				fmt.Println("Errors in Tasks --> ", exmap["error"])
				fmt.Println("")
				mtx.Unlock()
				time.Sleep(1 * time.Second)
			}
		}
	}()

	wg.Wait()
	close(done)
}
