#include<bits/stdc++.h>
using namespace std; 

// pattern  1

 void print1(int n){

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
 }

 //pattern 2

 void print2(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
 }

 //pattern 3

 void print3(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<j ;
        }
        cout<<endl;
    }
 }

 //pattern 4 

 void print4(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<i<<" " ;
        }
        cout<<endl;
    }
 }

 //pattern 5

 void print5(int n){
    for(int i=n;i>0;i--){
        for(int j=i;j>0;j--){
            cout<<"* " ;
        }
        cout<<endl;
    }
 }

 //pattern 6

 void print6(int n){
    for(int i=n;i>0;i--){
        for(int j=1;j<=i;j++){
            cout<<j<<" " ;
        }
        cout<<endl;
    }
 }


 //pattern 7

 void print7(int n){

    for(int i=0;i<n;i++){

        for(int j=0;j<n-i-1;j++){
            cout<< " ";
        }

        for(int j=0;j< 2*i+1;j++){
            cout<<"*";
        }
        
        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }

        cout<<endl;

    }
 }

 //pattern 8

 void print8(int n){

    for(int i=0;i<n;i++){

        for(int j=0;j<i;j++){
            cout<< " ";
        }

        for(int j=2*n;j> 2*i+1;j--){
            cout<<"*";
        }
        
        for(int j=0;j<i;j++){
            cout<<" ";
        }

        cout<<endl;

    }
 }

//pattern 9

    // pattern7+8;

//pattern 10

void print10(int n){
    for(int i=1;i<2*n;i++){
        int stars=i;
        if(i>n)
            stars=2*n-i;

        for(int j =0;j<stars;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

//pattern 11

void print11(int n){

    for(int i=1;i<=n;i++){

        if(i%2!=0){
            for(int j=0;j<i;j++){
                    if(j%2==0){
                        cout<<"1 ";
                    }else{
                        cout<<"0 ";
                    }
            }
            cout<<endl;
        }else{
            for(int j=0;j<i;j++){
                if(j%2==0){
                    cout<<"0 ";
                }else{
                    cout<<"1 ";
                }
        }
        cout<<endl;
        }
    }
}

//pattern 12

void print12(int n){

    int space= 2*(n-1);

    for(int i=1;i<=n;i++){
       
        //numbers

        for(int j=1;j<=i;j++){
            cout<< j;
        }

        //space
         

        for(int j=1;j<=space;j++){
            cout<<" ";
        }

        //numbers

        for(int j=i;j>=1;j--){
            cout<< j ;
        }

        cout<<endl;
        space-=2;
    }
}

//pattern 13

void print13(int n){
    int number=1;

    for(int i=0;i<n;i++){
        for(int j=1;j<=i;j++){
            cout<< number;
            number++;
        }
        cout<<endl;
    }
}

//pattern 14

void print14(int n){

    for(int i=0;i<n;i++){

        char c='A';

        for(int j=0;j<=i;j++){
            cout<<c;
            c++;
        }
        cout<<endl;
    }
}

//pattern 15

void print15(int n){

    for(int i=0;i<n;i++){

        char c='A';

        for(int j=n;j>i;j--){
            cout<<c;
            c++;
        }
        cout<<endl;
    }
}

//pattern 16

void print16(int n){

    for(int i=0;i<n;i++){
        char c='A'+i;

        for(int j=0;j<=i;j++){
            cout<<c<<" ";
        }

        cout<<endl;
    }
}

//pattern 17

void print17(int n){

    for(int i=0;i<n;i++){
        char c='A';

        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }

        int mid=(2*i +1)/2;

        for(int j=0;j<2*i+1;j++){
            cout<<c;

            if(j<mid)c++;
            else{
                c--;
            }
        }

        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }

        cout<<endl;
    }
}

//pattern18

void print18(int n){
    for(int i=0;i<n;i++){
        char c='A'+(n-i-1);

        for(int j=0;j<=i;j++){
            cout<<c<<" ";
            c++;
        }

        cout<<endl;
    }
}

//pattern19

void print19(int n){

    //top half 

    int space=0; 

    for(int i=0;i<n;i++){

       

        for(int j=n;j>i;j--){
            cout<<"*";
        }


        for(int j=0;j<space;j++){
            cout<<" ";
        }

        for(int j=n;j>i;j--){
            cout<<"*";
        }

        cout<<endl;
        space+=2;
    }

    //bottom half

    int space2=2*(n-1);

    for(int i=0;i<n;i++){

        for(int j=0;j<=i;j++){
            cout<<"*";
        }

        for(int j=0;j<space2;j++){
            cout<<" ";
        }

        for(int j=0;j<=i;j++){
            cout<<"*";
        }

        cout<<endl;
        space2-=2;
    }
}

//pattern 20

void print20(int n){

    int star=1;
    int space= 2*(n-1);
    int mid=(2*n-1)/2;

    for(int i=0;i<2*n-1;i++){

        for(int j=1;j<=star;j++){

            cout<<"*";
            
        }

        for(int j=0;j<space;j++){
            cout<<" ";
        }



        for(int j=star;j>0;j--){

            cout<<"*";
            
        }
        cout<<endl;

        if(i<mid){
            star++;
            space-=2;
        }else{
            space+=2;
            star--;
        }
    }
}

//pattern 21

void print21(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){

            if(i==0||i==n-1||j==0||j==n-1){
                cout<<"*";
            }else 
            cout<<" ";
        }
        cout<<endl;
    }
}


//pattern22

void print22(int n){
    for(int i=0;i<2*n-1;i++){
        for(int j=0;j<2*n-1;j++){
            int top=i;
            int left=j;
            int right=(2*n-2)-j;
            int bottom=(2*n -2)-i;

            cout<< (n-min(min(top,bottom),min(left,right)));
        }

        cout<<endl;
    }
}
int main(){
    int x;

    cout<<"enter a number: ";
    cin>>x;
   
    print22(x);
}