// Add or remove includes
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <sstream>
#include <cstdlib>

using namespace std;

void mergeIntoFirstList(list<int> &l1, list<int> l2){
    list<int>::iterator it1=l1.begin();
    list<int>::iterator it2=l2.begin();
    while (it2!=l2.end())
    {
        if (*it1 > *it2)
        {
            ++it1;
        }
        else if (*it1<=*it2)
        {
            l1.insert(it1,*it2);
            ++it2;
        }
        else if (it1==l1.end())
        {
            l1.splice(it1, l2);
            it2 = l1.end();
        }
        
        
    }
    
}

#ifndef IOSTACKFUNCTIONS
#define IOSTACKFUNCTIONS

struct Test {
    list<int> l1, l2;
};

list<int> readList(string line)
{
    istringstream mycin(line);
    list<int> l;
    int x;
    while (mycin >> x)
        l.push_back(x);
    return l;
}

void writeList(list<int> l)
{
    bool writespace = false;
    for (list<int>::iterator it = l.begin(); it != l.end(); it++) {
        if (writespace) cout << " ";
        writespace = true;
        cout << *it;
    }
    cout << endl;
}

#endif


int main()  {
    vector<Test> test;
    string line1, line2;
    while (getline(cin, line1) and getline(cin, line2)) {
        Test t;
        t.l1 = readList(line1);
        t.l2 = readList(line2);
        test.push_back(t);
    }
    for (int i=0;i<int(test.size());i++) {
        list<int> &l1 = test[i].l1;
        list<int> &l2 = test[i].l2;
        mergeIntoFirstList(l1, l2);
        writeList(l1);
    }
}
