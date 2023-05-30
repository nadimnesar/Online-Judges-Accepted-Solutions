#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, j, a1, a2;
    cin >> n;
    while (n--)
    {
        int c1, c2;
        cin >> c1;
        if(c1>=10)
        {
            a1=c1-10;
            a2=10;
            cout << a1 << ' ' << a2 << endl;
        }
        else
        {
            a1=0;
            a2=c1;
            cout << a1 << ' ' << a2 << endl;
        }
    }
}