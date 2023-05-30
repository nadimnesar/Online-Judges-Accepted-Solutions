#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, c=0;
    cin >> t;
    while(t--)
    {
        vector <long long unsigned int> n(3);
        for(int i=0; i<3; i++)
        {
            cin >> n[i];
        }
        sort(n.begin(), n.end());
        cout << "Case " << ++c << ": " << n[1] << endl;
    }
}