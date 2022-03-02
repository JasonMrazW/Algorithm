//
// Created by bo on 2022/3/2.
//

#include "ArrayExecutor.h"

using namespace std;

int ArrayExecutor::removeElement(std::vector<int> &input, int val) {
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
int ArrayExecutor::findMaxConsecutiveOnes(vector<int> &nums) {
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



int ArrayExecutor::minSubArrayLen(int target, vector<int> &nums) {
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
vector<vector<int>> ArrayExecutor::generate(int numRows) {
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

std::vector<int> ArrayExecutor::getRow(int rownums) {
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

int ArrayExecutor::findMin(vector<int> &nums) {
    int ret = nums[0];
    int count = 0;
    int pre_value = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] > pre_value) {
            count++;
            pre_value = nums[i];
        } else {
            ret = nums[i];
            break;
        }
    }
    return ret;
}

int ArrayExecutor::findMin2(vector<int> &nums) {

    int low = 0, high = nums.size() -1;
    while (low < high) {
        int middle = (high - low)/2 + low;
        if (nums[middle] < nums[high]) {
            high = middle;
        } else {
            low = middle + 1;
        }
    }
    return nums[low];
}

int ArrayExecutor::removeDuplicates(vector<int> &nums) {
    int fast = 0, slow = 0;
    while (fast < nums.size()) {
        if (nums[fast] != nums[slow]) {
            slow++;
            nums[slow] = nums[fast];
        }
        fast++;
    }
    return slow+1;
}

int ArrayExecutor::removeDuplicates2(vector<int> &nums) {
    int fast = 1, slow =0;
    int count = 1;
    while (fast < nums.size()) {
        if (nums[fast] != nums[slow]) {
            slow++;
            nums[slow] = nums[fast];
            count = 0;
            count++;
        } else if (count < 2) {
            count++;
            slow++;
            nums[slow] = nums[fast];
        }
        fast++;
    }
    return slow+1;
}

void ArrayExecutor::execute() {
    vector<int> input = {0,0,0,1,1,1,2,2};
    //cout << ArrayExecutor::removeElement(input, 2) << endl;
    //    cout << findMaxConsecutiveOnes(input) << endl;
    //cout << minSubArrayLen(11, input) << endl;
    //generate(5);
    //cout << findMin2(input) << endl;

    moveZeroes(input);
}

void ArrayExecutor::moveZeroes(vector<int> &nums) {
    int fast = 0, slow =0;
    while (fast < nums.size()) {
        if (nums[fast] != 0) {
            nums[slow++] = nums[fast];
        }
        fast++;
    }

    while (slow < nums.size()) {
        nums[slow++] = 0;
    }
}

