class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans=0;
        int sum=0;
        for(char ch:s){
            if(ch=='('){
                sum++;
            }
            else{
                sum--;
                if(sum<0){
                    sum=0;
                    ans++;
                }
            }
        }

        return ans+sum;
    }
};