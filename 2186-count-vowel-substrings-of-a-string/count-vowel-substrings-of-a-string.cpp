class Solution {
    bool isVowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    int countVowelSubstrings(string word) {
        int count = 0;
        int n = word.size();
        for(int i=0; i<n; i++){
            unordered_set<char> seen;
            for(int j=i; j<n; j++){
                if(!isVowel(word[j])){
                    break;
                }
                seen.insert(word[j]);
                if(seen.size()==5){
                    count++;
                }
            }
        }
        return count;
    }
};