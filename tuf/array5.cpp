//majority element
/*brute force 
*/
// class Solution {
//     public:
//         int majorityElement(vector<int>& nums) {
//             for(int i=0;i<nums.size();i++){
//                 int count=0;
    
//                 for(int j=0;j<nums.size();j++){
//                     if(nums[i]==nums[j]){
//                         count++;
//                     }
//                 }
    
//                 if(count>nums.size()/2){
//                     return nums[i];
//                 }
//             }
//             return -1;
//         }
//     };


/*better
hashmap*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int a[n];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    map<int,int> mpp;

    for(int i=0;i<n;i++){
        mpp[a[i]]++;
    }

    int ans=-1;

    for(auto num:mpp){
        if(num.second>n/2){
            ans=num.first;
            break;
        }
    }

    cout<<ans;
}
