class Solution {
public:
    char kthCharacter(int k) {
        int c=0;
        while(k>1)
        {
            int res=1;
            while(2*res<k)res*=2;
            if(res<k)
            {
                k-=res,c++;
            }
            else break;
        }
        return (char)('a'+(c%26));
    }
};