void arb_sumes(Arbre<int> &asum) const{
    asum.primer_node = copia_node_arbre(this->primer_node);
    aux(asum.primer_node);
}
/* Pre: cert */
/* Post: l'arbre asum és l'arbre suma del p.i. */

T aux(node_arbre* p) const{
    if (p==nullptr) return 0;
    int p1 = aux(p->segE);
    int p2  = aux(p->segD);
    p->info = p->info + p1 + p2;
    return p->info;
}