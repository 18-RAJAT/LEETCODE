class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0){return 1;}
        int x=floor(log(n)/log(2))+1;
        int y=(1<<x)-1;
        int result=n^y;
        return result;
    }
};