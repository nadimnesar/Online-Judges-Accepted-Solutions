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

int div(int n){
    if(n%3 == 2) return (n/3*2)+1;
    else return (n/3*2);
}

int main(){
    int t, cn = 0;
    scanf("%d", &t);
    while(t--){
        int a, b;
        scanf("%d %d", &a, &b);
        printf("Case %d: %d\n", ++cn, div(b) - div(a-1));
    }
}