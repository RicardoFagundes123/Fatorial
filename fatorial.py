def fat(n):
	if ( not isinstance(n, (int, long, str)) ):
	 	return False	
	elif (n <= 1):
		return 1
	else:
		return n * fat(n - 1)

print( fat(5) )
