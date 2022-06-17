#ifndef PANTALLAS
#define PANTALLAS


#include <iostream>
#include <vector>


// CABECERA DONDE SE VAN A INCLUIR FUNCIONES QUE SE UTILICEN EN TODAS LAS PANTALLAS


// LIMPIAR BUFFER ENTRADA
//
// Limpia el buffer de entrada cin para evitar problemas de entrada de datos
//
void limpiarBufferEntrada();


// IMPRIMIR LOG
//
// Funcion para imprimir un "Mensaje del Sistema" en la parte inferior de la pantalla
// Se usara para controlar errores e imprimir informacion relacionada con la entrada de datos
// 
// Si se pasa una cadena vacia como parametro, no imprime nada
//
std::string imprimirLog(std::string mensaje);


// VALIDAR OPCION
//
// Comprueba si la opcion pasada como parametro es valida para el menu actual
//
// Se pasa como parametro la opcion a validar y la constante con las opciones validas
//
bool validarOpcion(std::string opcion, std::vector<std::string> opcionesMenu);


// CARGAR PANTALLA
//
// Carga la pantalla en cuestion y ejecuta su menu
//
// Se pasa por parametro:
//     
//     canvasPantalla: string constante de la pantalla a imprimir
//
//     opcionesMenu: opciones validas para el menu de la pantalla
//     
//     log: mensaje para imprimir en el log en caso de que sea necesario
//
void cargarPantalla(std::string canvasPantalla, std::vector<std::string> opcionesMenu, std::string log);


#endif // PANTALLAS
