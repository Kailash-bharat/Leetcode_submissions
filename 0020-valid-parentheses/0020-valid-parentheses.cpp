class Solution {
public:
    bool isValid(string k) {
        stack<char> s;
        for(auto ch:k){
            if(ch=='(' || ch=='{' || ch=='['){
                s.push(ch);
            }
            else{
                if(ch==')'){
                    if(s.empty()) return false;
                    else if(s.top()!='(') return false;
                    s.pop();
                }
                else if(ch==']'){
                    if(s.empty()) return false;
                    else if(s.top()!='[') return false;
                    s.pop();
                }
                else{
                    if(s.empty()) return false;
                    else if(s.top()!='{') return false;
                    s.pop();
                }
            }
        }
        if(s.empty()) return true;
        return false;
    }
};