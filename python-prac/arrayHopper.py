#!/usr/bin/env python

import sys, copy

#Set current shortest solution length to INF for pruning
shortestSolutionLength = 9999999
allPossibleSolutions = []

#Parse the input file and store it into an array
def initialize():
	inputArray = [int(line.strip()) for line in open(sys.argv[1], 'r')]
	print inputArray
	arrayLength = len(inputArray)

	#solutionArray will contain pairs of (index, distanceTraveledSoFar)
	solutionArray = []
	solutionArray.append((0,0))
	print solutionArray
	print arrayLength
	forward_recur(inputArray, solutionArray, arrayLength-inputArray[0])

def forward_recur(inputArray, solutionArray, lengthLeft):
	currIndex = solutionArray[-1]
	indexRange = inputArray[currIndex[0]]

	print "(index, distance traveled so far)"
	print currIndex
	print "this range"
	print indexRange
	#Check if we are within range of exiting the array
	if(lengthLeft<=0):
		#We have a solution, so add it to the array
		allPossibleSolutions.append(solutionArray)
		return
	else:
		#We didn't have a solution, so recurse
		lengthLeft -= inputArray[i]
		for i in range(currIndex[1], currIndex[1]+indexRange):
			print "Going through this index now..."
			print i
			solutionArrayCopy = copy.deepcopy(solutionArray)
			solutionArrayCopy.append((i, inputArray[i]+currIndex[1]))
			print solutionArrayCopy
			forward_recur(inputArray, solutionArrayCopy, lengthLeft)
	return

initialize()

for item in allPossibleSolutions:
	print item


#Return element with fewest number of elements
#sorted(myList, key=lambda L: len(L))[0]