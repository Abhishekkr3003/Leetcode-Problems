/*
    Time: O()
    Space: O()
    Tag:
    Difficulty:
*/

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int counter = 0;
        int i = 0, j = people.size() - 1;
        while (i <= j)
        {
            counter++;
            if (limit - people[j] >= people[i]) {
                i++, j--;
            }
            else j--;
        }
        return counter;
    }
};