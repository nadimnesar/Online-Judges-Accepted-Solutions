/*BISMILLAHIR RAHMANIR RAHIM*/
#include <bits/stdc++.h>
using namespace std;
#define ll              long long
#define pb              push_back
#define all(x)          x.begin(), x.end()
#define all(y)          y.begin(), y.end()
#define all(z)          z.begin(), z.end()
#define pi              acos(-1.0)

list < char > x;
list < char >:: iterator it;

int main()
{
    string str;
    while(getline(cin, str))
    {
        it = x.begin();
        int len = str.size();
        for(int i = 0; i < len; i++)
        {
            if(str[i] == '[') it = x.begin();
            else if(str[i] == ']') it = x.end();
            else
            {
                x.insert(it, str[i]);
            }
        }
        for(it = x.begin(); it != x.end(); it++)
        {
            cout<< *it;
        }
        cout << '\n';
        x.clear();
    }
}
/*ALHAMDULILLAH*/
