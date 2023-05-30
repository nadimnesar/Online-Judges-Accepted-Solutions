#include<stdio.h>
#include<string.h>
int main()
{
    char a[100001];
    char b[100001];
    int n, j;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", &a);
        scanf("%s", &b);
        int a_counter[26]= {0};
        int b_counter[26]= {0};
        int x = strlen(a);
        int y = strlen(b);
        for (j=0; j<x; j++)
        {
            a_counter[a[j]-97]=a_counter[a[j]-97]+1;
        }
        for (j=0; j<y; j++)
        {
            b_counter[b[j]-97]=a_counter[b[j]-97]+1;
        }
        int match = 0;
        for (j=0; j<26; j++)
        {
            if(a_counter[j]>0 && b_counter[j]>0)
            {
                match=1;
                break;
            }
        }
        if (match==1)
            printf("YES\n");
        else
            printf("NO\n");
    }
}