#include <bits/stdc++.h>
using namespace std;

#define fastIO              ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

typedef struct node{
    int zero, one, two;
} node;

node segTree[400007];
int lazy[400007];
int A, B;

void build(int idx, int left, int right){
    if(left == right){
        segTree[idx].zero = 1;
        segTree[idx].one = 0;
        segTree[idx].two = 0;
        return;
    }

    int mid = ((left+right) >> 1);
    build((idx << 1), left, mid);
    build((idx << 1)+1, mid+1, right);

    segTree[idx].zero = segTree[(idx << 1)].zero + segTree[(idx << 1)+1].zero;
    segTree[idx].one = segTree[(idx << 1)].one + segTree[(idx << 1)+1].one;
    segTree[idx].two = segTree[(idx << 1)].two + segTree[(idx << 1)+1].two;
}

void increment(int idx){
    int ttwo = segTree[idx].two;
    segTree[idx].two = segTree[idx].one;
    segTree[idx].one = segTree[idx].zero;
    segTree[idx].zero = ttwo;
}

void propagation(int idx, int left, int right){
    int add = lazy[idx];
    lazy[idx] = 0;
    if(left != right){
        lazy[(idx << 1)] += add;
        lazy[(idx << 1)+1] += add;
    }
    add %= 3;
    for(int i = 0; i < add; i++){
        increment(idx);
    }
}

void update(int idx, int left, int right){
    if(lazy[idx]) propagation(idx, left, right);

    if(left > B or right < A) return;
    if(left >= A and right <= B){
        increment(idx);
        if(left != right){
            lazy[(idx << 1)]++;
            lazy[(idx << 1)+1]++;
        }
        return;
    }

    int mid = ((left+right) >> 1);
    update((idx << 1), left, mid);
    update((idx << 1)+1, mid+1, right);

    segTree[idx].zero = segTree[(idx << 1)].zero + segTree[(idx << 1)+1].zero;
    segTree[idx].one = segTree[(idx << 1)].one + segTree[(idx << 1)+1].one;
    segTree[idx].two = segTree[(idx << 1)].two + segTree[(idx << 1)+1].two;
}

int quary(int idx, int left, int right){

    if(lazy[idx]) propagation(idx, left, right);
    if(right < A or left > B) return 0;
    if(left >= A and right <= B) return segTree[idx].zero;

    return (quary((idx << 1), left, ((left+right) >> 1))+quary((idx << 1)+1, ((left+right) >> 1)+1, right));
}

void solve(){
    int n, q, type;
    cin >> n >> q;
    build(1, 1, n);
    for(int i = 1; i <= q; i++){
        cin >> type >> A >> B; ++A; ++B;
        if(type) cout << quary(1, 1, n) << endl;
        else update(1, 1, n);
    }
}

int main(){
    fastIO;
    solve();
    return 0;
}