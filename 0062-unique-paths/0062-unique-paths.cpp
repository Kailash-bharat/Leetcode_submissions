class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1 || n==1) return 1;
        m--;
        n--;
        int mini=min(m,n);
        int maxi=m+n-mini;

        long long ans=1;
        for(int i=1,j=mini+1;j<=mini+maxi;i++,j++){
            ans*=j;
            ans/=i;
        }
        return (int)ans;

    }
};