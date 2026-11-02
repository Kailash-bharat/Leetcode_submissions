class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        else if(n==2){
            return max(nums[0],nums[1])-min(nums[0],nums[1]);
        }

        int mini=*min_element(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=nums[i]-mini;
        }
        return ans;
    }
};