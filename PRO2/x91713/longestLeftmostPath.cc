#include "longestLeftmostPath.hh"
#include <algorithm>

int Depth(BinTree<int> t){
    if (!t.empty())
    {
        return 1 + max(Depth(t.left()), Depth(t.right()));
    }
    else return 0;
}

// Pre:
// Post: Retorna la llista d'elements que es troben a t, baixant des de l'arrel i
//       seguint el camí més llarg. En cas de varis camins màxims,
//       escull el de més a l'esquerra.
list<int> longestLeftmostPath(BinTree<int> t){
    list<int> l;
    if (t.empty())
    {
        return l;
    }
    else if (Depth(t.left()) >= Depth(t.right()))
    {
        
        l.splice(l.end() ,longestLeftmostPath(t.left()));
        l.push_front(t.value());
        return l;
    }
    else {
        
        l.splice(l.end() ,longestLeftmostPath(t.right())); 
        l.push_front(t.value());
        return l;
    }
}