class Solution {
public:
    int makepali(string s, int shift){
        int ans=0;
        int n=s.size();
        for(int i=0;i<n/2;i++){
            char fro=s[(i+shift)%n];
            char bac=s[(n-1-i+shift)%n];
            int a=fro-'a';
            int b=bac-'a';
            ans+=min({abs(a-b), abs(a-b+26), abs(a-b-26)});
        }
        return ans;
    }

    int minOperations(string s) {
        int ans=INT_MAX;
        int n=s.size();
        ans=makepali(s,0);

        for(int i=1;i<=n-1;i++){
            ans=min(ans,i+makepali(s,i));
        }

        return ans;
    }
};