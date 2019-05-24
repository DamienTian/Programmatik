#include "../includes.h"

// ref: //ref: http://zxi.mytechroad.com/blog/dynamic-programming/leetcode-121-best-time-to-buy-and-sell-stock/

// Solution 1
// use two space to stroes DP value (minimal purchase price & maximum profit)
//  Time: O(n)
//  Space: O(1)

class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        // erase case of only one day
        if(prices.size() < 1){
            return 0;
        }
        // Stores the minimal price among the previous days
        int min_price = prices[0];
        
        // Stores the maximum profit
        int max_profit = 0;
        
        for (int i = 1; i < prices.size(); ++i){
            min_price = min(min_price, prices[i]);
            max_profit = max(max_profit, prices[i] - min_price);
        }
        
        return max_profit;
    }
};

// Solution 2
class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        // erase case of only one day
        if (prices.size() < 2){
            return 0;
        }
        
        // a memo remember the daily profit
        vector<int> gains (prices.size() - 1, 0);
        
        for (int i = 1; i < prices.size(); ++i){
            // Note: we cannot gain anything from the first day 
            //       so we starts the program from the second day
            gains[i - 1] = prices[i] - prices[i - 1];
        }
        return max(0, maxArray(gains));
    }
    
    int maxArray(vector<int> array){
        // subarray stores the maximum gain at each day
        vector<int> subarray(array.size());
        subarray[0] = array[0];
        
        // find the maximum daily gains
        for (int i = 1; i < array.size(); ++i){
            subarray[i] = max(array[i], subarray[i - 1] + array[i]);
        }
        
        return *max_element(subarray.begin(), subarray.end());
    }
};

int main(){
    cout << "娃哈哈" << endl;
    return 0;
}