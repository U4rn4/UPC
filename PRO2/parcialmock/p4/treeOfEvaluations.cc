#include "treeOfEvaluations.hh"

BinTree<bool> aux(BinTree<string> t, bool& b){
    if (t.empty())
    {
        return BinTree<bool>();
    }
    else if (t.value()=="and")
    {
        bool a1=false, a2=false;
        aux(t.left(),a1);
        aux(t.right(),a2);
        return BinTree<bool>(a1 and a2, aux(t.left(), a1), aux(t.right(),a1));
    }
    else if (t.value()=="or")
    {
        bool a1=false, a2=false;
        aux(t.left(),a1);
        if(not a1) aux(t.right(),a2);
        return BinTree<bool>(a1 or a2, aux(t.left(),a1), aux(t.right(),a1));
    }
    else if (t.value()=="not")
    {
        bool a1 = not aux(t.left(), b).value();
        return BinTree<bool>(a1, aux(t.left(),a1), aux(t.right(),a1));
    }
    else if (t.value()=="true")
    {
        b=true;
        return BinTree<bool>(true);
        
    }
    else {
        b=false;
        return BinTree<bool>(false);
        
    }
    
}

// Pre:  t és un arbre no buit que representa una expressió booleana correcta
//       sobre els valors true,false i els operadors and,or,not.
// Post: Retorna un arbre binari de booleans
//       que té el mateix conjunt de posicions que t.
//       A més a més, per a cada posició p, el subarbre a posició p de t
//       representa una expressió que s'avalua a true si i només si
//       hi ha el valor true a la posició p de l'arbre retornat.
BinTree<bool> treeOfEvaluations(BinTree<string> t){
    bool b=false;
    return aux(t, b);
}