class Solution {
public:
    string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890";
    int n = s.size();
    unordered_map<string, string> m;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string code = "";
        int size = 6;
        while(size--){
            code.push_back(s[rand()%(n-1)]);
        }
        m[code] = longUrl;
        return code;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return m[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));