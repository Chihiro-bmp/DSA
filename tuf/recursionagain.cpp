#include<bits/stdc++.h>
using namespace std;

//sum of first n

// int total(int i, int sum){
//     if(i<1){
//      cout<<sum;
//      return 0;
//     }
//      total(i-1,sum+i);
// }

// int main(){
//     int n;
//     cin>>n;

//     total(n,0);
// }


//sum of first n(function)

// int total(int n){
//     if(n==1){
//         return 1;
//     }

//     return n+ total(n-1);
// }

// int main(){
//     int n;
//     cin>>n;

//     cout<< total(n);
// }


//factorial

// int fact(int n){
//     if(n==1)
//         return 1;
    
//         return n*fact(n-1);
// }

// int main(){
//     int n;
//     cin>>n;

//     cout<<fact(n);
// }


//REVERSE AN ARRAY 

// void swapping(int i, int a[], int n){

//     if(i>=n/2)
//     return;

//     swap(a[i],a[n-i-1]);

//     swapping(i+1,a,n);
// }

// int main(){
//     int n;
//     cin>>n;

//     int arr[n];

//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }

//     swapping(0,arr,n);

//     for(int i=0;i<n;i++){
//         cout<<arr[i]<< " ";
//     }
// }

//check string palindrome

// bool palindrome(int i, string &s){
//     if(i>=s.size()/2) return true;

//     if(s[i]!=s[s.size()-i-1])
//      return false;

//      return palindrome(i+1, s);
// }

// int main(){
//     string s;
//     cin>>s;

//     cout<<palindrome(0,s);
// }


//FIBONACCI 

int fibo(int n){
    if(n==0)return 0;
    if(n==1||n==2)
     return 1;

     return fibo(n-1)+fibo(n-2)+fibo(n-3);
}

int main(){
    int n;
    cin>>n;

    cout<<fibo(n);
}

