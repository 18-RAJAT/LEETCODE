class Solution {
public:
    int hammingWeight(uint32_t n) {
        long long int cnt=0;
        while(n)
        {
            cnt++;
            n&=(n-1);
        }
        return cnt; 
    }
};