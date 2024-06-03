/**
    * @file Ciudad.cc
    * @brief Implementación de la clase Ciudad
*/
#include "Mapa.hh"

Ciudad::Ciudad(){
    PesoTot =0;
    VolTot=0;
};

void Ciudad::actualizar_producto(const int id, const int cambio, const Total_productos& tp){
    if (cambio != 0)
    {
        InvCiudad[id].first += cambio;
        PesoTot += cambio*tp.ret_peso(id);
        VolTot += cambio*tp.ret_vol(id);
    }
    
}

void Ciudad::leer_inv_ciudad(const Total_productos& tp){
    InvCiudad.clear();
    int num, id, t, n;
    cin >> num;
    VolTot = 0;
    PesoTot = 0;
    for (int i = 0; i < num; i++)
    {
        cin >> id >> t >> n;
        PesoTot += t*tp.ret_peso(id);
        VolTot += t*tp.ret_vol(id);
        InvCiudad[id] = make_pair(t,n);
    }
    
}

void Ciudad::poner_prod_ciudad(const int id, const Total_productos& tp){
    int t, n;
    cin >> t >> n;
    PesoTot += t*tp.ret_peso(id);
    VolTot += t*tp.ret_vol(id);
    InvCiudad[id] = make_pair(t,n);

    cout << PesoTot << " " << VolTot << endl;
}

void Ciudad::modificar_prod_ciudad(const int id, const Total_productos& tp){
    int t, n,c;
    cin >> t >> n;
    c= t - InvCiudad[id].first;
    PesoTot += c*tp.ret_peso(id);
    VolTot += c*tp.ret_vol(id);
    InvCiudad[id] = make_pair(t,n);

    cout << PesoTot << " " << VolTot << endl;
}

void Ciudad::quitar_prod_ciudad(const int id, const Total_productos& tp){
    int n = InvCiudad[id].first;
    PesoTot -= n*tp.ret_peso(id);
    VolTot -= n*tp.ret_vol(id);
    InvCiudad.erase(id);
    cout << PesoTot << " " << VolTot << endl;

}

int Ciudad::consultar_sobrante(const int id) const{
    if(InvCiudad.find(id)==InvCiudad.end()) return 0;
    else return InvCiudad.at(id).first - InvCiudad.at(id).second;
}

bool Ciudad::existe_producto_ciudad(const int id) const{
    return InvCiudad.find(id)!=InvCiudad.end();
}

void Ciudad::escribir_ciudad_ciudad() const{
    map<int, pair<int, int>>::const_iterator it = InvCiudad.begin();
    
    while (it!=InvCiudad.end())
    {
        cout << it->first << " " << it ->second.first << " " << it->second.second << endl;
        it++;
    }
    cout << PesoTot << " " << VolTot << endl;
}

void Ciudad::consultar_prod_ciudad(const int id) const{
    cout << InvCiudad.at(id).first << " " << InvCiudad.at(id).second << endl;
}

void Ciudad::comerciar_ciudad(Ciudad& cd, const Total_productos& tp){
    
    map<int,pair<int,int>>::iterator it = InvCiudad.begin();
    map<int,pair<int,int>>::iterator it2 = cd.InvCiudad.begin();

    while (it!=InvCiudad.end() and it2!=cd.InvCiudad.end())
    {
        if (it->first == it2->first)
        {
            int c1 = consultar_sobrante(it->first);
            int c2 = cd.consultar_sobrante(it->first);
            if (c1<0 and c2>0)
            {
                if(c1*(-1) >= c2){
                    actualizar_producto(it->first,c2,tp);
                    cd.actualizar_producto(it->first,-c2,tp);
                }
                else if (c1*(-1) < c2)
                {
                    actualizar_producto(it->first,-c1,tp);
                    cd.actualizar_producto(it->first,c1,tp);
                }
                
            }
            else if (c1>0 and c2<0)
            {
                if(c1 >= c2*(-1)){
                    actualizar_producto(it->first,c2,tp);
                    cd.actualizar_producto(it->first,-c2,tp);
                }
                else if (c1 < c2*(-1))
                {
                    actualizar_producto(it->first,-c1,tp);
                    cd.actualizar_producto(it->first,c1,tp);
                }
            }
            ++it;
            ++it2;
        }
        else if(it->first < it2->first) ++it;
        else ++it2;
    }
}