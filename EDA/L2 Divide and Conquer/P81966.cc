#include <vector>
#include <iostream>
using namespace std;

int position(double x, const vector<double>& v, int left, int right){
    if (right >= left) {
    int mid = left + (right - left) / 2;

    // If found at mid, then return it
    if (x == v[mid])
      return mid;

    // Search the right half
    if (x > v[mid])
      return position(x, v, mid + 1, right);

    // Search the right half
    return position(x, v, left, mid - 1);
  }

  return -1;
}