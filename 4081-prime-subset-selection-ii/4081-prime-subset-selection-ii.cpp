class Solution {
public:
    vector<int> primes;
    int primenum;
    int n;
    int s;
    vector<vector<int>> dpsum;
    vector<vector<int>> dpcnt;

    int maxsum(int ind, int sum){
        if(ind==primenum){
            return 0;
        }
        
        if(dpsum[ind][sum]!=-1){
            return dpsum[ind][sum];
        }
        
        int ans=0;
        
        //take
        if(sum+primes[ind]<=s){
            ans=max(ans,primes[ind]+maxsum(ind+1,sum+primes[ind]));
        }
        //not take
        ans=max(ans,maxsum(ind+1,sum));

        return dpsum[ind][sum]=ans;
    }

    int mincnt(int ind, int reqsum){
        if(ind==primenum){
            if(reqsum==0) return 0;
            return 10000;
        }

        if(dpcnt[ind][reqsum]!=-1){
            return dpcnt[ind][reqsum];
        }
        int ans=10000;
        //take
        if(reqsum-primes[ind]>=0){
            ans=min(ans,1+mincnt(ind+1,reqsum-primes[ind]));
        }
        //not take
        ans=min(ans,mincnt(ind+1,reqsum));

        return dpcnt[ind][reqsum]=ans;
    }
    
    vector<int> maxPrimeSubset(int n, int s) {
        vector<int> ans;
        if(n==0 || n==1) return ans;
        
        this->n=n;
        this->s=s;
        vector<bool> v(n+1,1);
        v[0]=v[1]=0;
        for(int i=2;i*i<=n;i++){
            if(v[i]){
                for(int j=i*i;j<=n;j+=i){
                    v[j]=0;
                }
            }
        }
        for(int i=2;i<=n;i++){
            if(v[i]){
                primes.push_back(i);
            }
        }

        primenum=primes.size();
        
        dpsum.assign(n, vector<int>(s+1,-1));
        int sumtarget=maxsum(0,0);
        
        dpcnt.assign(n, vector<int>(sumtarget+1,-1));
        int cnttarget=mincnt(0,sumtarget);

        for(int i=0;i<primenum;i++){
            cout << sumtarget << " ";
            if(sumtarget==0) return ans;
            int ntarget=sumtarget-primes[i];
            if(dpcnt[i+1][ntarget]==cnttarget-1){
                ans.push_back(primes[i]);
                sumtarget=ntarget;
                cnttarget--;
            }
        }
        ans.push_back(sumtarget);
        return ans;
    }
};