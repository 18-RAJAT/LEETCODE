class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        
            int row =m;
            int cols=n;
            for(int i=0;i<ops.size();++i)
            {
                    if(ops[i][0]<row){row=ops[i][0];}
                    //cout<<"run";
                    if(ops[i][1]<cols){cols=ops[i][1];}
            }
            return row*cols;
    }
};