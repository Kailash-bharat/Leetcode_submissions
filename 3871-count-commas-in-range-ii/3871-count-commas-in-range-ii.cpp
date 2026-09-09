class Solution {
public:
    long long countCommas(long long n) {
        long long ans=0;
        (n<1000) ? ans=ans+0 : ans=ans+(n-999);
        (n<1000000) ? ans=ans+0 : ans=ans+(n-999999);
        (n<1000000000) ? ans=ans+0 : ans=ans+(n-999999999);
        (n<1000000000000) ? ans=ans+0 : ans=ans+(n-999999999999);
        (n<1000000000000000) ? ans=ans+0 : ans=ans+(n-999999999999999);
        return ans;
    }
};