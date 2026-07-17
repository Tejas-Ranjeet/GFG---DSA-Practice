#include<bits/stdc++.h>

class Solution { // infix to prefix
  public:
  
  int priority(char ch){
      if(ch == '^'){
          return 3;
      }
      else if(ch == '*' || ch == '/'){
          return 2;
      }
      else if(ch == '+' || ch == '-'){
          return 1;
      }
      else{
          return -1;
      }
    }
    
    string infixToPrefix(string &s) {
        
        reverse(s.begin(),s.end());
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                s[i] = ')';
            }
            else if(s[i] == ')'){
                s[i] ='(';
            }
        }
        
        stack<char> st;
        string ans;
        
        for(int i = 0 ; i < s.length(); i++){
            
            char ch = s[i];
            if((ch >= 'A' && ch <= 'Z')||
               (ch >= 'a' && ch <= 'z')||
               (ch >= '0' && ch <= '9')){
                    
                    ans += ch;
                }
            
            else if(ch == '('){
                st.push(ch);
            }
            else if(ch == ')'){
                while(!st.empty() && st.top() != '('){
                    ans += st.top();
                    st.pop();
                }
                st.pop();
            }
            else if(ch == '^'){
                while(!st.empty()&& priority(st.top())>= priority(ch)){
                    ans += st.top();
                    st.pop();
                }
                st.push(ch);
            }
            else{
                while(!st.empty() && priority(st.top())> priority(ch)){
                    ans += st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
        
    }
};
