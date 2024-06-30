class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<nums.size();i++){
            int j = i==0?1:0;
            int k = i==(nums.size()-1)?nums.size()-2:nums.size()-1;

            while(j < k){
                int sum = nums[i]+nums[j]+nums[k];

                if(sum == 0){
                    if (i!=k && i!=j){
                        vector<int> match = {nums[i], nums[j], nums[k]};
                        sort(match.begin(), match.end());
                        ans.insert(match);
                    }
                    j++;
                    k--;
                    while(j < k && nums[j] == nums[j-1]) j++;
                    while(j < k && nums[k] == nums[k+1]) k--;
                }
                else if(sum > 0) k--;
                else j++;
            }
        }

        vector<vector<int>> result(ans.begin(), ans.end());
        return result;
    }
};
