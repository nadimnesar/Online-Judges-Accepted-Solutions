#include <bits/stdc++.h>
using namespace std;

#define ll               long long int

map < ll, ll > feq;

void solve(){
    int n; cin >> n;
    int q, p;
    for(int i = 0; i < n; i++){
        cin >> q >> p;
        feq[p] += q; 
    }
    ll maxi = 0;
    for(auto it1: feq){
        int power = it1.first;
        bool start = false;
        int cnt = 0;
        for(auto it2: feq){
            if(!start){
                if(it2.first == power){ start = !start; cnt += it2.second; }
            }
            else cnt += it2.second;
        }
        maxi = max(maxi, 1LL*cnt*power);
    }
    cout << maxi << endl;
}

int main(){
    int t, cn = 0; cin >> t;
    while(t--){
        cout << "Case " << ++cn << ": ";
        solve();
        feq.clear();
    }
}