#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, j=1, r;
    cin >> t;
    while(t--)
    {
        long long int b, c=0;
        cin >> b;
        while(b!=0)
        {
            r=b%2;
            if(r==1)
            {
                c++;
            }
            b=b/2;
        }
        if(c%2==0)
        {
            cout << "Case "<< j++ << ": even" << endl;
        }
        else if(c%2!=0)
        {
            cout << "Case "<< j++ << ": odd" << endl;
        }
    }
}