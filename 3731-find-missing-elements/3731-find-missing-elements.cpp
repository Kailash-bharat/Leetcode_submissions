class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_map<int,bool> mp;
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(auto i:nums){
            mp[i]=true;
            mini=min(i,mini);
            maxi=max(i,maxi);
        }

        vector<int> ans;
        for(int i=mini+1;i<maxi;i++){
            if(mp[i]==0) ans.push_back(i);
        }

        return ans;
    }
};