#include "numTwins.hh"


// Pre:
// Post: Retorna el nombre de parelles de nodes de t que tenen el mateix node pare i el mateix valor
int numTwins(BinTree<int> t){
    if (t.empty())
    {
        return 0;
    }
    else if (((not t.right().empty()) and (not t.left().empty())) and t.right().value()==t.left().value())
    {
        return 1 + numTwins(t.right()) + numTwins(t.left());
    }
    else return numTwins(t.left()) + numTwins(t.right());
    
}