/**
    * @file Mapa.cc
    * @brief Implementación de la clase Mapa
*/
#include "Mapa.hh"

Mapa::Mapa(){}

void Mapa::iniciar_mapa(){
    cuenca = funcion_leer_mapa();
}

BinTree<string> Mapa::funcion_leer_mapa(){
    string str;

    cin >> str;
    
    if (str!="#")
    {
        mapa[str] = Ciudad();
        BinTree<string> left = funcion_leer_mapa();
        BinTree<string> right = funcion_leer_mapa();
        return BinTree<string>(str, left, right);
    }
    else return BinTree<string>();   
}

void Mapa::leer_rio(){
    mapa.clear();
    cuenca = funcion_leer_mapa();

}

void Mapa::leer_inventario(const string nombre, const Total_productos& tp){
    mapa.at(nombre).leer_inv_ciudad(tp);
}

void Mapa::escribir_ciudad(const string nombre) const{
    mapa.find(nombre)->second.escribir_ciudad_ciudad();
}

void Mapa::poner_prod(const string nombre, const int prod, const Total_productos& tp){
    mapa[nombre].poner_prod_ciudad(prod,tp);
}

void Mapa::quitar_prod(const string nombre, const int prod, const Total_productos& tp){
    mapa[nombre].quitar_prod_ciudad(prod,tp);
}

void Mapa::modificar_prod(const string nombre, int prod,const  Total_productos& tp){
    mapa[nombre].modificar_prod_ciudad(prod,tp);
}

void Mapa::comerciar(const string ciudad1, const string ciudad2,const  Total_productos& tp){

    mapa[ciudad1].comerciar_ciudad(mapa[ciudad2], tp);
    
}

void Mapa::redistribuir(const Total_productos& tp){
    funcion_redistriubuir(cuenca,tp);
}

void Mapa::funcion_redistriubuir(const BinTree<string>& bt, const Total_productos& tp){
    if (not bt.empty())
    {
        string str;
        str=bt.value();
        if (not bt.left().empty())
        {
            comerciar(str, bt.left().value(), tp);
        }
        if (not bt.right().empty())
        {
            comerciar(str, bt.right().value(), tp);
        }
        funcion_redistriubuir(bt.left(), tp);
        funcion_redistriubuir(bt.right(), tp);
    }
    
}

bool Mapa::existe_ciudad(const string nombre) const{
    return mapa.find(nombre) != mapa.end();
}

bool Mapa::existe_prod(const string nombre, const int prod) const{
    return mapa.at(nombre).existe_producto_ciudad(prod);
}

void Mapa::consultar_prod( const string nombre, const int id) const{
    mapa.at(nombre).consultar_prod_ciudad(id);
}


void Mapa::hacer_viaje(Barco& barco, Total_productos& Cjt_p)
{
    vector<string> v;

    int p = rec_viaje(cuenca,barco,0,0,v); // busca la mejor ruta y la guarda en v, devuelve <vendidas,compradas>

    if(v.size()>0) barco.poner_viaje(v[v.size()-1]); // si existe una ruta pone el ultimo elemento en el barco

    int idv = barco.ret_id_v();
    int idc = barco.ret_id_c();
    int v_ciudad, c_ciudad;
    int vendidas = 0;
    int compradas = 0;
   for(int i = 0; i < v.size(); ++i){
        comercio_barco(v[i],barco,vendidas,compradas,v_ciudad,c_ciudad);
    
        mapa[v[i]].actualizar_producto(idv, v_ciudad, Cjt_p);
        mapa[v[i]].actualizar_producto(idc, -c_ciudad, Cjt_p);
   }

    cout << p << endl;

}


