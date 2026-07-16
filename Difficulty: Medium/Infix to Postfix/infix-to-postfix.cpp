#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int priority(char ch) {
        if (ch == '^') return 3;
        else if (ch == '*' || ch == '/') return 2;
        else if (ch == '+' || ch == '-') return 1;
        return -1;
    }

    string infixToPostfix(string& s) {

        stack<char> st;
        string ans = "";

        for (int i = 0; i < s.length(); i++) {

            char ch = s[i];

            // Operand
            if ((ch >= 'A' && ch <= 'Z') ||
                (ch >= 'a' && ch <= 'z') ||
                (ch >= '0' && ch <= '9')) {

                ans += ch;
            }

            // Opening bracket
            else if (ch == '(') {
                st.push(ch);
            }

            // Closing bracket
            else if (ch == ')') {

                while (!st.empty() && st.top() != '(') {
                    ans += st.top();
                    st.pop();
                }

                if (!st.empty())
                    st.pop();
            }

            // Operator
            else {

                while (!st.empty() &&
                       (priority(st.top()) > priority(ch) ||
                       (priority(st.top()) == priority(ch) && ch != '^'))) {

                    ans += st.top();
                    st.pop();
                }

                st.push(ch);
            }
        }

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};