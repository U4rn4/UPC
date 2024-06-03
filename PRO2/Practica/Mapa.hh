/** @file Mapa.hh
    @brief Especificación de la clase Mapa
*/

#ifndef MAPA_HH
#define MAPA_HH


#include "Ciudad.hh"
#include "Barco.hh"


#ifndef NO_DIAGRAM
#include "BinTree.hh"
#include <map>
#include <list>
#include <stack>
#endif

/** @class Mapa
    @brief Representa el mapa de una cuenca fluvial. 

    Contiene las ciudades de la cuenca con sus identificadores y el mapa en formato árbol de las mismas ciudades.
*/
class Mapa
{
private:

    /** @brief Mapa del rio, cada nodo es una ciudad.
    */
    BinTree<string> cuenca; // Mapa del rio, cada nodo es una ciudad.

    /** @brief Map de todas las ciudades con sus respectivos nombres.
    */
    map<string,Ciudad> mapa; // Cada ciudad con su nombre respectivo

    /** @brief  Función redistribuir. 
      \pre <em>cierto</em>
      \post Comercio de todas las ciudades de forma recursiva, empieza por el nodo, luego va a la izquiera y luego a la derecha mirandolo como un arbol con el nodo principal arriba.
    */ 
    void funcion_redistriubuir(const BinTree<string>& bt, const Total_productos& tp);

    /** @brief Función de leer el mapa. 
      \pre <em>cierto</em>
      \post Lee de forma recursiva la estructura del rio.
    */
    BinTree<string> funcion_leer_mapa();

    /** @brief Recursividad de hacer viaje. 
      \pre <em>cierto</em>
      \post El barco busca la ruta a partir de la desembocadura que le permita comprar y vender el mayor número posible de productos.
    */
    int rec_viaje(const BinTree<string>& bt, Barco& bc, int vendidas, int compradas, vector<string>& v) const;

    /** @brief Calcular el comercio del barco. 
      \pre <em>cierto</em>
      \post El barco calcula los comercios que tiene con cada ciudad.
    */
    void comercio_barco(string nombrec, Barco& bc, int& vendidas, int& compradas, int& vc, int& cc) const;

public:

    // Consultoras


    /** @brief Creadora por defecto. 
      \pre <em>cierto</em>
      \post El resultado es un mapa vacío.
    */
    Mapa();


    // Modificadoras


    /** @brief Iniciar mapa. 
      \pre <em>cierto</em>
      \post Se llama para leer la estructura del rio.
    */
    void iniciar_mapa();

    /** @brief Leer rio. 
      \pre <em>cierto</em>
      \post Se la estructura en forma de BinTree del rio que genera el mapa.
    */
    void leer_rio();

    /** @brief Leer inventario. 
      \pre <em>La ciudad existe</em>
      \post Se lee el numero que indica la cantidad de elementos del inventario y para cada uno de ellos se leerá el identificador del producto, cuantas unidades tiene la ciudad y cuantas necesita.
    */
    void leer_inventario(const string nombre, const Total_productos& tp);

    /** @brief Poner producto. 
      \pre <em>cierto</em>
      \post Se usa para poner un producto en una ciudad. 
    */ 
    void poner_prod(const string nombre, int prod, const Total_productos& tp);

    /** @brief  Quitar producto. 
      \pre <em>cierto</em>
      \post Se usa para quitar un producto en una ciudad. 
    */ 
    void quitar_prod(const string nombre, const int prod, const Total_productos& tp);

    /** @brief  Modificar producto. 
      \pre <em>cierto</em>
      \post Se usa para modificar un producto en una ciudad. 
    */ 
    void modificar_prod(const string nombre, const int prod, const Total_productos& tp);
    
    /** @brief  Comerciar. 
      \pre <em>cierto</em>
      \post Las dos ciudades se intercambian los productos que le sobren a una y la otra necesite.
    */ 
    void comerciar(const string ciudad1, const string ciudad2, const Total_productos& tp); // se crea un loop donde se prueba si a una ciudad le falta algo y si a la otra le sobra de eso

    /** @brief  Redistribuir. 
      \pre <em>cierto</em>
      \post Comercio de todas las ciudades de forma recursiva, empieza por el nodo, luego va a la izquiera y luego a la derecha mirandolo como un arbol con el nodo principal arriba.
    */ 
    void redistribuir(const Total_productos& tp);

    /** @brief Hacer viaje. 
      \pre <em>cierto</em>
      \post El barco busca la ruta a partir de la desembocadura que le permita comprar y vender el mayor número posible de productos. En caso que haya vez encontrada la ruta, se hace el viaje y se compran y venden los productos a lo largo de la ruta, modificándose los inventarios de las ciudades.  Se escribe el total de unidades de productos compradas y vendidas por el barco.
    */
    void hacer_viaje(Barco& barco, Total_productos& Cjt_p);


    // Consultoras


    /** @brief Existe ciudad. 
      \pre <em>cierto</em>
      \post Devuelve true si la ciudad existe en el mapa.
    */
    bool existe_ciudad(const string nombre) const;

    /** @brief Existe producto en ciudad. 
      \pre <em>cierto</em>
      \post Devuelve true si el producto existe en la ciudad.
    */
    bool existe_prod(const string nombre, const int prod) const;


    // Escritura

    /** @brief Escribir ciudad. 
      \pre <em>Existe la ciudad</em>
      \post Sirve para escribir los datos de una ciudad.
    */ 
    void escribir_ciudad(const string nombre) const;

    /** @brief Consultar producto. 
      \pre <em>Existe el producto</em>
      \post Se escribe cuantas unidades de ese producto tiene y quiere la ciudad.
    */
    void consultar_prod(const string nombre,  const int prod) const;
};


#endif