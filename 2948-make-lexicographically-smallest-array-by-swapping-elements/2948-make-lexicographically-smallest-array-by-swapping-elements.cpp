class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<int> ans(n);
        vector<pair<int,int>> v;

        for(int i=0;i<n;i++){
            v.push_back({nums[i], i});
        }

        sort(v.begin(), v.end());
        v.push_back({INT_MAX, -1});

        vector<int> vals;
        vector<int> pos;
        for(int i=0;i<n;i++){
            vals.push_back(v[i].first);
            pos.push_back(v[i].second);

            if(v[i+1].first-v[i].first<=limit){
                continue;
            }
            else{
                sort(pos.begin(), pos.end());
                for(int k=0;k<pos.size();k++){
                    // cout << vals[k] << " -> " << pos[k] << " , ";
                    ans[pos[k]] = vals[k];
                }
                // cout << endl;

                vals.clear();
                pos.clear();
            }
        }

        return ans;
    }
};