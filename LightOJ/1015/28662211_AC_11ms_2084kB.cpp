#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int t, j=1;
    cin >> t;
    while(t--)
    {
        long long int i, n, dust, sum=0;
        cin >> n;
        for(i=1; i<=n; i++)
        {
            cin >> dust;
            if(dust<0 || dust >= 100)
                continue;
            sum+=dust;
        }
        cout << "Case " << j++ << ": " << sum << endl;
    }
}