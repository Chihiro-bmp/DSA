//left rotating an array by 1 place

// #include<bits/stdc++.h>
// using namespace std;

// int main(){

//     int n;
//     cin>>n;
    
//     int a[n];
    
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }
  
//     int temp=a[0];
    
//     for(int i=1;i<n;i++){
         
//         a[i-1]=a[i];
        
//     }

//     a[n-1]=temp;
    
    

//     for(int i=0;i<n;i++){
//         cout<<a[i]<< " ";
//     }



// }



//left rotating bt D-places

/*brute
first-d elements to a temp array
shift rest of the elements d places left
place the d-elements at the end*/

// #include<bits/stdc++.h>
// using namespace std;

// void leftrotate(int arr[], int n, int d){
//     if(d>n) d=n%d;
//     int temp[d];

//     for(int i=0;i<d;i++){
//         temp[i]=arr[i];
//     }

//     for(int i=d;i<n;i++){
//         arr[i-d]=arr[i];
//     }

//     for(int i=n-d;i<n;i++){
//         arr[i]=temp[i-(n-d)];
//     }

    
// }

// int main(){
//     int n;
//     cin>>n;

//     int a[n];
 
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }

//     leftrotate(a,n,2);

//     for(int i=0;i<n;i++){
//         cout<<a[i]<<" ";
//     }
// } 

/*optimal
reverse first d elements
reverse rest of the elements
reverse the whole array*/

// #include<bits/stdc++.h>
// using namespace std;

// void reversing(int arr[], int low, int high){

// while(low<=high){
//     int temp=arr[low];
//     arr[low]=arr[high];
//     arr[high]=temp;
//     low++;
//     high--;
// }
   
// }

// void rotateleft(int arr[], int n,int d){

//     reversing(arr,0,d-1);
//     reversing(arr,d,n-1);
//     reversing(arr,0,n-1);

// }

// int main(){
//     int n;
//     cin>>n;

//     int a[n];

//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }

//     rotateleft(a,n,2);

//     for(int i=0;i<n;i++){
//         cout<<a[i]<<" ";
//     }
// }

//right rotate by d-places
/*
reverse first n-d elements
reverse n-d to n elements
reverse the whole array*/


// #include<bits/stdc++.h>
// using namespace std;

// void reversing(int arr[], int low, int high){

// while(low<=high){
//     int temp=arr[low];
//     arr[low]=arr[high];
//     arr[high]=temp;
//     low++;
//     high--;
// }
   
// }


// void rotateright(int arr[], int n, int d){
//     reversing(arr,0,n-d-1);
//     reversing(arr,n-d,n-1);
//     reversing(arr,0,n-1);
// }
// int main(){
//     int n;
//     cin>>n;

//     int a[n];

//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }

//     rotateright(a,n,2);

//     for(int i=0;i<n;i++){
//         cout<<a[i]<<" ";
//     }
// }


//place the zeroes at the end

/*bruteforce
place the non-zero elements at a temporary array
place them back in the array
put zero in the remaining space*/

// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int n;
//     cin>>n;

//     int a[n];

//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }

//     vector<int> temp;

//     for(int i=0;i<n;i++){
//         if(a[i]!=0){
//             temp.push_back(a[i]);
//         }
//     }

//     int nz=temp.size();

//     for(int i=0;i<nz;i++){
//         a[i]=temp[i];
//     }

//     for(int i=nz;i<n;i++){
//         a[i]=0;
//     }

//     for(int i=0;i<n;i++){
//         cout<<a[i]<<" ";
//     }

// }

/*optimal
double pointer
one at first zero
another at the non-zero after first zero
swap*/

// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int n;
//     cin>>n;

//     int a[n];

//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }

//     int j=-1;

//     for(int p=0;p<n;p++){
//         if(a[p]==0){
//             j=p;
//             break;
//         }
//     }

//     for(int i=j+1;i<n;i++){
//         if(a[i]!=0){
//             swap(a[i],a[j]);
//             j++;
//         }
//     }

//     for(int i=0;i<n;i++){
//         cout<<a[i]<<" ";
//     }
// }


//union
/* ordered set
then print in a set*/

// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int m;
//     cin>>m;

//     int a[m];

//     for(int i=0;i<m;i++){
//         cin>>a[i];
//     }

//     int n;
//     cin>>n;

//     int b[n];

//     for(int i=0;i<n;i++){
//         cin>>b[i];
//     }

//     set<int> st;

//     for(int i=0;i<m;i++){
//         st.insert(a[i]);
//     }

//     for(int i=0;i<n;i++){
//         st.insert(b[i]);
//     }

//     // int uni[st.size()];
//     // int i=0;
//     // for( auto it:st){
//     //     uni[i]=it;
//     //     i++;
//     // }
// for(auto it:st){
//  cout<<it<<" ";
// }

// }//TIME COMPLEXITY(mlogm +nlogn)


/*optimal
two pointers */

// #include<bits/stdc++.h>
// using namespace std;

// int main(){

//     int n1;
//     cin>>n1;

//     int a[n1];

//     for(int i=0;i<n1;i++){
//         cin>>a[i];
//     }

//     int n2;
//     cin>>n2;

//     int b[n2];

//     for(int i=0;i<n2;i++){
//         cin>>b[i];
//     }

//     vector<int> uniarr;

//     int i=0;
//     int j=0;

//     while(i<n1 && j<n2){
//         if(a[i]<=b[j]){
//             if(uniarr.size()==0 || uniarr.back()!=a[i]){
//                 uniarr.push_back(a[i]);
//             }
//             i++;
//         }

//         else{
//             if(uniarr.size()==0 || uniarr.back()!=b[j]){
//                 uniarr.push_back(b[j]);
//             }
//             j++;
//         }
//     }

//     while(i<n1){
//         if(uniarr.back()!=a[i]){
//             uniarr.push_back(a[i]);
//         }
//         i++;
//     }

//     while(j<n2){
//         if(uniarr.back()!=b[j]){
//             uniarr.push_back(b[j]);
//         }
//         j++;
//     }

//     for(auto it:uniarr){
//         cout<<it<<" ";
//     }
// }


//intersectiom

/*
brute force
two loop traversal at the same time 
one marker arr to check repetition
*/

// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int n1;
//     cin>>n1;

//     int a[n1];

//     for(int i=0;i<n1;i++){
//         cin>>a[i];
//     }

//     int n2;
//     cin>>n2;

//     int b[n2];
//     for(int i=0;i<n2;i++){
//         cin>>b[i];
//     }

//     vector<int> interarr;

//     int check[n2]={0};

//     for(int i=0;i<n1;i++){
//         for(int j=0;j<n2;j++){
//             if(a[i]==b[j]&& check[j]==0){
//                interarr.push_back(a[i]);
//                 check[j]=1;
//                 break;
//             }

//             if(b[j]>a[i])
//             break;
//         }
//     }

//     for(auto num: interarr){
//         cout<<num<<" ";
//     }
// }

/*optimal
2 pointers*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n1;
    cin>>n1;

    int a[n1];

    for(int i=0;i<n1;i++){
        cin>>a[i];
    }

    int n2;
    cin>>n2;

    int b[n2];

    for(int i=0;i<n2;i++){
        cin>>b[i];
    }

    vector<int> ans;

    int i=0;
    int j=0;

    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            i++;
        }

        else if(b[j]<a[i]){
            j++;
        }

        else{
            ans.push_back(a[i]);
            i++;
            j++;
        }
    }

    for(auto num:ans){
        cout<<num<<" ";
    }
}
