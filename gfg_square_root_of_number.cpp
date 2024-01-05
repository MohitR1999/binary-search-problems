/**
 * @file gfg_square_root_of_number.cpp
 * @author your name (you@domain.com)
 * @brief Square root of a number
 * @version 0.1
 * @date 2024-01-03
 * Given an integer x, find the square root of x. If x is not a perfect square, then return floor(√x).
 * @copyright Copyright (c) 2024
 *
 */

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef set<int> si;
typedef unordered_set<int> usi;

long long int floorSqrt(long long int x)
{
    long long int start = 1;
    long long int end = x;
    for (;start <= end;) {
        long long int mid = start + (end - start) / 2;
        long long int square = mid * mid;
        if (square == x) return mid;
        else if (square > x) end = mid - 1;
        else start = mid + 1;
    }
    return end;
}

int main()
{
    long long int num;
    cin >> num;
    cout << floorSqrt(num) << endl;
    return 0;
}