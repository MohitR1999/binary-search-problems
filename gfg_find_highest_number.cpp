/**
 * @file gfg_find_highest_number.cpp
 * @author your name (you@domain.com)
 * @brief Find Highest number in array
 * @version 0.1
 * @date 2024-01-03
 *
 * Given an array in such a way that the elements stored in array are in increasing order initially and then after reaching to a peak element, the elements stored are in decreasing order. Find the highest element.
   Note: A[i] != A[i+1]
    Your Task:
You don't need to read or print anything. Your task is to complete the function findPeakElement() which takes the array as the input parameter and returns the highest element.

Expected Time Complexity: O(log(n))
Expected Space Complexity: O(1)


Constraints:
2 <= Size of array <= 200
1 <= Elements of the array <= 1000000


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
    int start = 0;
    int end = a.size() - 1;

    for (;start <= end;) {
        int mid = start + (end - start) / 2;
        int next = (mid + 1) % a.size();
        int prev = (mid - 1 + a.size()) % a.size();
        if (a[mid] > a[prev] && a[mid] > a[next]) {
            // if the mid element is greater than its neighbours, then for sure
            // it is the one we are trying to find, because the array is sorted
            return a[mid];
        } else if (a[mid] > a[prev] && a[mid] < a[next]) {
            // this means we are still in the increasing half, so we need to move more rightwards
            start = mid + 1;
        } else if (a[mid] < a[prev] && a[mid] > a[next]) {
            // this means we reached to the decreasing half, we need to move leftwards
            end = mid - 1;
        }
    }

    return -1;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    cout << findPeakElement(arr) << endl;
    return 0;
}