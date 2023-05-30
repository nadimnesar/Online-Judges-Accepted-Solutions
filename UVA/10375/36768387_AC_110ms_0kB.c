factorial = []
factorial.append(1);
for i in range(1, 10007):
  factorial.append(factorial[i-1]*i)

while True:
  try:
    p, q, r, s = map(int, input().split())
  except:
    break
  up = factorial[p]//(factorial[p-q]*factorial[q])
  down = factorial[r]//(factorial[r-s]*factorial[s])
  res = up/down
  print("%.5f"%res)