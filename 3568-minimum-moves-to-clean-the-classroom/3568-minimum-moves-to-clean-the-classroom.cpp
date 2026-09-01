class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int n=classroom.size();
        int m=classroom[0].size();

        vector<vector<int>> littermap(n, vector<int>(m));

        int cnt=0;
        int si=0,sj=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(classroom[i][j]=='S'){
                    si=i;
                    sj=j;
                }
                if(classroom[i][j]=='L'){
                    littermap[i][j]=cnt;
                    cnt++;
                }
            }
        }

        vector<vector<vector<int>>> bestenergy(n, vector<vector<int>>(m, vector<int>(1<<cnt,-1)));
        bestenergy[si][sj][0]=energy;

        int fullmask=0;
        for(int i=0;i<cnt;i++){
            fullmask|=(1<<i);
        }

        int changex[4]={0 , 1 , 0 , -1};
        int changey[4]={-1, 0 , 1 , 0};        

        //int moves, int energy, int i, int j, int mask
        queue<tuple<int,int,int,int,int>> q;
        q.emplace(0,energy,si,sj,0);
        while(!q.empty()){
            auto [moves,e,ni,nj,mask] = q.front(); q.pop();

            if(bestenergy[ni][nj][mask]>e) continue;

            if(mask==fullmask) return moves;

            for(int i=0;i<4;i++){
                int newi=ni+changex[i];
                int newj=nj+changey[i];

                if(newi>=n || newi<0 || newj>=m || newj<0){
                    continue;
                }
                if(classroom[newi][newj]=='X') continue;

                int newmask=mask;
                if(classroom[newi][newj]=='L'){
                    int num=littermap[newi][newj];
                    newmask|=(1<<num);
                }

                int newmoves=moves+1;

                int newe=e-1;
                if(classroom[newi][newj]=='R') newe=energy;
                if(newmask==fullmask) return newmoves;
                if(newe==0) continue;
                if(newe<=bestenergy[newi][newj][newmask]) continue;
                bestenergy[newi][newj][newmask]=newe;

                q.push({newmoves, newe, newi, newj, newmask});
            }
            
        }

        return -1;
    }
};