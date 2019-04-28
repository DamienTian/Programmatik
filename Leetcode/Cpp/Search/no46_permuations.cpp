#include <iostream>
#include <vector>
#include <algorithm>    // std::swap

void printVector(std::vector<int> res, std::string message);

class Solution1
{
public:
    std::vector<std::vector<int> > permute(std::vector<int> &num)
    {
        std::vector<std::vector<int> > res;
        std::vector<int> out, visited(num.size(), 0);
        permuteDFS(num, visited, out, res);
        return res;
    }
    void permuteDFS(std::vector<int> &num, std::vector<int> &visited, std::vector<int> &out, std::vector<std::vector<int> > &res)
    {
        if (out.size() == num.size())
        {
            printVector(out, "*** Return");
            res.push_back(out);
            // std::cout << "Number of results: " << res.size() << std::endl;
            return;
        }
        for (int i = 0; i < num.size(); ++i)
        {
            if (visited[i] == 1)
                // std::cout << "current index: " << i << std::endl;
                continue;
            visited[i] = 1;
            out.push_back(num[i]);

            printVector(out, "Searching...");
            printVector(visited, "[Visited]");
            permuteDFS(num, visited, out, res);

            // after return, pop the last element out from the output
            //  and search element in the list that has not been found.
            out.pop_back();
            visited[i] = 0;
        }
    }
};

class Solution2{
    public:
    std::vector<std::vector<int> > permute(std::vector<int> &num){
        std::vector<std::vector<int> > result;
        permuteRecursion(num, 0, result);
        return result;
    }

    void permuteRecursion(std::vector<int> &num, int begin, std::vector<std::vector<int> > &result){
        if (begin >= num.size()){
            printVector(num, "Return");
            result.push_back(num);
            return;
        }
        for (int i = begin; i < num.size(); ++i){
            std::swap(num[begin], num[i]);
            printVector(num, "with begin and i index of: ");
            std::cout << begin << "     " << i << std::endl;
            permuteRecursion(num, begin + 1, result);
            // std::swap(num[begin], num[i]);
        }
    }
};

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
    std::vector<int> num;
    num.push_back(1);
    num.push_back(2);
    num.push_back(3);

    Solution1 s;
    Solution2 s2;

    // std::vector<std::vector<int> > result = s.permute(num);
    std::vector<std::vector<int> > result = s2.permute(num);

    for (int i = 0; i < result.size(); ++i)
    {
        std::vector<int> res = result[i];
        printVector(res, "");
    }
}
