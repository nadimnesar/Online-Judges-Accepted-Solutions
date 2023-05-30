#include <bits/stdc++.h>
using namespace std;
 
#define ll               long long int
#define llu              long long unsigned int
#define pb               push_back
#define inst             insert
#define mp               make_pair
 
#define dot(x)           fixed << setprecision(x)
#define full(x)          x.begin(), x.end()
#define remove(x, y)     x.erase(remove(x.begin(), x.end(), y), x.end())
#define iremove(x, y)    x.erase(x.begin() + y)
#define debug(x)         cout << #x << " = " << x << endl
#define debug2(x, y)     cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define Clock            clock_t tStart = clock()
#define FastIO           ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define Freopen          freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define Runtime          fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC)
 
#define MAX              (10000001)
#define MOD              (1000000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define EPS              (1e-7)
#define LOG(b, x)        (log(x)/log(b))

ll n, m;
vector < ll > arr;

bool checker(ll mid){
    vector < ll > contain(m, 0);
    ll i, j = 0;
    for(i = 0; i < n; i++){
        if(j == m-1 and ((contain[j]+arr[i]) > mid)) break;
        if((contain[j]+arr[i]) <= mid) contain[j] += arr[i];
        else{
            j++;
            contain[j] += arr[i];
        }
    }
    if(i == n) return true;
    else return false;
}

int main(){
    while(cin >> n >> m){
        ll sum = 0, maxi = 0;
        for(ll i = 0; i < n; i++){
            ll temp;
            cin >> temp;
            arr.pb(temp);
            sum += temp;
            maxi = max(maxi, temp);
        }
        ll left = maxi;
        ll right = sum;
        ll ans;
        while(right >= left){
            ll mid = (left+right)/2;
            ll res = checker(mid);
            if(res){
                right = mid-1;
                ans = mid;
            }
            else left = mid+1;
        }
        cout << ans << endl;
        arr.clear();
    }
 
}