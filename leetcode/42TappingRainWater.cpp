class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> max_from_left(height.size(), 0);
        vector<int> max_from_right(height.size(), 0);

        int left = height[0];
        int right = height[height.size()-1];

        for(int i=1;i<height.size();i++){
            max_from_left[i] = left;
            max_from_right[height.size()-1-i] = right;

            if (left < height[i]) left = height[i];
            if (right < height[height.size()-1-i]) right = height[height.size()-1-i];
        }

        int water = 0;

        for(int i=0;i<height.size();i++){
            water += max(min(max_from_left[i], max_from_right[i])-height[i], 0);
        }

        return water;
    }
};
