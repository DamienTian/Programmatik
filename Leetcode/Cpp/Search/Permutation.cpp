// ref: https://zxi.mytechroad.com/blog/searching/leetcode-39-combination-sum/

#include "../includes.h"

using namespace std;

// 使用花花 Leetcode 讲义制作排列函数
class Permutation
{
public:
    Permutation() {}
    ~Permutation() {}

    vector<vector<int>> permutation(vector<int> nums, int numOfPer);
    void helper(vector<int> nums, int numOfPer, int depth, vector<bool> &used, vector<int> &current, vector<vector<int>> &result);

private:
    
};

vector<vector<int>> Permutation::permutation(vector<int> nums, int numOfPer)
{
    cout << "Call this" << endl;
    int n = nums.size();
    vector<bool> used(false, n);
    vector<vector<int>> result;
    vector<int> c;
    helper(nums, numOfPer, 0, used, c, result);
    cout << "End this" << endl;
    return result;
}

void Permutation::helper(vector<int> nums, int numOfPer, int depth, vector<bool>& used, vector<int>& current, vector<vector<int> >& result)
{
    if (depth == numOfPer)
    {
        result.push_back(current);
        return;
    }
    else{
        cout << "wo ri ni ma yo" << endl;
    }

    for (int i = 0; i < nums.size(); ++i)
    {
        // 若该位使用过则跳过
        if (used[i])
            continue;

        used[i] = true;
        current.push_back(nums[i]);
        cout << "Insert " << nums[i] << endl;
        helper(nums, numOfPer, depth + 1, used, current, result);
        current.pop_back();

        // 将 Used[i] 还原
        used[i] = false;
    }
}

void printVector(std::vector<int> res, std::string message)
{
    for (int j = 0; j < res.size(); ++j)
    {
        std::cout << res[j] << "\t";
    }
    std::cout << message <<"\n";
}

int main()
{
    // vector<int> nums{1, 2, 3};
    std::vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);

    Permutation p;

    if(nums.empty()){
        cout << "The vector is empty." << endl;
        return 0;
    }

    vector<vector<int>> r = p.permutation(nums, 3);
    for (int i = 0; i < r.size(); ++i)
    {
        vector<int> res = r[i];
        printVector(res, "");
    }

    return 0;
}