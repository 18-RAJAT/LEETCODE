class Spreadsheet {
    unordered_map<string,int>mp;
public:
    Spreadsheet(int rows) {
        
    }
    
    void setCell(string cell, int value) {
        mp[cell]=value;
    }
    
    void resetCell(string cell) {
        mp.erase(cell);
    }
    
    int getValue(string formula) {
        int pos=formula.find('+');
        string c1=formula.substr(1,pos-1),c2=formula.substr(pos+1);
        int v1=isalpha(c1[0])?(mp.count(c1)?mp[c1]:0):stoi(c1);
        int v2=isalpha(c2[0])?(mp.count(c2)?mp[c2]:0):stoi(c2);
        return v1+v2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */