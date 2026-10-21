class Solution {
public:
    int minOperations(string s) {
        int mini='z';
        int maxi='a';
        int cntmaxi=0;
        int cntmini=0;
        for(auto ch:s){
            mini=min(mini,(int)ch);
            maxi=max(maxi,(int)ch);
        }
        for(auto ch:s){
            if(ch==maxi) cntmaxi++;
            else if(ch==mini) cntmini++;
        }
        
        if(is_sorted(s.begin(),s.end())) return 0;

        int n=s.size();
        if(n==1) return 0;
        if(n==2){
            if(s[0]>s[1]){
                return -1;
            }
            else{
                return 0;
            }
        }

        if(s[0]==mini){
            return 1;
        }
        else if(s[n-1]==maxi){
            return 1;
        }
        else if(s[0]==maxi && s[n-1]==mini && cntmaxi==1 && cntmini==1){
            return 3;
        }
        return 2;
    }
};