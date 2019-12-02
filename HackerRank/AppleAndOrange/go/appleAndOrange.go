package AppleAndOrange

import "strings"
import "strconv"
import "os"
import "log"
import "fmt"
import "github.com/tcnksm/go-input"

func getInput(prompt string) string {
	cli := &input.UI{
		Writer: os.Stdout,
		Reader: os.Stdin,
	}
	out, err := cli.Ask(prompt, &input.Options{
		Required: true,
		Loop:     true,
	})
	handle(err)
	return out
}

func handle(e... error){
  for err := range e {
    if e[err] != nil {
      log.Fatal(err)
    }
  }
}

func count(s int, t int, a int, b int, apples []int, oranges []int) string {
  aHit, oHit := 0, 0
  for apple := range apples {
    if t >= (a + apples[apple]) && (a + apples[apple]) >= s {
      aHit++
    }
  }
  for orange := range oranges {
    if t >= (b + oranges[orange]) && (b + oranges[orange]) >= s {
      oHit++
    }
  }
  return fmt.Sprintf("%d\n%d", aHit, oHit)
}

func main() {
  st        := strings.Split(getInput("st"), " ")
  ab        := strings.Split(getInput("ab"), " ")
  mn        := strings.Split(getInput("mn"), " ")
  appleStr  := strings.Split(getInput("apples"), " ")
  orangeStr := strings.Split(getInput("oranges"), " ")
  s, se     := strconv.Atoi(st[0])
  t, te     := strconv.Atoi(st[1])
  a, ae     := strconv.Atoi(ab[0])
  b, be     := strconv.Atoi(ab[1])
  m, me     := strconv.Atoi(mn[0])
  n, ne     := strconv.Atoi(mn[1])
  handle(se, te, ae, be, me, ne)
  apple     := make([]int, m)
  orange    := make([]int, n)
  for aIndex := 0; aIndex < len(appleStr); aIndex++ {
    var err error
    apple[aIndex], err = strconv.Atoi(appleStr[aIndex])
    handle(err)
  }
  for oIndex := 0; oIndex < len(orangeStr); oIndex++ {
    var err error
    apple[oIndex], err = strconv.Atoi(orangeStr[oIndex])
    handle(err)
  }
  fmt.Println(count(s, t, a, b, apple, orange))
}
