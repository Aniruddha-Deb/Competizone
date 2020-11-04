def is_prime(n):
	for i in range(2, n):
		if n%i == 0:
			return False
	return True

prevPrime = 0;
for i in range(2, 101):
	if is_prime(i):
		prevPrime = i
	print(prevPrime, end=', ')
