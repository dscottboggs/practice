#!/bin/python

import sys
num_cases=0
cases = []
DEBUG = False
def getInput():
    global cases,num_cases, debug
    num_cases = int(raw_input().strip())
    for a0 in xrange(num_cases):
        n = int(raw_input().strip())
        cases.append(n)

def getHeightThisCycle(cycles):
	height_of_tree = 1
	for current_cycle in range(1,cycles+1): # the 1's in the range() are there because they convert from computer-count
					#(i.e. starting at zero) to the way people count (i.e. starting with 1) because 0-start breaks the math
					#within the loop
		if(DEBUG): print(current_cycle)
		if(DEBUG): print(current_cycle%2)
		if(current_cycle%2 == 0):		# using "if modulus of 2, then; else then" is the simplest way I know to cause
			height_of_tree+=1			# something to happen every other iteration of a loop. 
		else:
			height_of_tree*=2
	return height_of_tree
	
def main():
	global DEBUG
	getInput()
	for i in range(len(cases)):
		s = getHeightThisCycle(cases[i])
		print(s)

main()
