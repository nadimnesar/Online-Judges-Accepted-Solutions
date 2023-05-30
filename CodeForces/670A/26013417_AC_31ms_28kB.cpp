#include <iostream>
using namespace std;

int main()
{

    int n, x, y;
    cin >> n;
    x = (n/7)*2;
    y = n%7;
    if(n<=7)
    {
        if(n>=2 && n<=5)
        {
            cout << "0 " << "2" <<endl;
        }
        else if(n==6)
        {
            cout << "1 " << "2" << endl;
        }
        else if(n==7)
        {
            cout << "2 " << "2" << endl;
        }
        else if(n<2)
        {
            cout << "0 " << n << endl;
        }
    }
    else
    {
        if(y > 0)
        {
            if(y == 1) printf("%d %d\n", x, x+1);
            else if(y == 6) printf("%d %d\n", x+1, x+2);
            else printf("%d %d\n", x, x+2);
        }
        else
        {
            printf("%d %d\n", x, x);
        }
    }
}