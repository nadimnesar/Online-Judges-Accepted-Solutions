#include <iostream>
#include<string>
using namespace std;

int main()
{
    string arr;
int co=0;
    while(getline(cin, arr)){
        int len = arr.size();
        int i,j;
        for(i=0;i<len;i++){
            if(arr[i]=='"' && co==0){
                cout<<"``";
                co=1;
            }
            else if (arr[i]=='"' && co==1){
                cout<<"''";
                co=0;
            }
            else{
                cout<<arr[i];
            }
        }
        cout<<endl;
    }
}