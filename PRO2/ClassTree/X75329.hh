
int freq(const T& x) const{
    return aux(x,primer_node );
}
/* Pre: cert */
/* Post: el resultat indica el nombre d'aparicions de x en el p.i. */

int aux(const T& x, node_arbre* a) const{
    if (a==nullptr)
    {
        return 0;
    }

    if(x==a->info) return 1 + aux(x,a->segE ) + aux(x,a->segD );
    
    return aux(x,a->segE ) + aux(x,a->segD );
}