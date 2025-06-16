

#include<bits/stdc++.h>
using namespace std;


//count digits

// int count(int n){
//     int cnt=int(log10(n)+1);
    
//     return cnt;
// }

// int main(){
//     int x;
//     cin>>x;

//    int p= count(x);

//    cout<<p<<endl;
// }


//armstrong 

// void armstrong(int n){

//     int cnt=0;
//     while(n>0){
//         int lastDigit=n%10;
//         cnt++;
//         n/=10;
//     }

//     int sum=0;
//     while(n>0){
//         int Digit=n%10;
//         sum+= pow(Digit,cnt);
//         n/=10;
//     }

//     if(sum==n) cout<<"YES" ;
//     else cout<<"NO" ;
// }

// int main(){
//     int x;
//     cin>>x;

//     armstrong(x);
// }


//divisor(efficient)

// void divisor(int n){

//     vector<int> list;

//     for(int i=1;i*i<=n;i++){
//         if(n%i==0) list.push_back(i);
//         if((n/i)!=i) list.push_back(n/i);
//     }

//     sort(list.begin(),list.end());

//     for(auto it:list){
//         cout<<it<<" ";
//     }
// }


// int main(){
//     int x;
//     cin>>x;

//     divisor(x);
// }


//gcd

int gcd(int a, int b){

  while(a>0 && b>0){
    if(a>b) a=a%b;
    else b=b%a;

  }if(a==0)
    return b;
  else 
    return a;
}


int main(){
    int c,d;

    cin>>c>>d;

    int p=gcd(c,d);

    cout<<p<<endl;

    return 0;
}