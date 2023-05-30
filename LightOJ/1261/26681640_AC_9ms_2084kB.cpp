#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,m,k,p,i,j,x,l,r;
    cin >> t;
    for(i=1; i<=t; i++)
    {
        cin >> n >> m >> k;
        int x[n][k];
        for(j=0; j<n; j++)
        {
            for(l=0; l<k; l++)
            {
                cin >> x[j][l];
            }
        }
        cin >> p;
        int ar[p];
        for(j=0; j<p; j++)
        {
            cin >> ar[j];
        }

        int ans = 0;
        for(j=0; j<n; j++)
        {
            int match = 0;
            for(l=0; l<k; l++)
            {
                int found = 0;
                for(r=0; r<p; r++)
                {
                    if(abs(x[j][l]) == ar[r])
                    {
                        found = 1;
                        break;
                    }
                }
                if(x[j][l]>0)
                {
                    if(found == 1) match++;
                }
                else
                {
                    if(found == 0)
                    {
                        match++;
                    }
                }
            }
            if(match >= 1) ans++;
        }
        if(ans >= n)
        {
            cout<<"Case "<<i<<": Yes"<<endl;
        }
        else
        {
            cout<<"Case "<<i<<": No"<<endl;
        }
    }
    return 0;
}
