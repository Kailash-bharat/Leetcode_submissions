class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        int oddmini=INT_MAX;
        // int evenmini=INT_MAX;

        for(int i=0;i<n;i++){
            if(nums1[i]%2==0){
                // evenmini=min(nums1[i],evenmini);
            }
            else{
                oddmini=min(nums1[i],oddmini);
            }
        }

        if(oddmini==INT_MAX){
            bool ans=true;
            for(int i=0;i<n;i++){
                if(nums1[i]<1) ans=false;
            }
            if(ans) return true;
        }
        else{
            bool ans=true;
            for(int i=0;i<n;i++){
                if(nums1[i]%2==0){
                    if(nums1[i]-oddmini<1) ans=false;
                }
            }
            if(ans) return true;

            // ans=true;
            // for(int i=0;i<n;i++){
            //     if(nums1[i]%2==1){
            //         if(nums1[i]-oddmini<1) ans=false;
            //     }
            // }
            // if(ans) return true;
        }

        return false;
    }
};