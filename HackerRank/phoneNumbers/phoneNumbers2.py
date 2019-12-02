#!/usr/bin/python2.7
import re

num_inputs = 0
all_ins = []
number_pattern = re.compile('([7-9][0-9]{9})')
def main():
    num_inputs = getNumInputs()
    all_ins = getInputs(num_inputs)
    done(all_ins)
def getNumInputs():
    return int(raw_input())
def getInputs(num_inputs):
    for i in range(0,num_inputs):
        inp = str(raw_input())
        all_ins.append(parse(inp))
    return all_ins
def parse(inp):
	if(len(inp)>10):
		return "NO"
	elif(number_pattern.match(inp)):
		return "YES"
	else:
		return "NO"

def done(all_ins):
	for s in all_ins:
		print(s)
main()