int Mapa::rec_viaje(const BinTree<string>& bt, Barco& bc, int vendidas, int compradas, vector<string>& v) const{
    if (bt.empty())
    {
        return vendidas+compradas;
    }
    bool vendido = false;
    bool comprado = false;

    if (vendidas < bc.max_vender())
    {
        if (mapa.at(bt.value()).consultar_sobrante(bc.ret_id_v())<0)
        {
            
            if(mapa.at(bt.value()).consultar_sobrante(bc.ret_id_v())*(-1) >= bc.max_vender()-vendidas){
                vendidas = bc.max_vender();
                vendido = true;
            }
            else if (mapa.at(bt.value()).consultar_sobrante(bc.ret_id_v())*(-1) < bc.max_vender()-vendidas)
            {
                vendidas += mapa.at(bt.value()).consultar_sobrante(bc.ret_id_v())*(-1);
                vendido = true;
            }
        }
    }
    if (compradas < bc.max_comprar())
    {
        if (mapa.at(bt.value()).consultar_sobrante(bc.ret_id_c())>0)
        {
            
            if(mapa.at(bt.value()).consultar_sobrante(bc.ret_id_c())>=bc.max_comprar()-compradas){
                compradas = bc.max_comprar();
                comprado = true;
            }
            else if (mapa.at(bt.value()).consultar_sobrante(bc.ret_id_c())<bc.max_comprar()-compradas)
            {
                compradas += mapa.at(bt.value()).consultar_sobrante(bc.ret_id_c());
                comprado = true;
            }
        }
    }
    if (vendidas == bc.max_vender() and compradas == bc.max_comprar())
    {
        v.push_back(bt.value());
        return vendidas+compradas;
    }

    vector<string> vl;
    vector<string> vr;
    int a = rec_viaje( bt.left(),  bc, vendidas, compradas, vl);
    int b = rec_viaje( bt.right(), bc, vendidas, compradas,vr);

    if (vl.size()!=0 or vr.size()!=0) {
        if (a > b)
        {
            v=vl;
            v.insert(v.begin(),bt.value());
            return a;
        }
        else if (a < b)
        {
            v=vr;  
            v.insert(v.begin(),bt.value());
            return b;
        }
        else 
        {
            if (vl.size()>vr.size())
            {
                v=vr;
                v.insert(v.begin(),bt.value());
                return b;
            }
            else
            {
                v=vl;    
                v.insert(v.begin(),bt.value());
                return a;
            }
        }
    }
    if(vendido or comprado) v.insert(v.begin(),bt.value());
    return vendidas+compradas;
}

void Mapa::comercio_barco(string nombrec, Barco& bc, int& vendidas, int& compradas, int& vc, int& cc) const {
    cc = 0;
    vc = 0;
    
    if (mapa.at(nombrec).consultar_sobrante(bc.ret_id_c())>0)
    {
        
        if(mapa.at(nombrec).consultar_sobrante(bc.ret_id_c())>=bc.max_comprar()-compradas){

            cc = bc.max_comprar()-compradas;
            compradas = bc.max_comprar();
        }
        else if (mapa.at(nombrec).consultar_sobrante(bc.ret_id_c())<bc.max_comprar()-compradas)
        {
            compradas += mapa.at(nombrec).consultar_sobrante(bc.ret_id_c());
            cc = mapa.at(nombrec).consultar_sobrante(bc.ret_id_c());
        }
    }

    if (mapa.at(nombrec).consultar_sobrante(bc.ret_id_v())<0)
    {
        
        if(mapa.at(nombrec).consultar_sobrante(bc.ret_id_v())*(-1) >= bc.max_vender()-vendidas){
            vc = bc.max_vender()-vendidas;
            vendidas = bc.max_vender();
        }
        else if (mapa.at(nombrec).consultar_sobrante(bc.ret_id_v())*(-1) < bc.max_vender()-vendidas)
        {
            vendidas += mapa.at(nombrec).consultar_sobrante(bc.ret_id_v())*(-1);
            vc = mapa.at(nombrec).consultar_sobrante(bc.ret_id_v())*(-1);
            
        }
    }

}
