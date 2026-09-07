// class Solution {
// public:
//     int n;

//     void help(string &s, int ind, unordered_set<string> &st, string &cur){
//         if(ind==n){
//             st.insert(cur);
//             return;
//         }

//         // take
//         cur.push_back(s[ind]);
//         help(s, ind+1, st, cur);
//         cur.pop_back();

//         // not take
//         help(s, ind+1, st, cur);
//     }

//     int distinctSubseqII(string s) {
//         n=s.size();
//         unordered_set<string> st;
//         string cur="";
//         help(s, 0, st, cur);
//         return st.size()-1;
//     }
// };

class Solution {
    const int MOD = 1e9 + 7;

public:
    int distinctSubseqII(string s) {
        int tot = 0;
        vector<int> dp(26,0);

        for (auto& c : s) {
            int ch=c-'a';
            int add = (tot - dp[ch] + MOD) % MOD;
            dp[ch] = 1 + tot;
            tot = (dp[ch] + add) % MOD;
        }

        return tot;
    }
};