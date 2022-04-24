class UndergroundSystem {
    map<pair<string, string>, pair<int, int>>db;
    unordered_map<int, pair<string, int>>current;
    pair<int, int> p;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        current[id]={stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        if(db.find({current[id].first, stationName})==db.end())
        {
            db[{current[id].first, stationName}]={t-current[id].second, 1};
        }
        else
        {
            p=db[{current[id].first, stationName}];
            db[{current[id].first, stationName}]={p.first+(t-current[id].second), ++(p.second)};
        }
        current.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        p=db[{startStation, endStation}];
        return (double)p.first/p.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */