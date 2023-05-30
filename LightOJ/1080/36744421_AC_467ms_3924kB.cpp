#include <iostream>
#include <vector>
#include <utility>
#include <string.h>
using namespace std;

int segTree[4*100007];
int lazy[4*100007];
int p, q, v;

void build(int idx, int left, int right){
    if(left == right){
        segTree[idx] = 0;
        return;
    }

    int mid = ((left+right) >> 1);
    build((idx << 1), left, mid);
    build((idx << 1)+1, mid+1, right);

    segTree[idx] = segTree[(idx << 1)] + segTree[(idx << 1)+1];
}

void propagation(int idx, int left, int right){
    segTree[idx] += (lazy[idx]*((right-left)+1));
    if(left != right){
        lazy[(idx << 1)] += lazy[idx];
        lazy[(idx << 1)+1] += lazy[idx];
    }
    lazy[idx] = 0;
}

void update(int idx, int left, int right){
    if(lazy[idx]) propagation(idx, left, right);

    if(left > q or right < p) return;
    if(left >= p and right <= q){
        segTree[idx] += (v*((right-left)+1));
        if(left != right){
            lazy[(idx << 1)] += v;
            lazy[(idx << 1)+1] += v;
        }
        return;
    }

    int mid = ((left+right) >> 1);
    update((idx << 1), left, mid);
    update((idx << 1)+1, mid+1, right);

    segTree[idx] = segTree[(idx << 1)] + segTree[(idx << 1)+1];
}

int quary(int idx, int left, int right){
    if(lazy[idx]) propagation(idx, left, right);
    if(right < p or left > q) return 0;
    if(left >= p and right <= q) return segTree[idx];

    int mid = ((left+right) >> 1);
    return (quary((idx << 1), left, mid)+quary((idx << 1)+1, mid+1, right));
}

void solve(){
    char str[100007];
    scanf("%s", str);

    int n = strlen(str);
    build(1, 1, n);

    int t;
    cin >> t;
    while(t--){
        char x;
        getchar();
        scanf("%c", &x);
        if(x == 'I'){
            scanf("%d %d", &p, &q);
            v = 1;
            update(1, 1, n);
        }
        else{
            scanf("%d", &p); q = p;
            printf("%d\n", (quary(1, 1, n)&1) ? !(str[p-1]-'0'): (str[p-1]-'0'));
        }
    }
}

int main(){
    int t, cn = 0;
    scanf("%d", &t);
    getchar();
    while(t--){
        printf("Case %d:\n", ++cn);
        solve();
        memset(segTree, 0, sizeof(segTree));
        memset(lazy, 0, sizeof(lazy));
    }
    
    return 0;
}