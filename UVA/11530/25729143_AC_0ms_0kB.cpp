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
#define MAX             15000
#define yes             cout << "yes" << endl
#define no              cout << "no" << endl
#define YES             cout << "YES" << endl
#define NO              cout << "NO" << endl
#define FASTIO          ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)


int main()
{
    FASTIO;
    ll t, c=0;
    cin >> t;
    cin.ignore();
    while(t--)
    {
        string str;
        getline(cin, str);
        ll tap=0, len=str.size();
        for(ll i=0; i<len; i++)
        {
            if(str[i]==' ') tap+=1;
            else if(str[i]=='a') tap+=1;
            else if(str[i]=='b') tap+=2;
            else if(str[i]=='c') tap+=3;
            else if(str[i]=='d') tap+=1;
            else if(str[i]=='e') tap+=2;
            else if(str[i]=='f') tap+=3;
            else if(str[i]=='g') tap+=1;
            else if(str[i]=='h') tap+=2;
            else if(str[i]=='i') tap+=3;
            else if(str[i]=='j') tap+=1;
            else if(str[i]=='k') tap+=2;
            else if(str[i]=='l') tap+=3;
            else if(str[i]=='m') tap+=1;
            else if(str[i]=='n') tap+=2;
            else if(str[i]=='o') tap+=3;
            else if(str[i]=='p') tap+=1;
            else if(str[i]=='q') tap+=2;
            else if(str[i]=='r') tap+=3;
            else if(str[i]=='s') tap+=4;
            else if(str[i]=='t') tap+=1;
            else if(str[i]=='u') tap+=2;
            else if(str[i]=='v') tap+=3;
            else if(str[i]=='w') tap+=1;
            else if(str[i]=='x') tap+=2;
            else if(str[i]=='y') tap+=3;
            else if(str[i]=='z') tap+=4;
        }
        cout << "Case #" << ++c << ":" << " ";
        cout << tap << endl;
    }
}