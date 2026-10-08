class Solution {
public:
    string removeOuterParentheses(string s) {
        int sum=0;
        int n=s.size();
        vector<bool> v(n,true);

        bool onedone=false;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                sum++;
            }
            else{
                sum--;
            }
            if(sum==1 && onedone==false){
                onedone=true;
                v[i]=false;
            }
            else if(sum==0){
                onedone=false;
                v[i]=false;
            }
        }

        string ans="";
        for(int i=0;i<n;i++){
            if(v[i]) ans+=s[i];
        }
        return ans;
    }
};