#include<iostream>
#include<string>
#include<stack>
using namespace std;

int priority(char op){
    
        if(op == '^') return 3;
        else if(op == '*' || op == '/') return 2;
        else if(op == '-' || op == '+') return 1;
        else return -1;
}

string infixToPostfix(string s){
    int i = 0 ;
    int n = s.length();
    string ans = "";
    stack<char> st;

    while(i <n){
        // OPERAND
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')  || (s[i] >= '0' && s[i]<= '9')){
            ans += s[i];
        }
        else if(s[i] == '('){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            while(!st.empty() && st.top() != '('){
                ans += st.top();
                st.pop();
            }
            st.pop(); // for removing the opening bracket
        }
        else{
            // FOR OPERATOR
            while(!st.empty() && priority(s[i]) <= priority(st.top())){
                ans+= st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }
    // empty the stack after loop completion
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    return ans;
}