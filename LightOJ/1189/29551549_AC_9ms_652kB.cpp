#include <stdio.h>
#include <vector>

#define ll               long long int
#define pb               push_back

int main(){

    ll x[20] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600, 6227020800, 87178291200, 1307674368000, 20922789888000, 355687428096000, 6402373705728000,
    121645100408832000};
    int t, cn = 0;
    scanf("%d", &t);
    while(t--){
        ll m;
        scanf("%lld", &m);
        std::vector < ll > y;
        for(int i = 19; i >= 0; i--){
            if(m == 0) break;
            if(x[i] > m) continue;
            else{
                y.pb(i);
                m -= x[i];
            }
        }
        printf("Case %d: ", ++cn);
        if(m > 0) printf("impossible\n");
        else{
            int len = y.size();
            for(int i = len-1; i >= 0; i--){
                if(i == 0) printf("%d!", y[i]);
                else printf("%d!+", y[i]);
            }
            printf("\n");
        }
    }
}
