/** @file Ciudad.hh
    @brief Especificación de la clase Ciudad
*/

#ifndef CIUDAD_HH
#define CIUDAD_HH

#include "Total_productos.hh"


#ifndef NO_DIAGRAM
#include <map>
#include <stack>
#endif


/** @class Ciudad
    @brief Representa una ciudad. 

    La clase tiene la información del inventario de una ciudad y del peso y volumen total del mismo.
*/
class Ciudad
{
private:

    /** @brief Inventario de productos de la ciudad.    Mapa<id,<tiene, necesario>>.
    */
    map<int,pair<int,int>> InvCiudad; // Inventario de productos de la ciudad.    Mapa<id,<tiene, necesario>>

    /** @brief Peso total de inventario.
    */
    int PesoTot; // Peso total de inventario.

    /** @brief Volumen total del inventario.
    */ 
    int VolTot;  // Volumen total del inventario.

public:

    
    // Constructoras


    /** @brief Creadora por defecto. 
      \pre <em>cierto</em>
      \post El resultado es un producto sin volumen ni peso.
    */
    Ciudad();


    // Modificadoras


    /** @brief  Comerciar. 
      \pre <em>cierto</em>
      \post Las dos ciudades se intercambian los productos que le sobren a una y la otra necesite.
    */ 
    void comerciar_ciudad(Ciudad& cd, const Total_productos& tp);

    /** @brief Actualizar producto de una ciudad. 
      \pre <em>El producto existe en la ciudad</em>
      \post Se cambia el numero en posesión del producto en función del dado en el metodo;
    */
    void actualizar_producto(const int id, const int cambio, const Total_productos& tp);    

    /** @brief Leer inventario de ciudad. 
      \pre <em>cierto</em>
      \post Se lee el numero que indica la cantidad de elementos del inventario y para cada uno de ellos se leerá el identificador del producto, cuantas unidades tiene la ciudad y cuantas necesita.
    */
    void leer_inv_ciudad(const Total_productos& tp); 

    /** @brief Poner producto de ciudad. 
      \pre <em>cierto</em>
      \post Se añade un producto a la ciudad. Se escribe el peso y el volumen total..
    */
    void poner_prod_ciudad(const int id, const Total_productos& tp);
   
    /** @brief Modificar producto de ciudad. 
      \pre <em>El input contiene las unidades que tiene y que quiere del producto, el numero de unidades necesitadas es mayor a 0. El producto existe en la ciudad</em>
      \post Se modifica un producto de la ciudad. Se escribe el peso y el volumen total.
    */
    void modificar_prod_ciudad(const int id, const Total_productos& tp);

    /** @brief Quitar producto de ciudad. 
      \pre <em>cierto</em>
      \post Se quita el producto de la ciudad. Se escribe el peso y el volumen total.
    */
    void quitar_prod_ciudad(const int id, const Total_productos& tp);


    // Consultoras


    /** @brief Consultar sobrante. 
      \pre <em>El elemento existe</em>
      \post Devuelve la resta del actual menos el necesario, si el producto no existe devuelve 0.
    */
    int consultar_sobrante(const int id) const;

    /** @brief Existe producto. 
      \pre <em>cierto</em>
      \post Devuelve true si el producto existe en el inventario de la ciudad.
    */
    bool existe_producto_ciudad(const int id) const;


    // Escritoras


    /** @brief Escribir ciudad de ciudad. 
      \pre <em>cierto</em>
      \post Se escribirá su inventario, y el peso y el volumen total de los productos almacenados.
    */
    void escribir_ciudad_ciudad() const; // escribir_ciudad

    /** @brief Consultar producto de ciudad. 
      \pre <em>El producto existe en la ciudad</em>
      \post Se escribe cuantas unidades de ese producto tiene y quiere la ciudad.
    */
    void consultar_prod_ciudad(const int id) const;

};




#endif