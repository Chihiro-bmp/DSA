#include<bits/stdc++.h>

using namespace std;



//bubble sort

// void bubble(int arr[], int n){
//     for(int i=n-1;i>0;i--){
//         for(int j=0;j<i;j++){
//             if(arr[j]>arr[j+1]){
//                 int temp=arr[j];
//                 arr[j]=arr[j+1];
//                 arr[j+1]=temp;
//             }
//         }
//     }
// }


//insertion sort

void insertion(int arr[], int n){
    for(int i=0;i<n;i++){
        int j=i;

        while(j>0&& arr[j-1]>arr[j]){
            int temp=arr[j-1];
            arr[j-1]=arr[j];
            arr[j]=temp;

            j--;
        }
    }
}

int main(){
    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    insertion(a,n);

    for(int i=0;i<n;i++){
        cout<<a[i]<< " ";
    }
}
