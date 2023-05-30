#include <iostream>
using namespace std;
int workdays(int n, int m)
{
    m++;
    return m*n;
}
int main()
{
    int N, M;
    cin >> N >> M;
    cout << workdays(N, M) << endl;
}