#include <stdio.h>

int main(){
  unsigned short c;
  scanf("%hu",&c);
  char str[15][11] = {
    {'B','A','L','\0'},
    {'o','n','e','\0'},
    {'t','w','o', '\0'},
    {'t','h','r','e', 'e', '\0'},
    {'f','o','u','r','\0'},
    {'f','i','v', 'e','\0'},
    {'s','i','x','\0'},
    {'s','e','v', 'e', 'n','\0'},
    {'e','i','g', 'h', 't','\0'},
    {'n','i','n', 'e','\0'},
};
    /*unsigned short pp = 0;
    if(c > 9) pp = 1;

    switch(pp){
        case 1: printf("Greater than 9\n");
        break;
        default: printf("%s\n", str[c]);
        break;
    }*/

    if(c > 9) printf("Greater than 9\n");
    else printf("%s\n", str[c]);
}