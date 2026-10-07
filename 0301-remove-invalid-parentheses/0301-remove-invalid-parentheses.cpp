class Solution {
public:
    string s;
    int n;
    map<int,vector<int>> mp;

    void help(int ind, int sum, int mask){
        if(ind==n){
            if(sum==0){
                int bcount=__builtin_popcount(mask);
                mp[bcount].push_back(mask);
            }
            return;
        }

        if(s[ind]=='('){
            //take
            int nmask=mask|(1<<ind);
            help(ind+1, sum+1, nmask);

            //not take
            help(ind+1, sum, mask);
        }
        else if(s[ind]==')'){
            int nsum=sum-1;
            if(nsum>=0){
                //take
                int nmask=mask|(1<<ind);
                help(ind+1, nsum, nmask);
            }

            //not take
            help(ind+1, sum, mask);
        }
        else{
            //take only we need min removals
            int nmask=mask|(1<<ind);
            help(ind+1, sum, nmask);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        this->s=s;
        n=s.size();
        help(0,0,0);

        auto it=mp.rbegin();
        vector<int> req=it->second;

        set<string> ans;
        for(auto mask:req){
            string poscase="";
            int check=1;
            for(int i=0;i<n;i++,check=check<<1){
                if(mask & check){
                    poscase+=s[i];
                }
            }
            ans.insert(poscase);
        }

        return vector<string>(ans.begin(),ans.end());
    }
};