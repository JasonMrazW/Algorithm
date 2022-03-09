cmake_minimum_required(VERSION 3.20)
project(Algorithm)

set(CMAKE_CXX_STANDARD 11)

add_executable(Algorithm main.cpp array/TwoSum.cpp array/TwoSum.h common.h array/ArrayExecutor.cpp array/ArrayExecutor.h string/StringExecutor.cpp string/StringExecutor.h queue/MyCircularQueue.cpp queue/MyCircularQueue.h queue/QueueExecutor.cpp queue/QueueExecutor.h stack/MinStack.h stack/StackExecutor.cpp stack/StackExecutor.h stack/Node.h queue/MyQueue.h stack/MyStack.h tree/TreeNode.h tree/TreeExecutor.cpp tree/TreeExecutor.h)
