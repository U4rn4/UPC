#include "inorderTree.hh"

BinTree<int> aux(BinTree<int> t, int& a){
    if (not t.empty())
    {
        BinTree<int> izq = aux(t.left(), a);
        int b=a;
        a++;
        BinTree<int> Der = aux(t.right(),a);
        return BinTree<int> (b, izq, Der);
    }
    else return BinTree<int>();
    
}

// Pre:  Sigui T el valor inicial de l'arbre t que es rep com a paràmetre.
// Post: Sigui T' l'arbre retornat. T i T' tenen exactament la mateixa estructura.
//       Sigui n1,n2,...,nk els nodes de T' en el recorregut en inordre de T'.
//       Llavors, n1 guarda el valor 1, n2 guarda el valor 2, ..., nk guarda el valor k.
BinTree<int> inorderTree(BinTree<int> t){
    int a=1;
    return aux(t,a);
}