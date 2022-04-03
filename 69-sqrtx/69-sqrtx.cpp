class Solution {
public:
    
    int mySqrt(int x) {
        
        long store = x;
        
        while(store * store > x)
        {
            store = (store + x/store)/2;
        }
        return store;
    }
};