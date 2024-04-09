#include "postorderTree.hh"

#include "postorderTree.hh"


BinTree<int> aux(BinTree<int> t, int& a){
    if (not t.empty())
    {
        
        BinTree<int> b= aux(t.left(),a);
        BinTree<int> c= aux(t.right(),a);
        a++;
        return BinTree<int> (a, b, c);
    }
    else return BinTree<int> ();
    
}

// Pre:  Sigui T el valor inicial de l'arbre t que es rep com a parÃƒ metre.
// Post: Sigui T' l'arbre retornat. T i T' tenen exactament la mateixa estructura.
//       Sigui n1,n2,...,nk els nodes de T' en el recorregut en postordre de T'.
//       Llavors, n1 guarda el valor 1, n2 guarda el valor 2, ..., nk guarda el valor k.
BinTree<int> postorderTree(BinTree<int> t){
    int a = 0;
    if (t.empty())
    {
        return BinTree<int> ();
    }
    else return aux(t,a);
    
}