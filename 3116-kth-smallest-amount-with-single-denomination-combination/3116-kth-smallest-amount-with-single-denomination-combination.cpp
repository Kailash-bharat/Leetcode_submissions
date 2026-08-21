class Solution {
public:
    vector<long long> add,sub;
    void help(vector<int> &v, int ind, bool par, long long mul=1LL){
        if(ind==v.size()) return;

        help(v,ind+1,par,mul);

        mul=(mul/gcd(mul,v[ind]))*v[ind];
        if(par){
            sub.push_back(mul);
        }
        else{
            add.push_back(mul);
        }
        help(v,ind+1,!par,mul);
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        sort(coins.begin(),coins.end());

        help(coins, 0, 0);

        long long left=1;
        long long right = 1LL * coins[0] * k;
        long long ans=0;

        while(left<=right){
            long long mid=left+(right-left)/2;
            long long count=0;
            for(auto i:add){
                count+=mid/i;
            }
            for(auto i:sub){
                count-=mid/i;
            }

            if(count==k){
                ans=mid;
                right = mid-1;
            }
            else if(count>k) right = mid-1;
            else left = mid + 1;
        }

        // for(auto it:add){
        //     cout << it << " ";
        // }
        // cout << endl;
        // for(auto it:sub){
        //     cout << it << " ";
        // }

        return ans;
    }
};






// class Solution {
// public:
//     vector<pair<long long, int>> v;

//     void help(vector<int>& coins, int ind, bool par,
//               long long mul = 1LL) {

//         if (ind == coins.size())
//             return;

//         help(coins, ind + 1, par, mul);

//         long long nmul =
//             (mul / gcd(mul, 1LL * coins[ind])) * coins[ind];

//         if (nmul <= 1e9) {
//             v.push_back({nmul, par ? -1 : 1});
//             help(coins, ind + 1, !par, nmul);
//         }
//     }

//     long long findKthSmallest(vector<int>& coins, int k) {
//         sort(coins.begin(), coins.end());

//         v.clear();
//         help(coins, 0, false);

//         long long left = 1;
//         long long right = 1LL * coins[0] * k;

//         while (left < right) {
//             long long mid = left + (right - left) / 2;

//             long long count = 0;

//             for (auto [lcm, sign] : v) {
//                 if (lcm > mid) continue;

//                 count += sign * (mid / lcm);
//             }

//             if (count >= k)
//                 right = mid;
//             else
//                 left = mid + 1;
//         }

//         for(auto it:v){
//             if(it.second==1) cout << it.first << " ";
//         }
//         cout << endl;
//         for(auto it:v){
//             if(it.second==-1) cout << it.first << " ";
//         }

//         return left;
//     }
// };