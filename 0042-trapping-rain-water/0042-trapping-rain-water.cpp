class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1, total = 0, leftMax = 0, rightMax = 0;

        while(left < right){
            //height of left is less than or equal to right
            if(height[left] <= height[right]){  
                if(leftMax > height[left]){
                    total += leftMax - height[left];
                }
                else{
                    leftMax = height[left];
                }
                left++;
            }
            else{
                if(rightMax > height[right]){
                    total += rightMax - height[right];
                }
                else{
                    rightMax = height[right];
                }
                right--;
            }
        }
        return total;
    }
};