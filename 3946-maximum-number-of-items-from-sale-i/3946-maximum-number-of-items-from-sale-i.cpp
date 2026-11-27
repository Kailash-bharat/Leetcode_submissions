class Solution {
public:
    int n;
    vector<int> fact;
    vector<int> money;
    int minprice;
    vector<vector<int>> dp;

    int help(int ind,int budget){
        if(ind==n){
            return budget/minprice;
        }

        if(dp[ind][budget]!=-1) return dp[ind][budget];

        int ans1=-1,ans2=-1;

        //take
        if(budget>=money[ind]){
            ans1=1+fact[ind]+help(ind+1,budget-money[ind]);
        }

        //not take
        ans2=help(ind+1,budget);

        return dp[ind][budget]=max(ans1,ans2);
    }

    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        n=items.size();
        fact.assign(n,-1);
        minprice=INT_MAX;
        dp.assign(n,vector<int>(budget+1,-1));

        for(int i=0;i<n;i++){
            money.push_back(items[i][1]);
        }

        for(int i=0;i<n;i++){
            int facty=items[i][0];
            int pricey=items[i][1];

            minprice=min(minprice,pricey);

            for(int j=0;j<n;j++){
                if(items[j][0]%facty==0){
                    fact[i]++;
                }
            }
        }

        // cout << "money" << endl;
        // for(int i=0;i<n;i++){
        //     cout << money[i] << " ";
        // }
        // cout << endl << "factors" << endl;
        // for(int i=0;i<n;i++){
        //     cout << fact[i] << " ";
        // }

        return help(0,budget);
    }
};