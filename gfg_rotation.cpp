/*
Problem from GFG
Given an ascending sorted rotated array Arr of distinct integers of size N. The array is right rotated K times. Find the value of K.

Expected Time Complexity: O(log(N))
Expected Auxiliary Space: O(1)

Link : https://practice.geeksforgeeks.org/problems/rotation4723/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

*/

#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef set<int> si;
typedef unordered_set<int> usi;

int findKRotation(int arr[], int n) {
	int start = 0;
    int end = n - 1;
    for (;start <= end;) {
        int mid = start + (end - start) / 2;
        int next = (mid + 1) % n;
        int prev = (mid + n - 1) % n;

        if (arr[mid] <= arr[next] && arr[mid] <= arr[prev]) return arr[mid];
        else if (arr[mid] <= arr[end]) {
            end = mid - 1;
        } else if (arr[mid] >= arr[start]) {
            start = mid + 1;
        }
    }
    return -1;
}

int main() {
    int size;
    cin >> size;

    int elements[size];
    for (int i = 0; i < size; i++) {
        cin >> elements[i];
    }

    int res = findKRotation(elements, size);
    cout << res;
    cout << endl;

    return 0;
}