class ProductOfNumbers {
    vector<int>pref;
public:
    ProductOfNumbers() {
        pref={1};
    }
    
    void add(int num) {
        if(num==0)pref={1};
        else pref.push_back(pref.back()*num);
    }
    
    int getProduct(int k) {
        int n=pref.size();
        return k>=n?0:pref.back()/pref[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */