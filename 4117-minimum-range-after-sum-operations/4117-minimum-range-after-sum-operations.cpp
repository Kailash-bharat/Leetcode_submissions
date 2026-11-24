class Solution {
public:
    int minRange(int a, int b, int c) {
        vector<int> v={a,b,c};
        sort(v.begin(),v.end());
        return min(v[2]-v[0],v[1]);
    }
};