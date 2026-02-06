class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> userMp;
    unordered_map<string, pair<int ,int>> distance;

    UndergroundSystem() {
        userMp = unordered_map<int, pair<string, int>>();
        distance = unordered_map<string, pair<int ,int>> ();
    }
    
    void checkIn(int id, string stationName, int t) {
        userMp[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto [startStation, time] = userMp[id];
        string start_end = startStation+"->"+stationName;
        auto [total, cnt] = distance[start_end];
        distance[start_end] = {total+(t-time), cnt+1};
    }
    
    double getAverageTime(string startStation, string endStation) {
        string start_end = startStation+"->"+endStation;
        auto [time, cnt] = distance[start_end];
        return (double)time/cnt;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */