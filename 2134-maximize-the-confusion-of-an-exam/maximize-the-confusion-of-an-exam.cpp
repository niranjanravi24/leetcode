class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.length();
        int l=0; int r=0;
        int tCount=0; int fCount=0;
        int maxi = 0;
        while(r<n){
            if(answerKey[r]=='T'){
                tCount++;
            }
            else{
                fCount++;
            }
            while(min(tCount,fCount)>k){
                if(answerKey[l]=='T'){
                    tCount--;
                }
                else{
                    fCount--;
                }
                l++;
            }
            maxi = max(maxi, tCount+fCount);
            r++;
        }
        return maxi;
    }
};