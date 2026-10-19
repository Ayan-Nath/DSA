class Solution {
public:
    bool isValid(string st) {
        int n = st.size();
        if(n == 1) return false;

        stack<char> s;
        int i = 0;
        while(i < n) {
            if(st[i] == '(' || st[i] == '{' || st[i] == '[') {
                s.push(st[i]);
            }
            else if(st[i] == ')') {
                if(!s.empty() && s.top() == '(') {
                    s.pop();  
                } else {
                    return false; // invalid case
                }
            }
            else if(st[i] == '}') {
                if(!s.empty() && s.top() == '{') {
                    s.pop();  
                } else {
                    return false;
                }
            }
            else if(st[i] == ']') {
                if(!s.empty() && s.top() == '[') {
                    s.pop();  
                } else {
                    return false;
                }
            }
            i++;
        } 
        return s.empty();
    }
};

