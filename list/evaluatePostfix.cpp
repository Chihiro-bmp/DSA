#include<bits/stdc++.h>
using namespace std;

int evaluate(vector<string>& arr){

    stack<int> st;

    for(auto it:arr){

        if(isdigit(it[0]) || it.size()>1 && it[0]=='-'){
            st.push(stoi(it));
        }else{
            int a=st.top();
            st.pop();
            int b= st.top();
            st.pop();

            switch(it[0]){

                case '+':
                 st.push(b + a); 
                 break;
                case '-': 
                st.push(b - a); 
                break;
                case '*': 
                st.push(b * a); 
                break;
                case '/': 
                st.push(b / a); 
                break;
            }
        }
    }

    return st.top();
}


int main() {
    vector<string> arr = {"2", "3", "10", "*", "+", "9", "-"};
    cout << evaluate(arr) << endl; 
    return 0;
}