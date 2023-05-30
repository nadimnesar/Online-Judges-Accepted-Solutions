#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define llu                 long long unsigned int

#define in                  insert
#define ppb                 pop_back
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define dot(x)              fixed<<setprecision(x)

#define maxx                (ll)(1e3+7)
#define mod                 (ll)(1e9+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))
#define log(b, x)           (double)(log(x)/log(b))

void solve(){

    ll zero, one;
    cin >> zero >> one;

    if(zero+1 == one){
        while(zero + one > 0){
            if(one){
                cout << "1";
                one--;
            }
            if(zero){
                cout << "0";
                zero--;
            }
        }
        cout << endl;
        return;
    }

    if(one+1 == zero){
        while(zero + one > 0){
            if(zero){
                cout << "0";
                zero--;
            }
            if(one){
                cout << "1";
                one--;
            }
        }
        cout << endl;
        return;
    }

    if(zero > one){
        cout << "-1" << endl;
        return;
    }

    if(zero == one){
        for(ll i = 0; i < zero+one; i+=2){
            cout << "01";
        }
        cout << endl;
        return;
    }
    string res;
    bool flag = false;
    while(zero+one > 0){
        if(zero == one) flag = true;
        if(!zero){
            if(one > 2){
                cout << "-1" << endl;
                return;
            }
            if(one == 1) res += "1";
            else res += "11";
            break;
        }
        if(!flag){
            res += "11";
            res += "0";
            zero--;
            one-=2;
        }
        else{
            res += "1";
            res += "0";
            zero--;
            one--;
        }
    }


    cout << res << endl;
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();
    
    return 0;
}