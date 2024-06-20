class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int left=1,right=position.back()-position.front();
        while(left<right)
        {
            int mid=right-(right-left)/2;
            (canPlace(position,m,mid))?left=mid:right=mid-1;
        }
        return left;
    }

private:
    bool canPlace(vector<int>& position, int m, int minDist) {
        int count=1,lastPlaced=position[0];
        for(int i=1;i<position.size();++i)
        {
            if(position[i]-lastPlaced>=minDist)
            {
                count++;
                lastPlaced=position[i];
                if(count==m)return true;
            }
        }
        return false;
    }
};