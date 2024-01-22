/*

You have N books, each with A[i] number of pages. M students need to be allocated contiguous books, with each student getting at least one book.
Out of all the permutations, the goal is to find the permutation where the sum of maximum number of pages in a book allotted to a student should be minimum, out of all possible permutations.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).


Example 1:

Input:
N = 4
A[] = {12,34,67,90}
M = 2
Output:113
Explanation:Allocation can be done in
following ways:
{12} and {34, 67, 90} Maximum Pages = 191
{12, 34} and {67, 90} Maximum Pages = 157
{12, 34, 67} and {90} Maximum Pages =113.
Therefore, the minimum of these cases is 113,
which is selected as the output.


Example 2:

Input:
N = 3
A[] = {15,17,20}
M = 2
Output:32
Explanation: Allocation is done as
{15,17} and {20}

Your Task:
You don't need to read input or print anything. Your task is to complete the function findPages() which takes 2 Integers N, and m and an array A[] of length N as input and returns the expected answer.


Expected Time Complexity: O(NlogN)
Expected Auxilliary Space: O(1)


Constraints:
1 <= N <= 10^5
1 <= A [ i ] <= 10^6
1 <= M <= 10^5

Link: https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
*/

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef set<int> si;
typedef unordered_set<int> usi;

bool isValid(int A[], int n, int m, int mx) {
    int sum = 0;
    int students = 1;
    for (int i = 0; i < n; i++) {
        sum += A[i];
        if (sum > mx) {
            sum = A[i];
            students++;
        }

        if (students > m) return false;
    }
    return true;
}

int findPages(int A[], int N, int M)
{
    if (M > N) return -1;
    int sum = 0;
    int limit = INT_MIN;
    for(int i = 0; i < N; i++) {
        sum += A[i];
        limit = max(limit, A[i]);
    }

    int start = limit;
    int end = sum;
    int res = -1;
    for (;start <= end;) {
        int mid = start + (end - start) / 2;
        if (isValid(A, N, M, mid)) {
            res = mid;
            end = mid - 1;
        } else start = mid + 1;
    }

    return res;
}

int main()
{
    int a[] = {12,34,67,90};
    int m = 2;
    cout << findPages(a, sizeof(a)/sizeof(a[0]), m);    
    return 0;
}