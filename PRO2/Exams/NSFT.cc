// Add or remove inclurights
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void numberOccurrences(const string &s, int &n1, int &n2, int &n3){
    int n_left, left = 0;
    int n_right, right = s.length() - 1;
    while(left < right) {
        int mit = left + (right - left)/2;
        if(s[mit] == s[s.length() - 1]){
            right = mit;
        }
        else{
            left = mit+1;
        }
    }
    n_left = left; 
    left = 0;
    right = s.length() - 1;
    while(left < right) {
        int mit = left + (right - left)/2;
        if(s[mit] == s[0]) {
            left = mit+1;
        }
        else {
            right = mit;
        }
    }
    n_right = left;
    int d_right = s.length() - n_left;
    int d_left = n_right;
    n1 = d_right;
    n2 = d_left;
    n3 = (s.length())-n1-n2;
}

int numberHappyOrSadSubsequences(const string &s){
    int n1 = 0, n2 = 0, n3 = 0;
    numberOccurrences(s, n1, n2, n3);
    return(n1*n2*n3);
}

