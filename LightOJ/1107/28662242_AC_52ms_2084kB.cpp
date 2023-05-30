#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, j=1;
    cin >> t;
    while(t--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int n;
        cin >> n;
        cout << "Case " << j++ << ":" << endl;
        while(n--)
        {
            int c1, c2;
            cin >> c1 >> c2;
            if(c1<=x2 && c1>=x1 && c2<=y2 && c2>=y1)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
}