#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,b,m;

    cin>>n>>b;

    vector<int>seats(n);

    for(int i=0;i<n;i++){
        cin>>seats[i];
    }
    
    cin>>m;

    int availableSeats=0;
    int seatsPerBench=n/b;

    for(int bench=0;bench<b;bench++){

        int start=bench*seatsPerBench;
        int end=start+seatsPerBench;

        for(int i=start;i<end;i++){

            if(seats[i]==0){

                
                bool left=(i>start && (seats[i-1]==1 || seats[i-1]==2));
                bool right=(i+1<end && seats[i+1]==2);

                if(!left && !right){
                    availableSeats++;
                }
            }
        }
    }

    if(availableSeats>=m){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
}