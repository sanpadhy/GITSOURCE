
package main

func TestMerge(t *testing.T) {
	c := merge(asChan(1, 2, 3), asChan(4, 5, 6), asChan(7, 8, 9))
	seen := make(map[int]bool)

	for v := range c {
		if seen[v] {
			t.Errorf("saw %d atlease twice.", v)
		}
		seen[v] = true
	}

	for i := 0; i <= 9; i++ {
		if !seen[i] {
			t.Errorf("Not seen %d", i)
		}
	}
}

func BenchmarkMerge(b *testing.B) {
	for i := 0; i < b.N; i++ {
		c := merge(asChan(1, 2, 3), asChan(4, 5, 6), asChan(7, 8, 9))
		seen := make(map[int]bool)

		for v := range c {
			if seen[v] {
				b.Errorf("saw %d atlease twice.", v)
			}
			seen[v] = true
		}

		for i := 0; i <= 9; i++ {
			if !seen[i] {
				b.Errorf("Not seen %d", i)
			}
		}
	}
}

func BenchmarkMerge(b *testing.B) {
	for i := 0; i < b.N; i++ {
		c := mergeReflect(asChan(1, 2, 3), asChan(4, 5, 6), asChan(7, 8, 9))
		seen := make(map[int]bool)

		for v := range c {
			if seen[v] {
				b.Errorf("saw %d atlease twice.", v)
			}
			seen[v] = true
		}

		for i := 0; i <= 9; i++ {
			if !seen[i] {
				b.Errorf("Not seen %d", i)
			}
		}
	}
}

/*
func BenchmarkMerge(b *testing.B) {
	for n := 1; n <= 1024; n *= 2 {
		b.Run(fmt.Sprintf("%d", n), func(b *testing.B) {
			for i := 0; i < b.N; i++ {
				c := merge(asChan(1, 2, 3), asChan(4, 5, 6), asChan(7, 8, 9))
				seen := make(map[int]bool)

				for v := range c {
					if seen[v] {
						b.Errorf("saw %d atlease twice.", v)
					}
					seen[v] = true
				}

				for i := 0; i <= 9; i++ {
					if !seen[i] {
						b.Errorf("Not seen %d", i)
					}
				}
			}
		})
	}
}
*/

/*
func BenchmarkMerge(b *testing.B) {
	merges := []func(...<-chan int) <-chan int{
		merge,
		mergeReflect,
		mergeRec,
	}
	for _, merge := range merges {
		for i := 0; i < b.N; i++ {
			c := merge(asChan(0, 1, 2, 3, 4, 5, 6, 7, 8, 9))
			for range c {
			}
		}
	}
}
*/

func BenchmarkMerge(b *testing.B) {
	merges := []struct {
		name string
		fun  func(...<-chan int) <-chan int
	}{
		{"goroutines", merge},
		{"reflect", mergeReflect},
		{"recursion", mergeRec},
	}
	for _, merge := range merges {
		b.Run(merge.name, func(b *testing.B) {
			for i := 0; i < b.N; i++ {
				c := merge.fun(asChan(0, 1, 2, 3, 4, 5, 6, 7, 8, 9))
				for range c {
				}
			}
		})
	}
}

func BenchmarkMerge(b *testing.B) {
	merges := []struct {
		name string
		fun  func(...<-chan int) <-chan int
	}{
		{"goroutines", merge},
		{"reflect", mergeReflect},
		{"recursion", mergeRec},
	}
	for _, merge := range merges {
		for k := 0.; k <= 10; k++ {
			n := int(math.Pow(2, k))
			b.Run(fmt.Sprintf("%s/%d", merge.name, n), func(b *testing.B) {
				for i := 0; i < b.N; i++ {
					chans := make([]<-chan int, n)
					for j := range chans {
						chans[j] = asChan(0, 1, 2, 3, 4, 5, 6, 7, 8, 9)
					}
					c := merge.fun(chans...)
					for range c {
					}
				}
			})
		}
	}
}

