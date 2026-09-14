class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int width=min(rec2[2],rec1[2])-max(rec2[0],rec1[0]);
        int height=min(rec2[3],rec1[3])-max(rec2[1],rec1[1]);
        return (width>0 && height>0);
    }
};