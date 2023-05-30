#include <stdio.h>

#define MAX              (int)(1e5+7)

int n, q, type, i, v, j;
int arr[MAX];
int segTree[MAX * 4];

void build_segTree(int index, int left, int right){
    if(left == right){
        segTree[index] = arr[left];
        return;
    }
    int mid = (left+right) >> 1;
    build_segTree((index << 1), left, mid);
    build_segTree((index << 1)+1, mid+1, right);

    segTree[index] = (segTree[(index << 1)] + segTree[(index << 1)+1]);
}

void single_quary(int index, int left, int right){
    if(right < i or left > i) return;
    if(left == i and right == i){
        if(type == 1) printf("%d\n", segTree[index]);
        (type == 1) ? segTree[index] = 0: segTree[index] = segTree[index] + v;
        return;
    }

    int mid = (left+right) >> 1;
    single_quary((index << 1), left, mid);
    single_quary((index << 1)+1, mid+1, right);

    segTree[index] = (segTree[(index << 1)] + segTree[(index << 1)+1]);
}

int range_quary(int index, int left, int right){
    if(right < i or left > j) return 0;
    if(left >= i and right <= j) return segTree[index];

    int mid = (left+right) >> 1;
    int left_sum = range_quary((index << 1), left, mid);
    int right_sum = range_quary((index << 1)+1, mid+1, right);

    return (left_sum+right_sum);
}

void solve(){
    scanf("%d %d", &n, &q);
    for(int k = 1; k <= n; k++) scanf("%d", &arr[k]);
    build_segTree(1, 1, n);
    while(q--){
        scanf("%d", &type);
        if(type == 1){
            scanf("%d", &i);
            ++i; single_quary(1, 1, n);
        }
        else if(type == 2){
            scanf("%d %d", &i, &v);
            ++i; single_quary(1, 1, n);
        }
        else{
            scanf("%d %d", &i, &j);
            ++i; ++j; printf("%d\n", range_quary(1, 1, n));
        }
    }
}

int main(){

    int t; scanf("%d", &t);
    int cn = 0;
    while(t--){
        printf("Case %d:\n", ++cn);
        solve();
    }
 
}