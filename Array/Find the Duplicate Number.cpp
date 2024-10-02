class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,bool>mp;
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            if(!mp[nums[i]]){
                mp[nums[i]]=true;
            }
            else{
                ans = nums[i];
            }
        }
        return ans;
    }
};