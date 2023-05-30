#include "bits/stdc++.h"
using namespace std;

void nadimnesar() {
    int n, m, k;
    cin >> n >> m >> k;

    int grid[n][m] = { };

    while (k--) {
        int t, rc, ai;
        cin >> t >> rc >> ai;

        if (t == 1) for (int i = 0; i < m; i++) grid[rc - 1][i] = ai;
        if (t == 2) for (int i = 0; i < n; i++) grid[i][rc - 1] = ai;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    nadimnesar();

    return 0;
}