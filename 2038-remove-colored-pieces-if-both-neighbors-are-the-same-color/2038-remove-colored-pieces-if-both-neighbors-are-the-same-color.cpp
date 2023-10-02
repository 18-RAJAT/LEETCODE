class Solution {
public:
    bool winnerOfGame(string colors) {
        int n=colors.size();
        int a=0,b=0;
        for(int i=0;i<n;++i)
        {
            if(colors[i]=='A')
            {
                int cnt=0;
                while(i<n && colors[i]=='A')//multiple consecutive A's are counted as one A
                {
                    cnt++;
                    i++;
                }
                a+=max(cnt-2,(0));//cnt-2 because we are not counting the first and last element in the array
            }
            if(colors[i]=='B')
            {
                int cnt=0;
                while(i<n && colors[i]=='B')//multiple consecutive B's are counted as one B
                {
                    cnt++;
                    i++;
                }
                b+=max(cnt-2,(0));
            }
            i--;
        }
        return a>b?true:false;
    }
};