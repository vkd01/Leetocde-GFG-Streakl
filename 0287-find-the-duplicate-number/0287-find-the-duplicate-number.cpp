class Solution {
public:
   int findDuplicate(vector<int>& nums) {
    int slow = nums[0];
    int fast = nums[0];

    // Find the meeting point
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    // Reset one pointer to the beginning
    slow = nums[0];

    // Find the start of the cycle
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    // The meeting point is the start of the cycle, which is the repeated number
    return slow;
}

};