class Solution {
public:
    bool canAliceWin(int n) {
        if(n<10){
            return 0;
        }
        else if(n<19){
            return 1;
        }
        else if(n<27){
            return 0;
        }
        else if(n<34){
            return 1;
        }
        else if(n<40){
            return 0;
        }
        else if(n<45){
            return 1;
        }
        else if(n<49){
            return 0;
        }
        return 1;
    }
};