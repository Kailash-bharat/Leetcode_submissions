class Solution {
public:
    int n;
    vector<vector<vector<double>>> dp;
    int di[8]={1, 2, 2, 1, -1, -2, -2, -1};
    int dj[8]={2, 1, -1, -2, -2, -1, 1, 2};

    double help(int i, int j, int k){
        if(i<0 || i>=n || j<0 || j>=n){
            return 0.0;
        }
        if(k==0) return 1.0;

        if(dp[i][j][k]!=-1) return dp[i][j][k];

        double ans=0.0;
        for(int m=0;m<8;m++){
            ans+=(1.0/8.0)*help(i+di[m],j+dj[m],k-1);
        }

        dp[i][j][k]=ans;
        return ans;
    }

    double knightProbability(int n, int k, int row, int column) {
        this->n=n;
        dp.assign(n,vector<vector<double>> (n,vector<double>(k+1,-1.0)));
        return help(row,column,k);
    }
};