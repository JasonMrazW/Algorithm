//
// Created by bo on 2022/3/2.
//

#include "StringExecutor.h"

void StringExecutor::execute() {
    string input = "i have a book.";
    cout << reverseWords(input) << endl;
}

string StringExecutor::reverseWords(string s) {
    int start = 0, end = 0;
    int length = s.length();

    while (end < length) {
        if (s[end] == ' ') {
            //need swap
            int nums = end - start;
            if (nums > 0) {
                cout << start << ":" << end << endl;
                int i = start, j = end-1;
                while (i < j) {
                    swap(s[i++], s[j--]);
                }
            }
            end++;
            start = end;
        } else {
            end++;
            if (end == length ) {
                int i = start, j = end-1;
                while (i < j) {
                    swap(s[i++], s[j--]);
                }
            }
        }
    }



    return s;
}
