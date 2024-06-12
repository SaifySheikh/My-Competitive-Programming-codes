#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.size();
    int l = 0;
    int r = 0;
    int len = 0;
    vector<int> hash(256, -1);
    int maxlen = 0;
    while (r < n) {
        if (hash[s[r]] != -1) {
            if (l <= hash[s[r]]) l = hash[s[r]] + 1;
        }
        len = r - l + 1;
        maxlen = max(maxlen, len);    
        hash[s[r]] = r;
        r++;
    }
    return maxlen;
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);
    int result = lengthOfLongestSubstring(input);
    cout << "The length of the longest substring without repeating characters is: " << result << endl;
    return 0;
}
