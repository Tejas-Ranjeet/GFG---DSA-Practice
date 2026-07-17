class Solution {
  public:
    string preToInfix(string pre_exp) {
        
        stack<string> st;
        
        for(int i = pre_exp.length() - 1; i >= 0; i--){

            char ch = pre_exp[i];

            if(ch == ' ')
                continue;

            if(isalnum(ch)){
                st.push(string(1, ch));
            }
            else{

                if(st.size() < 2)
                return "";

                string t1 = st.top();
                st.pop();

                string t2 = st.top();
                st.pop();

                st.push("(" + t1 + ch + t2 + ")");
            }
        }

        return st.top();
        
    }
};