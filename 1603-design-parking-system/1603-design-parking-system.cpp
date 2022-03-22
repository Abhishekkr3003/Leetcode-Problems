class ParkingSystem {
    int parkingLot[4];
public:
    ParkingSystem(int big, int medium, int small) {
        parkingLot[1]=big;
        parkingLot[2]=medium;
        parkingLot[3]=small;
    }
    
    bool addCar(int carType) {
        if(parkingLot[carType]){
            parkingLot[carType]--;
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