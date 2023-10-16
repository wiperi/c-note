def isPrime(num):
    divisor = 2
    for i in range(2, num):
        if num % i == 0:
            return False

    return True

if False:
    print(isPrime(8))

def isPrime(num):
    