#include "evaluate.hh"
#include "BinTree.hh"

// Pre:  t és un arbre no buit que representa una expressió booleana correcta
//       sobre els true,false i els operadors and,or,not.
// Post: Retorna l'avaluació de l'expressió representada per t.
bool evaluate(const BinTree<string> t){
    if (t.empty())
    {
        return false;
    }
    else if (t.value()=="and")
    {
        return (evaluate(t.left()) and evaluate(t.right()));
    }
    else if (t.value()=="or")
    {
        return (evaluate(t.left()) or evaluate(t.right()));
    }
    else if (t.value()=="not")
    {
        return (not evaluate(t.left()));
    }
    else if (t.value()=="false")
    {
        return false;
    }
    else return true;
    
    
}