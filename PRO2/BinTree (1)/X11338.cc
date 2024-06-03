#include "BinTree.hh"

#include "ParInt.hh"

void sumak(BinTree<ParInt>& a, int k){
    if (!a.empty())
    {
        BinTree<ParInt> l = a.left();
        BinTree<ParInt> r = a.right();
        sumak(l, k);
        sumak(r, k);
        int s = a.value().segon()+k;
        ParInt p(a.value().primer(), s);
        a = BinTree<ParInt>(p, l, r );

    }
    
    
}
 
/*Pre: a = A */
/*Post: a es com a A amb k sumat al segon component de cada node */ 