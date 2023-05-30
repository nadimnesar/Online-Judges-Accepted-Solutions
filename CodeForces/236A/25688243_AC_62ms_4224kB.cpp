#include <bits/stdc++.h>
using namespace std;
#define ll              long long int
#define ull             long long unsigned int
#define vll             vector< ll >
#define pb              push_back
#define all(x)          x.begin(), x.end()
#define point(x)        fixed << setprecision(x)
#define PI              acos(-1.0) //3.1415926535897932
#define EPS             1e-9
#define yes             cout << "yes" << endl
#define no              cout << "no" << endl
#define YES             cout << "YES" << endl
#define NO              cout << "NO" << endl
#define FastIO          ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main()
{
    FastIO;
    string temp;
    getline(cin, temp);
    ll c=0, len=temp.size();
    for(int i=0; i<len; i++)
    {
        if(temp[i]==-1) continue;
        for(int j=i+1; j<len; j++)
        {
            if(temp[i]==temp[j])
            {
                temp[j]=-1;
            }
        }
        c++;
    }
    if(c%2==0)
        cout << "CHAT WITH HER!" << endl;
    else cout << "IGNORE HIM!" << endl;
}