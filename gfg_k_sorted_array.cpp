#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef set<int> si;
typedef unordered_set<int> usi;

bool comparator(pair<int, int> first_pair, pair<int, int> second_pair) {
    return first_pair.first <= second_pair.first;
}

string isKSortedArray(int arr[], int n, int k)
{
    vector<pair<int, int>> arrVsIndexVector;
    for (int i = 0; i < n; i++) {
        arrVsIndexVector.push_back({arr[i], i});
    }

    sort(arrVsIndexVector.begin(), arrVsIndexVector.end(), comparator);

    for (int i = 0; i < arrVsIndexVector.size(); i++) {
        int index = arrVsIndexVector[i].second;
        if (abs(index - i) > k) return "No";
    }

    return "Yes";
}

int main()
{
    int arr[] = {13, 8, 10, 7, 15, 14, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    cout << isKSortedArray(arr, n, k) << endl;
    return 0;
}