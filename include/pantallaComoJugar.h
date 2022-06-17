#ifndef PANTALLA_COMO_JUGAR
#define PANTALLA_COMO_JUGAR


#include <iostream>
#include <vector>
#include "utilidadesDeTerminal.h"


const std::string canvasPantallaComoJugar =                  "┌─────────────────────────────────────────────────────────────────────────────┐\n"
 	                                                         "│                                                                             │\n"
                                                             "│                                ┌────────────┐                               │\n"
                                                             "│                                │ COMO JUGAR │                               │\n"
                                                             "│                                └────────────┘                               │\n"
   	                                                         "│                                                                             │\n"
 	                                                         "│                                                                             │\n"                         
                                                             "│                                                                             │\n"
                                                             "│                          1. Objetivo del juego                              │\n"
                                                             "│                                                                             │\n"
                                                             "│                          2. Creacion del personaje                          │\n"
                                                             "│                                                                             │\n"
                          	                                 "│                          3. Sistema de combate                              │\n"
 	                                                         "│                                                                             │\n"
 	                                                         "│                          4. Eventos                                         │\n"
 	                                                         "│                                                                             │\n"
 	                                                         "│                          5. Volver                                          │\n"
 	                                                         "|                                                                             |\n"
											                 "│                                                                             │\n"
 	                                                         "│                                                                             │\n"
 	                                                         "└─────────────────────────────────────────────────────────────────────────────┘\n";

const std::vector<std::string> opcionesPantallaComoJugar = {"1", "2", "3", "4", "5"};

const std::string canvasPantallaObjetivo = 					 "┌─────────────────────────────────────────────────────────────────────────────┐\n"
										   					 "│                                                                             │\n"
										   					 "│                           ┌────────────────────┐                            │\n"
										   					 "│                           │ OBJETIVO DEL JUEGO │                            │\n"
										   					 "│                           └────────────────────┘                            │\n"
										   					 "│                                                                             │\n"
										   					 "│ Para poder completar el juego debes avanzar los 10 pisos de la mazmorra y   │\n"                         
										   					 "│ derrotar al jefe final                                                      │\n"
										   					 "│                                                                             │\n"
										   					 "│ En cada piso puedes encontrarte enemigos o, si tienes suerte, un evento.    │\n"
										   					 "│ Para poder derrotar a estos enemigos debes crear un personaje con el que    │\n"
										   					 "│ iras progresando segun avances en la mazmorra.                              │\n"
										   					 "│                                                                             │\n"
										   					 "│ El daño que sufras se ira acumulando tras cada combate, asi como las        │\n"
										   					 "| mejoras que obtengas y la magia que consumas.                               |\n"
										   					 "│                                                                             │\n"
										   					 "│ Si caes derrotado en combate, deberas volver a empezar el juego, creando un │\n"
										   					 "│ personaje nuevo y comenzando desde el primer piso.                          │\n"
										   					 "│                                                                             │\n"
										   					 "│                                                                             │\n"
										   					 "└─────────────────────────────────────────────────────────────────────────────┘\n";

const std::string canvasPantallaComoJugarCreacionPersonaje = "┌─────────────────────────────────────────────────────────────────────────────┐\n"
															 "│                                                                             │\n"
															 "│                         ┌────────────────────────┐                          │\n"
															 "│                         │ CREACION DEL PERSONAJE │                          │\n"
															 "│                         └────────────────────────┘                          │\n"
															 "│                                                                             │\n"
															 "│                                                                             │\n"
															 "│                               1. RAZA                                       │\n"                        
															 "│                                                                             │\n"
															 "│                               2. CLASE                                      │\n"
															 "│                                                                             │\n"
															 "│                               3. SUBCLASE                                   │\n"
															 "│                                                                             │\n"
															 "│                               4. ARMA                                       │\n"
															 "│                                                                             │\n"
															 "|                               5. ATRIBUTOS                                  |\n"
															 "│                                                                             │\n"
															 "│                               6. VOLVER                                     │\n"
															 "│                                                                             │\n"
															 "│                                                                             │\n"
															 "└─────────────────────────────────────────────────────────────────────────────┘\n";

