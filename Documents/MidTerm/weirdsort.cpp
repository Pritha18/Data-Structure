/*
      answer of 4.2.2

	main array
	4 3 7 1 5

	FIRST RECURSION CALL
	4 3 7 1

	4 3 7 -> 3 4 7
	3 4 7 1

	4 7 1 -> NO SWAP

	3 4 7 -> No swap

	3 4 7 1

	main array
	3 4 7 1 5

	SECOND RECURSION CALL

	4 7 1 5

	4 7 1
	7 1 5 -> 1 7 5
	4 1 7 -> 1 4 7

	1 4 7 5
	
	main array
	3 1 4 7 5
	
	THIRD RECURSION CALL

	3 1 4 7

	3 1 4 -> 1 3 4
	1 3 4 7

	3 4 7
	
	1 3 4

	main array
	1 3 4 7 5
*/