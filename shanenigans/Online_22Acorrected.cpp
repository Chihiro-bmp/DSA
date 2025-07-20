//only adjacent pairs


#include<bits/stdc++.h>

using namespace std;


int countAdjacentPairs(string & s, int low, int high){

    if(low>=high) return 0;

    if(high-low==1){
        return (s[low]>s[high])?1:0 ;
    }

    int count=0;
    int mid=(low+ high)/2;

    count+=countAdjacentPairs(s,low,mid);
    count+=countAdjacentPairs(s,mid+1,high);

    int cross=(s[mid]>s[mid+1])?1:0;

    return count+cross;
}

int main(){

    string s;

    cin>>s;

    int length=s.size();

    int ans=countAdjacentPairs(s,0,length-1);

    cout<<ans<<endl;
}