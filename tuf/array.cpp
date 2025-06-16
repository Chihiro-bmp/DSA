//largest element
    /*brute force
        sort......arr[n-1]
    */

    /*optimal*/

// #include<bits/stdc++.h>
// using namespace std;

// int main(){

//     int n;
//     cin>>n;

//     int a[n];

//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }

//     int max=a[0];

//     for(int i=0;i<n;i++){
//         if(a[i]>max){
//             max=a[i];
//         }
//     }

//     cout<<max;
// }



//sorted
// #include<bits/stdc++.h>
// using namespace std;

// int isSorted(vector<int> &arr, int n){
//     for(int i=1;i<n;i++){
//         if(arr[i]>=arr[i-1]){

//         }
//         else{
//             return false;
//         }
//     }

//     return true;
// }

// int main(){
//     vector<int> a={1,2,3,4,5};
//     cout<<isSorted(a,5);
// }


//2nd LARGEST ELEMENT (brute)

#include<bits/stdc++.h>
using namespace std;

// void sort(int arr[],int n){
//     for(int i=0;i<n;i++){
//         int j=i;

//         while(j>0&& arr[j-1]>arr[j]){
//             int temp=arr[j-1];
//             arr[j-1]=arr[j];
//             arr[j]=temp;

//             j--;
//         }
//     }
// }

// int main(){
//     int n;
//     cin>>n;

//     int a[n];

//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }

//     sort(a,n);

//     int largest=a[n-1];

//     int slargest;

//     for(int i=n-2;i>=0;i--){
//         if(a[i]!=largest){
//             slargest=a[i];
//             break;
//         }
//     }

//     cout<<slargest;

// }  //TIME COMPLEXITY O(NlogN)


//better (first largest......then slargest)  TIMECOMPLEXITY O(N)

//optimal

// int main(){
//     int n;
//     cin>>n;

//     int a[n];

//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }

//     int largest=a[0];
//     int slargest=-1;

//     for(int i=0;i<n;i++){
//         if(a[i]>largest){
//             slargest=largest;
//             largest=a[i];
//         }
//         else if(a[i]<largest && a[i]>slargest){
//             slargest=a[i];
//         }
//     }

//     cout<<slargest;
// } //TIMECOMPLEXITY O(N)  spacecomplexity 0(1)




//remove duplicates

/*brute
    set(unique,ascending order)
    put them in array    
*/

// int main(){
//     int n;
//     cin>>n;

//     int a[n];

//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }

//     set<int> st;

//     for(int i=0;i<n;i++){
//         st.insert(a[i]);
//     }

//     int idx=0;

//     for(auto it:st){
//         a[idx]=it;
//         idx++;
//     }

//     cout<<idx<<endl;
//     for(int i=0;i<idx;i++){
//         cout<<a[i]<<" ";
//     }
// }  

//TIMECOMPLEXITY 0(NlogN+N)

/*optimal
 double pointer
*/

int main(){
    int n;
    cin>>n;

    int a[n];

    for(int p=0;p<n;p++){
        cin>>a[p];
    }

    int i=0;

    for(int j=1;j<n;j++){
        if(a[i]!=a[j]){
            a[i+1]=a[j];
            i++;
        }
    }
    cout<<i+1<<endl;

    for(int p=0;p<=i;p++){
        cout<<a[p]<<" ";
    }
}
