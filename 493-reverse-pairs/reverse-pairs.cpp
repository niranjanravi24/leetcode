class Solution {

    void merge(vector<int>& arr, int low, int mid, int high) {
        // Create temp arrays
        vector<int> temp;
        int left = low, right = mid + 1;

        // Merge two sorted halves
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right])
                temp.push_back(arr[left++]);
            else
                temp.push_back(arr[right++]);
        }

        // Copy remaining elements from left half
        while (left <= mid)
            temp.push_back(arr[left++]);

        // Copy remaining elements from right half
        while (right <= high)
            temp.push_back(arr[right++]);

        // Copy sorted elements back to original array
        for (int i = low; i <= high; i++)
            arr[i] = temp[i - low];
    }
    int countPairs(vector<int>& nums, int low, int mid, int high){
        int right = mid+1;
        int cnt = 0;
        for(int i=low; i<=mid; i++){
            while(right<=high && (long long)nums[i]>2LL*nums[right]) right++;
            cnt += (right-(mid+1));
        }
        return cnt;
    }

    // Recursive merge sort function
    int mergeSort(vector<int>& nums, int low, int high) {
        int cnt = 0;
        if (low >= high)
            return cnt;

        // Find the middle index
        int mid = (low + high) / 2;

        // Recursively sort left half
        cnt+=mergeSort(nums, low, mid);

        // Recursively sort right half
        cnt+=mergeSort(nums, mid + 1, high);

        cnt+=countPairs(nums,low,mid,high);

        // Merge the two sorted halves
        merge(nums, low, mid, high);
        return cnt;
    }
public:
    int reversePairs(vector<int>& nums) {
       return mergeSort(nums,0,nums.size()-1); 
    }
};