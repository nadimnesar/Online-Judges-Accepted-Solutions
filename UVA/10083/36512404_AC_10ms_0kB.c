import sys
import math

def binpow(a, b):
  if b == 0:
    return 1
  res = binpow(a, b//2)
  r = b%2
  if r == 0:
    return (res * res)
  else:
    return (res * res * a)

for take in sys.stdin:
  take = take.split();
  t = int(take[0])
  a = int(take[1])
  b = int(take[2])
  
  q = "(" + str(t) + "^" + str(a) + "-1)" + "/(" + str(t) + "^" + str(b) + "-1)"

  if t == 1:
    print(q, "is not an integer with less than 100 digits.")
  elif a == b:
    print(q, "1")
  elif a < b:
    print(q, "is not an integer with less than 100 digits.")
  else:
    digit = math.floor(math.log10(t)*(a-b))+1;

    if(digit <= 150):
      up = int(binpow(t, a)) - int(1)
      down = int(binpow(t, b)) - int(1)
      mod = up % down
      
      res = str(up//down)
      if mod == 0:
        if len(res) < 100:
          print(q, res)
        else:
          print(q, "is not an integer with less than 100 digits.")
      else:
        print(q, "is not an integer with less than 100 digits.")
    else:
      print(q, "is not an integer with less than 100 digits.")