#include "sumOfTree.hh"

int sumOfTree(BinTree<int> t){
    if (t.empty())
    {
        return 0;
    }
    else return sumOfTree(t.left())+sumOfTree(t.right())+t.value();
}
    