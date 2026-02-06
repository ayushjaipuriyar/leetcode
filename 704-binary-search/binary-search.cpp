class Solution {
public:
    int search(vector<int>& nums, int target) {
        int f = 0;
        int l = nums.size() - 1;
        int middle = (f+l)/2;
        while(f<=l){
            if (nums[middle] == target)
                return middle;
            else if (target > nums[middle])
                f = middle + 1;
            else
                l = middle -1;
            middle = (f+l)/2;
        }
        return -1;
    }
};