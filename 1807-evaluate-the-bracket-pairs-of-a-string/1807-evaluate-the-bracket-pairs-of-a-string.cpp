class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> mp;
        for(auto i:knowledge){
            mp[i[0]]=i[1];
            // cout << i[0] << " " << i[1] << endl;
        }
        int n=s.size();
        string ans="";
        for(int i=0;i<n;i++){
            // cout << i << " " << s[i] << endl;
            if(s[i]=='('){
                i++;
                string check="";
                while(s[i]!=')'){
                    check+=s[i];
                    i++;
                }
                cout << check << endl;
                if(mp.find(check)==mp.end()){
                    ans+="?";
                }
                else{
                    ans+=mp[check];
                }
            }
            else{
                ans+=s[i];
            }
            // cout << ans << endl;
        }
        return ans;
    }
};