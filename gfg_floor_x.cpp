#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef set<int> si;
typedef unordered_set<int> usi;

int findFloor(vector<long long> v, long long n, long long x)
{
    int start = 0;
    int end = n - 1;

    for (;start <= end;) {
        int mid = start + (end - start) / 2;
        if (v[mid] == x) return mid;
        else if (v[mid] > x) end = mid - 1;
        else start = mid + 1;
    }

    return end;
}

int main()
{
    vector<long long> v = {1,2,8,10,11,12,19};
    ll x = 5;
    cout << findFloor(v, v.size(), x);
    return 0;
}