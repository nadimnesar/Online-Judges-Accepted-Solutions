fibo = []
fibo.append(1)
fibo.append(2)

for i in range(2, 101):
    fibo.append(fibo[i-1]+fibo[i-2])

nl = False
while True:
    try:
        
        if nl:
            c = input()
            
        a = str(input())
        b = str(input())
        
        if nl:
            print('')
        else:
            nl = True

        sum = 0
        j = 0
        for i in reversed(range(len(a))):
            sum = sum + int(a[i])*fibo[j]
            j = j+1
        j = 0
        for i in reversed(range(len(b))):
            sum = sum + int(b[i])*fibo[j]
            j = j+1

        res = ""
        flag = False
        for i in reversed(range(101)):
            if flag and sum >= fibo[i]:
                    flag = True
                    sum -= fibo[i]
                    res += '1'
            elif flag and sum < fibo[i]:
                res += '0'
            elif not flag and sum >= fibo[i]:
                flag = True
                sum -= fibo[i]
                res += '1'
            else:
                continue
        if len(res) == 0:
            res += '0'
        print(res)
    except EOFError:
        break