#include <vector>

class Solution {
public:
    int trap(std::vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int leftMax = INT_MIN;
        int rightMax = INT_MIN;
        int result = 0;
        while (left < right) {
            leftMax = std::max(leftMax, height[left]);
            rightMax = std::max(rightMax, height[right]);
            result += (leftMax < rightMax) ? leftMax - height[left++] : rightMax - height[right--];
        }
        return result;
    }
};


int main() {
    Solution sl;
    std::vector<int> height = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
    sl.trap(height);

    return 0;
}

//Given n non - negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
//
//Example 1:
//
//Input: height = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
//Output : 6
//Explanation : The above elevation map(black section) is represented by array[0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1].In this case, 6 units of rain water(blue section) are being trapped.
//
//Example 2:
//
//Input: height = [4, 2, 0, 3, 2, 5]
//Output : 9
//
//Constraints:
//
//n == height.length
//1 <= n <= 2 * 10^4
//0 <= height[i] <= 10^5