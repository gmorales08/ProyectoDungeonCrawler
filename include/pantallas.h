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
// El primer parametro "tipoDeMensaje" sirve para saber el color del mensaje a imprimir:
//
//     0: aviso -> imprime un mensaje amarillo
//     1: error -> imprime un mensaje rojo
//
std::string imprimirLog(int tipoDeMensaje, std::string mensaje);


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
// Ademas devuelve la opcion seleccionada para luego pasarla al menu como parametro
//
// Se pasa por parametro:
//     
//     canvasPantalla: string constante de la pantalla a imprimir
//
//     opcionesMenu: opciones validas para el menu de la pantalla
//     
//     log: mensaje para imprimir en el log en caso de que sea necesario
//
std::string cargarPantalla(std::string canvasPantalla, std::vector<std::string> opcionesMenu, std::string log);


// IMPRIMIR PANTALLA ESTATICA
//
// Imprime una pantalla donde no haya que seleccionar ninguna opcion
//
// Se para por parametro el canvas de la pantalla
//
void imprimirPantallaEstatica(std::string canvasPantalla);


#endif // PANTALLAS
