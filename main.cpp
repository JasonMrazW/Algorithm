#include <iostream>
#include <ctime>
#include "array/TwoSum.h"
#include "array/RemoveNum.h"
#include "string/StringExecutor.h"
using namespace std;

int main() {
    clock_t start = clock();
    IExecutor *executor = new StringExecutor();
    executor->execute();
    clock_t end = clock();
    cout << "cost:" << (end - start)/1000 << "ms" << endl;
    return 0;
}
