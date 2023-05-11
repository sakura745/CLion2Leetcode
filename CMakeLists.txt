cmake_minimum_required(VERSION 3.25)
project(LeetCode2CLion)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)


add_executable(704-binary-search leetcode/editor/cn/704-binary-search.cpp)
add_executable(35-search-insert-position leetcode/editor/cn/35-search-insert-position.cpp)
add_executable(34-find-first-and-last-position-of-element-in-sorted-array leetcode/editor/cn/34-find-first-and-last-position-of-element-in-sorted-array.cpp)
add_executable(27-remove-element leetcode/editor/cn/27-remove-element.cpp)
add_executable(977-squares-of-a-sorted-array leetcode/editor/cn/977-squares-of-a-sorted-array.cpp)
add_executable(209-minimum-size-subarray-sum leetcode/editor/cn/209-minimum-size-subarray-sum.cpp)
add_executable(59-spiral-matrix-ii leetcode/editor/cn/59-spiral-matrix-ii.cpp)