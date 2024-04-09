#include "reverseTree.hh"

BinTree<int> reverseTree(BinTree<int> t){
    if(t.empty()) return t;
    else return BinTree<int>(t.value(), reverseTree(t.right()), reverseTree(t.left()));
}
