#include "searchInBST.hh"

// Pre: t és un BST
// Post: Retorna cert si i només si x apareix a t

bool searchInBST(BinTree<int> t, int x){
    bool b=false;
    if(t.empty()) return false;
    else if (t.value()==x) return true;
    else{
        
        if(t.value()>x) b = searchInBST(t.left(),x);
        if(!b and t.value()<x) b = searchInBST(t.right(),x);
    }
    return b;
}