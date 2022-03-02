//
// Created by bo on 2022/3/2.
//

#include "TwoSum.h"
using namespace std;

vector<int> TwoSum::twoSum(vector<int> &numbers, int target) {
    vector<int> ret;

    int size = numbers.size();
    int temp = 0;
    for (int i = 0; i < size - 1; ++i) {
        int low = i + 1, high = size - 1;

        //二分查找
        temp = target - numbers[i];
        while (low <= high) {
            int middle = (high - low)/2 + low;
            if (numbers[middle] == temp) {
                ret.push_back(i + 1);
                ret.push_back(middle + 1);
                return ret;
            } else if (numbers[middle] > temp) {
                high = middle -1;
            } else {
                low = middle + 1;
            }
        }
    }

    return {-1, -1};
}

std::vector<int> TwoSum::twoSum2Pointer(vector<int> &numbers, int target) {
    int size = numbers.size();

    int start = 0, end = size -1;
    int sum = 0;
    while (start >=0 && end < size && start < end) {
        sum = numbers[start] + numbers[end];
        if (sum == target) {
            return {start+1, end+1};
        } else if (sum > target) {
            end--;
        } else {
            start ++;
        }
    }

    return {-1, -1};
}
