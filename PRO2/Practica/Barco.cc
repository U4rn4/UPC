/**
    * @file Barco.cc
    * @brief Implementación de la clase Barco
*/
#include "Barco.hh"

Barco::Barco(){
    nvender=0;
    ncomprar=0;
    idvender=0;
    idcomprar=0;
}

void Barco::iniciar_barco(){
    cin >> idcomprar >> ncomprar >> idvender >> nvender;
}

void Barco::reiniciar_viajes(){
    viajes.clear();
}

void Barco::modificar_barco(const int comprar, const int numc, const int vender, const int numv){
    idcomprar = comprar;
    ncomprar = numc;
    idvender = vender;
    nvender = numv;
}

void Barco::escribir_barco() const{
    cout << idcomprar << " " << ncomprar << " " << idvender << " "  << nvender << endl;
    list<string>::const_iterator it = viajes.begin();
    while (it != viajes.end())
    {
        cout << *it << endl;
        ++it;
    }
}

void Barco::poner_viaje(string nombre){
    viajes.push_back(nombre);
}

int Barco::max_comprar() const{
    return ncomprar;
}

int Barco::max_vender() const{
    return nvender;
}

int Barco::ret_id_c() const{
    return idcomprar;
}

int Barco::ret_id_v() const{
    return idvender;
}