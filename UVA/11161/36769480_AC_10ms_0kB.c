fib = []
fibend = []
fib.append(1)
fib.append(1)
fibend.append(0)
fibend.append(1)
for i in range(3, 1507):
  x = fib[-1] + fib[-2]
  fib.append(x)
  fibend.append(fibend[-1] + x)

cn = 1
while True:
  n = int(input())
  if n == 0:
    break
  print("Set %d:"%cn)
  cn = cn+1

  if n == 1:
    print(int(0))
    continue
  if n == 2:
    print(int(1))
    continue


  y = fib[n-1]
  if y&1:
    y = (y+1)//2
  else:
    y = y//2
  print(int(fibend[n-2]+y))
