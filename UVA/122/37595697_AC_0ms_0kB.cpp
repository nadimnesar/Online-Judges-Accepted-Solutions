#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define llu                 long long unsigned int

#define endl                '\n'
#define in                  insert
#define ppb                 pop_back
#define ppf                 pop_front
#define pb                  push_back
#define pf                  push_front

#define full(x)             x.begin(),x.end()
#define iremove(x,y)        x.erase(x.begin()+y)
#define memset(x, y)        memset(x,y,sizeof(x))
#define dot(x)              fixed<<setprecision(x)
#define remove(x,y)         x.erase(remove(x.begin(),x.end(),y),x.end())

#define gcd(x, y)           (ll)(__gcd(x, y))
#define lcm(x, y)           (ll)((x/gcd(x,y))*y)
#define log(b, x)           (double)(log(x)/log(b))

#define base                (ll)23
#define maxx                (ll)(3e4+7)
#define mod                 (ll)(1e9+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))

void solve() {
    vector < string > v;
    string str;
    while (cin >> str) {
        if (str == "()") {

            bool flag = false;

            unordered_map < string, ll > mp;
            for (ll j = 0; j < v.size(); j++) {
                string temp;
                ll i = 1;
                for (; i < v[j].size(); i++) {
                    if (v[j][i] == ',') break;
                    temp += v[j][i];
                }

                ll n = stoi(temp);
                temp.clear();
                i++;
                for (; i < v[j].size(); i++) {
                    if (v[j][i] == ')') break;
                    temp += v[j][i];
                }

                if (temp.size() == 0) temp += 'X';


                if(mp[temp] > 0) flag = true;
                mp[temp] = n;
            }

            if (mp["X"] <= 0) {
                cout << "not complete" << endl;
                v.clear();
                continue;
            }

            for (auto it : mp) {
                string temp = it.first;
                if (temp == "X") continue;

                while (temp.size() > 0) {
                    if (mp[temp] <= 0) {
                        flag = true;
                        break;
                    }
                    iremove(temp, temp.size() - 1);
                }
                if (flag) break;
            }

            if (flag) {
                cout << "not complete" << endl;
                v.clear();
                continue;
            }

            vector < string > lastv;
            lastv.pb("X");

            ll prt = 0;
            while (prt < lastv.size()) {
                if(v.size() == 1) break;
                if (prt == 0) {
                    if (mp["L"] > 0) lastv.pb("L");
                    if (mp["R"] > 0) lastv.pb("R");
                }
                else {
                    if (mp[lastv[prt] + "L"] > 0) lastv.pb(lastv[prt] + "L");
                    if (mp[lastv[prt] + "R"] > 0) lastv.pb(lastv[prt] + "R");
                }
                prt++;
            }

            for (ll i = 0; i < lastv.size(); i++) {
                if (i+1 == lastv.size()) cout << mp[lastv[i]] << endl;
                else cout << mp[lastv[i]] << ' ';
            }

            v.clear();
        }
        else v.pb(str);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();

    return 0;
}