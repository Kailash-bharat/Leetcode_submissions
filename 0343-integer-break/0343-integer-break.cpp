class Solution {
public:
    int integerBreak(int n) {
        if(n==2) return 1;
        else if(n==3) return 2;
        else if(n==4) return 4;

        int ans=1;

        for(int i=2;i<n-1;i++){
            int parts=i;
            int partvalue=n/i;
            int add1=n%i;
            int curr=1;
            for(int j=0;j<add1;j++){
                curr*=(partvalue+1);
            }
            for(int j=0;j<parts-add1;j++){
                curr*=(partvalue);
            }
            ans=max(ans,curr);
        }

        return ans;
    }
};