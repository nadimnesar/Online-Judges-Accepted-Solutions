#include <bits/stdc++.h>
using namespace std;

int segTree[400007];
set < pair < int, int > > preadd;

void update(int idx, int left, int right, int x, int val){
    if(left > x or right < x) return;
    if(left == x and right == x){
        segTree[idx] = val;
        return;
    }

    int mid = ((left+right) >> 1);
    int l = (idx << 1);
    int r = (idx << 1)+1;

    update(l, left, mid, x, val);
    update(r, mid+1, right, x, val);

    if(segTree[l] == 0) segTree[idx] = segTree[r];
    else if(segTree[r] == 0) segTree[idx] = segTree[l];
    else segTree[idx] = __gcd(segTree[l], segTree[r]);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    char ch; int q, val; cin >> q;
    for(int i = 1; i <= q; i++){
        cin >> ch >> val;
        if(ch == '+'){
            update(1, 1, q, i, val);
            preadd.insert({val, i});
        }
        else{
            auto it = preadd.lower_bound({val,1});
            update(1, 1, q, it -> second, 0);
            preadd.erase(it);
        }
        if(segTree[1]) cout << segTree[1] << endl;
        else cout << 1 << endl;
    }
    return 0;
}