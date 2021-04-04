Matthew Rutigliano
CPSC 3500
14 January 2021
Homework 1

All of my programs were tested using three files: a multiline poem, a brief string of
repeating characters, and a lengthy 100+ line of repeating characters.

wcat.cpp : No problems.

wgrep.cpp : No problems.

wzip.cpp :  I had an issue where multiline entries would lose lines past the first. 
	This was resolved by moving where the loop parameters were reset, and appending 
	a "1\n" to the end of each line. Everything works correctly now.

wunzip.cpp : I had an issue where the final term in a line would be printed twice. 
	This was resolved by adding a second check of the feof function, as it takes
	two checks to be properly set when the end of the file is reached. Everything works
	correctly now.