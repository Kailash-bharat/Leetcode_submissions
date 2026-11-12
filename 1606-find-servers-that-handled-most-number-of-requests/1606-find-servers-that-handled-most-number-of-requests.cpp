class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        priority_queue<pair<int,int>> pq;
        set<int> st;
        vector<int> ans(k);
        for(int i=0;i<k;i++){
            st.insert(i);
        }

        for(int i=0;i<arrival.size();i++){
            int time=arrival[i];
            int wt=load[i];

            while(pq.size() && -(pq.top().first)<=time){
                int server=pq.top().second;
                pq.pop();
                st.insert(server);
            }
            if(st.size()==0) continue;

            int completion=time+wt;
            int required_server=i%k;
            auto it=st.lower_bound(required_server);
            int useful;
            if(it!=st.end()){
                useful=*it;
                st.erase(it);
            }
            else{
                useful=*st.begin();
                st.erase(st.begin());
            }

            ans[useful]++;
            pq.push({-completion,useful});
        }

        vector<int> result;
        int maxi=0;
        for(int i=0;i<k;i++){
            if(maxi<ans[i]){
                result.clear();
                maxi=ans[i];
                result.push_back(i);
            }
            else if(maxi==ans[i]){
                result.push_back(i);
            }
        }

        return result;
    }
};