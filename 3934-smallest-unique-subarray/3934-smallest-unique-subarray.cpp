class Solution {
public:
    int n;
    vector<int> arr;
    unordered_map<long long,int> io;

    bool help(int k){
        map<int,int> mp;
        int base=7;
        long long remconst=1;
        long long hash=0;
        int mod=1e9+7;
        int cnt=0;

        for(int i=0;i<k;i++){
            remconst*=base;
            remconst%=mod;
        }

        for(int i=0;i<k;i++){
            hash=(hash*base+arr[i])%mod;
        }
        mp[hash]++;
        if(mp[hash]==1) cnt++;

        for(int i=k;i<n;i++){
            hash=((hash*base-arr[i-k]*remconst+arr[i])%mod+mod)%mod;
            mp[hash]++;
            if(mp[hash]==1) cnt++;
            else if(mp[hash]==2) cnt--;
        }

        if(cnt) return true;
        return false;
    }

    int smallestUniqueSubarray(vector<int>& nums) {
        n=nums.size();

        int uni=0;
        for(int i=0;i<n;i++){
            int ele=nums[i];
            if(io[ele]==0){
                uni++;
                io[ele]=uni;
            }
            arr.push_back(io[ele]);
        }

        int l=1;
        int r=n;
        int ans=n;

        while(l<=r){
            int mid=l+(r-l)/2;
            if(help(mid)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }

        return ans;
    }
};