class Solution {
public:

    int help(string &s, string &t, int i, int j, int n1, int n2, vector<vector<int>> &dp){
        if(dp[i][j]!=-1) return dp[i][j];

        if(i==n1 || j==n2) return dp[i][j] = 0;
        if(j==n2-1){
            if(s[i]==t[j]) return dp[i][j] = 1+help(s,t,i+1,j,n1,n2,dp);
            return dp[i][j] = help(s,t,i+1,j,n1,n2,dp);
        }

        if(s[i]==t[j]) return dp[i][j] = help(s,t,i+1,j+1,n1,n2,dp)+help(s,t,i+1,j,n1,n2,dp);
        return dp[i][j] = help(s,t,i+1,j,n1,n2,dp);
    }

    int numDistinct(string s, string t) {
        int n1=s.size();
        int n2=t.size();

        vector<vector<int>> dp(n1+1, vector<int>(n2+1,-1));
        return help(s, t, 0, 0, n1, n2, dp);
    }
};