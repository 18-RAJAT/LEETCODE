class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int>cnt;
        int i,j;
        int n=fruits.size();
        for(i=0,j=0;j<n;++j)
        {
            cnt[fruits[j]]++;
            // if(cnt.size()<=2)
            // {
            //     return {};
            // }
            if(cnt.size()>2)
            {
                if(--cnt[fruits[i]]==0)
                {
                    cnt.erase(fruits[i]);
                }
                i++;
            }
        }
        return abs(i-j);
    }
};