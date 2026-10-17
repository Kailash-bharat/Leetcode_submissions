class Solution {
public:
    vector<bool> visited;

    int sumdig(int n){
        if(n==0) return 0;
        return n%10+sumdig(n/10);
    }

    int dfs(int ind,vector<int> &sorted){
        if(visited[ind]==true) return 0;
        visited[ind]=true;
        return 1+dfs(sorted[ind],sorted);
    }

    int minSwaps(vector<int>& nums) {
        vector<pair<int,int>> v;
        for(auto i:nums){
            v.push_back({sumdig(i),i});
        }
        sort(v.begin(),v.end());

        unordered_map<int,int> ind;
        for(int i=0;i<v.size();i++){
            ind[v[i].second]=i;
        }

        vector<int> sorted;
        visited.assign(nums.size(),false);
        for(int i=0;i<nums.size();i++){
            sorted.push_back(ind[nums[i]]);
            if(i==ind[nums[i]]) visited[i]=true;
        }

        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(visited[i]==false){
                ans+=dfs(i,sorted);
                ans--;
            }
        }
        return ans;
    }
};