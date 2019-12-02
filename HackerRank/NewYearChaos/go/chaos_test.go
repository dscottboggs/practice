package main

import (
	"bufio"
	"fmt"
	"io"
	"log"
	"os"
	"strconv"
	"strings"
	"testing"
)

type TestCase struct {
	bribes     int32
	line       []int32
	tooChaotic bool
}

var TestCases []TestCase

func TestMinimumBribes(t *testing.T) {
	var (
		testCases = readinTestCases()
		testCase  TestCase
		ok        bool
	)
	for {
		testCase, ok = <-testCases
		if !ok {
			fmt.Println("done.")
			break
		}
		t.Run(fmt.Sprintf("test case %#+v", testCase), func(t *testing.T) {
			if testCase.tooChaotic {
				if bribes := MinimumBribes(testCase.line); bribes != -1 {
					t.Errorf(
						"got %d, but should have gotten too many for %#+v",
						bribes,
						testCase.line)
				}
			} else if bribes := MinimumBribes(testCase.line); bribes != testCase.bribes {
				t.Errorf("got %d, not %d bribes for %#+v",
					bribes,
					testCase.bribes,
					testCase.line)
			}
		})
	}
}

func BenchmarkMinimumBribes(b *testing.B) {
	var (
		testCases = readinTestCases()
		testCase  TestCase
		ok        bool
	)
	for {
		testCase, ok = <-testCases
		if !ok {
			fmt.Println("done.")
			break
		}
		b.Run(fmt.Sprintf("test case with %d bribes", testCase.bribes), func(b *testing.B) {
			if testCase.tooChaotic {
				for index := 0; index < b.N; index++ {

					if bribes := MinimumBribes(testCase.line); bribes != -1 {
						b.Fatalf(
							"got %d, but should have gotten too many",
							bribes)
					}
				}
			} else {
				for index := 0; index < b.N; index++ {
					if bribes := MinimumBribes(testCase.line); bribes != testCase.bribes {
						b.Fatalf("got %d, not %d bribes",
							bribes,
							testCase.bribes)
					}
				}
			}
		})
	}
}

func readinTestCases() chan TestCase {
	output := make(chan TestCase)
	go func() {
		for _, fileNumber := range [4]int{0, 1, 6, 11} {
			var (
				casesCount  int64
				err         error
				infile      *os.File
				resultsFile *os.File
				done        bool
			)
			// open both the input and output file for this test case round number
			infile, err = os.Open(fmt.Sprintf("input/input%02d.txt", fileNumber))
			if err != nil {
				log.Fatal(err)
			}
			defer infile.Close()
			resultsFile, err = os.Open(fmt.Sprintf("output/output%02d.txt", fileNumber))
			if err != nil {
				log.Fatal(err)
			}
			defer resultsFile.Close()
			var (
				// create a scanner which will read the file in line by line
				inputScanner   = bufio.NewReaderSize(infile, 1<<20)
				resultsScanner = bufio.NewScanner(resultsFile)
				thisLine       string
			)
			// the first line has the total number of cases
			thisLine, err = inputScanner.ReadString('\n')
			if err != nil {
				log.Fatal(err)
			}
			thisLine = strings.TrimSpace(thisLine)
			if thisLine == "" {
				continue
			}
			totalCases, err := strconv.ParseInt(thisLine, 10, 32)
			if err != nil {
				log.Fatalf(
					"error parsing total cases %s into an integer in file %s: %v",
					thisLine,
					infile.Name(),
					err,
				)
			}
			for /* ever */ {
				casesCount++
				thisLine, err = inputScanner.ReadString('\n')
				if err != nil {
					log.Fatal(err)
				}
				thisLine = strings.TrimSpace(thisLine)
				if thisLine == "" {
					continue
				}
				length, err := strconv.ParseInt(thisLine, 10, 32)
				if err != nil {
					log.Fatalf(
						"at case %d in file %s; error parsing length %s into an integer: %v",
						casesCount,
						infile.Name(),
						thisLine,
						err)
				}
				queue := make([]int32, length)
				thisLine, err = inputScanner.ReadString('\n')
				if err == io.EOF {
					if casesCount == totalCases {
						done = true
					} else {
						log.Fatalf("got EOF at case #%d in %s", casesCount, infile.Name())
					}
				} else if err != nil {
					log.Fatal(err)
				}
				thisLine = strings.TrimSpace(thisLine)
				if thisLine == "" {
					continue
				}
				var thisNumber int64
				for i, number := range strings.Split(thisLine, " ") {
					thisNumber, err = strconv.ParseInt(strings.Trim(number, ","), 10, 32)
					if err != nil {
						log.Fatalf(
							"at case %d in file %s; error parsing %s into an integer: %v",
							casesCount,
							infile.Name(),
							number,
							err,
						)
					}
					queue[i] = int32(thisNumber)
				}
				if queue[len(queue)-1] == 0 {
					log.Fatalf("didn't initialize the whole queue for %s: %v", thisLine, queue)
				}
				resultsScanner.Scan()
				results := resultsScanner.Text()
				if results == "Too chaotic" {
					output <- TestCase{
						tooChaotic: true,
						line:       queue,
					}
				} else {
					bribes, err := strconv.ParseInt(results, 10, 32)
					if err != nil {
						log.Fatalf("error parsing %s into an integer: %v", results, err)
					}
					output <- TestCase{
						bribes: int32(bribes),
						line:   queue,
					}
				}
				if done {
					break
				}
			}
		}
		close(output)
	}()
	return output
}
