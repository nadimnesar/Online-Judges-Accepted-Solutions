#include <stdio.h>

int n, q, temp, cn = 0;
int arr[10000007];

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

int binarysearch(int q){
    int right = n-1;
    int left = 0;
    int index = -1;
    while(right >= left){
        int mid = left + (right-left)/2;
        if(arr[mid] == q){
            index = mid;
            right = mid -1;
        }
        else if(arr[mid] > q) right = mid-1;
        else left = mid+1;
    }
    return index;
}

int main(){
    while(~scanf("%d %d", &n, &q)){
        if(n == 0 and q == 0) break;
        for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
        margesorting(0, n-1);
        printf("CASE# %d:\n", ++cn);
        while(q--){
            scanf("%d", &temp);
            int index = binarysearch(temp);
            if(index == -1) printf("%d not found\n", temp);
            else printf("%d found at %d\n", temp, ++index);
        }
    }
}