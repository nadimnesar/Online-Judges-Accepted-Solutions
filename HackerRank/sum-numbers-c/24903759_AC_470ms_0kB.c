#include <stdio.h>
int main()
{
    int n1, n2, sum=0, avg=0;
    float f1, f2, sum2, avg2;

    scanf("%d %d", &n1, &n2);
    scanf("%f %f", &f1, &f2);
    sum=n1+n2;
    avg=n1-n2;

    sum2=f1+f2;
    avg2=f1-f2;

    printf("%d %d\n", sum, avg);
    printf("%.1f %.1f\n", sum2, avg2);
    return 0;
}
