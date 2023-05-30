/*BISMILLAHIR RAHMANIR RAHIM*/
#include <bits/stdc++.h>
using namespace std;
#define ll        long long
#define pb        push_back
#define ins       insert
#define all(x)    x.begin(), x.end()
#define dot(x)    fixed << setprecision(x)
#define fastIO    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define PI        acos(-1.0) //3.1415926535897932
#define Log(b,x)  (log(x)/log(b))
#define eps       (int)(1e-9)
#define MAX       (int)(1e9+1)
#define MOD       (int)(1e7+1)


int main(){
    #ifndef ONLINE_JUDGE
        clock_t tStart = clock();
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    fastIO;

    int t, cn = 0;
    cin >> t;
    cin.ignore();
    while(t--){
        cout << "Case " << ++cn << ":" << endl;
        stack < string > forword;
        stack < string > backward;
        string current = "http://www.lightoj.com/";
        while(1){
            string str;
            getline(cin, str);

            if(str == "QUIT") break;
            else if(str == "FORWARD"){
                if(forword.empty()){
                    cout << "Ignored" << endl;
                }
                else{
                    backward.push(current);
                    current = forword.top();
                    forword.pop();
                    cout << current << endl;
                }

            }
            else if(str == "BACK"){
                if(backward.empty()){
                    cout << "Ignored" << endl;
                }
                else{
                    forword.push(current);
                    current = backward.top();
                    backward.pop();
                    cout << current << endl;
                }
            }
            else{
                int limit = str.size();
                string link;
                link = str.substr(6, limit-1);
                backward.push(current);
                current = link;
                cout << current << endl;
                while(!forword.empty()) forword.pop();
            }
        }
    }

    #ifndef ONLINE_JUDGE
        fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
    #endif
}