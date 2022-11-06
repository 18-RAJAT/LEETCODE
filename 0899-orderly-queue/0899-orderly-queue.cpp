class Solution {
public:
    string orderlyQueue(string s, int k) {
        
        if (k==1)
        {
            int n=s.size();
            string bigstring=s+s;
            string result=s;
            for (int i=0;i<n;i++) //o(n)
            {
                string temp=bigstring.substr(i,n);
                if (temp<result) // o(n)
                {
                    result=temp; // (o(n))
                }
            }
            return result;
            
        }
        sort(s.begin(),s.end());
        return s;
    }
};