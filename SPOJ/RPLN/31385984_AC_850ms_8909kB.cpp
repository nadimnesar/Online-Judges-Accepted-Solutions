#include <stdio.h>
#include<climits>

#define ll               long long int
#define MAX              (ll)(1e6+7)


ll n, q, s, e;
ll arr[MAX];
ll segTree[MAX * 4];

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
    if(right < s or left > e) return LLONG_MAX;
    if(left >= s and right <= e) return segTree[index];

    ll mid = (left+right) >> 1;
    ll left_min = range_quary((index << 1), left, mid);
    ll right_min = range_quary((index << 1)+1, mid+1, right);

    return (left_min > right_min) ? right_min: left_min;
}

void solve(){
    scanf("%lld %lld", &n, &q);
    for(ll i = 1; i <= n; i++) scanf("%lld", &arr[i]);
    build_segTree(1, 1, n);
    while(q--){
        scanf("%lld %lld", &s, &e);
        printf("%lld\n", range_quary(1, 1, n));
    }
}

int main(){

    ll t; scanf("%lld", &t);
    ll cn = 0;
    while(t--){
        printf("Scenario #%lld:\n", ++cn);
        solve();
    }
 
}
