class Solution {
public:
    int trailingZeroes(int n) {
        int answer=0;
        int i=5;
        while(n>=i)
        {
            answer+=(n/i);
            i*=5;
        }
        return answer;
    }
};