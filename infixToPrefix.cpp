#include<iostream>
#include<string>
#include<stack>
using namespace std;

string reverse(string s){

    int n = s.length();
    string ans = "";
    for(int i = n-1; i>= 0; i++){
        if(s[i] == '('){
            ans += ')';
        }
        else if(s[i] == ')'){
            ans += '(';
        }
        else{
            ans += s[i];
        }
    }
    return ans;
}

int priority(char op){
    
        if(op == '^') return 3;
        else if(op == '*' || op == '/') return 2;
        else if(op == '-' || op == '+') return 1;
        else return -1;
}

string infixToPrefix(string s){

    // STEP -1 STRING REVERSAL
    s = reverse(s);
    int n = s.length();
    int i = 0;
    string ans = "";
    stack<char> st;

    // STEP -2 INFIX TO POSTFIX
    while (i < n){
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i]>='0' && s[i] <='9')){
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
            st.pop();
        }
        else{
            if(s[i] == '^'){
                while(!st.empty() && priority(s[i]) <= priority(st.top())){
                    ans += st.top();
                    st.pop();
            }
            }
            else{
                while(!st.empty() && priority(s[i]) < priority(st.top())){
                    ans += st.top();
                    st.pop();
                }
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

    // STEP -3 REVERSAL OF ANSWER
    ans = reverse(ans);
    return ans;
}