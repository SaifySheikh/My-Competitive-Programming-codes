#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int numberOfSubstrings(string s) {
    int l = 0;
    int r = 0;
    int n = s.size();
    int cnt = 0;
    unordered_map<char, int> map = {{'a', 0}, {'b', 0}, {'c', 0}};
    
    while (r < n) {
        map[s[r]]++;
        while (map['a'] > 0 && map['b'] > 0 && map['c'] > 0) {
            cnt += n - r;
            map[s[l]]--;
            l++;
        }
        r++;
    } 
    return cnt;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;
    int result = numberOfSubstrings(input);
    cout << "The number of substrings containing 'a', 'b', and 'c' is: " << result << endl;
    return 0;
}
