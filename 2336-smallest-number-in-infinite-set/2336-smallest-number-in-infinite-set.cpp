typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
#define ff(a,b) for(int i=a;i<b;i++)

class SmallestInfiniteSet {
public:
    SETI st;
    // priority_queue<int,vector<int>,greater<int>>pq;
    SmallestInfiniteSet() {
        st.clear();        
        for(int i=1;i<=1000;++i)//{pq.push(i);st.insert(i);}
            st.insert(i);
    }
    
    int popSmallest() {
        // int tp=*st.begin();st.erase(*st.begin());return tp;
    // int tp=pq.top();pq.pop();st.erase(st.find(tp));return tp;
        int tp=*st.begin();st.erase(st.begin());return tp;
    }
    
    void addBack(int num) {
        // if(st.find(num)==st.end()){st.insert(num);pq.push(num);}
        st.insert(num);
    }
};
/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */