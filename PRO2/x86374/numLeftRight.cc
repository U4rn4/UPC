#include "numLeftRight.hh"


BinTree<int> func(BinTree<int> t, int left, int right){
    if (t.empty())
    {
        return BinTree<int>();
    }
    else if (t.value()==-1)
    {
        int a = left+1;
        int b = right+1;
        return BinTree<int>(left, func(t.left(), a, right), func(t.right(),left,b));
    }
    else
    {
        int a = 1+left;
        int b = 1+right;   
        return BinTree<int>(right, func(t.left(),a,right), func(t.right(),left,b));
    }
    
}


// Pre:  Sigui T el valor inicial de l'arbre t que es rep com a paràmetre.
//       Els valors guardats a T son tots -1 o -2.
// Post: Sigui T' l'arbre retornat. T i T' tenen exactament la mateixa estructura.
//       Sigui p una posició qualsevol de T'.
//       Si T té un valor -1 a posició p, llavors T' té el nombre de cops que
//       s'escull fill-esquerra en el camí des de l'arrel fins a posició p.
//       Si T té un valor -2 a posició p, llavors T' té el nombre de cops que
//       s'escull fill-dret en el camí des de l'arrel fins a posició p.
BinTree<int> numLeftRight(BinTree<int> t){
    BinTree<int> a = func(t, 0, 0);
    return a;
}
