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

int occurence(vector<int> &arr, int n, int x, bool first) {
    int start = 0;
    int end = n - 1;
    int result = -1;

    for (;start <= end;) {
        int mid = start + (end - start)/2;
        if (arr[mid] == x) {
            result = mid;
            /*
                Here is the catch in the binary search procedure
                If we need to find the first occurence, we should not stop as soon as the element is found.
                Instead, we should keep searching in the lower half of the array as the element would be
                present there only as the array is sorted.

                If we need to find the last occurence, we need to continue the search in the upper half of the array
            */
            if (first) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        } else if (arr[mid] > x) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return result;
}

/*
    This function needs to be completed for the problem
    It will return first and last occurence of the element if it exists
    It will return -1 in array if it does not exists
*/
vector<int> firstAndLast(vector<int> &arr, int n, int x) {
    // Code here
    int first_occurence = occurence(arr, n, x, true);
    if (first_occurence > -1) {
        int last_occurence = occurence(arr, n, x, false);
        return {first_occurence, last_occurence};
    } 
    return {-1};
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

    vi res = firstAndLast(elements, elements.size(), key_to_be_found);

    for(auto x : res) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}