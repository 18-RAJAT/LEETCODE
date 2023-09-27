class Solution {
public:
    bool isdigit(char c)
    {
        if(c>='0' && c<='9')
        {
            return true;
        }
        return false;
    }
    string decodeAtIndex(string s, int k) {
        long long int n=s.size();
        long long int i=0;
        long long int j=0;
        long long int count=0;
        while(i<n)
        {
            if(isdigit(s[i]))
            {
                //calculate the count of the string till now
                count=count*(s[i]-'0');
            }
            else
            {
                count++;
            }
            if(count>=k)//if count==k then we have to return the character at that index
            {
                break;
            }
            i++;
        }
        j=i;
        while(j>=0)
        {
            if(isdigit(s[j]))
            {
                int ert=(s[j]-'0');
                count=count/ert;
                k%=count;
                if(k==0)
                {
                    k=count;
                }
            }
            else
            {
                if(k==count)
                {
                    return string(1,s[j]);//to convert char to string
                }
                count--;
            }
            j--;
        }
        return "";      
    }
};