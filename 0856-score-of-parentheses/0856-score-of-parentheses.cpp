class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        for(auto ch:s){
            if(ch=='('){
                st.push(-1);
            }
            else{
                if(st.top()==-1){
                    st.pop();
                    st.push(1);
                }
                else{
                    int sum=0;
                    while(st.top()!=-1){
                        sum+=st.top();
                        st.pop();
                    }
                    st.pop();
                    st.push(2*sum);
                }
            }
        }
        int ans=0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};
