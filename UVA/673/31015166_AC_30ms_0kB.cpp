#include <bits/stdc++.h>
using namespace std;

#define llu              long long unsigned int
#define ll               long long int
#define pb               push_back
#define mp               make_pair
// #define pop              pop_back

#define bug              cout<<"bug!!!"<<endl
#define debug(x)         cout<<#x<<" = "<<x<<endl
#define debug2(x,y)      cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl

#define full(x)          x.begin(),x.end()
#define iremove(x,y)     x.erase(x.begin()+y)
#define dot(x)           fixed<<setprecision(x)
#define remove(x, y)     x.erase(remove(x.begin(),x.end(),y),x.end())
#define alluniq(x, y)    x.resize(dis(x.begin(),unique(x.begin(),x.begin()+y)))
#define FastIO           ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

#define EPS              (1e-7)
#define MAX              (1e5+7)
#define MOD              (1e9+7)
#define PI               (acos(-1.0))
#define LOG(b, x)        (log(x)/log(b))

void solve(){
    string str; getline(cin, str);
    if(str.size() == 0){
        cout << "Yes" << endl;
        return;
    }
    int first = 0, third = 0;
    for(int i = 0; str[i]; i++){
        if(str[i] == '(') first++;
        else if(str[i] == ')') first--;
        else if(str[i] == '[') third++;
        else third--;

        if(first < 0) break;
        if(third < 0) break;
    }
    if(first != 0 or third != 0){
        cout << "No" << endl;
        return;
    }
    bool ok = true;
    for(int i = 1; str[i]; i++){
        if(str[i] == ')' and str[i-1] == '[') ok = false;
        else if(str[i] == ']' and str[i-1] == '(') ok = false;
    }
    if(!ok){
        cout << "No" << endl;
        return;
    }
    stack < char > s;
    for(int i = 0; str[i]; i++){
        if(str[i] == ')'){
            if(s.size() == 0){
                ok = false;
                break;
            }

            if(s.top() == '(') s.pop();
            else if(s.top() == '['){
                ok = false;
                break;
            }
            else s.push(str[i]);
        }
        else if(str[i] == ']'){
            if(s.size() == 0){
                ok = false;
                break;
            }
            if(s.top() == '[') s.pop();
            else if(s.top() == '('){
                ok = false;
                break;
            }
            else s.push(str[i]);
        }
        else s.push(str[i]);
    }
    if(s.size() != 0) ok = false;
    if(!ok) cout << "No" << endl;
    else cout << "Yes" << endl;
}

int main(){
    
    FastIO;
    int t; cin >> t; cin.ignore();
    // int cn = 0;
    while(t--){
        // cout << "Case " << ++cn << ": ";
        // cout << "Case " << ++cn << ':' << endl;
        solve();
    }
}