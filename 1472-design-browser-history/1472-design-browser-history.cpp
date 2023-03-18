class BrowserHistory {
public:
    string his[1001];
    int idx=0,end=0,jo=0;
    
    BrowserHistory(string homepage) {
        his[idx]=homepage;
    }
    
    void visit(string url) {
        his[++idx]=url;
        end=idx;
    }
    
    string back(int steps) {
        int db=idx-steps;
        idx=max(db,jo);
        return his[idx];
    }
    
    string forward(int steps) {
        int ert=idx+steps;
        idx=min(ert,end);
        return his[idx];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */