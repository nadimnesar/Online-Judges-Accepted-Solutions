#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, j=1;
    cin >> t;
    while(t--)
    {
        long long int a, b;
        cin >> a >> b;
        if(a < b || a == b)
            cout << "Case " << j++ << ": " << ((b*4)+19) << endl;
        else if(a>b)
            cout << "Case " << j++ << ": " << ((((a-b)+a)*4)+19) << endl;
    }
}