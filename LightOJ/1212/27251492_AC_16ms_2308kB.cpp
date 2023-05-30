/*BISMILLAHIR RAHMANIR RAHIM*/
#include <bits/stdc++.h>
using namespace std;
 
#define ll               long long int
#define llu              long long unsigned int
#define pb               push_back
#define ist              insert
#define mp               make_pair
 
#define dot(x)           fixed << setprecision(x)
#define full(x)          x.begin(), x.end()
#define remove(x, y)     x.erase(remove(x.begin(), x.end(), y), x.end())
#define iremove(x, y)    x.erase(x.begin() + y)
#define debug(x)         cout << #x << " = " << x << endl
#define debug2(x, y)     cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define fastIO           ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
 
#define MOD              (1000000007)
#define PI               (acos(-1.0)) //3.1415926535897932384626
#define EPS              (1e-7)
#define LOG(b, x)        (log(x)/log(b))
 
template <class T> T gcd(T a, T b){ if(a == 0) return b; return gcd(b%a, a); }
template <class T> T lcm(T a, T b){ return ((a*b)/gcd(a, b)); }

deque <int> mydeque;

int main(){
 
    fastIO;
#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

    int t, cn = 0;
    cin >> t;
    while(t--){
        int size, commands;
        cin >> size >> commands;
        cin.ignore();
        cout << "Case " << ++cn << ":" << endl;
        while(commands--){
            string cmd;
            getline(cin, cmd);
            int value = 0;
            if(cmd.size() > 8){
                stringstream ss(cmd);
                ss >> cmd >> value;
            }
            if(cmd == "pushLeft"){
                if(mydeque.size() < size){
                    mydeque.push_front(value);
                    cout << "Pushed in left: " << value << endl;
                }
                else cout << "The queue is full" << endl;
            }
            else if(cmd == "pushRight"){
                if(mydeque.size() < size){
                    mydeque.push_back(value);
                    cout << "Pushed in right: " << value << endl;
                }
                else cout << "The queue is full" << endl;
            }
            else if(cmd == "popLeft"){
                if(!mydeque.empty()){
                    cout << "Popped from left: " <<  mydeque.front() << endl;
                    mydeque.pop_front();
                }
                else cout << "The queue is empty" << endl;
            }
            else{
                if(!mydeque.empty()){
                    cout << "Popped from right: " << mydeque.back() << endl;
                    mydeque.pop_back();
                }
                else cout << "The queue is empty" << endl;
            }
        }
        mydeque.clear();
    }
#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
 
}