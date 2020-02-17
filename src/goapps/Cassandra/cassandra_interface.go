// cassandra_interface
package main

import (
	"fmt"
	"github.com/gocql/gocql"
)

var Session *gocql.Session

type Emp struct {
    id string
    firstName string
    lastName string
    age int
}

func init() {
	var err error

	// Initialize the cluster. Local machine part of cluster. 
    cluster := gocql.NewCluster("127.0.0.1")

	// keyspace is important in Cassandra
    cluster.Keyspace = "code2succeed"

	// Create a session
     Session, err = cluster.CreateSession()
     if err != nil { panic(err) }
          fmt.Println("cassandra init done")
}

func createEmp(emp Emp) {
    fmt.Println(" **** Creating new emp ****\n", emp)

	// CQL Query : INSERT INTO emps(empid, first_name, last_name, age) VALUES(?, ?, ?, ?)
    if err := Session.Query("INSERT INTO emps(empid, first_name, last_name, age) VALUES(?, ?, ?, ?)", emp.id, emp.firstName, emp.lastName, emp.age).Exec(); err != nil {
        fmt.Println("Error while inserting Emp")
        fmt.Println(err)
    }
}

func getEmps() []Emp {
    fmt.Println("Getting all Employees")
    var emps []Emp
    m := map[string]interface{}{}

	// Define the iterator
	// CQL Query: SELECT * FROM emps 
    iter := Session.Query("SELECT * FROM emps").Iter()
    for iter.MapScan(m) {
        emps = append(emps, Emp{
            id:        m["empid"].(string),
            firstName: m["first_name"].(string),
            lastName:  m["last_name"].(string),
            age:       m["age"].(int),
        })

		// Next record 
        m = map[string]interface{}{}
    }

    return emps
}

// gcql query: DELETE FROM emps WHERE empid = ?
func deleteEmp(id string) {
    fmt.Printf("Deleting Emp with id = %s\n", id)
    if err := Session.Query("DELETE FROM emps WHERE empid = ?", id).Exec(); err != nil {
        fmt.Println("Error while deleting Emp")
        fmt.Println(err)
    }
}

func main() {
    emp1 := Emp{"E-1", "Anupam", "Raj", 20}
    emp2 := Emp{"E-2", "Rahul", "Anand", 30}
    createEmp(emp1)
    fmt.Println(getEmps())
    createEmp(emp2)
    fmt.Println(getEmps())
    emp3 := Emp{"E-1", "Rahul", "Anand", 30}
    createEmp(emp3)
    fmt.Println(getEmps())
    deleteEmp("E-2")
    fmt.Println(getEmps())
}
