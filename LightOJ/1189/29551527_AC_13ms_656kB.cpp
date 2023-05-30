#include <stdio.h>
#include <vector>

#define ll               long long int
#define pb               push_back

int main(){

    ll x[20];
    x[0] = 1;
    x[1] = 1;
    x[2] = 2;
    x[3] = 6;
    x[4] = 24;
    x[5] = 120;
    x[6] = 720;
    x[7] = 5040;
    x[8] = 40320;
    x[9] = 362880;
    x[10] = 3628800;
    x[11] = 39916800;
    x[12] = 479001600;
    x[13] = 6227020800;
    x[14] = 87178291200;
    x[15] = 1307674368000;
    x[16] = 20922789888000;
    x[17] = 355687428096000;
    x[18] = 6402373705728000;
    x[19] = 121645100408832000;

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
