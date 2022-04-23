class Solution {
    string codes="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    vector<string>origURLs;
    int i=0;
    
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        origURLs.push_back(longUrl);
        int id=i;
        string shortUrl="";
        while(id>0)
        {
            shortUrl+=codes[id%62];
            id/=62;
        }
        i++;
        //cout<<"id:"<<id<<"\n";
        reverse(shortUrl.begin(), shortUrl.end());
        shortUrl="http://tinyurl.com/"+shortUrl;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortURL) {
        int id=0;
        for (int i=19; i < shortURL.length(); i++)
        {
            if ('a' <= shortURL[i] && shortURL[i] <= 'z')
              id = id*62 + shortURL[i] - 'a';
            if ('A' <= shortURL[i] && shortURL[i] <= 'Z')
              id = id*62 + shortURL[i] - 'A' + 26;
            if ('0' <= shortURL[i] && shortURL[i] <= '9')
              id = id*62 + shortURL[i] - '0' + 52;
        }
        return origURLs[id];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));