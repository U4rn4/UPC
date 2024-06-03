#include "maximumTree.hh"

BinTree<int> maximumTree(BinTree<int> a1, BinTree<int> a2){
    if(a1.empty() and a2.empty()) return a1;
    else if(!a1.empty() and a2.empty()) return BinTree<int>(a1.value(), maximumTree(a1.left(), a2), maximumTree(a1.right(), a2));
    else if(a1.empty() and !a2.empty()) return BinTree<int>(a2.value(), maximumTree(a1, a2.left()), maximumTree(a1, a2.right()));
    else if(a1.value() > a2.value()) return BinTree<int>(a1.value(), maximumTree(a1.left(), a2.left()), maximumTree(a1.right(), a2.right()));
    else return BinTree<int>(a2.value(), maximumTree(a1.left(), a2.left()), maximumTree(a1.right(), a2.right()));
}
