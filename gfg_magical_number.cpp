/*
Problem from GeeksForGeeks
Given a sorted array having N elements, find the indices of the first and last occurrences of an element X in the given array.
Note: If the number X is not found in the array, return '-1' as an array.

Expected Time Complexity: O(log(N))
Expected Auxiliary Space: O(1)

We would be using binary search for this
*/

#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef set<int> si;
typedef unordered_set<int> usi;

int occurence(vector<int> &arr, int n) {
    int start = 0;
    int end = n - 1;
    int result = -1;

    for (;start <= end;) {
        int mid = start + (end - start)/2;
        if (arr[mid] == mid) {
            result = mid;
            /*
                Here is the catch in the binary search procedure
                If we need to find the first occurence, we should not stop as soon as the required element is found.
                Instead, we should keep searching in the lower half of the array as the element would be
                present there only as the array is sorted.

                If we need to find the last occurence, we need to continue the search in the upper half of the array
            */
            end = mid - 1;
        } else if (arr[mid] > mid) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return result;
}


int findMagicalNumber(int N, vector<int> &arr) {
    return occurence(arr, N);
}

void initialize(vi& elements, int& number) {
    // Number of elements to be present in the array
    cin >> number;

    // individual elements of the array
    for (int index = 0; index < number; index++) {
        int element;
        cin >> element;
        elements.push_back(element);
    }
}

int main() {
    int number_of_elements;
    vi elements;

    initialize(elements, number_of_elements);

    int res = findMagicalNumber(elements.size(), elements);

    cout << res;
    cout << endl;

    return 0;
}