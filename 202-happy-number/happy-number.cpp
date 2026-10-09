class Solution {
public:
    int getNextNumber(int n){
        int newNum = 0;
        while(n>0){
            int digit = n%10;
            newNum += digit*digit;
            n = n/10;
        }
        return newNum;
    }
    bool isHappy(int n) {
        unordered_set<int> visit;

        while(visit.find(n)==visit.end()){
            visit.insert(n);
            n = getNextNumber(n);
            if(n==1) return true;
        }

        return false;

            

    }
};