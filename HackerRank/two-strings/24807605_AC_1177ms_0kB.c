#include<stdio.h>
#include<string.h>
int main()
{
    char a[100001];
    char b[100001];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", &a);
        scanf("%s", &b);
        int a_counter[26];
        int b_counter[26];

        memset(a_counter, 0, sizeof(a_counter));
        memset(b_counter, 0, sizeof(b_counter));

        int x = strlen(a);
        int y = strlen(b);
        for (int j = 0; j < x; j++)
        {

            a_counter[a[j] - 'a']++;
        }
        for (int j = 0; j < y; j++)
        {

            b_counter[b[j] - 'a']++;
        }
        int match = 0;
        for (int j = 0; j<26; j++)
        {
            if(a_counter[j]>0 && b_counter[j]>0)
            {
                match = 1;
                break;
            }
        }
        if (match)
            printf("YES\n");
        else
            printf("NO\n");
    }
}
