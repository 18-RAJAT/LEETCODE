class Robot {
public:
    vector<vector<int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
    int X,Y;
    int row,col,ok;
    Robot(int width, int height) {
        row=height;
        col=width;
        X=0,Y=0,ok=0;
    }
    
    void step(int num) {
        int per=2*(row+col-2);
        num%=per;
        if(num==0 && X==0 && Y==0)
        {
            ok=3;
        }
        while(num--)
        {
            int res=X+dir[ok][0],res1=Y+dir[ok][1];
            if(res>=0 && res1>=0 && res<row && res1<col)
            {
                X=res;
                Y=res1;
            }
            else
            {
                ok=(ok+1)%4;
                X=X+dir[ok][0];
                Y=Y+dir[ok][1];
            }
        }
    }
    
    vector<int> getPos() {
        return {Y,X};
    }
    
    string getDir() {
        vector<string>ar={"East","North","West","South"};
        return ar[ok];
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */