package main

import "fmt"

func main() {
	if "" {
		fmt.Println("the empty string is truthy")
	} else {
		fmt.Println("the empty string is falsey")
	}
	if []int{} {
		fmt.Println("an empty array is truthy")
	} else {
		fmt.Println("an empty array is falsey")
	}
	if 0 {
		fmt.Println("0 was truthy")
	} else {
		fmt.Println("0 was falsey")
	}
	if nil {

	}
}
