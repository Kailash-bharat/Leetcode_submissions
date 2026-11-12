using ll=long long;
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<tuple<ll,int,int>> used; //time(-ve),wt(-ve),ind(-ve)
        priority_queue<tuple<int,int,ll>> free; //wt(-ve),ind(-ve),time(-ve)
        for(int i=0;i<servers.size();i++){
            free.push({-servers[i],-i,0});
        }

        vector<int> ans;
        for(int i=0;i<tasks.size();i++){
            while(used.size() && -get<0>(used.top())<=i){
                auto [time,wt,ind]=used.top();
                used.pop();
                free.push({wt,ind,time});
            }
            if(free.size()==0){
                auto [time,wt,ind]=used.top();
                used.pop();
                free.push({wt,ind,time});
            }

            auto [wt,ind,time]=free.top();
            free.pop();

            time=max(-time,(ll)i)+tasks[i]; //don't miss this max condition
            ans.push_back(-ind);
            used.push({-time,wt,ind});
        }
        return ans;
    }
};