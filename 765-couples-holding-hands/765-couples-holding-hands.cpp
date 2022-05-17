class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int ct=0;
            unordered_map<int,int>m;
            //Traverse
            for(int i=0;i<row.size();++i){m[row[i]]=i;}
            //Two step further traverse to find the pattern of (n,n+1)......(2n-2,2n-1)
            for(int i=0;i<row.size();i+=2)
            {
                    int first=row[i];
                    int second=first+(first%2==0?1:-1);
                    if(row[i+1]!=second)
                    {
                            ct++;
                            int tp=row[i+1];
                            swap(row[i+1],row[m[second]]);
                            m[tp]=m[second];
                            m[second]=i+1;
                    }
            }
            return ct;
    }
};