//longest sub-array with sum k
/*brute
double loop traversal
check for each sub-array if the sum is k
*/
// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int n;
//     cin>>n;

//     int a[n];
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }

//     int k;
//     cin>>k;

//     int len=0;

//     for(int i=0;i<n;i++){
//         int sum=0;
//         for(int j=i;j<n;j++){
//             sum+=a[j];
//             if(sum==k){
//                 len=max(len,j-i+1);
//                 break;
//             }
//         }
//     }

//     cout<<len<<endl;
// }


//two sum
/*brute
double loop traversal
*/

// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int n;
//     cin>>n;

//     int a[n];
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }

//     int k;
//     cin>>k;

//     for(int i=0;i<n;i++){
//         for(int j=i+1;j<n;j++){
//             if(a[i]+a[j]==k){
//                 cout<<i<<" "<<j<<endl;
//                 break;
//             }
//         }
//     }

//     }


/*maximum sum of a sub-array*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    //to print the sub-array 


    int max_sum=INT_MIN;
    int sum=0;
    int start=0;
    int ansStart=0,ansEnd=0; 

    for(int i=0;i<n;i++){
        sum+=a[i];
      
        if(sum>max_sum){
            max_sum=sum;
            ansStart=start;
            ansEnd=i;

        }
        
        if(sum<0){
            sum=0;
            start=i+1;
        }
    }

    cout<<max_sum<<endl;

    for(int i=ansStart;i<=ansEnd;i++){
        cout<<a[i]<<" ";
    }
}
