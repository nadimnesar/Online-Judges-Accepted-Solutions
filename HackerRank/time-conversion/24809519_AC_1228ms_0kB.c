#include <stdio.h>
#include <string.h>
int main()
{
    int h, m, s;
    char ap[3];
    scanf("%d:%d:%d%s", &h, &m, &s, ap);
    if(!strcmp(ap, "PM"))
    {
        if(h<12)
        {
            h=h+12;
        }
        else if(h==12)
        {
            h=12;
        }
    }
    else if(!strcmp(ap, "AM"))
    {
        if(h==12)
        {
            h=0;
        }
    }
    printf("%02d:%02d:%02d", h, m, s);
}
