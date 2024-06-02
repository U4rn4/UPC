bool buscar(const T& x) const{
    return aux(this->primer_node,x);
}
/* Pre: cert */
/* Post: el resultat indica si x es troba al p.i. o no */

bool aux(node_arbreGen* p, const T& x) const{
    if(p==nullptr) return false;
    if(p->info==x) return true;

    int a = (p->seg).size();
    for (int i = 0; i < a; i++)
    {
        if(aux((p->seg)[i],x)) return true;
    }
    return false;
}