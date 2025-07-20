#include<bits/stdc++.h>
using namespace std;

int uniqueElements(vector<int>&arr, int low, int high){

    if(high==low) return 1;

    int count=0;
    int mid=low+ (high-low)/2;

    count+=uniqueElements(arr,low,mid);
    count+=uniqueElements(arr,mid+1,high);

    if(arr[mid]==arr[mid+1]){
        return (count-1);
    }else{
        return count;
    }


}

int main(){

    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int ans=uniqueElements(arr,0,n-1);

    cout<<ans<<endl;
}