const std::vector<std::string> opcionesPantallaComoJugarCreacionPersonaje = {"1", "2", "3", "4", "5", "6"};

const std::string canvasPantallaRaza = 						 "┌─────────────────────────────────────────────────────────────────────────────┐\n"
									   						 "│                                                                             │\n"
									   						 "│                                  ┌──────┐                                   │\n"
									   						 "│                                  │ RAZA │                                   │\n"
									   						 "│                                  └──────┘                                   │\n"
									   						 "│                                                                             │\n"
									   						 "│ La raza determina el 50\% de los atributos del personaje, asi como su        │\n"
									   						 "│ afinidad con cierto tipo de armas y magia.                                  │\n"                                           
									   						 "│                                                                             │\n"
									   						 "│ Hay 6 razas disponibles:                                                    │\n"
									   						 "│                                                                             │\n"
									   						 "│     - Humano: domina las espadas y no es afin a ningun tipo de magia.       │\n"
									   						 "│     - Enano: domina los martillos y el elemento " + imprimirVerde("tierra") +".                     │\n"
									   						 "│     - Elfo: domina los arcos y el elemento " + imprimirCyan("hielo") + ".                           │\n"
									   						 "│     - Ogro: domina las hachas y el elemento " + imprimirRojo("fuego") + ".                          │\n"
									   						 "|     - Triton: domina las lanzas y el elemento " + imprimirAzul("agua") + ".                         |\n"
									   						 "│     - Licantropo: domina los nudillos y el elemento " + imprimirAmarillo("rayo") + ".                   │\n"
									   						 "│                                                                             │\n"
									   						 "│                                                                             │\n"
									   						 "│                                                                             │\n"
									   						 "└─────────────────────────────────────────────────────────────────────────────┘\n";

const std::string canvasPantallaClase = 					 "┌─────────────────────────────────────────────────────────────────────────────┐\n"
															 "│                                                                             │\n"
															 "│                                  ┌───────┐                                  │\n"
															 "│                                  │ CLASE │                                  │\n"
															 "│                                  └───────┘                                  │\n"
															 "│                                                                             │\n"
															 "│ La clase determina el 25\% de los atributos del personaje, asi como su       │\n"
															 "│ afinidad con cierto tipo de arma. Cada clase destaca en un atributo.        │\n"                  
															 "│                                                                             │\n"
															 "│ Hay 6 clases disponibles:                                                   │\n"
															 "│                                                                             │\n"
															 "│     - Guerrero: domina los mandobles y destaca en defensa fisica.           │\n"
															 "│     - Mago: domina los baculos y destaca en ataque magico.                  │\n"
															 "│     - Monje: domina los nudillos y destaca en ataque fisico.                │\n"
															 "│     - Clerigo: domina los baculos y destaca en defensa magica.              │\n"
															 "|     - Ladron: domina las dagas y destaca en velocidad.                      |\n"
															 "│     - Trovador: domina los estoques y destaca en velocidad.                 │\n"
															 "│                                                                             │\n"
															 "│                                                                             │\n"
															 "│                                                                             │\n"
															 "└─────────────────────────────────────────────────────────────────────────────┘\n";

const std::string canvasPantallaSubclase = 					 "┌─────────────────────────────────────────────────────────────────────────────┐\n"
										   					 "│                                                                             │\n"
										   					 "│                                ┌──────────┐                                 │\n"
										   					 "│                                │ SUBCLASE │                                 │\n"
										   					 "│                                └──────────┘                                 │\n"
										   					 "│                                                                             │\n"
										   					 "│ La subclase determina el 25\% de los atributos del personaje, asi como su    │\n"
										   					 "│ afinidad con cierto tipo de arma. Cada clase destaca en un atributo.        │\n"                     
										   					 "│                                                                             │\n"
										   					 "│ Hay 6 subclases disponibles:                                                │\n"
										   					 "│                                                                             │\n"
										   					 "│     - Herrero: domina los martillos y destaca en defensa fisica.            │\n"
										   					 "│     - Alquimista: domina las lanzas y destaca en ataque magico.             │\n"
										   					 "│     - Gladiador: domina los mandobles y destaca en ataque fisico.           │\n"
										   					 "│     - Boticario: domina las dagas y destaca en defensa magica.              │\n"
										   					 "|     - Druida: domina los arcos y destaca en defensa magica.                 |\n"
										   					 "│     - Mercenario: domina las espadas y destaca en velocidad.                │\n"
										   					 "│                                                                             │\n"
										   					 "│                                                                             │\n"
										   					 "│                                                                             │\n"
										   					 "└─────────────────────────────────────────────────────────────────────────────┘\n";

