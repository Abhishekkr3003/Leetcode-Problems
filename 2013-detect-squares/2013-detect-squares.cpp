/* 
    Time: O()
    Space: O()
    Tag: 
    Difficulty: 
*/

class DetectSquares {
    unordered_map<int, unordered_map<int, int>> coord;

public:
    DetectSquares() {
        coord.clear();
    }

    void add(vector<int> point) {
        coord[point[1]][point[0]]++;
    }

    int count(vector<int> point) {
        int res = 0;
        for (auto &pair : coord[point[1]]) {
            int dist = abs(pair.first - point[0]);
            if(dist==0) continue;
            if (coord.find(point[1] + dist) != coord.end()) {
                if (coord[point[1] + dist].find(pair.first) != coord[point[1] + dist].end() && coord[point[1] + dist].find(point[0]) != coord[point[1] + dist].end()) {
                    res += coord[point[1]][pair.first] * coord[point[1] + dist][point[0]] * coord[point[1] + dist][pair.first];
                }
            }
            if (coord.find(point[1] - dist) != coord.end()) {
                if (coord[point[1] - dist].find(pair.first) != coord[point[1] - dist].end() && coord[point[1] - dist].find(point[0]) != coord[point[1] - dist].end()) {
                    res += coord[point[1]][pair.first] * coord[point[1] - dist][point[0]] * coord[point[1] - dist][pair.first];
                }
            }
        }
        return res;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */