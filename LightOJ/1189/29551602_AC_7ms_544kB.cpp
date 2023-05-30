#include <stdio.h>

int main(){

    long long x[20] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600, 6227020800, 87178291200, 1307674368000, 20922789888000, 355687428096000, 6402373705728000,
    121645100408832000};
    int t, cn = 0;
    scanf("%d", &t);
    while(t--){
        long long m;
        scanf("%lld", &m);
        int y[20];
        int j = 0;
        for(int i = 19; i >= 0; i--){
            if(x[i] <= m){
                y[j++] = i;
                m -= x[i];
            }
        }
        printf("Case %d: ", ++cn);
        if(m > 0) printf("impossible\n");
        else{
            for(int i = j-1; i >= 0; i--){
                if(i == 0) printf("%d!", y[i]);
                else printf("%d!+", y[i]);
            }
            printf("\n");
        }
    }
}
