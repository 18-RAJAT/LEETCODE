class Solution {
public:
    bool Symmetric(int num)
    {
        string ss=to_string(num);
        int n = ss.length();
        if(n%2!=0)
        {
            return false;
        }
        int LS=0,RS=0;
        for(int i=0;i<n/2;++i)LS+=ss[i]-'0',RS+=ss[n-i-1]-'0';
        return LS==RS?1:0;
    }
    int countSymmetricIntegers(int low, int high) {
        int count=0;
        for(int i=low;i<=high;++i)
        {
            if(Symmetric(i))count++;
        }
        return count;
    }
};