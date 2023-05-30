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
    string str;
    getline(cin, str);
    ll c=0, len=str.size();
    if(len>1)
    {
        for(int i=1; i<len; i++)
        {
            if(str[i]>='A' && str[i]<='Z')
                c++;
        }
        if(str[0]>='a' && c==len-1)
        {
            for(int i=0; i<len; i++)
            {
                if(str[i]>='a' && str[i]<='z')
                    str[i]=toupper(str[i]);
                else
                    str[i]=tolower(str[i]);
            }
        }
        else if(str[0]>='A' && c==len-1)
        {
            for(int i=0; i<len; i++)
            {
                if(str[i]>='a' && str[i]<='z')
                    str[i]=toupper(str[i]);
                else
                    str[i]=tolower(str[i]);
            }
        }
        cout << str << endl;
    }
    else if(len==1)
    {
        if(str[0]>='a' && str[0]<='z')
            str[0]=toupper(str[0]);
        else
            str[0]=tolower(str[0]);
        cout << str << endl;
    }
}