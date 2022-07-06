/* 
    Time: O()
    Space: O()
    Tag: 
    Difficulty: 
*/

class MKAverage {
    map<int, int> mp1, mp2, mp3;
    queue<int> q;
    int s1, s2, s3;
    int k;
    long long sum;
    int m;

    void addSet1(int num) {
        mp1[num]++;
        s1++;
    }

    void deleteSet1(int num) {
        mp1[num]--;
        if (mp1[num] == 0) mp1.erase(num);
        s1--;
    }

    void addSet2(int num) {
        mp2[num]++;
        s2++;
        sum += num;
    }

    void deleteSet2(int num) {
        mp2[num]--;
        if (mp2[num] == 0) mp2.erase(num);
        s2--;
        sum -= num;
    }

    void addSet3(int num) {
        mp3[num]++;
        s3++;
    }

    void deleteSet3(int num) {
        mp3[num]--;
        if (mp3[num] == 0) mp3.erase(num);
        s3--;
    }

public:
    MKAverage(int m, int k) {
        s1 = 0, s2 = 0, s3 = 0;
        sum = 0;
        this->k = k;
        this->m = m;
    }

    void addElement(int num) {
        if (s1 < k) {
            addSet1(num);
            q.push(num);
        } else if (s2 < (m - (2 * k))) {
            int lastEle = prev(mp1.end())->first;
            if (num >= lastEle) {
                addSet2(num);
            } else {
                deleteSet1(lastEle);
                addSet1(num);
                addSet2(lastEle);
            }
            q.push(num);
        } else if (s3 < k) {
            int last1 = prev(mp1.end())->first;
            int last2 = prev(mp2.end())->first;
            if (num >= last1 && num >= last2) {
                addSet3(num);
            } else if (num >= last1 && num < last2) {
                deleteSet2(last2);
                addSet2(num);
                addSet3(last2);
            } else {
                deleteSet2(last2);
                addSet3(last2);
                deleteSet1(last1);
                addSet2(last1);
                addSet1(num);
            }
            q.push(num);
        } else {
            int toErase = q.front();
            q.pop();
            int first3 = mp3.begin()->first;
            int first2 = mp2.begin()->first;
            int first1 = mp1.begin()->first;

            if (toErase >= first3) {
                deleteSet3(toErase);
            } else if (toErase >= first2) {
                deleteSet3(first3);
                deleteSet2(toErase);
                addSet2(first3);
            } else {
                deleteSet3(first3);
                deleteSet2(first2);
                deleteSet1(toErase);
                addSet1(first2);
                addSet2(first3);
            }
            addElement(num);
        }
    }

    int calculateMKAverage() {
        // for(auto p:mp1) cout<<p.first<<" "<<p.second<<endl;
        // cout<<"------\n";
        // for(auto p:mp2) cout<<p.first<<" "<<p.second<<endl;
        // cout<<"------\n";
        // for(auto p:mp3) cout<<p.first<<" "<<p.second<<endl;
        // cout<<"######\n";
        
        if (q.size() < m) return -1;
        return sum / (m-(2*k));
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */