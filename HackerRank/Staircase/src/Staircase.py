#!/usr/bin/python
#Staircase.py draws a staircase of input size
#Author: D. Scott Boggs
import sys
inp = 0
def main():
	inp = getInput()
	print(getStaircase(inp))
def getInput ( ):
		## Checks to see if there were CLI args passed
	if(len(sys.argv) == 1):
		return int(raw_input()) # if there weren't, it promts for input
	else:
		return int(sys.argv[1])
			# if there were, it grabs the first one and ignores any
			# subsequent args
def getStaircase(inp):
	staircase = ""
	for row in range(0,inp):
		#one row at a time, do all of the below:
		col = 0 #starting with the first column
		while(col < (inp - row -1)):	#increment over each column
			staircase += " "			#adding a space to the string
			col+=1						#until the total columns, minus
										#the current row, minus one
		while(col >= (inp - row -1) and col < inp):
			staircase += "#"	#then fill in the rest with hashes
			col+=1
		staircase += "\n"		#after incrementing through all the
								#columns, pass newline to the string for
								#a new row
										
	return staircase
main()
