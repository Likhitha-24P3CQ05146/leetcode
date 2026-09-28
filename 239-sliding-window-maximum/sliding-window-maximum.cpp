class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans;
        // First window
        for (int i = 0; i < k; i++) {
            while (!q.empty() && nums[q.back()] < nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        ans.push_back(nums[q.front()]);
        // Remaining windows
        for (int i = k; i < nums.size(); i++) {
            // Remove element outside the window
            if (q.front() == i - k) {
                q.pop_front();
            }
            // Remove smaller elements
            while (!q.empty() && nums[q.back()] < nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
            // Maximum is always at front
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};