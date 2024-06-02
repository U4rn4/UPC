T max_suma_cami() const{
    return sumaaux(primer_node);
}
/* Pre: el parametre implicit no es buit */
/* Post: el resultat es la suma del cami de suma maxima del parametre implicit */

T sumaaux(node_arbre* p) const{
    if (p==nullptr)
    {
        return 0;
    }
    
    return p->info + max(sumaaux(p->segE),sumaaux(p->segD));

}