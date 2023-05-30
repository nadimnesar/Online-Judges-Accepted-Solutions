#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main()
{
    char n[101];
    int len;
    gets(n);
    puts(n);
    len=strlen(n);
    printf("%d", len);
    return 0;
}