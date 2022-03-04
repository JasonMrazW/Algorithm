//
// Created by bo on 2022/3/3.
//

#include "StackExecutor.h"


bool StackExecutor::isValid(string s) {
    int length = s.length();

    if (length % 2 != 0) return false;

    auto isLeft = [](char x) -> bool {
        if (x == '(' || x == '{' || x == '[') {
            return true;
        }
        return false;
    };

    auto is_complte = [](char a, char b) -> bool {
        if( (a == '(' && b == ')') ||
        (a == '[' && b == ']') ||
        (a == '{' && b == '}')) {
            return true;
        }
        return false;
    };

    stack<char> left_stack;
    for (int i = 0; i < length; ++i) {
        if (isLeft(s[i])) {
            left_stack.push(s[i]);
        } else {
            if (left_stack.empty()) {
                return false;
            }
            char t = left_stack.top();
            left_stack.pop();
            if (!is_complte(t, s[i])) {
                return false;
            }
        }
    }
    return left_stack.empty();
}

bool StackExecutor::checkValidString(string s) {
    auto is_left = [](char x)->bool {
        return x == '(';
    };

    stack<int> left_stack;
    stack<int> common_stack;
    for (int i = 0; i < s.length(); ++i) {
        if (is_left(s[i])) {
            left_stack.push(i);
        } else if (s[i] == '*') {
            common_stack.push(i);
        } else {
            if (!left_stack.empty()) {
                left_stack.pop();
            } else if (!common_stack.empty()) {
                common_stack.pop();
            } else {
                return false;
            }
        }
    }

    while (!left_stack.empty()) {
        int top = left_stack.top();
        left_stack.pop();
        if (common_stack.empty()) {
            return false;
        }
        if (top > common_stack.top()) {
            return false;
        }
        common_stack.pop();
    }

    return true;
}

vector<int> StackExecutor::dailyTemperatures(vector<int> &temperatures) {
    stack<int> min_stack;
    vector<int> ret(temperatures.size(), 0);
    for (int i = 0; i < temperatures.size(); ++i) {
        while (!min_stack.empty()) {
            int index = min_stack.top();
            if (temperatures[i] > temperatures[index]) {
                ret[index] = i - index;
            } else {
                break;
            }
            min_stack.pop();
        }
        min_stack.push(i);
    }
    return ret;
}


void StackExecutor::execute() {
    cout << isValid("){") << endl;
    cout << checkValidString("((((()(()()()*()(((((*)()*(**(())))))(())()())(((())())())))))))(((((())*)))()))(()((*()*(*)))(*)()") << endl;
    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    vector<int> ret = dailyTemperatures(temperatures);

    for (int i = 0; i < ret.size(); ++i) {
        cout << ret[i] << ",";
    }
    cout << endl;
}