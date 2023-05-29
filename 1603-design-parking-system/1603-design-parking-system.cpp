class ParkingSystem {
public:
    vector<int> sm, mid, large;
    int small_count = 0, mid_count = 0, large_count = 0;
    
    ParkingSystem(int big, int medium, int small) {
        small_count = small;
        mid_count = medium;
        large_count = big;
        
        sm.clear();
        mid.clear();
        large.clear();
    }
    
    bool addCar(int carType) {
        if(carType==1){
            if(large_count > large.size()){
                large.push_back(1);
                return true;
            }
            else {
                return false;
            }
        }
        
        else if(carType == 2){
            if(mid_count > mid.size()){
                mid.push_back(1);
                return true;
            }
            else {
                return false;
            }
        }
        else if(carType == 3){
            if(small_count > sm.size()){
                sm.push_back(1);
                return true;
            }
            else return false;
        }
        
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */