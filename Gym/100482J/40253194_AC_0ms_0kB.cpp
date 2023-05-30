#include "bits/stdc++.h"
using namespace std;

void nadimnesar() {
    int n;
    scanf("%d", &n);

    int v[n];
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);

    sort(v, v+n);

    int res = 0;
    for (int i = 0; i < n; i++) {
        if (i != 0 and v[i] == v[i - 1]) continue;
        for (int j = i + 1; j < n; j++) {
            if (j != i + 1 and v[j] == v[j - 1]) continue;
            for (int k = j + 1; k < n; k++) {
                if (k != j + 1 and v[k] == v[k - 1]) continue;

                if(v[i]+v[j] > v[k]) res++;
            }
        }
    }

    printf("%d\n", res);
}

int main() {

    int t, cn = 0;
    scanf("%d", &t);
    while (t--) {
        cout << "Case #" << ++cn << ": ";
        nadimnesar();
    }

    return 0;
}