const std::string canvasPantallaArma = 						 "┌─────────────────────────────────────────────────────────────────────────────┐\n"
									   						 "│                                                                             │\n"
									   						 "│                                  ┌──────┐                                   │\n"
									   						 "│                                  │ ARMA │                                   │\n"
									   						 "│                                  └──────┘                                   │\n"
									   						 "│                                                                             │\n"
									   						 "│                                                                             │\n"
									   						 "│ El arma que equipa el personaje determina parte del daño fisico al realizar │\n"
									   						 "│ un ataque. Los baculos, ademas, aumentan el daño realizado por las magias.  │\n"                          
									   						 "│                                                                             │\n"
									   						 "│ El arma tambien afecta a la precision y a la probabilidad de ejecutar un    │\n"
									   						 "│ golpe critico.                                                              │\n"
									   						 "│                                                                             │\n"
									   						 "│ Dependiendo de tu raza, clase y subclase tendras mas afinidad con una armas │\n"
									   						 "│ u otras.                                                                    │\n"
									   						 "│                                                                             │\n"
									   						 "| Hay diez armas disponibles: espada, estoque, daga, mandoble, baculo, hacha, |\n"
									   						 "│ lanza, arco, martillo y nudillos.                                           │\n"
									   						 "│                                                                             │\n"
									   						 "│                                                                             │\n"
									   						 "└─────────────────────────────────────────────────────────────────────────────┘\n";

const std::string canvasAtributos = 						 "┌─────────────────────────────────────────────────────────────────────────────┐\n"
															 "│                                                                             │\n"
															 "│                                ┌───────────┐                                │\n"
															 "│                                │ ATRIBUTOS │                                │\n"
															 "│                                └───────────┘                                │\n"
															 "│                                                                             │\n"
															 "│                                                                             │\n"
															 "│                                                                             │\n"
															 "│ Los atributos se determinan de manera pseudoaleatoria a partir de la raza,  │\n"
															 "│ la clase, la subclase y el arma del personaje.                              │\n"                         
															 "│                                                                             │\n"
															 "│ Cada nivel que aumenta el personaje, incrementa aleatoriamente sus          │\n"
															 "│ atributos.                                                                  │\n"
															 "│                                                                             │\n"
															 "│ Los atributos son: vida, ataque fisico, ataque magico, defensa fisica,      │\n"
															 "│ defensa magica, velocidad, precision y critico.                             │\n"
															 "│                                                                             │\n"
															 "│                                                                             │\n"
															 "|                                                                             |\n"
															 "│                                                                             │\n"
															 "└─────────────────────────────────────────────────────────────────────────────┘\n";


// MENU PANTALLA COMO JUGAR
//
// Funcion para controlar la seleccion del usuario en el menu
//
// Se introduce una de las siguientes opciones:
//	
//	1: Objetivo del juego
//	2: Creacion del personaje
//	3: Sistema de combate
//	4: Eventos
//	5: Volver
//
// Cada seleccion nos llevara a una nueva pantalla o imprimira la documentacion en cuestion
//
void menuPantallaComoJugar(std::string opcion);


// MENU PANTALLA COMO JUGAR CREACION PERSONAJE
//
// Subpantalla dentro de ComoJugar > CreacionPersonaje
//
void menuPantallaComoJugarCreacionPersonaje(std::string opcion);



#endif //PANTALLA_COMO_JUGAR
