class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int best=0;
        for(int i:lights){
            best=max(best,i);
        }

        int ans=0;
        for(int i:arrivalTime){
            int j=i%period;
            if(j>=best){
                ans=max(ans,period-j);
            }
        }

        return ans;
    }
};