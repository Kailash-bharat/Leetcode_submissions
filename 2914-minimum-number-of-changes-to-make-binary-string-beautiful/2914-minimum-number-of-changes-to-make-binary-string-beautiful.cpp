class Solution {
public:
    int minChanges(string s) {
        int cnt=1;
        vector<int> v;
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]){
                cnt++;
            }
            else{
                v.push_back(cnt);
                cnt=1;
            }
            if(i==s.size()-1) v.push_back(cnt);
        }
        int ans=0;
        cnt=0;
        bool seen=0;
        for(int i=0;i<v.size();i++){
            if(v[i]%2==0){
                if(seen==0) continue;
                else cnt++;
            }
            else{
                if(seen==0){
                    seen=1;
                    cnt=0;
                }
                else{
                    seen=0;
                    ans+=cnt+1;
                    cnt=0;
                }
            }
        }
        return ans;
    }
};