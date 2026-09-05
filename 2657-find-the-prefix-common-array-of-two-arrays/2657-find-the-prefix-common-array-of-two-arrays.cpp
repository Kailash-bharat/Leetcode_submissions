class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<bool> va(51),vb(51);
        vector<int> ans(n);

        if(A[0]==B[0]){
            ans[0]=1;
        }
        va[A[0]]=true;
        vb[B[0]]=true;

        for(int i=1;i<n;i++){
            int a=A[i];
            int b=B[i];

            va[a]=true;
            vb[b]=true;

            ans[i]=ans[i-1];
            if(a==b){
                ans[i]++;
                continue;
            }

            if(vb[a]==true){
                ans[i]++;
            }
            if(va[b]==true){
                ans[i]++;
            }
        }

        return ans;
    }
};