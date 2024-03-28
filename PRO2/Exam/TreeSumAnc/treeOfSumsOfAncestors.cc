#include "BinTree.hh"
#include "treeOfSumsOfAncestors.hh"

// Pre:
// Post: Retorna un arbre d'enters t' amb la mateixa estructura que t.
//       Per a cada posició p, el valor guardat a t' a posició p és igual a la suma
//       dels valors guardats a t a posició p i a posicions ancestres de p.
BinTree<int> treeOfSumsOfAncestors(const BinTree<int> t){

    if(t.empty()) return BinTree<int> ();
    else if(!t.left().empty() and !t.right().empty()) return BinTree<int> (t.value(), treeOfSumsOfAncestors( BinTree<int> (t.left().value() + t.value(), t.left().left(), t.left().right())) , treeOfSumsOfAncestors(BinTree<int> (t.right().value() + t.value(), t.right().left(), t.right().right())));
    else if(!t.right().empty()) return BinTree<int> (t.value(), t.left(), treeOfSumsOfAncestors(BinTree<int> (t.right().value() + t.value(), t.right().left(), t.right().right())));
    else if(!t.left().empty()) return BinTree<int> (t.value(), treeOfSumsOfAncestors( BinTree<int> (t.left().value() + t.value(), t.left().left(), t.left().right())) , t.right());
    else return BinTree<int> (t.value());
}