#include<bits/stdc++.h>
using namespace std;

int countInvertedpairs(string& s, int low, int mid, int high){

  int left=low;
  int right=mid+1;
  vector<char>temp;
    int count=0;

  while(left<=mid && right<=high){

    if(s[left]<s[right]){
        temp.push_back(s[left]);
        left++;
    }else{
        count+=(mid-low)+1;
        temp.push_back(s[right]);
        right++;
    }
  }

  while(left<=mid){
     temp.push_back(s[left]);
    left++;
  }

  while(right<=high){
    temp.push_back(s[right]);
    right++;
  }

  for(int i=low;i<=high;i++){
    s[i]=temp[i-low];
  }
  return count;

}

int sortAndCount(string&s, int low,int high){

    if(low>=high) return 0;

    int cnt=0;

    int mid=(low+high)/2;

    cnt+=sortAndCount(s,low,mid);
    cnt+=sortAndCount(s,mid+1,high);
    cnt+=countInvertedpairs(s,low,mid,high);


    return cnt;
}


int main(){

    string s;

    cin>>s;

    int length=s.size();

    int ans=sortAndCount(s,0,length-1);

    cout<<ans<<endl;
}