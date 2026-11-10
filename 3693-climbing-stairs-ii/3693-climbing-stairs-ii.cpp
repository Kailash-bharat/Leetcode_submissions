class Solution {
public:
    int n;

    int help(int ind, vector<int> &costs, vector<int> &dp){
        if(ind==n-1) return 0;
        if(dp[ind+1]!=-1) return dp[ind+1];
        int ans=1+costs[ind+1]+help(ind+1,costs,dp);

        for(int i=2;i<=3;i++){
            if(ind+i>=n) break;
            ans=min(ans,i*i+costs[ind+i]+help(ind+i,costs,dp));
        }

        return dp[ind+1]=ans;
    }

    int climbStairs(int p, vector<int>& costs) {
        n=costs.size();
        vector<int> dp(n+2,-1);
        return help(-1,costs,dp);
    }
};