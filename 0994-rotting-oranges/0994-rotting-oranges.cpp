class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n=grid.size();
        int m=grid[0].size();

        bool everything_zero=true;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                    everything_zero=false;
                }
            }
        }
        if(everything_zero) return 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int ans=0;
        while(!q.empty()){
            int sz=q.size();
            ans++;
            while(sz--){
                auto [i,j]=q.front();
                q.pop();

                int di[4]={1, 0, 0, -1};
                int dj[4]={0, -1, 1, 0};

                for(int k=0;k<4;k++){
                    int ni=i+di[k];
                    int nj=j+dj[k];

                    if(ni<n && ni>=0 && nj>=0 && nj<m && grid[ni][nj]==1){
                        grid[ni][nj]=2;
                        q.push({ni,nj});
                    }
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }

        return ans-1;
    }
};