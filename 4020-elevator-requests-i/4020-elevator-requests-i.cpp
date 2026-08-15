class Solution {
public:
    int elevatorRequests(int m, vector<int>& requests) {
        int ans=requests[0];
        int n=requests.size();
        for(int i=1;i<n;i++){
            ans+=abs(requests[i]-requests[i-1]);
        }
        return ans;
    }
};