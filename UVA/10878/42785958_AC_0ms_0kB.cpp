#include <bits/stdc++.h>
using namespace std;

#define ll              long long int
#define endl            '\n'
#define in              insert
#define pb              push_back

#define full(x)         x.begin(),x.end()
#define dot(x)          fixed<<setprecision(x)

#define gcd(x, y)       (ll)(__gcd(x, y))
#define lcm(x, y)       (ll)((x/gcd(x,y))*y)
#define log(b, x)       (double)(log(x)/log(b))

const ll mod = 1e9 + 7;
const ll maxx = 1e6 + 7;
const ll inf = LLONG_MAX;
const double eps = 1e-7;
const double pi = acos(-1.0);

ll dx[] = { 0, 0, 1, -1 };
ll dy[] = { 1, -1, 0, 0 };

void solve() {
  string s;
  ll cnt = 0;
  while(getline(cin, s)){
    if(s == "___________"){
      cnt++;
      if(cnt == 2) break;
      continue;
    }

    ll bit = 0;
    if(s[2] == 'o') bit += 64;
    if(s[3] == 'o') bit += 32;
    if(s[4] == 'o') bit += 16;
    if(s[5] == 'o') bit += 8;
    if(s[7] == 'o') bit += 4;
    if(s[8] == 'o') bit += 2;
    if(s[9] == 'o') bit += 1;

    cout << char(bit);
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);

  solve();

  return 0;
}