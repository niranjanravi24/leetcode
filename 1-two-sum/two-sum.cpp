class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target){
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i=0; i<n; i++){
            int compli = target - nums[i];
            if(mp.find(compli)!=mp.end()){
                return {mp[compli], i};
            }
            else{
                mp[nums[i]]=i;
            }
        }
        return {-1,-1};
    
    }
    
};




    // HASH MAP
    // unordered_map<int,int> mp;

    // for(int i=0; i<nums.size(); i++){
    //     int rem = target - nums[i];

    //     if(mp.find(rem) != mp.end()){
    //         return{mp[rem],i};
    //     }
    //     else{
    //         mp[nums[i]] = i;
    //     }
    // }
    // return {-1,-1};







