class Solution {
public:
    int smallestNumber(int n) {
        int m=0;
        while((1<<m)-1<n)m++;
        return (1<<m)-1;
    }
};