#include<bits/stdc++.h>
using namespace std;

// int main(){
//     int n;
//     cin>>n;

//     int a[n];

//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }

   
//     map<int,int> mpp;

//     for(int i=0;i<n;i++){
//         mpp[a[i]]++;
//     }

//     int q;
//     cin>>q;

//     while(q--){
//         int number;
//         cin>>number;

//         cout<<mpp[number]<<endl;
//     }
// }


//hashing for character 

// int main(){
    
//     string s;

//     cin>>s;

//     map<char,int>mpp;

//     for(int i=0;i<s.size();i++){


//         mpp[s[i]]++;
//     }

//     int q;
//     cin>>q;

//     while(q--){
//         char ch;
//         cin>>ch;

//         cout<<mpp[ch]<<endl;
//     }
// }

//highest frequency

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

   
    
    int max=a[0];
    int freq=mpp[a[0]];

    for(auto it:mpp){
        if(it.second>freq)
            max=it.first;
            freq=it.second;
    }

    cout<<max;
}
