/** @file Total_productos.hh
    @brief Especificación de la clase Total_productos
*/

#ifndef TOTAL_PRODUCTOS_HH
#define TOTAL_PRODUCTOS_HH

#ifndef NO_DIAGRAM
#include <iostream>
using namespace std;
#include <map>
#include <stack>
#endif

/** @class Total_productos
    @brief Representa el total de todos los productos que existen. 

    Contiene el total de todos los productos que se han declarado durante la ejecución del programa y el número de productos diferentes que existen.
*/
class Total_productos
{
private:

    /** @brief Mapa de todos los productos, Map<id,<peso,volumen>>.
    */
    map<int,pair<int,int>> Prodtot; // Map de todos los productos, Map<id,<peso,volumen>>.

    /** @brief Numero de productos distintos.
    */
    int num;    // Numero de productos distintos.

public:


    // Constructoras


    /** @brief Constructora por defecto.
      \pre <em>cierto</em>
      \post Construye la clase total productos, pone el atributo num en 1 y inicializa el map.
    */
    Total_productos();


    // Modificadoras


    /** @brief Iniciar total productos. 
      \pre <em>En el input se encuentra un numero de productos y sus atributos</em>
      \post Agregan productos al total de productos con sus atributos.
    */
    void iniciar_tot_prod();

    /** @brief Agregar productos. 
      \pre <em>En el input se encuentra los atributos de un nuevo producto</em>
      \post Agrega el producto al total de productos con sus atributos y su id respectivamente según el id del ultimo producto.
    */
    void agregar_producto();


    // Consultoras


    /** @brief Existe producto. 
      \pre <em>cierto</em>
      \post Devuelve true si el producto existe.
    */
    bool existe_producto(const int id) const;

    /** @brief Return volumen. 
      \pre <em>cierto</em>
      \post Devuelve el volumen.
    */
    int ret_vol(const int id) const;
    
    /** @brief Return peso. 
      \pre <em>cierto</em>
      \post Devuelve el peso.
    */
    int ret_peso(const int id) const;


    // Escritura


    /** @brief Escribir producto. 
      \pre <em>cierto</em>
      \post Escribe el peso y el volumen del producto.
    */
    void escribir_producto(const int id) const;

    /** @brief Consultar numero. 
      \pre <em>cierto</em>
      \post Escribe el numero de productos distintos que hay.
    */
    void consultar_num() const;
    
};

#endif