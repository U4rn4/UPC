/** @file Barco.hh
    @brief Especificación de la clase Barco
*/

#ifndef BARCO_HH
#define BARCO_HH



#ifndef NO_DIAGRAM
#include <list>
#include <iostream>
using namespace std;
#include <stack>
#endif

/** @class Barco
    @brief Representa el barco. 

    Representa el barco que se usa para la operación hacer_viaje entre otras. Puede contener un cierto número de objetos para vender o comprar.
*/
class Barco
{
private:
    
    /** @brief Numero que se quiere vender del producto.
    */
    int nvender;    // Numero que se quiere vender del producto

    /** @brief Numero que se quiere comprar del producto.
    */
    int ncomprar;   // Numero que se quiere comprar del producto

    /** @brief Producto a vender.
    */
    int idvender;   // Producto a vender

    /** @brief Producto a comprar.
    */
    int idcomprar;  // Producto a comprar

    /** @brief Son los viajes realizados en orden cronologico, contiene la última ciudad visitada por cada viaje.
    */
    list<string> viajes;  // Son los viajes realizados en orden cronologico, contiene la ultima ciudad visitada por cada viaje.

public:

    // Constructoras


    /** @brief Creadora por defecto. 
      \pre <em>cierto</em>
      \post El resultado es una clase Barco inicializada.
    */
    Barco();
    

    // Modificadoras


    void poner_viaje(string nombre);

    /** @brief Iniciar Barco. 
      \pre <em>cierto</em>
      \post Se leen los atributos iniciales del barco.
    */
    void iniciar_barco();
    
    /** @brief Reiniciar viajes. 
      \pre <em>cierto</em>
      \post Reinicia el vector de viajes.
    */
    void reiniciar_viajes();

    /** @brief Modificar barco. 
      \pre <em>Ambas cantidades existiran, serán no negativas y al menos una de ellas será estrictamente positiva.</em>
      \post Se han modificado los atributos del barco correctamente.
    */
    void modificar_barco(const int comprar, const int numc, const int vender, const int numv);


    // Consultoras


    /** @brief Maximo comprar. 
      \pre <em>cierto</em>
      \post Devuelve el valor del numero  que se quiere comprar del productos.
    */
    int max_comprar() const;

    /** @brief Maximo vender. 
      \pre <em>cierto.</em>
      \post Devuelve el valor del numero  que se quiere vender del productos.
    */
    int max_vender() const;

    /** @brief Identificador vender. 
      \pre <em>cierto.</em>
      \post Devuelve el identificador del producto que se quiere vender.
    */
    int ret_id_v() const;

    /** @brief Identificador comprar. 
      \pre <em>cierto.</em>
      \post Devuelve el identificador del producto que se quiere comprar.
    */
    int ret_id_c() const;


    // Escritoras


    /** @brief Escribir Barco. 
      \pre <em>cierto</em>
      \post Se escriben el identificador del producto que se quiere comprar y la cantidad, y el identificador del producto que se quiere vender y la cantidad, y se escribe  los viajes realizados, en orden cronológico. Para cada viaje solo se ha de escribir la última ciudad visitada de la ruta escogida.
    */
    void escribir_barco() const;

};



#endif