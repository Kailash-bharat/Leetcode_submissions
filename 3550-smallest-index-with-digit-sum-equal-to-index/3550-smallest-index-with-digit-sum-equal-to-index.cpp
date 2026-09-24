class Solution {
public:
    int help(string s){
        int res=0;
        for(auto ch:s){
            res+=ch-'0';
        }
        return res;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(i==help(to_string(nums[i]))) return i;
        }
        return -1;
    }
};