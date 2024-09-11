class Solution {
public:
    int minBitFlips(int start, int goal) {
        return __builtin_popcountl(start^goal);
    }
};