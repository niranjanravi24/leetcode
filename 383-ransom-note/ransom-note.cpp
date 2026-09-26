class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> r(26,0);
        vector<int> m(26,0);
        for(int i=0; i<ransomNote.length(); i++){
            r[ransomNote[i]-'a']++;
        }
        for(int i=0; i<magazine.length(); i++){
            m[magazine[i]-'a']++;
        }
        for(int i=0; i<ransomNote.length(); i++){
            if(r[ransomNote[i]-'a'] > m[ransomNote[i]-'a']){
                return false;
            }
        }
        return true;
    }
};