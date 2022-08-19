class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int>m,endWith;
        for(int val:nums){
            m[val]++;
        }
        
        int subseq=0;
        for(int val:nums){
            if(m[val]==0)continue;
            m[val]--;
            if(endWith[val-1]>0){
                endWith[val-1]--;
                endWith[val]++;
            }
            else if(m[val+1]&&m[val+2]){
                m[val+1]--;
                m[val+2]--;
                endWith[val+2]++;
            }
            else{
                return false;
            }
        }
        return true;
    }
};