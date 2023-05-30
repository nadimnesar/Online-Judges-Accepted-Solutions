def lcm_of_array(arr):
    lcm = arr[0]
    for i in range(1, len(arr)):
        num1 = lcm
        num2 = arr[i]
        gcd = 1
        while num2 != 0:
            temp = num2
            num2 = num1 % num2
            num1 = temp
        gcd = num1
        lcm = (lcm * arr[i]) // gcd
    return lcm

t = int(input())
cn = 1
while t > 0:
    n = int(input())
    arr = list(map(int, input().split()))
    print('Case '+str(cn)+': '+str(lcm_of_array(arr)))
    cn = cn + 1
    t = t-1