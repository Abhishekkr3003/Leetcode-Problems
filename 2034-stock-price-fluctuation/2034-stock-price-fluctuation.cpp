/* 
    Time: O()
    Space: O()
    Tag: 
    Difficulty: 
*/

class StockPrice {
    unordered_map<int, int> prices;
    set<pair<int, int>> inc, dec;
    int latest = 0;
    int maxi = 0;
    int mini = 0;

public:
    StockPrice() {
    }

    void update(int timestamp, int price) {
        if (prices.find(timestamp) != prices.end()) {
            inc.erase({prices[timestamp], timestamp});
            dec.erase({-prices[timestamp], timestamp});
        }
        prices[timestamp] = price;
        inc.insert({prices[timestamp], timestamp});
        dec.insert({-prices[timestamp], timestamp});
        latest = max(latest, timestamp);
        maxi = -(dec.begin()->first);
        mini = inc.begin()->first;
    }

    int current() {
        return prices[latest];
    }

    int maximum() {
        return maxi;
    }

    int minimum() {
        return mini;
    }
};


/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */