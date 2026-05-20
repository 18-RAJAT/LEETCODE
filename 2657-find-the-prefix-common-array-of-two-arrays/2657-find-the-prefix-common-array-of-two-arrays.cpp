class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A,vector<int>& B) {
        int n=A.size(),count=0;
        vector<int>ans;
        unordered_map<int,int>frequency;
        for(int i=0;i<n;++i)
        {
            frequency[A[i]]++;
            frequency[B[i]]++;
            if(A[i]==B[i] && frequency[A[i]]==2)count++;
            else
            {
                if(frequency[A[i]]==2)count++;
                if(frequency[B[i]]==2)count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};