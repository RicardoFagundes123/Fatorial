def fat(n):
	if ( not isinstance(n, (int, long, str)) ):
	 	return TypeError("N must be an integer or long")
	elif (n <= 1):
		return 1
	else:
		return n * fat(n - 1)

print( fat(5) )
print( fat(-5.2) )
print( fat(10) )
