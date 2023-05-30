fib = []
p = 1
q = 2
fib.append(p)
fib.append(q)

for i in range(0, 500):
  fib.append(p+q)
  temp = p+q
  p = q
  q = temp

while True:
  a, b = input().split()
  a = int(a)
  b = int(b)
  count = 0
  if(a == 0 and b == 0):
    break
  for temp in fib:
    if(temp >= a and temp <= b):
      count += 1
  print(count)