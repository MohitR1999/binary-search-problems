/**
 * @file leetcode_search_in_rotated_sorted_array.cpp
 * @author Mohit Ranjan
 * @brief Leetcode problem #33: Search in rotated sorted array
 * @version 1.0
 * @date 2024-01-01
 * 
 * There is an integer array nums sorted in ascending order (with distinct values).

    Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

    Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

    You must write an algorithm with O(log n) runtime complexity.
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef set<int> si;
typedef unordered_set<int> usi;

int binarySearch(vector<int>& nums, int target, int index_start, int index_end) {
    int start = index_start;
    int end = index_end;

    for (;start <= end;) {
        int mid = start + (end - start) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] > target) end = mid - 1;
        else start = mid + 1;
    }

    return -1;
}

int search(vector<int>& nums, int target) {
    int start = 0;
    int end = nums.size() - 1;
    int pivot_index = -1;
    for(;start <= end;) {
        int mid = start + (end - start)/2;
        int prev = (mid + nums.size() - 1) % nums.size();
        int next = (mid + 1) % nums.size();

        if (nums[mid] <= nums[next] && nums[mid] <= nums[prev]) {
            pivot_index = mid;
            break;
        } else if (nums[mid] <= nums[end]) {
            end = mid - 1;
        } else if (nums[mid] >= nums[start]) {
            start = mid + 1;
        }
    }

    if (pivot_index > -1) {
        int left_half_res = binarySearch(nums, target, 0, pivot_index - 1);
        if (left_half_res > -1) return left_half_res;
        int right_half_res = binarySearch(nums, target, pivot_index, nums.size() - 1);
        return right_half_res;
    } else return -1;
}

void initialize(vi& elements, int& number, int& key) {
    // Number of elements to be present in the array
    cin >> number;

    // individual elements of the array
    for (int index = 0; index < number; index++) {
        int element;
        cin >> element;
        elements.push_back(element);
    }

    // key to be found
    cin >> key;
}

int main() {
    int number_of_elements;
    vi elements;
    int key_to_be_found;

    initialize(elements, number_of_elements, key_to_be_found);
    int res = search(elements, key_to_be_found);
    cout << res;
    cout << endl;

    return 0;
}