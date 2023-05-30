#include <bits/stdc++.h>
using namespace std;
 
#define ll               long long int
#define llu              long long unsigned int
#define pb               push_back
#define inst             insert
#define mp               make_pair
#define pop              pop_back
 
#define dot(x)           fixed << setprecision(x)
#define full(x)          x.begin(), x.end()
#define remove(x, y)     x.erase(remove(x.begin(), x.end(), y), x.end())
#define iremove(x, y)    x.erase(x.begin() + y)
#define debug(x)         cout << #x << " = " << x << endl
#define debug2(x, y)     cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define fastIO           ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
 
#define MOD              (1000000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define EPS              (1e-7)
#define LOG(b, x)        (log(x)/log(b))
 
template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }

ll binarysearch(vector < ll > &allfibonacci, ll q){
    ll right = allfibonacci.size()-1;
    ll left = 0;
    ll index = -1;
    while(right >= left){
        int mid = left + (right-left)/2;
        if (allfibonacci[mid] == q){
            index = mid;
            right = mid -1;
        }
        else if(allfibonacci[mid] > q) right = mid-1;
        else left = mid+1;
    }
    return index;
}

int main(){

    fastIO;
#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

    vector < ll > allfibonacci;
    ll a = 1; allfibonacci.pb(a);
    ll b = 2; allfibonacci.pb(b);
    while(true){
        if(a+b >= 2147483648) break;
        else{
            ll c = a+b;
            allfibonacci.pb(c);
            a = b;
            b = c;
        }
    }

    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector < ll > fibs(n);
        for(ll i = 0; i < n; i++){
            cin >> fibs[i];
        }
        cin.ignore();
        string encrypt;
        getline(cin, encrypt);
        for(ll i = 0; encrypt[i]; ){
            if(encrypt[i] >= 'A' and encrypt[i] <= 'Z'){
                i++;
            }
            else iremove(encrypt, i);
        }
        vector < pair < ll , char > > mainset;
        ll maxi = 0;
        for(ll i = 0; i < n; i++){
        	ll index = binarysearch(allfibonacci, fibs[i])+1;
        	maxi = max(maxi, index);
        	mainset.pb(mp(index, encrypt[i]));
        }
        sort(full(mainset));
        ll j = 1;
        for(ll i = 0; i < mainset.size(); ){
        	if(mainset[i].first == j){
        		cout << mainset[i].second;
        		i++;
        		j++;
        	}
        	else{
        		cout << ' ';
        		j++;
        	}
        }
        cout << endl;
    }
    

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
 
}