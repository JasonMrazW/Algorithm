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
    cout << minSubArrayLen(11, input) << endl;
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
