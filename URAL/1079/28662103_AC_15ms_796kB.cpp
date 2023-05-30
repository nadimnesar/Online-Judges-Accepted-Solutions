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
    while(1){
        int n;
        scanf("%d", &n);
        if(n == 0) break;
        vector < int > x(n+1); x[0] = 0; x[1] = 1;
        for(int i = 1; ; i++){
            if(2*i > n) break;
            x[2*i] = x[i];
            if(((2*i)+1) > n) break;
            x[(2*i)+1] = x[i]+x[i+1];
        }
        printf("%d\n", *max_element(all(x)));
    }
}