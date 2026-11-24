// class Solution {
// public:
//     int n;
//     vector<int> arr;
//     vector<vector<long long>> dp;
//     long long help(int ind ,bool par){
//         if(ind==n-2){
//             if(par){
//                 return arr[ind];
//             }
//             else{
//                 return 0;
//             }
//         }

//         if(dp[ind][par]!=-1) return dp[ind][par];

//         long long ans1=0,ans2=0;
//         //take
//         ans1=1LL*arr[ind]+help(ind+1,!par);
//         //not take
//         ans2=help(ind+1,par);

//         return dp[ind][par]=min(ans1,ans2);
//     }

//     long long minCost(vector<int>& nums) {
//         n=nums.size();
//         arr=nums;
//         dp.assign(n+1,vector<long long>(2,-1));

//         long long ans = 1LL*arr.front() + 1LL*arr.back();
//         if(n==2 || n==3){
//             return ans;
//         }
//         ans+=help(1,0);
//         return ans;
//     }
// };

class Solution {
public:
    long long minCost(vector<int>& nums) {
        int n=nums.size();
        long long ans=1LL*nums[0] + 1LL*nums[n-1];
        int cnt=0;
        long long negsum=0;
        int negmax=INT_MIN;
        int posmin=INT_MAX;
        for(int i=1;i<n-1;i++){
            if(nums[i]<0){
                negsum+=1LL*nums[i];
                cnt++;
                negmax=max(negmax,nums[i]);
            }
            else{
                posmin=min(posmin,nums[i]);
            }
        }
        if(cnt%2!=0){
            if(posmin==INT_MAX){
                return ans+negsum-1LL*negmax;
            }
            else{
                return ans+min(negsum-1LL*negmax,negsum+1LL*posmin);
            }
        }
        return ans+negsum;
    }
};