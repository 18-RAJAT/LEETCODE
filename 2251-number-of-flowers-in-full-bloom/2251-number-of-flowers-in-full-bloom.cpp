class Solution {
public:
    void build(int index,int low,int high,int l,int r,int key,map<int,int>&segment)
    {
        if(l>high || r<low)
        {
            return;
        }
        if(l<=low && r>=high)
        {
            segment[index]+=key;
            return;
        }
        int mid=low+(high-low)/2;
        build(2*index+1,low,mid,l,r,key,segment);//left child
        build(2*index+2,mid+1,high,l,r,key,segment);//right child
    }
    void query(int index,int low,int high,int i,int &ans,map<int,int>&segment)
    {
        if(segment.find(index)!=segment.end())//if the index is present in the map
        {
            ans+=segment[index];
        }
        if(low==high)
        {
            return ;
        }
        int mid=low+(high-low)/2;
        if(i<=mid)
        {
            query(2*index+1,low,mid,i,ans,segment);
        }
        else
        {
            query(2*index+2,mid+1,high,i,ans,segment);
        }
    }
    /*
        Approach:
        1. Build a segment tree with the range of days as the range of the segment tree
        2. For each flower, update the segment tree with the value 1
        3. For each person, query the segment tree with the position of the person

        Time Complexity: O(nlogn)
        Space Complexity: O(n)
    */
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int,int>segment;
        int end=1e9;
        end--;
        for(int i=0;i<flowers.size();++i)
        {
            // cout<<flowers[i][0]<<" "<<flowers[i][1]<<endl;
            int x=flowers[i][0];//day
            int y=flowers[i][1];//position
            build(0,0,end,x-1,y-1,1,segment);
        }
        vector<int>ans;
        for(int i=0;i<people.size();++i)
        {
            int x=people[i];
            x--;//position
            int res=0;
            query(0,0,end,x,res,segment);//res is the number of flowers that have bloomed
            ans.push_back(res);
        }
        return ans;
    }
};