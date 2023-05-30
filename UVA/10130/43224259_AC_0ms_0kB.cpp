#include <bits/stdc++.h>
using namespace std;

pair < int, int > products[1007];
int dp[37];
int fw[107];

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> products[i].first >> products[i].second;
  }
  int f;
  cin >> f;
  for (int i = 0; i < f; i++) {
    cin >> fw[i];
  }

  memset(dp, -1, sizeof(dp));
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 30 - products[i].second; j >= 0; j--) {
      if (dp[j] > -1) {
        dp[j + products[i].second] = max(dp[j + products[i].second], dp[j] + products[i].first);
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < f; i++) {
    int tmp = -1;
    for (int j = 0; j <= fw[i]; j++) {
      tmp = max(tmp, dp[j]);
    }
    ans += tmp;
  }

  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) solve();

  return 0;
}