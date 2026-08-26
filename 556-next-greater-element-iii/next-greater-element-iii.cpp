class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> digits;
        while(n>0){
            digits.push_back(n%10);
            n = n/10;
        }

        reverse(digits.begin(), digits.end());
        
        int size = digits.size();
        int index = -1;
        for(int i=size-2; i>=0; i--){
            if(digits[i] < digits[i+1]){
                    index = i;
                    break;
            }
        }

        if(index == -1) return -1;

        for(int i=size-1; i>=0; i--){
            if(digits[i]>digits[index]){
                swap(digits[i], digits[index]);
                break;
            }
        }

        reverse(digits.begin()+index+1, digits.end());

        long long sum = 0;
        for(int j : digits){
            sum = sum*10+j;
        }
        if(sum > INT_MAX) return -1;
        return sum;
    }
};