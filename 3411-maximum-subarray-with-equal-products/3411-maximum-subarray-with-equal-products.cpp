class Solution {
public:
    int maxLength(vector<int>& nums) {
        int ans=2;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            int len=1;
            long long pro=nums[i];
            int gc=nums[i];
            int lc=nums[i];
            for(int j=i+1;j<n;j++){
                len++;
                pro*=nums[j];
                gc=gcd(nums[j],gc);
                lc=lcm(lc,nums[j]);
                if(lc*gc==pro){
                    ans=max(ans,len);
                }
                else break;
            }
        }
        return ans;
    }
};