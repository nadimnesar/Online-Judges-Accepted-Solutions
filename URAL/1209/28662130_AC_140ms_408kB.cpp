#include <bits/stdc++.h>
using namespace std;
#define ll              long long
#define pb              push_back
#define all(x)          x.begin(), x.end()
#define all(y)          y.begin(), y.end()
#define YES             printf("YES\n")
#define NO              printf("NO\n")
#define PI              acos(-1.0)
#define MAX             1000001
#define MOD             10000007

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        long double n;
        scanf("%Lf", &n);
        n = (sqrt((8.00*n)-7.00)-1.00)/2.00;
        if(t == 0){
            if(n == int(n)){
                printf("1\n");
            }
            else printf("0\n");
        }
        else{
            if(n == int(n)){
                printf("1 ");
            }
            else printf("0 ");
        }
    }
}
