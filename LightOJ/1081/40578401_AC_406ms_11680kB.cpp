#include <bits/stdc++.h>
using namespace std;

#define maxx                (int)(5e2+7)
#define log(b, x)           (double)(log(x)/log(b))
#define memset(x, y)        memset(x,y,sizeof(x))

int n, q, s, e;
int arr[maxx][maxx];
int sTable[maxx][10][maxx];
int L[maxx];

void build_sTable(int r) {
    int limit = L[n];
    for (int i = 0; i <= limit; i++) {
        int l = 1 << i;
        for (int j = 0; j + l <= n; j++) {
            if (l == 1) sTable[r][i][j] = arr[r][j];
            else sTable[r][i][j] = max(sTable[r][i - 1][j], sTable[r][i - 1][j + l / 2]);
        }
    }
}

int serarch_MIN(int r) {
    int x = (e - s) + 1;
    int limit = L[x];
    int l = 1 << limit;
    return max(sTable[r][limit][s], sTable[r][limit][(e - l) + 1]);
}

void nadimnesar() {
    memset(sTable, 0);
    memset(arr, 0);

    scanf("%d %d", &n, &q);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
        build_sTable(i);
    }

    while (q--) {
        int p1, q1, x;
        scanf("%d %d %d", &p1, &q1, &x);

        int p2 = p1 + x - 1;
        int q2 = q1 + x - 1;

        s = q1-1;
        e = q2-1;

        int res = -1;
        for (int i = p1; i <= p2; i++) res = max(res, serarch_MIN(i - 1));

        printf("%d\n", res);
    }
}

int main() {

    for(int i = 0; i < maxx; i++) L[i] = log(10, i) / log(10, 2);

    int t, cn = 0;
    scanf("%d", &t);
    while (t--) {
        printf("Case %d:\n", ++cn);
        nadimnesar();
        
    }

    return 0;
}