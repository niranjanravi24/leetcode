class RandomizedSet {
public:
    unordered_map<int,int> mp;
    vector<int> arr;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
     if(mp.find(val)==mp.end()){
        arr.push_back(val);
        mp[val] = arr.size()-1;
        return true;
     }
     return false;   
    }
    
    bool remove(int val) {
        int ind = 0;
      if(mp.find(val)!=mp.end()){
        ind = mp[val];
        swap(arr[ind],arr.back());
        mp[arr[ind]] = ind;
        arr.pop_back();
        mp.erase(val);
        return true;
      }  
      return false;
    }
    
    int getRandom() {
        int ran = rand()%arr.size();
        return arr[ran];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */