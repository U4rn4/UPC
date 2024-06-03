#include "BinTree.hh"
#include <iostream>

bool poda_subarbre(BinTree<int> &a, int x){
    
    if (a.empty())
    {
        return false;
    }
    else if (a.value()==x)
    {
        a = BinTree<int> ();
        return true;
    }
    else{ 
        bool b;

        BinTree<int> a1 = a.left();
        b= poda_subarbre(a1,x);
        if (b)
        {
            a = BinTree<int> (a.value(),a1,a.right());
        }
        if(not b){
            BinTree<int> a2 = a.right();
            b = poda_subarbre(a2,x);
            if(b) a = BinTree<int> (a.value(),a.left(),a2);
        }
        return b;
    }
}