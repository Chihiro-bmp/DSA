#include<bits/stdc++.h>
using namespace std;

bool isMonotomic(vector<int>& arr, int i){

    return ( (arr[i]<arr[i+1] && arr[i+1]<arr[i+2]) || ( arr[i]>arr[i+1] &&arr[i+1]>arr[i+2]));
}

int findMonoatomic(vector<int>& arr, int left, int right){

    if(right-left<2) return -1;

    if((right-left)==2){

        return isMonotomic(arr,left)?left:-1;
    }

    int mid=left+(right-left)/2;

    int ans1=findMonoatomic(arr,left,mid);
    if(ans1!=-1) return ans1;

    for(int i=max(left,mid-2);i<=min(mid,right-2);++i){
        if(isMonotomic(arr,i)){
            return i;
        }
    }


    return findMonoatomic(arr,mid+1,right);
}


int main(){

    int n;
    cin>>n;

    vector<int> nums(n);

    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    int answer=findMonoatomic(nums,0,n-1);

    cout<<answer<<endl;
}