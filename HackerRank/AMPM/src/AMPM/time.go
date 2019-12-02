package main

import (
	"fmt"
	"log"
	"os"
	"strings"

	"github.com/tcnksm/go-input"
)

var outFile *os.File
var twelve string
var twenty4 string

func getenv() map[string]string {
	var out = make(map[string]string)
	for _, envvar := range os.Environ() {
		ev := strings.Split(envvar, "=")
		k, v := ev[0], ev[1]
		out[k] = v
	}
	return out
}

func getInput(prompt string) string {
	cli := &input.UI{
		Writer: outFile,
		Reader: os.Stdin,
	}
	out, err := cli.Ask(prompt, &input.Options{
		Required: true,
		Loop:     true,
	})
	handle(err)
	return out
}

func handle(e ...error) {
	for err := range e {
		if e[err] != nil {
			log.Fatal(err)
		}
	}
}

func to24hour(time12 string) string {

}

func to12hour(time24 string) string {

}
func main() {
	env := getenv()
	if env["OUTPUT_FILE"] == "" {
		outFile = os.Stdout
	} else {
		outFile = env["OUTPUT_FILE"]
	}
	fmt.Println(to24hour(getInput("Time to be converted.")))
}
