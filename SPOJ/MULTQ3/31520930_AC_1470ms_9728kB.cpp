#include <bits/stdc++.h>
using namespace std;

typedef struct node{
    int zero, one, two;
} node;

node segTree[400007];
int lazy[400007];

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
    int zzero = segTree[idx].zero, oone = segTree[idx].one, ttwo = segTree[idx].two;
    segTree[idx].one = zzero;
    segTree[idx].two = oone;
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

void update(int idx, int left, int right, int A, int B){

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
    update((idx << 1), left, mid, A, B);
    update((idx << 1)+1, mid+1, right, A, B);

    segTree[idx].zero = segTree[(idx << 1)].zero + segTree[(idx << 1)+1].zero;
    segTree[idx].one = segTree[(idx << 1)].one + segTree[(idx << 1)+1].one;
    segTree[idx].two = segTree[(idx << 1)].two + segTree[(idx << 1)+1].two;
}

int quary(int idx, int left, int right, int A, int B){

    if(lazy[idx]) propagation(idx, left, right);
    if(right < A or left > B) return 0;
    if(left >= A and right <= B) return segTree[idx].zero;

    int mid = ((left+right) >> 1);
    int left_zeros = quary((idx << 1), left, mid, A, B);
    int right_zeros = quary((idx << 1)+1, mid+1, right, A, B);

    return (left_zeros+right_zeros);
}

void solve(){
    int n, q;
    cin >> n >> q;
    build(1, 1, n);
    for(int i = 1; i <= q; i++){
        int type, A, B;
        cin >> type >> A >> B;
        if(type) cout << quary(1, 1, n, A+1, B+1) << endl;
        else update(1, 1, n, A+1, B+1);
    }
}

int main(){
    solve();
    return 0;
}