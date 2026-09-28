class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> pS;
        unordered_map<string, char> sP;

        int j = 0;

        for(int i = 0; i < pattern.length(); i++) {

            // If no more words are available
            if(j >= s.length())
                return false;

            char p = pattern[i];
            string sNew = "";

            // Extract current word
            while(j < s.length() && s[j] != ' ') {
                sNew += s[j];
                j++;
            }

            // pattern character -> word
            if(pS.count(p)) {
                if(pS[p] != sNew)
                    return false;
            }
            else {
                pS[p] = sNew;
            }

            // word -> pattern character
            if(sP.count(sNew)) {
                if(sP[sNew] != p)
                    return false;
            }
            else {
                sP[sNew] = p;
            }

            // Move past the space
            if(j < s.length())
                j++;
        }

        // Check for extra words
        if(j < s.length())
            return false;

        return true;
    }
};