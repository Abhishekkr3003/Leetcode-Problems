class Solution {
    static bool comp(string s1, string s2)
    {
        return s1.length()>s2.length();
    }
public:
    int minimumLengthEncoding(vector<string>& words) {
        string s;
        sort(words.begin(), words.end(), comp);
        vector<int>indices;
        s+=words[0];
        s+="#";
        int flag=1;
        indices.push_back(s.size());
        for(int i=1;i<words.size();i++)
        {
            //cout<<words[i]<<"\n";
            for(auto sizes: indices)
            {
                flag=1;
                //cout<<s<<" : "<<sizes<<" "<<sizes-1-words[i].length()<<"\n";
                if(sizes-1>=words[i].length())
                {
                    if(s.compare(sizes-1-words[i].length(), words[i].length(), words[i])==0)
                    {
                        flag=0;
                        break;
                    }
                }
            }
            if(flag)
            {
                s+=words[i];
                s+="#";
                indices.push_back(s.size());
            }
            
        }
        //cout<<s<<"\n";
        return s.length();
    }
};