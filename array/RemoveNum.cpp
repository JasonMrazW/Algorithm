//
// Created by bo on 2022/3/2.
//

#include "RemoveNum.h"

using namespace std;

int RemoveNum::removeElement(std::vector<int> &input, int val) {
    int fast = 0;
    int slow = 0;
    int size = input.size();
    while (fast < size) {
        if (input[fast] != val) {
            input[slow] = input[fast];
            slow++;
        }
        fast++;
    }

    return slow;
}

//找连续1的最大个数
int RemoveNum::findMaxConsecutiveOnes(vector<int> &nums) {
    int size = nums.size();
    int fast = 0, slow = -1;
    int max = 0;
    while (fast < size) {
        if (nums[fast] == 0) {
            if ((fast - slow -1) > max) {
                max = fast - slow -1;
            }
            slow = fast;
        }
        fast++;
        if (fast == size && (fast - slow -1) > max) {
            max = fast - slow -1;
        }
    }

    return max;
}

void RemoveNum::execute() {
    vector<int> input = {1,2,3,4,5};
    //cout << RemoveNum::removeElement(input, 2) << endl;
    //    cout << findMaxConsecutiveOnes(input) << endl;
    //cout << minSubArrayLen(11, input) << endl;
    generate(5);
}

int RemoveNum::minSubArrayLen(int target, vector<int> &nums) {
    int start = 0, end = 0;
    int size = nums.size();
    int count = 0;
    int ret = 0;
    while (end < size) {
        count += nums[end];
        while (count >= target) {
            ret = ret ==0 ? (end-start+1):min(ret, end-start+1);
            count -= nums[start];
            start++;
        }
        end++;
    }
    return ret;
}

//杨辉三角
vector<vector<int>> RemoveNum::generate(int numRows) {
    vector<vector<int>> ret;
    int index = 0;
    vector<int> sub;
    sub.push_back(1);
    ret.push_back(sub);

    int row = 2;
    int left = 0;
    int right = 0;

    while (row <= numRows) {
        vector<int> sub_vector;
        while (index < row) {
            left = index == 0? 0:(ret[row - 2][index-1]);
            right = index > ret[row - 2].size() ? 0: ret[row - 2][index];
            sub_vector.push_back(left + right);
            index++;
        }
        ret.push_back(sub_vector);
        row++;
        index = 0;
        left = 0;
        right = 0;
    }
    return ret;
}

std::vector<int> RemoveNum::getRow(int rownums) {
    vector<int> ret(rownums);
    //first row
    ret[0] = 1;

    int rowIndex = 2;
    int index = 0;
    while(rowIndex <= rownums) {
        index = rowIndex -1;
        while (index >= 1) {
            ret[index] = ret[index] + ret[index-1];
            index--;
        }
        rowIndex++;
    }

    return ret;
}
