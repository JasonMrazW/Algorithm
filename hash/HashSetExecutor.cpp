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
