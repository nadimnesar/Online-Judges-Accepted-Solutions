def decimalToBinary(n):
    return bin(n).replace("0b", "")

t = 1;
while t > 0:
  n = int(input())
  if n == 0:
    break
  x = decimalToBinary(n)
  print("The parity of", x, "is", x.count('1'), "(mod 2).")