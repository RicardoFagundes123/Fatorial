def fat(n):
	if ( n is not int(n) ):
	 	return False	
	elif (n <= 1):
		return 1
	else:
		return n * fat(n - 1)


