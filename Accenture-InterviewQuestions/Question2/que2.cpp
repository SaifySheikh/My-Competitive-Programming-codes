#include <iostream>
#include <cstring>

int OperationsBinaryString(const char* str) {
    if (str == NULL) {
        return -1;
    }

    int n = strlen(str);
    if (n == 0) {
        return -1;
    }

    int result = str[0] - '0'; 

    for (int i = 1; i < n; i += 2) {
        char op = str[i];
        int nextDigit = str[i + 1] - '0';

        switch (op) {
            case 'A':
                result = result && nextDigit;
                break;
            case 'B':
                result = result || nextDigit;
                break;
            case 'C':
                result = result ^ nextDigit;
                break;
            default:
                return -1; 
        }
    }

    return result;
}

int main() {
    const char* str = "1C0C1C1A0B1";
    int result = OperationsBinaryString(str);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
