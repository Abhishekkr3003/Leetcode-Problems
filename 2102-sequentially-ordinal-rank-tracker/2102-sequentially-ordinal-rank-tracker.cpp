/*
    Time: O()
    Space: O()
    Tag:
    Difficulty:
*/

class Compare1
{
public:
    bool operator()(pair<int,string>&a, pair<int,string>&b){
        if(a.first==b.first) return a.second>b.second;
        return a.first<b.first;
    }
};

class Compare2
{
public:
    bool operator() (pair<int,string>&a,pair<int,string>&b){
        if(a.first==b.first) return a.second<b.second;
        return a.first>b.first;
    }
};

class SORTracker {
  
    priority_queue<pair<int, string>,vector<pair<int, string>>, Compare1>mainQ;
    priority_queue < pair<int, string>, vector<pair<int, string>>, Compare2>visited;

public:
    SORTracker() {
        visited.push({ INT_MAX,"" });
    }

    void add(string name, int score) {
        if (visited.top().first<score ||( visited.top().first==score ) &&(visited.top().second>name)) {
            mainQ.push(visited.top());
            visited.pop();
            visited.push(make_pair(score, name));
        }
        else {
            mainQ.push(make_pair(score, name));
        }
        // cout<<mainQ.top().second<<" "<<visited.top().second<<endl;
    }

    string get() {
        visited.push(mainQ.top());
        string res = mainQ.top().second;
        mainQ.pop();
        // cout<<"Get -> "<<mainQ.top().second<<" "<<visited.top().second<<endl;
        return res;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */