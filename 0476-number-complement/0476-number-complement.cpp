class Solution {
public:
    int findComplement(int num) {
        return ~num&((unsigned int)1<<(int)log2(num)+1)-1;
    }
};
