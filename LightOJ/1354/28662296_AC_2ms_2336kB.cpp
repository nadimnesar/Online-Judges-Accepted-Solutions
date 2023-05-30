#include <bits/stdc++.h>
using namespace std;
int DtoB(int binary)
{
    int i=0, decimal=0;
    while(binary!=0)
    {
        decimal=decimal+pow(2, i)*(binary%10);
        binary/=10;
        i++;
    }
    return decimal;
}
int main()
{
    int t, j=1;
    cin >> t;
    while(t--)
    {
        long long unsigned int a, b, c, d, ba, bb, bc, bd;
        cin >> a;
        cin.ignore();
        cin >> b;
        cin.ignore();
        cin >> c;
        cin.ignore();
        cin >> d;
        cin >> ba;
        cin.ignore();
        cin >> bb;
        cin.ignore();
        cin >> bc;
        cin.ignore();
        cin >> bd;
        ba=DtoB(ba);
        bb=DtoB(bb);
        bc=DtoB(bc);
        bd=DtoB(bd);
        if(a==ba && b==bb && c==bc && d==bd)
            cout << "Case " << j++ << ": Yes" << endl;
        else
            cout << "Case " << j++ << ": No" << endl;
    }
}
