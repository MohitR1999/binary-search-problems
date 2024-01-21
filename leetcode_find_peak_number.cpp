/**
 * @file leetcode_find_highest_number.cpp
 * @author your name (you@domain.com)
 * @brief Find Highest number in array
 * @version 0.1
 * A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time.
Expected Time Complexity: O(log(n))
Expected Space Complexity: O(1)


Constraints:
1 <= nums.length <= 1000
-2^31 <= nums[i] <= 2^31 - 1
nums[i] != nums[i + 1] for all valid i.


 * @copyright Copyright (c) 2024
 *
 */
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef set<int> si;
typedef unordered_set<int> usi;

/**
 * @brief Finds peak element in an array
 * We will be using the binary search technique to solve the problem
 * @param a
 * @return int
 */
int findPeakElement(vector<int> &a)
{
    if (a.size() == 1) return 0;
    
    int start = 0;
    int end = a.size() - 1;

    for (; start <= end;)
    {
        int mid = start + (end - start) / 2;

        if (mid > 0 && mid < a.size() - 1)
        {
            int next = (mid + 1);
            int prev = (mid - 1);
            if (a[mid] > a[prev] && a[mid] > a[next])
            {
                // if the mid element is greater than its neighbours, then for sure
                // it is the one we are trying to find, because the array is sorted
                return mid;
            }
            else if (a[mid] > a[prev])
            {
                // this means we are still in the increasing half, so we need to move more rightwards
                start = mid + 1;
            }
            else
            {
                // this means we reached to the decreasing half, we need to move leftwards
                end = mid - 1;
            }
        } else if (mid == 0) {
            if (a[mid] > a[mid + 1]) return mid;
            else return mid + 1;
        } else if (mid == a.size() - 1) {
            if (a[mid] > a[mid - 1]) return mid;
            else return mid - 1;
        }
    }

    return 0;
}

int main()
{
    vector<int> arr = {3, 1, 2};
    cout << findPeakElement(arr) << endl;
    return 0;
}