#include <iostream>

class Solution{
public:
    std::string longestPalindrome(std::string s){
        if (s == ""){
            return "";
        }
        const int size = s.length();
        bool mem[size][size];

        memset(mem, 0, sizeof(mem));

        // length of 1
        for (int i = 0; i < size; ++i){
            mem[i][i] = true;
        }

        int start = 0;
        int max_length = 1;

        // length of 2
        for (int i = 0; i < size - 1; ++i){
            if (s[i] == s[i+1]){
                mem[i][i+1] = true;
                start = i;
                max_length = 2;
            }
        }

        for (int current_length = 3; current_length <= size; ++current_length){
            for (int i = 0; i <= size - current_length; ++i){
                int j = current_length + i - 1;

                if(s[i] == s[j] && mem[i+1][j-1]){
                    mem[i][j] = true;
                }

                if (current_length > max_length){
                    start = i;
                    max_length = current_length;
                }
            }
        }

        std::string result = "";

        for (int i = start; i <= start + max_length; ++i){
            result += s[i];
        }

        return result;
    }
};

int main(){
    Solution solution;
    std::string s = "a";
    std::cout << solution.longestPalindrome(s) << std::endl;
}