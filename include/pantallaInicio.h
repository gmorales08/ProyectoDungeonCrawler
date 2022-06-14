#ifndef PANTALLA_INICIO
#define PANTALLA_INICIO


#include <iostream>


//NO SE USA
//#define FILAS 24                      // Numero de filas que va a tener la ventana de inicio
//#define COLUMNAS 80                   // Numero de columnas que va a tener la ventana de inicio
//#define CARACTER_HORIZONTAL       "─" ///////////////////
//#define CARACTER_VERTICAL         "│" // Caracteres    //
//#define CARACTER_ESQUINA_SUP_DCHA "┐" // para dibujar  //
//#define CARACTER_ESQUINA_SUP_IZDA "┌" // los bordes    //
//#define CARACTER_ESQUINA_INF_DCHA "┘" // de la ventana //
//#define CARACTER_ESQUINA_INF_IZDA "└" ///////////////////
//FIN NO SE USA

const std::string canvasPantallaInicio = "┌─────────────────────────────────────────────────────────────────────────────┐\n"
	                                     "│                                                                             │\n"
 	                                     "│                   ___                                                       │\n"
                                         "│                  |  _ \\ _   _ _ __   __ _  ___  ___  _ __                   │\n"
                                         "│                  | | | | | | | '_ \\ / _` |/ _ \\/ _ \\| '_ \\                  │\n"
                                         "│                  | |_| | |_| | | | | (_| |  __/ (_) | | | |                 │\n"
                                         "│                  |____/ \\__,_|_| |_|\\__, |\\___|\\___/|_| |_|                 │\n"
                                         "│                                     |___/                                   │\n"
                                         "│                    ____                    _                                │\n"
                                         "│                   / ___|_ __ __ ___      _| | ___ _ __                      │\n"
                                         "│                  | |   | '__/ _` \\ \\ /\\ / / |/ _ \\ '__|                     │\n"
                          	             "│                  | |___| | | (_| |\\ V  V /| |  __/ |                        │\n"
 	                                     "│                   \\____|_|  \\__,_| \\_/\\_/ |_|\\___|_|                        │\n"
 	                                     "│                                                                             │\n"
 	                                     "│                                                                             │\n"
 	                                     "│                                 1. JUGAR                                    │\n"
 	                                     "│                                                                             │\n"
 	                                     "│                            2. ¿COMO SE JUEGA?                               │\n"
 	                                     "│                                                                             │\n"
 	                                     "│                                 3. SALIR                                    │\n"
 	                                     "│                                                                             │\n"
 	                                     "└─────────────────────────────────────────────────────────────────────────────┘\n"
	                                     "Opcion: ";


// IMPRIMIR PANTALLA INICIO
//
// Imprime una ventana de FILAS x COLUMNAS
//
// Las constantes FILAS y COLUMNAS valen por defecto 24 y 80 respectivamente
//
void imprimirPantallaInicio();


// MENU PANTALLA INICIO
//
// Funcion para controlar la seleccion del usuario en el menu
//
// Se introduce una de las siguientes opciones:
//	
//	1: JUGAR
//	2: ¿COMO SE JUEGA?
//	3: SALIR
//
// Cualquier entrada que no sea 1, 2 o 3 volvera a llamar a imprimirPantallaInicio()
//
void menuPantallaInicio();





#endif //PANTALLA_INICIO

