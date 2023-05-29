class ParkingSystem {
    vector<int>a;
public:
    ParkingSystem(int big, int medium, int small) {
        a={big,medium,small};
    }
    
    bool addCar(int carType) {
        if(a[carType-1]>0)
        {
            a[carType-1]--;
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */