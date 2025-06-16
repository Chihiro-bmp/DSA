#include<bits/stdc++.h>
using namespace std;

int precedence(char c){
    if(c=='^') return 3;
    else if(c=='*' || c=='/') return 2;
    else if(c=='+' || c=='-') return 1;
    else return -1;
}

string conversion(string in){

    string ans;
    stack<char> st;

    for(int i=0;i<in.size();i++){

        if(in[i]==' ') continue;

        if(in[i]>='A' && in[i]<='Z' ||
         in[i]>='a' && in[i]<='z' ||
          in[i]>='0' && in[i]<='9')
          
          {
            ans+=in[i];
          }

         else if(in[i]=='('){

            st.push(in[i]);

         } else if(in[i]==')'){

            while(!st.empty() && st.top()!='('){
                ans+=st.top();
                st.pop();
            }
                if(!st.empty()) {
                st.pop(); // Remove '('
            }
         }else{

            while(!st.empty() && precedence(in[i])<=precedence(st.top())){

                ans+=st.top();
                st.pop();
            }
            st.push(in[i]);
         }

    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }

    return ans;
}

int main(){
     string exp = "a+b*(c^d-e)^(f+g*h)-i";
    cout << conversion(exp);
    return 0;
}