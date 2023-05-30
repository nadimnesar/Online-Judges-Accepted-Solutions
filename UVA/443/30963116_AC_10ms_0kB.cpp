#include <bits/stdc++.h>
using namespace std;

#define llu              long long unsigned int
#define ll               long long int
#define pb               push_back
#define mp               make_pair

#define bug              cout<<"bug!!!"<<endl
#define debug(x)         cout<<#x<<" = "<<x<<endl
#define debug2(x,y)      cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl

#define For(x,y)         for(ll i = (int)x; i < (int)y; i++)
#define rFor(x,y)        for(ll i = (int)x; i => (int)y; i--)

#define full(x)          x.begin(),x.end()
#define iremove(x,y)     x.erase(x.begin()+y)
#define dot(x)           fixed<<setprecision(x)
#define remove(x, y)     x.erase(remove(x.begin(),x.end(),y),x.end())
#define alluniq(x, y)    x.resize(dis(x.begin(),unique(x.begin(),x.begin()+y))) //for sorted array

#define EPS              (1e-7)
#define MAX              (1000007)
#define MOD              (1000000007)
#define PI               (acos(-1.0))
#define LOG(b, x)        (log(x)/log(b))

/*st is used with numbers ending in 1 (e.g. 1st, pronounced first)
nd is used with numbers ending in 2 (e.g. 92nd, pronounced ninety-second)
rd is used with numbers ending in 3 (e.g. 33rd, pronounced thirty-third)
As an exception to the above rules, all the "teen" numbers ending with 11, 12 or 13 use -th (e.g. 11th, pronounced eleventh, 112th, pronounced one hundred [and] twelfth)
th is used for all other numbers (e.g. 9th, pronounced ninth).*/

vector < ll > humble_numbers;

void magic(){
    for(int i = 0; i <= 11; i++){ //7
        for(int j = 0; j <= 13; j++){ //5
            for(int k = 0; k <= 19; k++){ //3
                for(int l = 0; l <= 30; l++){ //2
                    ll res = 1LL*pow(2, l)*pow(3, k)*pow(5, j)*pow(7, i);
                    if(res <= 0) continue;
                    else if(res > 2e9) continue;
                    else humble_numbers.pb(res);
                }
            }
        }
    }
    sort(full(humble_numbers));
}

void solve(){
    magic();
    ll n;
    while(cin >> n and n){
        if(n > 10 and n%100 == 11) cout << "The " << n << "th humble number is " << humble_numbers[n-1] << "." << endl;
        else if(n > 10 and n%100 == 12) cout << "The " << n << "th humble number is " << humble_numbers[n-1] << "." << endl;
        else if(n > 10 and n%100 == 13) cout << "The " << n << "th humble number is " << humble_numbers[n-1] << "." << endl;
        else if(n%10 == 1) cout << "The " << n << "st humble number is " << humble_numbers[n-1] << "." << endl;
        else if(n%10 == 2) cout << "The " << n << "nd humble number is " << humble_numbers[n-1] << "." << endl;
        else if(n%10 == 3) cout << "The " << n << "rd humble number is " << humble_numbers[n-1] << "." << endl;
        else cout << "The " << n << "th humble number is " << humble_numbers[n-1] << "." << endl;
    }
}

int main(){

    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifdef NADIMNESAR
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // ll t; cin >> t;
    // int cn = 0;
    // while(t--){
        // cout << "Case " << ++cn << ": ";
        // cout << "Case " << ++cn << ':' << endl;
        solve();
    // }

#ifdef NADIMNESAR
    fprintf(stderr, "\n>> Runtime: %.3fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif

}