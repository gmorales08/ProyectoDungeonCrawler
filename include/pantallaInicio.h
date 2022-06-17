#ifndef PANTALLA_INICIO
#define PANTALLA_INICIO


#include <iostream>
#include <vector>


const std::string canvasPantallaInicio = "┌─────────────────────────────────────────────────────────────────────────────┐\n"
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
 	                                     "└─────────────────────────────────────────────────────────────────────────────┘\n";

const std::vector<std::string> opcionesPantallaInicio = {"1", "2", "3"};


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
void menuPantallaInicio(std::string opcion);


#endif //PANTALLA_INICIO
