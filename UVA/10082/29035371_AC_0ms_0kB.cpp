#include<stdio.h>
#include<math.h>
#include<string.h>

int main()
{
    char ch[]= {"`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./"};
    char ch1[100000];
    while(fgets(ch1, 100000, stdin))
    {
        for(int i=0; i<strlen(ch1) ; i++)
        {
            if(ch1[i]==' ')
            {
                printf(" ");
                continue;
            }
            for(int j=0; j<strlen(ch); j++)
            {
                if(ch[j]==ch1[i])
                {
                    printf("%c",ch[j-1]);
                    break;
                }
            }
        }
        printf("\n");
    }
    return 0;
}
