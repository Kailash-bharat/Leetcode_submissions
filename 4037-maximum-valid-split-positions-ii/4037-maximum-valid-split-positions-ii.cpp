class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefgcd(n),suffgcd(n);

        prefgcd[0]=nums[0];
        for(int i=1;i<n;i++){
            prefgcd[i]=gcd(prefgcd[i-1],nums[i]);
        }

        suffgcd[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffgcd[i]=gcd(suffgcd[i+1],nums[i]);
        }

        int l=n-1, r=0;
        for(int i=n-2;i>=0;i--){
            if(prefgcd[i]!=prefgcd[i+1]) break;
            l--;
        }
        for(int i=1;i<n;i++){
            if(suffgcd[i]!=suffgcd[i-1]) break;
            r++;
        }

        int ans=r-l;

        if(l!=0){
            vector<int> v;
            for(int i=0;i<n;i++){
                if(i!=l-1) v.push_back(nums[i]);
            }

            int sz=v.size();
            vector<int> pref(sz),suff(sz);

            pref[0]=v[0];
            for(int i=1;i<sz;i++){
                pref[i]=gcd(pref[i-1],v[i]);
            }

            suff[sz-1]=v[sz-1];
            for(int i=sz-2;i>=0;i--){
                suff[i]=gcd(suff[i+1],v[i]);
            }

            int ll=sz-1, rr=0;
            for(int i=sz-2;i>=0;i--){
                if(pref[i]!=pref[i+1]) break;
                ll--;
            }
            for(int i=1;i<sz;i++){
                if(suff[i]!=suff[i-1]) break;
                rr++;
            }

            ans=max(ans,rr-ll);
        }

        if(r!=n-1){
            vector<int> v;
            for(int i=0;i<n;i++){
                if(i!=r+1) v.push_back(nums[i]);
            }

            int sz=v.size();
            vector<int> pref(sz),suff(sz);

            pref[0]=v[0];
            for(int i=1;i<sz;i++){
                pref[i]=gcd(pref[i-1],v[i]);
            }

            suff[sz-1]=v[sz-1];
            for(int i=sz-2;i>=0;i--){
                suff[i]=gcd(suff[i+1],v[i]);
            }

            int ll=sz-1, rr=0;
            for(int i=sz-2;i>=0;i--){
                if(pref[i]!=pref[i+1]) break;
                ll--;
            }
            for(int i=1;i<sz;i++){
                if(suff[i]!=suff[i-1]) break;
                rr++;
            }

            ans=max(ans,rr-ll);
        }

        if(1){
            vector<int> v;
            for(int i=0;i<n;i++){
                if(i!=l) v.push_back(nums[i]);
            }

            int sz=v.size();
            vector<int> pref(sz),suff(sz);

            pref[0]=v[0];
            for(int i=1;i<sz;i++){
                pref[i]=gcd(pref[i-1],v[i]);
            }

            suff[sz-1]=v[sz-1];
            for(int i=sz-2;i>=0;i--){
                suff[i]=gcd(suff[i+1],v[i]);
            }

            int ll=sz-1, rr=0;
            for(int i=sz-2;i>=0;i--){
                if(pref[i]!=pref[i+1]) break;
                ll--;
            }
            for(int i=1;i<sz;i++){
                if(suff[i]!=suff[i-1]) break;
                rr++;
            }

            ans=max(ans,rr-ll);
        }

        if(1){
            vector<int> v;
            for(int i=0;i<n;i++){
                if(i!=r) v.push_back(nums[i]);
            }

            int sz=v.size();
            vector<int> pref(sz),suff(sz);

            pref[0]=v[0];
            for(int i=1;i<sz;i++){
                pref[i]=gcd(pref[i-1],v[i]);
            }

            suff[sz-1]=v[sz-1];
            for(int i=sz-2;i>=0;i--){
                suff[i]=gcd(suff[i+1],v[i]);
            }

            int ll=sz-1, rr=0;
            for(int i=sz-2;i>=0;i--){
                if(pref[i]!=pref[i+1]) break;
                ll--;
            }
            for(int i=1;i<sz;i++){
                if(suff[i]!=suff[i-1]) break;
                rr++;
            }

            ans=max(ans,rr-ll);
        }

        return max(0,ans);
    }
};