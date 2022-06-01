// bool compare(vector<int>&a,vector<int>&b)
// {
//         return a[1]<b[1];
// }

class Solution {
public:
    int minCostToMoveChips(vector<int>& pos) {
        int chip1=0;
        int chip2=0;
            for(int i=0;i<pos.size();++i)
            {
                    if(pos[i]%2==0){chip1++;}
                    else{chip2++;}
            }
            return min(chip1,chip2);
    }
};