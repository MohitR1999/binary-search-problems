/*
    This is the source for recursive process of binary search using divide and conquer strategy
*/

#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef set<int> si;
typedef unordered_set<int> usi;

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

/*
    Helper function for the binary search procedure
*/
int binary_search_helper(int start, int end, int& key, vi& elements) {
    if (start == end) {
        // start and end values are same, so it is a small problem
        // only one element needs to be compared
        if (elements[start] == key) return start;
        return -1;
    } else {
        // start and end values are not same so it is a big problem
        // we will break it down and solve each of them
        int mid = start + (end - start)/2;
        if (elements[mid] == key) {
            // we found the element so return the index
            return mid;
        }
        else if (elements[mid] > key) {
            // element at mid position is bigger than the key
            // we need to search in the lower half of the array
            return binary_search_helper(start, mid - 1, key, elements);
        } else {
            // element at mid position is smaller than the key
            // we need to search in the upper half of the array
            return binary_search_helper(mid + 1, end, key, elements);
        }
    }
}

int binary_search(vi& elements, int key) {
    /*
    We maintain two pointers, start and end, both pointing
    to the ends of the initial array
    */
    int start = 0;
    int end = elements.size() - 1;
    // use binary search helper and return the result
    return binary_search_helper(start, end, key, elements);
}


int main() {
    // Declare variables to be used
    int number_of_elements;
    vi elements;
    int key_to_be_found;
    // Initialize them with user input
    initialize(elements, number_of_elements, key_to_be_found);
    
    // perform binary search
    int index = binary_search(elements, key_to_be_found);

    // print out the search status
    if (index > -1) {
        cout << "Element " << key_to_be_found << " found at index: " << index;
    } else {
        cout << "Element " << key_to_be_found << " was not found!";
    }

    // exit
    return 0;
}