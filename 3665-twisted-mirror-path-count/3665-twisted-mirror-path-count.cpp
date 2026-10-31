class Solution {
public:
    int mod=1e9+7;
    int uniquePaths(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<long long>> dpl(n,vector<long long>(m));
        vector<vector<long long>> dpu(n,vector<long long>(m));

        if(grid[n-1][m-1]==1) return 0;

        dpl[0][0]=1;
        dpu[0][0]=1;

        for(int i=1;i<n;i++){
            if(grid[i-1][0]!=1){
                dpu[i][0]=dpu[i-1][0];
            }
            else{
                dpu[i][0]=0;
            }
            dpl[i][0]=0;
        }

        for(int i=1;i<m;i++){
            if(grid[0][i-1]!=1){
                dpl[0][i]=dpl[0][i-1];
            }
            else{
                dpl[0][i]=0;
            }
            dpu[0][i]=0;
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(grid[i-1][j]){
                    dpu[i][j]=dpl[i-1][j];
                }
                else{
                    dpu[i][j]=(dpu[i-1][j]+dpl[i-1][j])%mod;
                }

                if(grid[i][j-1]){
                    dpl[i][j]=dpu[i][j-1];
                }
                else{
                    dpl[i][j]=(dpu[i][j-1]+dpl[i][j-1])%mod;
                }
            }
        }

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout << "u " << i << " " << j << " " << dpu[i][j] << " ";
        //         cout << "l " << i << " " << j << " " << dpl[i][j]; 
        //         cout << endl;
        //     }
        // }

        return (dpu[n-1][m-1]+dpl[n-1][m-1])%mod;
    }
};