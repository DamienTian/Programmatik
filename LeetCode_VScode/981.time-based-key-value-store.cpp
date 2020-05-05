/*
 * @lc app=leetcode id=981 lang=cpp
 *
 * [981] Time Based Key-Value Store
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// class TimeMap
// {
// public:
//     /** Initialize your data structure here. */
//     TimeMap() {}

//     void set(string key, string value, int timestamp)
//     {
//         if (mem.count(key))
//         {
//             int left = 0;
//             int right = mem[key].size();
//             while (left < right)
//             {
//                 int mid = left + (right - left) / 2;
//                 if (timestamp < mem[key][mid].first)
//                 {
//                     left = mid + 1;
//                 }
//                 else
//                 {
//                     right = mid;
//                 }
//             }

//             mem[key].insert(mem[key].begin() + right, pair<int, string>(timestamp, value));
//         }
//         else
//         {
//             mem[key] = {};
//             mem[key].push_back(pair<int, string>(timestamp, value));
//         }
//     }

//     string get(string key, int timestamp)
//     {
//         if (!mem.count(key))
//             return "";
//         int left = 0;
//         int right = mem[key].size();
//         while (left < right)
//         {
//             int mid = left + (right - left) / 2;
//             if (timestamp < mem[key][mid].first)
//             {
//                 left = mid + 1;
//             }
//             else
//             {
//                 right = mid;
//             }
//         }

//         return mem[key][right].second;
//     }

// private:
//     unordered_map<string, vector<pair<int, string>>> mem;
// };

// Author: Huahua, running time: 200 ms
class TimeMap {
public:
  /** Initialize your data structure here. */
  TimeMap() {}
 
  void set(string key, string value, int timestamp) {
    s_[key].emplace(timestamp, std::move(value));
  }
 
  string get(string key, int timestamp) {
    auto m = s_.find(key);
    if (m == s_.end()) return "";    
    auto it = s_[key].upper_bound(timestamp);
    if (it == begin(s_[key])) return "";
    return prev(it)->second;
  }
private:
  unordered_map<string, map<int, string>> s_; 
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// @lc code=end
