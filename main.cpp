#include <iostream>
#include <ctime>
#include "array/TwoSum.h"
#include "array/ArrayExecutor.h"
#include "string/StringExecutor.h"
#include "queue/MyCircularQueue.h"
#include "queue/QueueExecutor.h"
#include "stack/StackExecutor.h"
#include "hash/HashSetExecutor.h"

using namespace std;

int main() {
    clock_t start = clock();
    IExecutor *executor = new HashSetExecutor();
    executor->execute();

    clock_t end = clock();
    cout << "cost:" << (end - start)/1000 << "ms" << endl;
    return 0;
}
