class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int count=0,chk=0;
        for(auto& it:moves)
        {
            if(it=='L')count--;
            else if(it=='R')count++;
            else chk++;
        }
        return chk+abs(count);
    }
};