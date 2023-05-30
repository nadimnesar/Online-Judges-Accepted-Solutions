#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int

ll n;
ll arr[262144+7];
ll cnt;


void marge(ll left, ll mid, ll right){
    ll leftsize = (mid-left)+1;
    ll rightsize = (right-mid);

    ll leftarray[leftsize], rightarray[rightsize];
    for(ll i = 0; i < leftsize; i++) leftarray[i] = arr[left+i];
    for(ll i = 0; i < rightsize; i++) rightarray[i] = arr[mid+i+1];

    if(leftarray[0] > rightarray[0]){
        ll k = left;
        ll i = 0;
        ll j = 0;

        for(ll j = 0; j < rightsize; j++){
            arr[k] = rightarray[j];
            k++;
        }

        for(ll i = 0; i < leftsize; i++){
            arr[k] = leftarray[i];
            k++;
        }

        cnt++;
    }
}

void margesorting(ll left, ll right){
    if(left >= right) return;
    ll mid = left + (right-left)/2;
    margesorting(left, mid);
    margesorting(mid+1, right);
    marge(left, mid, right);
}

void solve(){
    scanf("%d", &n);
    for(ll i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    cnt = 0;
    margesorting(0, n-1);

    if(is_sorted(arr, arr + n)){
        cout << cnt << endl;
    }
    else cout << "-1" << endl;
}

int main(){
    ll t;
    cin >> t;
    while(t--){

        solve();
    }
}