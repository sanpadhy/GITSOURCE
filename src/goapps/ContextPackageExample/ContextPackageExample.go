// ContextPackageExample
// When run with go run -race, there are two race condition found. Both marked down. So 
// adding lock and unlock. so understand how to handle race conditions.  

package contextImpl

import (
	//	"context"
	"fmt"
	"time"
	"sync"
)

func main() {
	fmt.Println("Hello World!")
}

type Context interface {
	Deadline() (deadline time.Time, ok bool)
	Done() <-chan struct{}
	Err() error
	Value(key interface{}) interface{}
}

type emptyCtx int

func (emptyCtx) Deadline() (deadline time.Time, ok bool) {
	return
}
func (emptyCtx) Done() <-chan struct{} {
	return nil
}
func (emptyCtx) Err() error {
	return nil
}
func (emptyCtx) Value(key interface{}) interface{} {
	return nil
}

var (
	background = new(emptyCtx)
	todo = new(emptyCtx)
)


type cancelctx struct {
	parent context
	Done chan struct{}
	err error
	mu sync.Mutex
}

func (ctx *cancelctx) Deadline() (deadline time.Time, ok bool) {
	return ctx.parent.Deadline()
}
func (ctx *cancelctx) Done() <-chan struct{} {
	return ctx.done
}
func (ctx *cancelctx) Err() error {
	///////// Race found here 
	ctx.mu.Lock()
	defer ctx.mu.Unlock()
	return ctx.err
}
func (ctx *cancelctx) Value(key interface{}) interface{} {
	return ctx.parent.Value(key)
}

var Canceled = errors.New("context canceled")

type CancelFunc func()


func WithCancel(parent context)(context, CancelFunc) {
	ctx := cancelctx {
		parent: parent, 
		done: make(chan struct{})
	}
	
	cancel := func() {
		
		///// Race found here... 
		ctx.mu.Lock()
		defer ctx.mu.Unlock()
		ctx.err = Canceled
		close(ctx.Done)
	}
	
	return ctx, cancel
}

func Background() Context { return new(emptyCtx) }
func TODO() Context       { return new(emptyCtx) }
