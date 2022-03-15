//
// Created by bo on 2022/3/11.
//

#include "HashSetExecutor.h"
using namespace std;

bool HashSetExecutor::containsDuplicate(vector<int> &nums) {
    unordered_set<int> set;
    for (int num: nums) {
        if (set.count(num)) {
            return true;
        } else {
            set.emplace(num);
        }
    }
    return false;
}

int HashSetExecutor::singleNumber(vector<int> &nums) {
    int ret = 0;
    for (int num: nums) {
        ret = num^ret;
    }
    return ret;
}

int HashSetExecutor::singleNumber2(vector<int> &nums) {
    if (nums.size() == 1) return nums[0];
    sort(nums.begin(), nums.end());
    int i = 0;
    while (i < nums.size()) {
        if (i > nums.size() - 3) {
            return nums[i];
        }
        if (nums[i] != nums[i+2]) {
            return nums[i];
        }

        i+=3;
    }
    return -1;
}

vector<int> HashSetExecutor::singleNumber3(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int i =0 ;
    while(i < nums.size()) {
        if (nums[i] != nums[i+1]) {
            return vector<int>({nums[i], nums[i+1]});
        }
        i+=2;
    }
}

bool HashSetExecutor::isHappy(int n) {
    unordered_set<int> value;
    int sum = n;

    while (sum != 1) {
        int v = sum;
        sum = 0;
        while (v !=0) {
            sum+= ((v%10)*(v%10));
            v = v/10;
        }
        if (value.count(sum)) {
            return false;
        }
        value.emplace(sum);
    }

    return true;
}

void HashSetExecutor::execute() {
    cout << isHappy(2) << endl;
}

bool HashSetExecutor::isIsomorphic(string s, string t) {
    unordered_map<char,char> map;
    unordered_set<char> value_set;

    for (int i = 0; i < s.length(); ++i) {
        //该字符没有映射过
        if (map.count(s[i]) <= 0) {
            if (value_set.count(t[i]) <= 0) {
                value_set.emplace(t[i]);
                map.emplace(s[i], t[i]);
            } else {
                return false;
            }
        } else {
            if (map[s[i]] != t[i]) {
                return false;
            }
        }
    }

    return true;
}

vector<string> HashSetExecutor::findRestaurant(vector<string> &list1, vector<string> &list2) {
    unordered_map<string, int> key_val;
    unordered_map<string, int> tmp;
    int min_value = INT32_MAX;
    string min_str = "";

    for (int i = 0; i < list1.size(); ++i) {
        key_val.emplace(list1[i], i);
    }

    for (int i = 0; i < list2.size(); ++i) {
        string t = list2[i];
        if (key_val.count(t) > 0) {
            tmp.emplace(t, key_val[t] + i);
            min_value = min(min_value, key_val[t] + i);
        }
    }

    vector<string> ret;
    for (auto it = tmp.begin(); it != tmp.end() ; it++) {
        if (it->second == min_value) {
            ret.push_back(it->first);
        }
    }

    return ret;
}

//两个数组的交集 II
vector<int> HashSetExecutor::intersect(vector<int> &nums1, vector<int> &nums2) {
    if (nums1.size() > nums2.size()) {
        return intersect(nums2, nums1);
    }

    unordered_map<int, int> kv;
    for (int num: nums1) {
        ++kv[num];
    }

    vector<int> ret;
    for (int num: nums2) {
        if (kv.count(num)) {
            ret.push_back(num);
            --kv[num];
            if (kv[num] == 0) {
                kv.erase(num);
            }
        }
    }
    return ret;
}

bool HashSetExecutor::containsNearbyDuplicate(vector<int> &nums, int k) {

    unordered_set<int> set;

    int index = 0;
    for(int num: nums) {
        if (index > k) {
            set.erase(nums[index -k - 1]);
        }

        if (set.count(num)) {
            return true;
        }
        set.emplace(num);
        index++;
    }

    return false;
}

vector<vector<string>> HashSetExecutor::groupStrings(vector<string> &strings) {
    unordered_map<char, vector<string>> hash_map;

    for(string str:strings) {
        string tmp(str);
        for(char &c:tmp) {
            c = (c-str[0] + 26)%26 + 'a';
        }
        hash_map[tmp].push_back(str);
    }

    vector<vector<string>> ret;
    for(auto it=hash_map.begin();it!=hash_map.end();it++) {
        ret.push_back(it->second);
    }

    return ret;
}

bool HashSetExecutor::isValidSudoku(vector<vector<char>> &board) {
    int rowNum = board.size();
    int colNum = board[0].size();
    vector<vector<int>> rows(rowNum, vector<int>(colNum));
    vector<vector<int>> cols(colNum, vector<int>(rowNum));
    vector<vector<vector<int>>> subRows(rowNum/3, vector<vector<int>>(colNum/3, vector<int>(9)));

    for (int i = 0; i < rowNum; ++i) {
        for (int j = 0; j < colNum; ++j) {
            if (board[i][j] == '.') continue;
            int index = board[i][j] - '0' - 1;
            rows[i][index]++;
            cols[j][index]++;
            subRows[i/3][j/3][index]++;
            if (rows[i][index] > 1 || cols[index][j] > 1 || subRows[i/3][j/3][index] > 1) {
                return false;
            }
        }
    }

    return true;
}

int HashSetExecutor::lengthOfLongestSubstring(string s) {
    int right = 0;
    int left = 0;
    int num = 0;
    vector<int> chars(128, -1);

    while (right < s.length()) {
        char c = s[right];
        int index = chars[c];
        if(index != -1 && index >= left && index < right) {
            left = index + 1;
        }
        chars[c] = right;
        num = max(num, right - left + 1);
        right++;
    }
    return num;
}

int HashSetExecutor::fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4) {
    unordered_map<int, int> map;
    for(int num1: nums1) {
        for(int num2: nums2) {
            ++map[num1+num2];
        }
    }

    int count = 0;
    for (int num3: nums3) {
        for (int num4: nums4) {
            int sum = -(num3 + num4);
            if (map.count(sum)) {
                count+=map[sum];
            }
        }
    }


    return count;
}

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> set1;
    for(int num: nums1) {
        set1.emplace(num);
    }
    unordered_set<int> set2;
    for(int num: nums2) {
        set2.emplace(num);
    }

    vector<int> ret;
    for(auto it= set1.begin();it!=set1.end();it++) {
        if (set2.count(*it)) {
            ret.push_back(*it);
        }
    }
    return ret;
}
