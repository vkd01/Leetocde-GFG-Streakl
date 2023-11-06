class SeatManager {
public:
    
    set<int> seats, booked;
     
    
    SeatManager(int n) {
        for(int i = 1;i<=n;i++) seats.insert(i);
    }
    
    int reserve() {
        int x = *seats.begin();
        
        booked.insert(x);
        
        seats.erase(*seats.begin());
        
        return x;
    }
    
    void unreserve(int seatNumber) {
        auto x = booked.find(seatNumber);
        
        seats.insert(*x);
        booked.erase(x);
        
       
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */