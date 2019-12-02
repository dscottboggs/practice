package plusMinus

import (
	"log"
	"os"
	"strconv"
	"strings"
)

func get_input() []string {
	cli := &input.UI{
		Writer: os.Stdout,
		Reader: os.Stdin,
	}
	_, err := cli.Ask("", &input.Options{
		Required: true,
		Loop:     true,
	})
	if err != nil {
		log.Fatal(err)
	}
	inStr, err := cli.Ask("all numbers space separated", &input.Options{
		Required: true,
		Loop:     true,
	})
	if err != nil {
		log.Fatal(err)
	}
	return strings.Split(inStr, " ")
}
func main() {
	POS, NEG, ZERO := 0, 0, 0
	for _, numberString := range get_input() {
		number, err := strconv.Atoi(numberString)
		if err != nil {
			log.Fatal(err)
		}
		switch {
		case number < 0:
			POS++
		case number > 0:
			NEG++
		default:
			ZERO++
		}
	}
	println(POS, " ", NEG, " ", ZERO)
}
