#!/usr/bin/env python
import sys, copy

allPossibleSolutions = []
#keep track of current shortest solution length
shortestSolutionLength = 999999

#Parse the input file and store it into an array
def initialize():
	'''
	1. Read in the input and store it into an array
	2. Pass in the array, the solution array so far, and the input length to the recursive function
	'''
	inputArray = [int(line.strip()) for line in open(sys.argv[1], 'r')]
	arrayLength = len(inputArray)-1

	#solutionArray will contain a list of indexes
	solutionArray = []
	solutionArray.append(0)
	forward_recur(inputArray, solutionArray, arrayLength)

def forward_recur(inputArray, solutionArray, lengthLeft):
	'''
	Input: the input array, the current solution array so far, the remaining length
	This function will recursively check each hop possibility to check if we can fully traverse the array.
	Optimizations: this algorithm keeps track of the current shortest path. If a possible solution branch
	is as long as the shortest solution, then ignore it.
	'''
	#Check if we are within range of exiting the array
	global shortestSolutionLength
	if(len(solutionArray)>=shortestSolutionLength):
		return
	else:
		if(lengthLeft<=0):
			if(shortestSolutionLength > len(solutionArray)):
				#We are able to hop out of the array with this node, so add this solution to the array
				del solutionArray[-1] #get rid of last hop destination
				allPossibleSolutions.append(solutionArray)
				shortestSolutionLength = len(solutionArray)
			return
		else:
			currIndex = solutionArray[-1]
			indexRange = inputArray[currIndex]
			# We didn't have a solution, so recurse through every option
			for i in range(currIndex+1, 1+currIndex+indexRange):
				solutionArrayCopy = copy.deepcopy(solutionArray)
				solutionArrayCopy.append(i)
				forward_recur(inputArray, solutionArrayCopy, len(inputArray)-i)
		return

#Run the functions
initialize()
if(len(allPossibleSolutions)==0): # no solutions, so print failure
	print "failure"
else: # we have solutions
	output = sorted(allPossibleSolutions, key=lambda L: len(L))[0] # return one with shortest # of hops
	outputStr = ""
	for num in output:
		outputStr += str(num) + ", "
	outputStr+="out"
	print outputStr

