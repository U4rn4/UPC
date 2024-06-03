/** 
 * @mainpage Simulación de comercio entre ciudades de una cuenca fluvial.
 
En esta práctica se simula el comercio entre ciudades de una cuenca fluvial. Cada ciudad tiene un inventario de productos con la cantidad que tienen de cada una y la cantidad necesaria de los mismos. Cada ciudad busca tener la cantidad necesaria de cada producto dentro de su inventario. Se pueden modificar todos los participantes de la simulación a través de las opciones del menú, esto incluye la cuenca fluvial, las ciudades, los productos y el barco.

Las ciudades están colocadas en una cuenca fluvial que imita la forma de un árbol binario. 

Existe un barco que puede vender o comprar productos designados a través de rutas de la cuenca. El programa principal es program.cc y el resto de clases son Ciudad, Total_productos, Barco y Mapa.
*/

/** @file program.cc
    @brief Programa principal de la práctica con el menú de opciones
*/
#include "Mapa.hh"
#include "Total_productos.hh"
#include "Barco.hh"

int main()
{
    Total_productos tp;
    Barco barco;
    Mapa mp;
    string op;

    tp.iniciar_tot_prod();
    mp.iniciar_mapa();
    barco.iniciar_barco();

    cin >> op;
    while (op!="fin")
    {
        if (op=="leer_rio" or op=="lr")
        {
            if(op=="leer_rio") cout << "#leer_rio" << endl;
            else cout << "#lr" << endl;
            mp.leer_rio();
            barco.reiniciar_viajes();
        }
        else if (op=="leer_inventario" or op=="li")
        {
            string name;
            cin >> name;

            if(op=="leer_inventario")cout << "#leer_inventario " << name << endl;
            else cout << "#li " << name << endl;

            if(not mp.existe_ciudad(name)){
                cout << "error: no existe la ciudad" << endl;
                int n,aux;
                cin >> n;
                for (int i = 0; i < n; i++)
                {
                    cin >> aux;
                    cin >> aux;
                    cin >> aux;
                } 
            }
            else mp.leer_inventario(name,tp);
        }
        else if (op=="leer_inventarios" or op=="ls")
        {
            string name;    

            if(op=="leer_inventarios")cout << "#leer_inventarios" << endl;
            else cout << "#ls" << endl;
            cin >> name;
            while ( name!="#")
            {
                mp.leer_inventario(name,tp);
                cin >> name;
            }
            
            
        }
        else if (op=="modificar_barco" or op=="mb")
        {
            if(op=="modificar_barco")cout << "#modificar_barco" << endl;
            else cout << "#mb" << endl;

            int idvender_, idcomprar_,nvender_,ncomprar_;
            cin >> idcomprar_ >> ncomprar_ >> idvender_ >> nvender_;
            
            if((not tp.existe_producto(idcomprar_)) or (not tp.existe_producto(idvender_))) cout << "error: no existe el producto" << endl;
            else if(idcomprar_ == idvender_) cout << "error: no se puede comprar y vender el mismo producto" << endl;
            else barco.modificar_barco( idcomprar_,ncomprar_,idvender_,nvender_);
        }
        else if (op=="escribir_barco" or op=="eb")
        {
            if(op=="escribir_barco")cout << "#escribir_barco" << endl;
            else cout << "#eb" << endl;
            barco.escribir_barco();
        }
        else if (op=="consultar_num" or op=="cn")
        {
            if(op=="consultar_num")cout << "#consultar_num" << endl;
            else cout << "#cn" << endl;
            tp.consultar_num();
        }
        else if (op=="agregar_productos" or op=="ap")
        {
            int n;
            cin >> n;

            if(op=="agregar_productos") cout << "#agregar_productos " << n << endl;
            else cout << "#ap " << n << endl;
            
            for (int i = 0; i < n; i++)
            {
                tp.agregar_producto();
            }                
        }
        else if (op=="escribir_producto" or op=="ep")
        {
            int id;
            cin >> id;
            if(op=="escribir_producto")cout << "#escribir_producto " << id << endl;
            else cout << "#ep " << id << endl;
           
            if(not tp.existe_producto(id)) cout << "error: no existe el producto" << endl;
            else tp.escribir_producto(id);
        }
        else if (op=="escribir_ciudad" or op=="ec")
        {
            string name;
            cin >> name;
            if(op=="escribir_ciudad")cout << "#escribir_ciudad " << name << endl;
            else cout << "#ec " << name << endl;
   
            if(not mp.existe_ciudad(name)) cout << "error: no existe la ciudad" << endl;
            else mp.escribir_ciudad(name);
        }
        else if (op=="poner_prod" or op=="pp")
        {
            string name;
            int prod;
            cin >> name >> prod;

            if(op=="poner_prod")cout << "#poner_prod " << name << " " << prod << endl;
            else cout << "#pp " << name << " " << prod << endl;

            if(not tp.existe_producto(prod)) cout << "error: no existe el producto" << endl;
            else  if(not mp.existe_ciudad(name)) cout << "error: no existe la ciudad" << endl;
            else if(mp.existe_prod(name, prod)) cout << "error: la ciudad ya tiene el producto" << endl;
            else mp.poner_prod(name, prod,tp);
        }
        else if (op=="modificar_prod" or op=="mp")
        {
            string name;
            int prod;
            cin >> name >> prod;

            if(op=="modificar_prod")cout << "#modificar_prod " << name << " " << prod << endl;
            else cout << "#mp "  << name << " " << prod << endl;

            if(not tp.existe_producto(prod)) cout << "error: no existe el producto" << endl;
            else if(not mp.existe_ciudad(name)) cout << "error: no existe la ciudad" << endl;
            else if(not mp.existe_prod(name, prod)) cout << "error: la ciudad no tiene el producto" << endl;
            else mp.modificar_prod(name, prod,tp);
        }
        else if (op=="quitar_prod" or op=="qp")
        {
            string name;
            int prod;
            cin >> name >> prod;

            if(op=="quitar_prod")cout << "#quitar_prod "  << name << " " << prod << endl;
            else cout << "#qp "  << name << " " << prod << endl;

            if(not tp.existe_producto(prod)) cout << "error: no existe el producto" << endl;
            else if(not mp.existe_ciudad(name)) cout << "error: no existe la ciudad" << endl;
            else if(not mp.existe_prod(name, prod)) cout << "error: la ciudad no tiene el producto" << endl;
            else mp.quitar_prod(name, prod,tp);
        }
        else if (op=="consultar_prod" or op=="cp")
        {
            string name;
            int prod;
            cin >> name >> prod;

            if(op=="consultar_prod")cout << "#consultar_prod "  << name << " " << prod << endl;
            else cout << "#cp "  << name << " " << prod << endl;

            if(not tp.existe_producto(prod)) cout << "error: no existe el producto" << endl;
            else if(not mp.existe_ciudad(name)) cout << "error: no existe la ciudad" << endl;
            else if(not mp.existe_prod(name, prod)) cout << "error: la ciudad no tiene el producto" << endl;
            else mp.consultar_prod(name, prod);
        }
        else if (op=="comerciar" or op=="co")
        {
            string c1,c2;
            cin >> c1 >> c2;

            if(op=="comerciar")cout << "#comerciar " << c1 << " " << c2 << endl;
            else cout << "#co " << c1 << " " << c2 << endl;

            if((not mp.existe_ciudad(c1)) or (not mp.existe_ciudad(c2))) cout << "error: no existe la ciudad" << endl;
            else if(c1==c2) cout << "error: ciudad repetida" << endl;
            else {
                mp.comerciar(c1, c2, tp);
            }
        }
        else if (op=="redistribuir" or op=="re")
        {
            if(op=="redistribuir")cout << "#redistribuir" << endl;
            else cout << "#re" << endl;
            mp.redistribuir(tp);
        }
        else if (op=="hacer_viaje" or op=="hv")
        {
            if(op=="hacer_viaje")cout << "#hacer_viaje" << endl;
            else cout << "#hv" << endl;
            mp.hacer_viaje(barco,tp);
        }
        else if(op=="//") getline(cin,op);
        cin >> op;
        
    }
    
}
