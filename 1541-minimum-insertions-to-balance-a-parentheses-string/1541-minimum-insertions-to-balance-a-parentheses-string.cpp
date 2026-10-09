class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        int ans=0;
        int open=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') open++;
            else{
                if(i==n-1){
                    if(open>0){
                        open--;
                        ans++;
                    }
                    else{
                        ans+=2;
                    }
                }
                else{
                    if(s[i+1]==')'){
                        i++;
                        if(open>0){
                            open--;
                        }
                        else{
                            ans++;
                        }
                    }
                    else{
                        if(open>0){
                            open--;
                            ans++;
                        }
                        else{
                            ans+=2;
                        }
                    }
                }
            }
        }
        return ans+open*2;
    }
};