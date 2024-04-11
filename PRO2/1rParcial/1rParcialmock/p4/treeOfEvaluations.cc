#include "treeOfEvaluations.hh"

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

// Pre:  t és un arbre no buit que representa una expressió booleana correcta
//       sobre els valors true,false i els operadors and,or,not.
// Post: Retorna un arbre binari de booleans
//       que té el mateix conjunt de posicions que t.
//       A més a més, per a cada posició p, el subarbre a posició p de t
//       representa una expressió que s'avalua a true si i només si
//       hi ha el valor true a la posició p de l'arbre retornat.
BinTree<bool> treeOfEvaluations(BinTree<string> t){
    if (t.empty())
    {
        return BinTree<bool>();
    }
    else if (t.value()=="and")
    {
        return BinTree<bool>(evaluate(t.left()) and evaluate(t.right()), treeOfEvaluations(t.left()), treeOfEvaluations(t.right()));
    }
    else if (t.value()=="or")
    {
        return BinTree<bool>(evaluate(t.left()) or evaluate(t.right()), treeOfEvaluations(t.left()), treeOfEvaluations(t.right()));
    }
    else if (t.value()=="not")
    {
        return BinTree<bool>(not evaluate(t.left()) , treeOfEvaluations(t.left()), treeOfEvaluations(t.right()));
    }
    else if (t.value()=="true")
    {
        return BinTree<bool>(true);
        
    }
    else {
        return BinTree<bool>(false);
        
    }
}