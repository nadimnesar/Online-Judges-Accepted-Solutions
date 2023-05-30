#include <bits/stdc++.h>
using namespace std;

#define ll                  long long
#define llu                 unsigned long long

#define endl                '\n'
#define in                  insert
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define memset(x, y)        memset(x,y,sizeof(x))
#define dot(x)              fixed<<setprecision(x)

#define gcd(x, y)           (ll)(__gcd(x, y))
#define lcm(x, y)           (ll)((x/gcd(x,y))*y)
#define log(b, x)           (double)(log(x)/log(b))

#define base                (ll)(10)
#define maxx                (ll)(1e6+7)
#define mod                 (ll)(1e9+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))

ll n;
ll arr[maxx];
bool flag;
ll sswap;

void marge(ll left, ll mid, ll right){
    if(!flag) return;

    ll leftsize = (mid-left)+1;
    ll rightsize = (right-mid);

    ll leftarray[leftsize], rightarray[rightsize];
    for(ll i = 0; i < leftsize; i++) leftarray[i] = arr[left+i];
    for(ll i = 0; i < rightsize; i++) rightarray[i] = arr[mid+i+1];

    ll a = leftarray[0];
    ll b = leftarray[leftsize-1];

    ll c = rightarray[0];
    ll d = rightarray[rightsize-1];

    for(ll i = 0; i < leftsize; i++){
        if(leftarray[i] > c and leftarray[i] < d){
            flag = false;
            return;
        }
    }

    for(ll i = 0; i < rightsize; i++){
        if(rightarray[i] > a and rightarray[i] < b){
            flag = false;
            return;
        }
    }

    ll k = left;
    ll i = 0;
    ll j = 0;

    if(c > b){
        while(i < leftsize){
            arr[k] = leftarray[i];
            i++;
            k++;
        }
        while(j < rightsize){
            arr[k] = rightarray[j];
            k++;
            j++;
        }
    }
    else{
        sswap++;
        while(j < rightsize){
            arr[k] = rightarray[j];
            k++;
            j++;
        }

        while(i < leftsize){
            arr[k] = leftarray[i];
            i++;
            k++;
        }
    }
}

void margesorting(ll left, ll right){
    if(left >= right) return;
    if(!flag) return;

    ll mid = left + (right-left)/2;
    margesorting(left, mid);
    margesorting(mid+1, right);
    marge(left, mid, right);
}

void nadimnesar() {
    cin >> n;
    for(ll i = 0; i < n; i++) cin >> arr[i];

    sswap = 0;
    flag = true;
    margesorting(0, n-1);

    if(flag) cout << sswap << endl;
    else cout << -1 << endl;
 }

int main() {

    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t, cn = 0;
    cin >> t;
    while (t--){
        // cout << "Case #" << ++cn << ": ";
        nadimnesar();
    }

    return 0;
}