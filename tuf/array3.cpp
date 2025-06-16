//find the missing number from 1-N

/*brute
TC 0(n^2)*/


// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int n;
//     cin>>n;

//     int a[n-1];

//     for(int i=0;i<n-1;i++){
//         cin>>a[i];
//     }

//     for(int i=1;i<=n;i++){
//         int flag=0;
//         for(int j=0;j<n-1;j++){
//             if(a[j]==i){
//                 flag=1;
//                 break;
//             }
//         }
//         if(flag==0){
//             cout<<i<<" ";
//         }
//     }
// }


/*better
hashing*/

// #include<bits/stdc++.h>
// using namespace std;

// int main(){

//     int n;
//     cin>>n;

//     int a[n-1];

//     for(int i=0;i<n-1;i++){
//         cin>>a[i];
//     }

//     int check[n+1]={0};

//     for(int i=0;i<n-1;i++){
//         check[a[i]]=1;
//     }

//     for(int i=1;i<=n;i++){
//         if(check[i]==0){
//             cout<<i<<" ";
//         }
//     }

// }


/*optimal
sum*/

// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int n;
//     cin>>n;

//     int a[n-1];

//     for(int i=0;i<n-1;i++){
//         cin>>a[i];
//     }
//     int s1=0.5*n*(n+1);
//     int s2=0;

//     for(int i=0;i<n-1;i++){
//         s2+=a[i];
//     }

//     cout<<s1-s2<<" ";
// }



//maximum consecutive 1's//

// #include<bits/stdc++.h>
// using namespace std;

// int main(){

//     int n;
//     cin>>n;

//     int a[n];

//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }

//     int count=0;
//     int one=0;

//     for(int i=0;i<n;i++){
        
//         if(a[i]==1){
//             one++;
//         }
//         else{
//             count=max(count,one);
//             one =0;
//         }
//     }
//     count=max(count,one);
//     cout<<count<<" ";
// }


//find one element once, others twice

/*brute
double loop*/

// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int n;
//     cin>>n;

//     int a[n];

//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }

//     int ans=0;

//     for(int i=0;i<n;i++){
//         ans=a[i];
//         int count=0;
//         for(int j=0;j<n;j++){
//             if(a[j]==ans){
//                 count++;
//             }
//         }

//         if(count==1){
//             cout<<ans<<" ";
//             break;
//         }
//     }
// }

/*optimal
X-OR*/

#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;

    int a[n];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int ans=0;
    for(int i=0;i<n;i++){
        ans=ans^a[i];
    }

    cout<<ans<<" ";
}