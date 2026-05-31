class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for (const string& s : strs) {
            // Append length, followed by our '#' delimiter, followed by the string
            encoded += to_string(s.size()) + "#" + s;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            // 1. Scan forward to find the delimiter
            while (s[j] != '#') {
                j++;
            }
            
            // 2. Extract the integer length (from i up to j)
            int length = stoi(s.substr(i, j - i));
            
            // 3. Extract the actual string (starting right after '#')
            string str = s.substr(j + 1, length);
            result.push_back(str);
            
            // 4. Move the main pointer i to the start of the next chunk
            i = j + 1 + length;
        }
        return result;
    }
};
