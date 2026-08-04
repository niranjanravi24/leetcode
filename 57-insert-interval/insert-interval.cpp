class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> newArr;
        int n = intervals.size();
        for(int i=0; i<n; i++){
            if(!newArr.empty()){
                if((newArr.back()[1] >= intervals[i][0]) && (newArr.back()[1]<=intervals[i][1])){
                    newArr.back()[1] = intervals[i][1];
                    continue;
                }
                else if(newArr.back()[1]>=intervals[i][0] && newArr.back()[1]>=intervals[i][1]){
                    continue;
                }
        
            } 
            newArr.push_back(intervals[i]);  
        }
        return newArr;

    }
};