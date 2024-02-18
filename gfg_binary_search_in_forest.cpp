/*
There are n trees in a forest. The heights of the trees is stored in array tree[], where tree[i] denotes the height of the ith tree in the forest. If the ith tree is cut at a height H, then the wood collected is tree[i] - H, provided tree[i] > H. If the total woods that needs to be collected is exactly equal to k, find the height H at which every tree should be cut (all trees have to be cut at the same height). If it is not possible then return -1 else return H.

Example 1:

Input:
n = 5, k = 4
tree[] = {2, 3, 6, 2, 4}
Output: 3
Explanation: Wood collected by cutting trees
at height 3 = 0 + 0 + (6-3) + 0 + (4-3) = 4
hence 3 is to be subtracted from all numbers.
Since 2 is lesser than 3, nothing gets
subtracted from it.

Example 2:

Input:
n = 6, k = 8
tree[] = {1, 7, 6, 3, 4, 7}
Output: 4
Explanation: Wood collected by cutting trees
at height 4 = 0+(7-4)+(6-4)+0+0+(7-4) = 8

Your Task:
Your task is to complete the function find_height(). This function takes the array tree[ ], and the integers n and k as input parameters and returns the height at which trees have to be cut. If no positive integer value of height is possible, return -1.


Expected Time Complexity: O(n log h)
Expected Auxiliary Space: O(1)


Constraints:
1 <= n <= 10^4
1 <= tree[i] <= 10^3
1 <= k <= 10^7

Link: https://www.geeksforgeeks.org/problems/binary-search-in-forest--141631/1?page=1&category=Binary%20Search&sortBy=difficulty
*/

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef set<int> si;
typedef unordered_set<int> usi;

int get_height(int tree[], int n, int h)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (tree[i] > h)
        {
            sum += (tree[i] - h);
        }
    }

    return sum;
}

int find_height(int tree[], int n, int k)
{
    if (n == 1)
    {
        if (k < tree[0])
        {
            return tree[0] - k;
        }
        else
            return -1;
    }

    int start = INT_MAX;
    int end = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        start = min(start, tree[i]);
        end = max(end, tree[i]);
    }

    for (; start <= end;)
    {
        int mid = start + (end - start) / 2; // we are deciding our cut height here
        int obtained_height = get_height(tree, n, mid);
        if (obtained_height == k)
            return mid;
        else if (obtained_height > k)
            start = mid + 1; // this means our cut was lower, so we need to increase it
        else
            end = mid - 1; // this means our cut was higher, so we need to lower it
    }

    return -1;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << find_height(arr, n, k);
    return 0;
}