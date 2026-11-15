using ll=long long;
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod=1e9+7;
        ll n=arr.size();
        ll anseve=0;
        ll ansodd=0;
        ll eves=0;
        ll odds=0;
        for(int i=0;i<n;i++){
            ll ele=arr[i];
            ll neve=0,nodd=0;
            if(ele%2==0){
                neve++;
                neve+=eves;
                nodd+=odds;
            }
            else{
                nodd++;
                nodd+=eves;
                neve+=odds;
            }
            eves=neve%mod;
            odds=nodd%mod;
            anseve+=eves%mod;
            anseve%=mod;
            ansodd+=odds%mod;
            ansodd%=mod;
        }
        return ansodd;
    }
};