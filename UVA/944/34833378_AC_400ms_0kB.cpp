#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define llu                 long long unsigned int

#define in                  insert
#define ppb                 pop_back
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define dot(x)              fixed<<setprecision(x)

#define maxx                (ll)(2e7+7)
#define mod                 (ll)(1e9+7)
#define inf                 (0x3f3f3f3f)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))
#define log(b, x)           (double)(log(x)/log(b))

vector < pair < int, int > > happy;

int digitsum(int n){
    int sum = 0;
    while(n){
        int x = n%10;
        sum += (x * x);
        n /= 10;
    }
    return sum;
}

void magic(){
    for(int i = 1; i <= 99999; i++){
        int x = i;
        int cnt = 0;
        bool flag = true;
        while(true){
            cnt++;
            if(x == 1) break;
            int sum = digitsum(x);
            if(sum == 4){
                flag = false;
                break;
            }
            x = sum;
        }
        if(flag) happy.pb({i, cnt});
    }
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    magic();
    int n, m;
    bool flag = 0;
    while(cin >> n >> m){
        if(flag) cout << endl;
        flag = 1;
        for(int i = 0; i < happy.size(); i++){
            if(happy[i].first >= n and happy[i].first <= m){
                cout << happy[i].first << ' ' << happy[i].second << endl;
            }
        }
    }
    
    return 0;
}