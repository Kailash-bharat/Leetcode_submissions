class Solution {
public:
    int mySqrt(int x) {
        int r=x;
        int l=0;
        int ans=0;
        while(l<=r){
            long long mid=(l+r)/2;
            if(mid*mid==1LL*x) return mid;
            else if(mid*mid<1LL*x){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};