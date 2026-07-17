#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int floordiv(int a, int b){
        int q = a / b;
        int r = a % b;

        if(r != 0 && ((a < 0) != (b < 0))){
            q--;
        }
        return q;
    }

    int evaluatePostfix(vector<string>& arr) {

        stack<int> st;

        for(string s : arr){

            if(s != "+" && s != "-" && s != "*" && s != "/" && s != "^"){
                st.push(stoi(s));
            }
            else{

                int x1 = st.top();
                st.pop();

                int x2 = st.top();
                st.pop();

                if(s == "+"){
                    st.push(x2 + x1);
                }
                else if(s == "-"){
                    st.push(x2 - x1);
                }
                else if(s == "*"){
                    st.push(x2 * x1);
                }
                else if(s == "/"){
                    st.push(floordiv(x2, x1));
                }
                else{   // ^
                    st.push(pow(x2, x1));
                }
            }
        }

        return st.top();
    }
};