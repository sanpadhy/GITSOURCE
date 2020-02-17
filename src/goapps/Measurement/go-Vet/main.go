package main

import (
	"golang.org/x/tools/go/analysis/multichecker"
	"golang.org/x/tools/go/analysis/passes/atomic"
	"golang.org/x/tools/go/analysis/passes/loopclosure"
	"github.com/blanchonvincent/ctxarg/analysis/passes/ctxarg"
)

func main() {
	multichecker.Main(
		atomic.Analyzer,
		loopclosure.Analyzer,
		ctxarg.Analyzer,
	)
}
