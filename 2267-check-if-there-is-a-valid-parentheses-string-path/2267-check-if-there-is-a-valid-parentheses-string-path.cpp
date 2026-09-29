class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<vector<bool>>> vis(n,vector<vector<bool>>(m,vector<bool>(n+m,false)));

        queue<tuple<int,int,int>> q;
        if(grid[0][0]==')') return false;
        q.push({0,0,1});
        vis[0][0][1]=true;

        int di[2]={1,0};
        int dj[2]={0,1};

        while(!q.empty()){
            auto [row,col,sum]=q.front();
            q.pop();


            for(int i=0;i<2;i++){
                int nrow=row+di[i];
                int ncol=col+dj[i];

                if(nrow<n && nrow>=0 && ncol<m && ncol>=0){
                    int nsum=sum;
                    grid[nrow][ncol]=='(' ? nsum+=1 : nsum-=1;

                    if(nsum>=0 && vis[nrow][ncol][nsum]==false){
                        q.push({nrow,ncol,nsum});
                        vis[nrow][ncol][nsum]=true;
                    }
                    if(nrow==n-1 && ncol==m-1 && nsum==0) return true;
                }
            }
        }

        return false;
    }
};

// class Solution {
// public:
//     int n,m;
//     int dx[4]={1,0,-1,0};
//     int dy[4]={0,1,0,-1};

//     bool dfs(int row, int col, vector<vector<bool>> &dfsvis, int sum, vector<vector<char>> &grid){
//         if(grid[row][col]=='('){
//             sum+=1;
//         }
//         else{
//             sum-=1;
//         }

//         if(sum<0) return false;
//         if(row==n-1 && col==m-1){
//             if(sum==0) return true;
//             return false;
//         }

//         for(int i=0;i<4;i++){
//             int nrow=row+dx[i];
//             int ncol=col+dy[i];

//             if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && dfsvis[nrow][ncol]==false){
//                 bool check=false;
//                 dfsvis[nrow][ncol]=true;
//                 check=dfs(nrow, ncol, dfsvis, sum, grid);
//                 dfsvis[nrow][ncol]=false;
//                 if(check) return true; 
//             }
//         }

//         return false;
//     }

//     bool hasValidPath(vector<vector<char>>& grid) {
//         n=grid.size();
//         m=grid[0].size();

//         vector<vector<bool>> dfsvis(n,vector<bool>(m,false));
//         dfsvis[0][0]=true;
        
//         if(dfs(0,0,dfsvis,0,grid)) return true;
//         return false;
//     }
// };