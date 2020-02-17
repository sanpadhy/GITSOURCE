import (
     "github.com/logrange/linker"
)


// MySQLAccessService implements DatabaseAccessService
type MySQLAccessService struct {
    // Conns uses field's tag to specify injection param name(mySqlConns)
    // or sets-up the default value(32), if the param with "mySqlConns" name is not provided 
    Conns int `inject:"mySqlConns, optional:32"`
}

type BigDataService struct {
    // DBa has DatabaseAccessService type which value will be injected.
    // Injection will fail if there is no appropriate component with "dba" name
    // was registered...
    DBa DatabaseAccessService `inject:"dba"`
}



...
func main() {
    // 1st step is to create the injector
	// The main Linker component is Injector.
    inj := linker.New()    // 2nd step is to register components
	// 3 components are registered in the injector inj
    inj.Register(
        linker.Component{Name: "dba", Value: &MySQLAccessService{}},
        linker.Component{Name: "", Value: &BigDataService{}},
        linker.Component{Name: "mySqlConns", Value: int(23)},
        ...
    )

	// Component initialization supposes calling function Init() for all components that implement Initializer interface.
	// 3rd step is to inject dependencies and initialize the registered components
    inj.Init(ctx)    // the injector fails-fast, so if no panic everything is good so far.    ...
    // 4th de-initialize all components properly
	// Shutdown() function to de-initialize all component that were initialized before.
    inj.Shutdown()
}
...
}
