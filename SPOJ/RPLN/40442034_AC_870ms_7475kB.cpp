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
#define maxx                (ll)(1e5+7)
#define mod                 (ll)(1e9+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))

ll n, q, s, e;
ll arr[maxx];
ll segTree[4*maxx];

void build_segTree(ll index, ll left, ll right){
    if(left == right){
        segTree[index] = arr[left];
        return;
    }
    ll mid = (left+right) >> 1;
    build_segTree((index << 1), left, mid);
    build_segTree((index << 1)+1, mid+1, right);

    segTree[index] = (segTree[(index << 1)] > segTree[(index << 1)+1]) ? segTree[(index << 1)+1]: segTree[(index << 1)];
}

ll range_quary(ll index, ll left, ll right){
    if(right < s or left > e) return (1LL*1000000007);
    if(left >= s and right <= e) return segTree[index];

    ll mid = (left+right) >> 1;
    ll left_min = range_quary((index << 1), left, mid);
    ll right_min = range_quary((index << 1)+1, mid+1, right);

    return (left_min > right_min) ? right_min: left_min;
}

void nadimnesar() {
    cin >> n >> q;

    for(ll i = 1; i <= n; i++) cin >> arr[i];
    build_segTree(1, 1, n);

    while(q--){
        cin >> s >> e;
        cout << range_quary(1, 1, n) << endl;
    }
}

int main() {

    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll t, cn = 0;
    cin >> t;
    while (t--){
        cout << "Scenario #" << ++cn << ":" << endl;
        nadimnesar();
    }

    return 0;
}