#include <iostream>
#include <vector>

class Solution
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
            res.push_back(out);
            // std::cout << "Number of results: " << res.size() << std::endl;
            return;
        }
        for (int i = 0; i < num.size(); ++i)
        {
            if (visited[i] == 1)
                continue;
            visited[i] = 1;
            out.push_back(num[i]);

            permuteDFS(num, visited, out, res);
            out.pop_back();
            visited[i] = 0;
        }
    }
};

int main()
{
    std::vector<int> num;
    num.push_back(1);
    num.push_back(2);
    num.push_back(3);

    Solution s;

    std::vector<std::vector<int> > result = s.permute(num);

    for (int i = 0; i < result.size(); ++i){
        std::vector<int> res = result[i];
        for (int j = 0; j < res.size(); ++j){
            std::cout << res[j] << "\t";
        }
        std::cout << "\n";
    }
}

