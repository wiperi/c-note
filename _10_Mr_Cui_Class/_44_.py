for i in range(7, 9):
    print(i)


sum = 0
for i in range(5):
    for j in range(6):
        sum += i * j

print(sum)


# 0 1 1 2 3 5 8
def fibo(n):
    if n == 0:
        return 0
    if n == 1:
        return 1
    
    left = 0
    right = 1
    ret = 0
    for i in range(n - 1):
        ret = left + right
        left = right
        right = ret
    return ret

for i in range(8):
    print(fibo(i))
