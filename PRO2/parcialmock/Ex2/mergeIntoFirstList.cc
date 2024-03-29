#include "mergeIntoFirstList.hh"
// Pre: l1 i l2 estan ordenades creixentment. Siguin L1 i L2 els seus valors inicials.
// Post: l1 conté la fusió ordenada de L1 i L2.
//       A més a més, els elements inicials de la llista han persistit i
//       no han canviat de valor.
void mergeIntoFirstList(list<int> &l1, list<int> l2){
    list<int>::iterator it1=l1.begin();
    list<int>::iterator it2=l2.begin();
    while (it2!=l2.end() and it1!=l1.end())
    {
        if (*it1 <= *it2)
        {
            ++it1;
        }
        else if (*it1>*it2)
        {
            l1.insert(it1,*it2);
            ++it2;
        }
        
    }
    
    while (it2!=l2.end())
    {
        l1.insert(it1, *it2);
        ++it2;
    }
}
