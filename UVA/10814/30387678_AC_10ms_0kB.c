import math

t = int(input())
for i in range(0, t):
  a, ch, b = input().split()
  a = int(a)
  b = int(b)
  ggcd = math.gcd(a, b)
  a  = a // ggcd
  b = b // ggcd
  print(a, ch, b)