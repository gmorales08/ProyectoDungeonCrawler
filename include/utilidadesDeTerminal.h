#ifndef UTILIDADES_DE_TERMINAL
#define UTILIDADES_DE_TERMINAL


#include <string>
#include <chrono> // Para pausar()
#include <thread> // Para pausar()


// LIMPIAR PANTALLA
//
// Limpia la pantalla, valido para bash
//
// Tambien cambia el color a blanco sobre negro, por si la terminal estuviese configurada en otro color,
// y oculta el prompt de la terminal
//
void limpiarPantalla();


// PAUSAR
//
// Pausa la ejecucion del programa x segundos
// 
// El numero de segundo se pasa por paramentro
// El de tipo float para poder pasar valores decimales
// Como luego se va a convertir a milisegundos en float, el maximo de decimales es 3
// Este metodo hace uso de <thread> y <chrono> para funcionar
//
void pausar(float segundos);


// IMPRIMIR DE COLORES
//
// Funciones para imprimir el texto pasado por parametro en un determinado color
// Imprime el texto en un color, y tras imprimirlo vuelve a poner el color blanco para las siguientes lineas 
// Funciona en: bash
//
// Tabla de codigos de colores:
//
//  +--COLOR------HEX-----CODIGO_BASH-+
//  |                                 |
//  | BLACK   - #000000 -     016     |
//  | BLUE    - #0000FF -     021     |
//  | GREEN   - #00FF00 -     046     |
//  | AQUA    - #00FFFF -     051     |
//  | RED     - #FF0000 -     196     |
//  | FUCHSIA - #FF00FF -     201     |
//  | YELLOW  - #FFFF00 -     226     |
//  | WHITE   - #FFFFFF -     231     |
//  +---------------------------------+
//
std::string imprimirAzul(std::string texto);
std::string imprimirVerde(std::string texto);
std::string imprimirCyan(std::string texto);
std::string imprimirRojo(std::string texto);
std::string imprimirMagenta(std::string texto);
std::string imprimirAmarillo(std::string texto);
std::string imprimirBlanco(std::string texto);


#endif //UTILIDADES_DE_TERMINAL
