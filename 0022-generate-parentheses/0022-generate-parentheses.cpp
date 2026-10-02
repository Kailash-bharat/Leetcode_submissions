class Solution {
public:
    set<string> ans;

    void help(string cur, int opens, int closes){
        if(opens==0 && closes==0){
            ans.insert(cur);
            return;
        }

        //open
        if(opens>0){
            help(cur+'(', opens-1, closes);
        }

        //close
        if(closes>opens){
            help(cur+')', opens, closes-1);
        }
    }

    vector<string> generateParenthesis(int n) {
        string cur="";
        help(cur, n, n);
        return vector<string> (ans.begin(),ans.end());
    }
};