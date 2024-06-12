#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longestOnes(vector<int>& nums, int k) {
    int l = 0;
    int r = 0;
    int n = nums.size();
    int maxlen = 0;
    int zeros = 0;
    while (r < n) {
        if (nums[r] == 1) {
            int len = r - l + 1;
            maxlen = max(maxlen, len);
        } else {
            while (zeros >= k) {
                if (nums[l] == 0) zeros--;
                l++;
            }
            if (zeros < k) {
                zeros++;
                int len = r - l + 1;
                maxlen = max(maxlen, len);
            }
        }
        r++;
    }
    return maxlen;
}

int main() {
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    int result = longestOnes(nums, k);
    cout << "The longest subarray with at most " << k << " zeros is: " << result << endl;
    return 0;
}
