class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>res;
        int i=0, n=words.size();
        while(i<n)
        {
            int j=i, len=0;
            while(j<n && len+words[j].size()+j-i<=maxWidth)
                len+=words[j++].size();
            string out;
            int space=maxWidth-len;
            for(int k=i; k<j; k++)
            {
                out+=words[k];
                if(space>0)
                {
                    int tmp;
                    if(j==n) // last line
                    {
                        if(j-k==1) tmp=space;
                        else tmp=1;
                    }
                    else
                    {
                        if(j-k-1>0)
                        {
                            if(space%(j-k-1)==0) tmp=space/(j-k-1);
                            else tmp=space/(j-k-1)+1;
                        }
                        else tmp=space;
                    }
                    out.append(tmp, ' ');
                    space-=tmp;
                }
            }
            res.push_back(out);
            i=j;
        }
        return res;
    }
};