class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0,j=0;
        int sza=chars.size();
        while(i<sza)
        {
            int cnt=1;
            while(i+1<sza and chars[i]==chars[i+1])
            {
                cnt++;i++;
            }
            if(cnt==1)
            {
                chars[j++]=chars[i];
            }
            else
            {
                chars[j++]=chars[i];
                string S=to_string(cnt);
                for(int k=0;k<S.size();++k)
                {
                    chars[j++]=S[k];
                }
            }
            i++;
        }
        return j;
    }
};