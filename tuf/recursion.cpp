#include<bits/stdc++.h>
using namespace std;


//name N times

// void name(int a, int b){
//     if(a>b)
//         return;

//         cout<<"Wasik"<<endl;

//         name(a+1,b);
// }

// int main(){
//     int n;
//     cin>>n;

//     name(1,n);
// }


//1-to-N

// void num(int a, int b){
//     if(a>b) 
//         return;
//         cout<<a<<endl;

//         num(a+1,b);
// }

// int main(){
//     int n;
//     cin>>n;
//     num(1,n);
//     return 0;

// }

//N-to-1

// void num(int a, int b){
//     if(a<b) 
//         return;
//         cout<<a<<endl;

//         num(a-1,b);
// }

// int main(){
//     int n;
//     cin>>n;
//     num(n,1);
//     return 0;

// }


//1=to-N(backtrack)

// void num(int a, int b){

//     if(a<1)
//      return;
    
//      num(a-1,b);
//      cout<<a<<endl;
// }

// int main(){
//     int n;
//     cin>>n;

//     num(n,n);
// }

//N-to-1(backtrack)

void num(int a, int b){
    if(a>b)
        return;
    num(a+1,b);

    cout<<a<<endl;
}

int main(){
    int n;
    cin>>n;
    num(1,n);
}


