class Solution {
public:
    string s;
    int n;
    bool help(int i, int sum, vector<vector<int>> &dp){
        if(sum<0){
            return dp[i][sum+100]=0;
        }
        if(i==n){
            if(sum==0) return true;
            else return false;
        }
        if(dp[i][sum+100]!=-1){
            return dp[i][sum+100];
        }

        bool ans;
        if(s[i]=='('){
            ans=help(i+1, sum+1, dp);
        }
        else if(s[i]==')'){
            ans=help(i+1, sum-1, dp);
        }
        else{
            ans=false;
            if(help(i+1, sum+1, dp)){
                ans=true;
            }
            else if(help(i+1, sum-1, dp)){
                ans=true;
            }
            else if(help(i+1, sum, dp)){
                ans=true;
            }
        }
        return dp[i][sum+100]=ans;
    }

    bool checkValidString(string s) {
        this->s=s;
        n=s.size();
        if(s[0]==')' || s[n-1]=='('){
            return false;
        }

        vector<vector<int>> dp(n+1,vector<int>(202,-1));
        return help(0, 0, dp);
    }
};