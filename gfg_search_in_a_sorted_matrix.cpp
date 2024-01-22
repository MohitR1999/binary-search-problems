/*
Given a matrix of size n x m, where every row and column is sorted in increasing order, and a number x. Find whether element x is present in the matrix or not.
Your Task:
You don't need to read input or print anything. Complete the function search() that takes n, m, x, and matrix[][] as input parameters and returns a boolean value. True if x is present in the matrix and false if it is not present.

Input:
n = 3, m = 3, x = 62
matrix[][] = {{ 3, 30, 38},
              {36, 43, 60},
              {40, 51, 69}}
Output: 0
Explanation:
62 is not present in the matrix,
so output is 0.

Input:
n = 1, m = 6, x = 55
matrix[][] = {{18, 21, 27, 38, 55, 67}}
Output: 1
Explanation: 55 is present in the matrix.


Expected Time Complexity: O(N + M)
Expected Auxiliary Space: O(1)

Problem link : https://www.geeksforgeeks.org/problems/search-in-a-matrix-1587115621/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
*/

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef set<int> si;
typedef unordered_set<int> usi;

// Function to search a given number in row-column sorted matrix.
bool search(vector<vector<int>> matrix, int n, int m, int x)
{
    // code here
    // n is the number of rows, m is the number of columns
    int row_idx = 0;
    int col_idx = m - 1;

    for (; row_idx >= 0 && row_idx < n && col_idx >= 0 && col_idx < m;)
    {
        if (matrix[row_idx][col_idx] == x)
            return true;
        else if (matrix[row_idx][col_idx] > x)
        {
            col_idx--;
        }
        else
            row_idx++;
    }

    return false;
}

int main()
{
    vector<vector<int>> v = {{18, 21, 27, 38, 55, 67}};
    int x = 55;
    cout << search(v, v.size(), v[0].size(), x);

    return 0;
}