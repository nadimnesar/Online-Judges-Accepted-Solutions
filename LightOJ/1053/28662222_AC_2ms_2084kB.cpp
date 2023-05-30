#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, j=1;
    cin >> t;
    while(t--)
    {
        long long unsigned int a, b, c;
        cin >> a >> b >> c;
        if(a<=0 || b<=0 || c<=0)
            cout << "Case " << j++ << ": no" << endl;
        else if(((a*a)+(b*b))==(c*c))
            cout << "Case " << j++ << ": yes" << endl;
        else if(((a*a)+(c*c))==(b*b))
            cout << "Case " << j++ << ": yes" << endl;
        else if(((b*b)+(a*a))==(c*c))
            cout << "Case " << j++ << ": yes" << endl;
        else if(((b*b)+(c*c))==(a*a))
            cout << "Case " << j++ << ": yes" << endl;
        else if(((c*c)+(a*a))==(b*b))
            cout << "Case " << j++ << ": yes" << endl;
        else if(((c*c)+(b*b))==(a*a))
            cout << "Case " << j++ << ": yes" << endl;
        else
            cout << "Case " << j++ << ": no" << endl;
    }
}