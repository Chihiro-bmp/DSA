#include<bits/stdc++.h>
using namespace std;


int partition(vector<int> &arr,int low, int high){
    int pivot=arr[low];
    int i=low;
    int j=high;

    while(i<j){
        while(pivot>=arr[i]&& i<high){
            i++;
        }
        while(pivot<arr[j]&&j>low){
            j--;
        }

        if(i<j){
            swap(arr[i],arr[j]);
        }
    }

    

    swap(arr[low],arr[j]);
    return j;
}

void quicksort(vector<int> &arr, int low, int high){
    if(low<high){
        int pindex=partition(arr,low,high);

        quicksort(arr,low,pindex-1);
        quicksort(arr,pindex+1,high);
    }
}


int main(){
    vector<int> arr ={12, 11, 13, 5, 6, 7};
    quicksort(arr,0,5);

    for(auto num: arr){
        cout<< num << " ";
    }

}