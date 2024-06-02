void arbsuma(ArbreNari& asum) const{
    asum.primer_node = copia_node_arbreNari(this->primer_node);
    aux(asum.primer_node, asum.N);
}
/* Pre: cert */
/* Post: asum és un arbre amb la mateixa estructura que el p.i.
         i cada node és la suma del node corresponent al p.i
         i tots els seus descendents al p.i. */

    int aux(node_arbreNari* p, const int n) const{
        if(p==nullptr) return 0;

        T sum =p->info;
        for (int i = 0; i < n; i++)
        {
            sum += aux((p->seg)[i], n);
        }
        p->info = sum;

        return sum;
    }