/**
    * @file Total_productos.cc
    * @brief Implementación de la clase Total_productos
*/
#include "Total_productos.hh"

Total_productos::Total_productos(){
    num = 0;
}

void Total_productos::iniciar_tot_prod(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        agregar_producto();
    }
}

void Total_productos::agregar_producto(){
    int p,v;
    cin >> p >> v;
    num++;
    Prodtot[num] = make_pair(p,v);
}

bool Total_productos::existe_producto(const int id) const{
    return Prodtot.find(id) != Prodtot.end();
}

int Total_productos::ret_vol(const int id) const{
    return Prodtot.find(id)->second.second;
}

int Total_productos::ret_peso(const int id) const{
    return Prodtot.find(id)->second.first;
}

void Total_productos::escribir_producto(const int id) const{
    cout << id << " " << Prodtot.find(id)->second.first << " " << Prodtot.find(id)->second.second << endl;
}

void Total_productos::consultar_num() const{
    cout << num << endl;
}


