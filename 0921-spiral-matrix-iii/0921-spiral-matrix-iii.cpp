class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>>ans;
        vector<int>move={rStart,cStart};
        int direction=3;
        int temp=-1;
        ans.push_back(move);
        while(ans.size()<rows*cols)
        {
            temp++,direction=(direction+1)%4;
            for(int i=0;i<(temp/2)+1;++i)
            {
                switch (direction)
                {
                    case 0:
                        move[1]++;
                        break;
                    case 1:
                        move[0]++;
                        break;
                    case 2:
                        move[1]--;
                        break;
                    case 3:
                        move[0]--;
                        break;
                }
                if (move[0]>=0 && move[0]<rows && move[1]>=0 && move[1]<cols)
                {
                    ans.push_back(move);
                }
            }
        }
        return ans;
    }
};