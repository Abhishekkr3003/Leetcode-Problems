/*
    Time: O()
    Space: O()
    Tag:
    Difficulty:
*/

class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0, j = 0;
        int count = 1;
        for (;i < chars.size() - 1;i++) {
            if (chars[i] == chars[i + 1]) count++;
            else if (count == 1) chars[j++] = chars[i];
            else {
                chars[j++] = chars[i];
                string cnt=to_string(count);
                for(char ch:cnt) chars[j++]=ch;
                count = 1;
            }
        }
        if (count == 1) chars[j++] = chars.back();
        else {
            chars[j++] = chars.back();
            string cnt=to_string(count);
            for(char ch:cnt) chars[j++]=ch;
        }
        return j;
    }
};