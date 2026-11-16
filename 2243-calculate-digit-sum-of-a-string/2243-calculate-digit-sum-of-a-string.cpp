class Solution {
public:
    string help(string temp){
        int res=0;
        for(auto ch:temp){
            res+=ch-'0';
        }
        return to_string(res);
    }
    string digitSum(string s, int k) {
        while(s.size()>k){
            int n=s.size();
            string news="";
            for(int i=0;i<n;i+=k){
                string temp="";
                for(int j=0;j<k && i+j<n;j++){
                    temp+=s[i+j];
                }
                news+=help(temp);
            }
            s=news;
        }
        return s;
    }
};