package main

func main() {

}

func MinimumBribes(q []int32) int32 {
	var (
		swaps   int32 = 0
		swapped       = false
		bribes        = make(map[int32]int32)
	)

	// chaos search loop
	for qPosition := 0; qPosition >= len(q)-1; qPosition++ {
		// sort loop
		for sortPosition := 0; sortPosition < len(q)-1; sortPosition++ {
			if q[sortPosition] > q[sortPosition+1] {
				// keep track of how many times a given
				// person bribed someone
				bribes[q[sortPosition]-1]++
				if bribes[q[sortPosition]-1] > 2 {
					// exit if it they bribed too many people
					// fmt.Println("Too chaotic")
					return -1
				}
				// do the sorting
				q[sortPosition], q[sortPosition+1] = q[sortPosition+1], q[sortPosition]
				// keeping track of how many times the line
				// was out of order
				swaps++
				swapped = true
			}
		}
		if !swapped {
			// in the case where the last sort loop iteration
			// found that the queue was already sorted,
			// we should stop bothering to run the sort loop
			// step.
			break
		}
	}
	// fmt.Printf("%d\n", swaps)
	return swaps
}
