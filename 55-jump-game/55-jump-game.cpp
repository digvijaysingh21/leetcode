class Solution {
public:
    bool canJump(vector<int>& nums) {
        int N = nums.size()-1;
         for(int i= nums.size() -1; i>=0; i--){
        if(nums[i] + i >= N)
        N = i;
    }
    if(N == 0) return true;
     else return false;
        
    }
};