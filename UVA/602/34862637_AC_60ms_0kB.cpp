#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define llu                 long long unsigned int

#define in                  insert
#define ppb                 pop_back
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define dot(x)              fixed<<setprecision(x)

#define maxx                (ll)(2e7+7)                           
#define mod                 (ll)(1e9+7)
#define inf                 (0x3f3f3f3f)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))
#define log(b, x)           (double)(log(x)/log(b))

ll m, d, y;
string day[8] = {"Friday", "Saturday", "Sunday", "Monday","Tuesday","Wednesday", "Thursday"};
string month[] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
int mcnt[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int leap(ll x){
    if(x < 1752){
        if(x%4 == 0) return 1;
        else return 0;
    }
    if (x%400 == 0) return 1;
    if (x%100 == 0) return 0;
    if (x%4 == 0) return 1;
    return 0;
}

bool before(){
    if(y < 1752) return true;
    if(y == 1752){
        if(m < 9) return true;
    }
    if(y == 1752){
        if(m == 9){
            if(d <= 2) return true;
        }
    }
    return false;
}

void solve(){
    while(cin >> m >> d >> y){
        if(m == 0 and d == 0 and y == 0) break;

        if(m < 1 or m > 12){
            cout << m << '/' << d << '/' << y << " is an invalid date." << endl;
            continue;
        }
        if(d < 1 or d > 31){
            cout << m << '/' << d << '/' << y << " is an invalid date." << endl;
            continue;
        }

        if(m == 2){
            if(d > 29){
                cout << m << '/' << d << '/' << y << " is an invalid date." << endl;
                continue;
            }
            if(!leap(y)){
                if(d > 28){
                    cout << m << '/' << d << '/' << y << " is an invalid date." << endl;
                    continue;
                }
            }
        }

        if(y < 0){
            cout << m << '/' << d << '/' << y << " is an invalid date." << endl;
            continue;
        }

        if(m == 2 and d == 29){
            if(y%4 != 0){
                cout << m << '/' << d << '/' << y << " is an invalid date." << endl;
                continue;
            }
            if(y > 1752){
                if(y%400 != 0){
                    if(y%100 == 0 or y%4 != 0){
                        cout << m << '/' << d << '/' << y << " is an invalid date." << endl;
                        continue;
                    }
                }
            }
        }

        if(y == 1752){
            if(m == 9){
                if(d >= 3 and d <= 13){
                    cout << m << '/' << d << '/' << y << " is an invalid date." << endl;
                    continue;
                }
            }
        }

        if(m == 4 or m == 6 or m == 9 or m == 11){
            if(d == 31){
                cout << m << '/' << d << '/' << y << " is an invalid date." << endl;
                continue;
            }
        }

        mcnt[2] += leap(y);
        ll total_days = d;
        for(int i = 1; i < m; i++) total_days += mcnt[i];
        for(int i = 1; i < y; i++) total_days += 365+leap(i);
        
        if(!before()) total_days -= 11;

        cout << month[m] << ' ' << d << ", " << y << " is a " << day[total_days % 7] << endl;
        mcnt[2] = 28;
    }
}


int main(){

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    solve();
    
    return 0;
}