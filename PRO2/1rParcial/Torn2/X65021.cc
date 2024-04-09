#include "appendReverseOrder.hh"

void appendReverseOrder(list<int> &l){
    list<int>::iterator it = l.end();
    --it;
    while (it!=l.begin())
    {
        l.push_back(*it);
        --it;
    }
    l.push_back(*it);
}
