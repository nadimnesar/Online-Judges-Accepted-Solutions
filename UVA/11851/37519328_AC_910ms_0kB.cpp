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

bool cmp(pair < ll , ll > x, pair < ll , ll > y){
    return (x.second < y.second);
}

vector < ll > x, y;
vector < pair < ll , ll > > xset;
vector < pair < ll , ll > > yset;

void BT(int idx, ll a, ll b, ll sold, char type, int end) {
    if (idx == end) {
        if (type == 'x') xset.pb({a - b, sold});
        if (type == 'y') yset.pb({a - b, sold});
        return;
    }

    if (type == 'x') {
        BT(idx + 1, a, b, sold + x[idx], type, end);
        BT(idx + 1, a + x[idx], b, sold, type, end);
        BT(idx + 1, a, b + x[idx], sold, type, end);
    }

    if (type == 'y') {
        BT(idx + 1, a, b, sold + y[idx], type, end);
        BT(idx + 1, a + y[idx], b, sold, type, end);
        BT(idx + 1, a, b + y[idx], sold, type, end);
    }
}

int binarysearch(ll q){
    int right = yset.size()-1;
    int left = 0;

    int index = -1;
    while(right >= left){
        int mid = left + (right-left)/2;

        if (yset[mid].first == q){
            index = mid;
            right = mid -1;
        }
        else if(yset[mid].first > q) right = mid-1;
        else left = mid+1;
    }
    return index;
}

void solve() {
    int n;
    while (cin >> n and n) {
        x.clear();
        y.clear();
        ll mxSOLD = 0;

        for (int i = 0; i < n / 2; i++) {
            ll temp;
            cin >> temp;
            x.pb(temp);
            mxSOLD += temp;
        }

        for (int i = n / 2; i < n; i++) {
            ll temp;
            cin >> temp;
            y.pb(temp);
            mxSOLD += temp;
        }

        xset.clear();
        yset.clear();

        BT(0, 0, 0, 0, 'x', x.size());
        BT(0, 0, 0, 0, 'y', y.size());

        sort(full(yset));
        sort(full(xset), cmp);

        ll res = mxSOLD;

        for (int i = 0; i < xset.size(); i++) {
            int idx = binarysearch(xset[i].first);

            if(idx != -1) res = min(res, xset[i].second+yset[idx].second);
        }
        cout << res << endl;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();

    return 0;
}