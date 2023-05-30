#include <bits/stdc++.h>
using namespace std;

#define ll                  long long int
#define llu                 long long unsigned int

#define endl                "\n"
#define in                  insert             
#define ppb                 pop_back
#define pb                  push_back

#define full(x)             x.begin(),x.end()
#define iremove(x,y)        x.erase(x.begin()+y)
#define dot(x)              fixed<<setprecision(x)
#define remove(x,y)         x.erase(remove(x.begin(),x.end(),y),x.end())

#define maxx                (ll)(1e7+7)
#define mod                 (ll)(1e9+7)
#define eps                 (double)(1e-7)
#define pi                  (double)(acos(-1.0))
#define log(b, x)           (double)(log(x)/log(b))

void solve(){

    int t;
    cin >> t;
    ll cn = 0;
    while(t--){
        string str;
        cin >> str;

        cout << "Case " << ++cn << ": ";
        
        string copy = str;
        reverse(full(copy));

        ll n = str.size();

        if(str == copy){

            bool all_9 = true;
            for(ll i = 0; str[i]; i++){
                if(str[i] != '9'){
                    all_9 = false;
                    break;
                }
            }

            if(all_9){
                cout << '1';
                ll x = str.size();
                x--;
                while(x--) cout << '0';
                cout << '1' << endl;
                continue;
            }

            ll idx = str.size()/2;
            if((str.size())&1){
                if(str[idx] != '9'){
                    str[idx]++;
                    cout << str << endl;
                    continue;
                }

                for(ll i = idx; str[i]; i++){
                    if(str[i] != '9'){
                        str[i]++;
                        str[(n-i)-1] = str[i];
                        break;
                    }
                    else{
                        str[i] = '0';
                        str[(n-i)-1] = str[i];
                    }
                }
                cout << str << endl;
                continue;
            }
            else{
                for(ll i = idx; str[i]; i++){
                    if(str[i] != '9'){
                        str[i]++;
                        str[(n-i)-1] = str[i];
                        break;
                    }
                    else{
                        str[i] = '0';
                        str[(n-i)-1] = str[i];
                    }
                }
                cout << str << endl;
                continue;
            }
        }
        else{

            if(n&1){

                string c1, c2, c3, c4;

                ll idx = (str.size()/2);


                string x = str.substr(0, idx);

                reverse(full(x));
                string y = x;
                reverse(full(x));
                x += str[idx] + 1;
                x += y;

                if(str[idx] + 1 == ':') c1 = str;
                else c1 = x;

                x = str.substr(0, idx);
                reverse(full(x));
                y = x;
                reverse(full(x));
                x += str[idx];
                x += y;

                c2 = x;

                x = str.substr(0, idx);
                for(ll i = x.size()-1; i >= 0; i--){
                    if(x[i] != '9'){
                        x[i]++;
                        break;
                    }
                    else x[i] = '0';
                }

                reverse(full(x));
                y = x;
                reverse(full(x));
                x += str[idx];
                x += y;

                c3 = x;

                x = str.substr(0, idx);
                for(ll i = x.size()-1; i >= 0; i--){
                    if(x[i] != '9'){
                        x[i]++;
                        break;
                    }
                    else x[i] = '0';
                }

                reverse(full(x));
                y = x;
                reverse(full(x));
                x += '0';
                x += y;

                c4 = x;

                string res;
                bool flag = false;

                if(c1 > str){

                    if(flag) res = min(res, c1);
                    else{
                        res = c1;
                        flag = true;
                    }
                }

                if(c2 > str){
                    if(flag) res = min(res, c2);
                    else {res = c2;flag = true;}
                }

                if(c3 > str){
                    if(flag) res = min(res, c3);
                    else {res = c3;flag = true;}
                }

                if(c4 > str){
                    if(flag) res = min(res, c4);
                    else {res = c4;flag = true;}
                }



                cout << res << endl;
                continue;
            }
            else{
                string c1, c2;

                ll idx = (str.size()/2);

                string x = str.substr(0, idx);
                reverse(full(x));
                string y = x;
                reverse(full(x));
                x += y;

                c1 = x;

                x = str.substr(0, idx);

                for(ll i = x.size()-1; i >= 0; i--){
                    if(x[i] != '9'){
                        x[i]++;
                        break;
                    }
                    else x[i] = '0';
                }

                reverse(full(x));
                y = x;
                reverse(full(x));
                x += y;

                c2 = x;


                string res;
                bool flag = false;


                if(c1 > str){
                    res = c1;
                    flag = true;
                }
                if(c2 > str){
                    if(flag) res = min(res, c2);
                    else{
                        res = c2;
                    }
                }

                cout << res << endl;
                continue;
            }
        }
    }

}

int main(){

    solve();
    
    return 0;
}