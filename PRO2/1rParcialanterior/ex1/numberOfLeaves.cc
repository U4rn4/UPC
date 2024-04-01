#include "numberOfLeaves.hh"

// Pre:
// Post: Retorna el nombre de fulles de t
int numberOfLeaves(BinTree<int> t){
    if (t.empty())
    {
        return 0;
    }
    else if (t.right().empty() and t.left().empty())
    {
        return 1;
    }
    else return numberOfLeaves(t.right()) + numberOfLeaves(t.left());
    

}