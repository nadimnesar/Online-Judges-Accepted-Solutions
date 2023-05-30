#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, j=1;
    cin >> t;
    while(t--)
    {
        int n, sum=0;
        cout << "Case " << j++ << ":" << endl;
        cin >> n;
        while(n--)
        {
            string s;
            cin >> s;
            if(s=="donate")
            {
                int m;
                cin >> m;
                sum+=m;
            }
            else if(s=="report")
            {
                cout << sum << endl;
            }
        }
    }
}
