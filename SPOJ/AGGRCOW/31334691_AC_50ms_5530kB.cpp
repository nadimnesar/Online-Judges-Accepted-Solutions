#include <stdio.h>

int t, n, cow, temp;
int arr[100007];

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

bool process(int z){
    int counter = 1;
    int p = 0;
    for(int i = 1; i < n; i++){
        temp = arr[i]-arr[p];
        if(temp < 0) temp *= -1;
        if(temp >= z){
            p = i;
            counter++;
        }
    }
    if(counter >= cow) return true;
    else return false;
}

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &cow);
        for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
        margesorting(0, n-1);
        int low = 1, high = 1e9, maxi = 0;
        while(high >= low){
            int mid = low + (high-low)/2;
            if(process(mid)){
                low = mid + 1;
                if(maxi <= mid) maxi = mid;
            }
            else high = mid - 1;
        }
        printf("%d\n", maxi);
    }
}