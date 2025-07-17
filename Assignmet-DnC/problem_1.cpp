#include<bits/stdc++.h>
using namespace std;

bool canAllocate(vector<int>&arr, int k, int maxLoad){

    int currentLoad=0; //indicates workload for current worker
    int worker=1;

    for(int i=0;i<arr.size();i++){

        if(currentLoad+arr[i]>maxLoad){

            worker++;
            currentLoad=arr[i];

            if(worker>k){
                return false;
            }
        }else{
                currentLoad+=arr[i];
            }
    }

    return true;
}


int findMaxLoad(vector<int>& arr, int n, int k){

    if(n<k) return -1; //atleast one task must be allocated to a worker

    int left = *max_element(arr.begin(), arr.end());
    int right =0;

    for(int i=0;i<arr.size();i++){
        right+=arr[i];
    }

    int ans=right;

    while(left<=right){

        int mid=left+(right-left)/2;

        if(canAllocate(arr,k,mid)){
            ans=mid;
            right=mid-1;
        }else{
            left=mid+1;
        }
    }

    return ans;
}


int main(){

    int n,k;

    cin>>n>>k;

    vector<int>workloads(n);

    for(int i=0;i<n;i++){
        cin>>workloads[i];
    }
    
    int answer=findMaxLoad(workloads,n,k);

    cout<<"Maximum workload: "<<answer<<endl;
}