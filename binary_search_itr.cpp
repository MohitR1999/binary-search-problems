/*
    This is the source for iterative process of binary search
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

int binary_search(vi& elements, int key) {
    /*
    We maintain two pointers, start and end, both pointing
    to the ends of the initial array
    */
    int start = 0;
    int end = elements.size() - 1;
    
    // As long as the start does not cross over end, we will continue the search
    for(;start <= end;) {
        // We will calculate the mid value
        // This formula looks weird, but actually it is just
        // adding an offset to start, which is basically half the distance between start and end
        // this method prevents overflow of the indexes in case they are too big
        int mid = start + (end - start)/2;

        if (elements[mid] == key) {
            // we found the key, just return the index of it from here
            return mid;
        } else if (elements[mid] > key) {
            // element in middle is bigger than the key, so end needs to be updated
            end = mid - 1;
        } else {
            // element in the middle is lower than the key, so start needs to be updated
            start = mid + 1;
        }
    }

    // if we reach here, it means we didn't found the element, so return -1;
    return -1;
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