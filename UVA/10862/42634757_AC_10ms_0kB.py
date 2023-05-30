fibo = []
fibo.append(0)
fibo.append(1)
fibo.append(2)

for i in range(3, 4001):
    fibo.append(fibo[i-1]+fibo[i-2])

while True:
        n = int(input())
        if n == 0:
            break
        print(fibo[n*2-1])