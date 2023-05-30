#include <iostream>
using namespace std;

int n, q, temp;
int arr[50007];

void marge(int left, int mid, int right){
    int leftsize = (mid-left)+1;
    int rightsize = (right-mid);

    int leftarray[leftsize], rightarray[rightsize];
    for(int i = 0; i < leftsize; i++) leftarray[i] = arr[left+i];
    for(int i = 0; i < rightsize; i++) rightarray[i] = arr[mid+i+1];

    int i = 0;
    int j = 0;
    int k = left;

    while(i < leftsize and j < rightsize){
        if(leftarray[i] <= rightarray[j]){
            arr[k] = leftarray[i];
            k++;
            i++;
        }
        else{
            arr[k] = rightarray[j];
            k++;
            j++;
        }
    }

    while(i < leftsize){
        arr[k] = leftarray[i];
        i++;
        k++;
    }

    while(j < rightsize){
        arr[k] = rightarray[j];
        k++;
        j++;
    }
}

void margesorting(int left, int right){
    if(left >= right) return;
    int mid = left + (right-left)/2;
    margesorting(left, mid);
    margesorting(mid+1, right);
    marge(left, mid, right);
}

int upperbound(int q){
    int right = n-1;
    int left = 0;
    int up = -1;
    while(right >= left){
        int mid = left + (right-left)/2;
        if(arr[mid] > q){
            up = mid;
            right = mid-1;
        }
        else left = mid+1;
    }
    return (up == -1) ? n: up;
}

int lowerbound(int q){
    int right = n-1;
    int left = 0;
    int low = -1;
    while(right >= left){
        int mid = left + (right-left)/2;
        if(arr[mid] == q){
            low = mid;
            right = mid -1;
        }
        else if(arr[mid] > q){
            low = mid;
            right = mid-1;
        }
        else left = mid+1;
    }
    return (low == -1) ? n: low;
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    margesorting(0, n-1);
    scanf("%d", &q);
    for(int i = 0; i < q; i++){
        scanf("%d", &temp);
        int up = upperbound(temp);
        int low = lowerbound(temp);

        if(arr[low] == temp){
            if(low == n-1) cout << arr[low-1] << ' ' << 'X' << endl;
            else if(low-1 < 0) cout << 'X' << ' ' << arr[up] << endl;
            else if(up == n){
                if(arr[low] == temp)  cout << arr[low-1] << ' ' << 'X' << endl;
                else  cout << arr[low] << ' ' << 'X' << endl;
            }
            else cout << arr[low-1] << ' ' << arr[up] << endl;
        }
        else if(low == n) cout << arr[low-1] << ' ' << 'X' << endl;
        else if(up == n) cout << arr[low] << ' ' << 'X' << endl;
        else cout << arr[low-1] << ' ' << arr[up] << endl;

        // cout << low << ' ' << up << endl;

    }
}