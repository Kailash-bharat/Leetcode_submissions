class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans=LLONG_MIN;
        unordered_map<int,long long> ind;
        int n=nums.size();

        vector<long long> prefsum(n+1,0);
        for(int i=0;i<n;i++){
            prefsum[i+1]=prefsum[i]+nums[i];
            int ele=nums[i];
            if(ind.find(ele-k)!=ind.end()){
                ans=max(ans,prefsum[i+1]-ind[ele-k]);
            }
            if(ind.find(ele+k)!=ind.end()){
                ans=max(ans,prefsum[i+1]-ind[ele+k]);
            }
            if(ind.find(ele)!=ind.end()){
                long long keep=min(ind[ele],prefsum[i]);
                ind[ele]=keep;
            }
            else{
                ind[ele]=prefsum[i];
            }
        }

        if(ans==LLONG_MIN) return 0;
        return ans;
    }
};