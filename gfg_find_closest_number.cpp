/**
 * @file gfg_find_closest_number.cpp
 * @author Mohit Ranjan
 * @brief
 * @version 0.1
 * @date 2024-01-02
 *
 * Given an array of sorted integers. The task is to find the closest value to the given number in array. Array may contain duplicate values.

    Note: If the difference is same for two values print the value which is greater than the given number.
 *
    Input : Arr[] = {1, 3, 6, 7} and K = 4
    Output : 3
    Explanation:
    We have an array [1, 3, 6, 7] and target is 4.
    If we look at the absolute difference of target
    with every element of an array we will
    get [ |1-4|, |3-4|, |6-4|, |7-4| ].
    So, the closest number is 3.


    Input : Arr[] = {1, 2, 3, 5, 6, 8, 9}, K = 4
    Output : 5

    Expected Time Complexity: O(log(N)).
    Expected Auxiliary Space: O(1).

 *
 *
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
 * @brief This function is intended to find the closest number in the array 
 * We can use binary search to acheive this. In case of successful search, the number itself
 * is returned. In case search is unsuccessful, we will have start index pointing to the number just
 * greater than the target, and end index pointing to the number just lesser than the target
 * 
 * This will allow us to compute the difference between the target and its bounds. Then we will
 * return the number with the closest bound. In case both the lower and upper bounds are equally distant
 * we will return the upper bound
 * @param arr
 * @param n 
 * @param target 
 * @return int 
 */
int findClosest(int arr[], int n, int target)
{
    int start = 0;
    int end = n - 1;
    for (;start <= end;)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target)
            return target;
        else if (arr[mid] > target)
        {
            end = mid - 1;
        }
        else
            start = (mid + 1);
    }

    if (end < 0) end = 0;
    if (start >= n) start = n - 1;

    int lower_difference = abs(arr[end] - target);
    int higher_difference = abs(arr[start] - target);

    if (lower_difference < higher_difference)
    {
        return arr[end];
    }
    return arr[start];
}

int main()
{
    int arr[] = {5, 9, 12, 16};
    int target = 2;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << findClosest(arr, n, target) << endl;
    return 0;
}