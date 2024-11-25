#include <vector>
#include <iostream>
using namespace std;

int cerca(double x, const vector<double>& v, int left, int right){
    int mid = left + (right - left) / 2;
    if (right > left)
    {
        

        if (x==v[mid])
        {
            return cerca(x, v, left, mid);
        }
        
        if (x>v[mid])
        {
            return cerca(x,v,mid+1, right);
        }
        else return cerca(x,v,left,mid-1);
    }
    if (right==left)
    {
        if(v[left] == x)return left;
        
    }
    
    return -1;
}

int first_occurrence(double x, const vector<double>& v){
    return cerca(x,v,0,v.size()-1);
    
}