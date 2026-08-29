class Solution {
public:
    bool help(int node, vector<vector<int>> &graph, vector<int> &history, vector<bool> &vis){
        bool ans=1;

        for(auto nbh:graph[node]){
            if(vis[nbh]==1){
                if(history[nbh]==1){
                    ans&=1;
                }
                else{
                    ans&=0;
                }
            }
            else{
                vis[nbh]=1;
                ans&=help(nbh, graph, history, vis);
            }
        }

        return history[node]=ans;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> history(n,-1);
        vector<bool> vis(n,0);

        for(int i=0;i<n;i++){
            if(graph[i].size()==0){
                history[i]=1;
                vis[i]=1;
            }
        }

        for(int i=0;i<n;i++){
            if(vis[i]==0){
                vis[i]=1;
                help(i, graph, history, vis);
            }
        }

        vector<int> ans;
        for(int i=0;i<n;i++){
            if(history[i]==1) ans.push_back(i);
        }
        return ans;

    }
};