#include <iostream>
#include <string>
using namespace std;
int main()
{
    int i, X, Y;
    string y;
    cin >> X >> y;
    Y=y.length();
    int sum=X;
    for(i=X-Y; i>0 ; i=i-Y)
    {
        sum*=i;
    }
    cout << sum << endl;
}
