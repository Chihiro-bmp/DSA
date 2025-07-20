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

int main(){

    int n,k;

    cin>>n>>k;

    vector<int>workloads(n);

    int left=0;
    int right=0;

    for(int i=0;i<n;i++){
        cin>>workloads[i];
        right+=workloads[i];
    }

    if(n<k){
        cout<<-1<<endl; //at least one task will be alloced to each employee
        return 0;
    }

    left=*max_element(workloads.begin(),workloads.end());
    int ans=right;

     while(left<=right){

        int mid=left+(right-left)/2;

        if(canAllocate(workloads,k,mid)){
            ans=mid;
            right=mid-1;
        }else{
            left=mid+1;
        }
    }
    
    
    cout<<"Maximum workload: "<<ans<<endl;
}