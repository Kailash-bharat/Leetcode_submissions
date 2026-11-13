class Solution {
public:
    vector<int> countServers(int servers, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int n=logs.size();
        for(int i=0;i<n;i++){
            swap(logs[i][0],logs[i][1]);
        }
        sort(logs.begin(),logs.end());

        int l=0;
        int r=-1;
        unordered_map<int,int> mp;

        vector<pair<int,int>> qs;
        for(int i=0;i<queries.size();i++){
            qs.push_back({queries[i],i});
        }
        sort(qs.begin(),qs.end());

        vector<int> ans(qs.size());

        for(int i=0;i<qs.size();i++){
            int ind=qs[i].second;
            int rend=qs[i].first;
            int lend=rend-x;

            while(r+1<n && logs[r+1][0]<=rend){ //+1 is important
                r++;
                mp[logs[r][1]]++;
            }
            while(l<n && logs[l][0]<lend){
                if(l<n && logs[l][0]<lend){
                    mp[logs[l][1]]--;
                    if(mp[logs[l][1]]==0){
                        mp.erase(logs[l][1]);
                    }
                }
                l++;
            }

            ans[ind]=servers-mp.size();
        }

        return ans;
    }
};