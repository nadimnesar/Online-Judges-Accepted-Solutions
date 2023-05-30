#include <stdio.h>

int main() {
  unsigned short c;
  scanf("%hu",&c);
  if (c > 9) printf("Greater than 9\n");
  else if (c == 1) printf("one\n");
  else if (c == 2) printf("two\n");
  else if (c == 3) printf("three\n");
  else if (c == 4) printf("four\n");
  else if (c == 5) printf("five\n");
  else if (c == 6) printf("six\n");
  else if (c == 7) printf("seven\n");
  else if (c == 8) printf("eight\n");
  else printf("nine\n");
}