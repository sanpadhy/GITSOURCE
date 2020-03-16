// ContextPackageExample_test
package contextImpl

import (
	"fmt"
	"testing"
)

func TestBackgroundNotTODO(t *testing.T) {
	todo := fmt.Sprint(TODO())
	bg := fmt.Sprint(Background())
	
	if todo == bg {
		t.Errorf("TODO and backgrounds are equals: %q vs %q", t.)
	}
} 

func testwithCancel(t *testing.T) {
	ctx, cancel := WithCancel(Background())
	
	if err := ctx.Err(); err != nil {
		t.Errorf("error should be nill first, got %v ", err)
	}
	
	cancel()
	
	<-ctx.Done()
	
}
