class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans="";
        while(sum){
            if(sum>9){
                sum-=9;
                ans+="9";
            }
            else{
                ans+=to_string(sum);
                sum=0;
            }
            num--;
        }
        if(num<0) return "";
        for(int i=0;i<num;i++){
            ans+="0";
        }
        return ans;
    }
};