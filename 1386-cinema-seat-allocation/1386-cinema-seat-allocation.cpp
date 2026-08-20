class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,set<int>> seats;

        for(auto v:reservedSeats){
            seats[v[0]].insert(v[1]);
        }

        int ans=0;
        ans+=(n-seats.size())*2;
        for(auto &it:seats){
            set <int> s=it.second;
            int p1=0,p2=0,p3=0;
            if(s.find(2)==s.end() && s.find(3)==s.end() && s.find(4)==s.end() && s.find(5)==s.end()){
                p1=1;
            }
            if(s.find(4)==s.end() && s.find(5)==s.end() && s.find(6)==s.end() && s.find(7)==s.end()){
                p2=1;
            }
            if(s.find(6)==s.end() && s.find(7)==s.end() && s.find(8)==s.end() && s.find(9)==s.end()){
                p3=1;
            }

            int k=p1+p2+p3;
            if(k==3) ans+=2;
            else if(k==0) continue;
            else ans++;
        }

        return ans;
    }
};