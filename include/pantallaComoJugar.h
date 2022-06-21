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
										   					 "│ Para poder completar el juego debes superar los 10 pisos de la mazmorra y   │\n"                         
										   					 "│ derrotar al jefe final                                                      │\n"
										   					 "│                                                                             │\n"
										   					 "│ En cada piso puedes encontrarte enemigos o, si tienes suerte, un evento.    │\n"
										   					 "│ Para poder derrotar a estos enemigos debes crear un personaje con el que    │\n"
										   					 "│ iras progresando segun avances en la mazmorra.                              │\n"
										   					 "│                                                                             │\n"
										   					 "│ El daño que sufras se ira acumulando tras cada combate, asi como las        │\n"
										   					 "│ mejoras que obtengas y la magia que consumas.                               │\n"
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
															 "│                           1. Raza                                           │\n"                        
															 "│                                                                             │\n"
															 "│                           2. Clase                                          │\n"
															 "│                                                                             │\n"
															 "│                           3. Subclase                                       │\n"
															 "│                                                                             │\n"
															 "│                           4. Arma                                           │\n"
															 "│                                                                             │\n"
															 "│                           5. Atributos                                      │\n"
															 "│                                                                             │\n"
															 "│                           6. Magia y habilidades                            │\n"
															 "│                                                                             │\n"
															 "│                           7. Volver                                         │\n"
															 "│                                                                             │\n"
															 "└─────────────────────────────────────────────────────────────────────────────┘\n";

const std::vector<std::string> opcionesPantallaComoJugarCreacionPersonaje = {"1", "2", "3", "4", "5", "6", "7"};

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
									   						 "│     - Triton: domina las lanzas y el elemento " + imprimirAzul("agua") + ".                         │\n"
									   						 "│     - Licantropo: domina las garras y el elemento " + imprimirAmarillo("rayo") + ".                     │\n"
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
															 "│     - Monje: domina las garras y destaca en ataque fisico.                  │\n"
															 "│     - Clerigo: domina los baculos y destaca en defensa magica.              │\n"
															 "│     - Ladron: domina las dagas y destaca en velocidad.                      │\n"
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
										   					 "│     - Druida: domina los arcos y destaca en defensa magica.                 │\n"
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
									   						 "│ Hay diez armas disponibles: espada, estoque, daga, mandoble, baculo, hacha, │\n"
									   						 "│ lanza, arco, martillo y garras.                                             │\n"
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
															 "│                                                                             │\n"
															 "│                                                                             │\n"
															 "└─────────────────────────────────────────────────────────────────────────────┘\n";

const std::string canvasMagiaYHabilidades =                  "┌─────────────────────────────────────────────────────────────────────────────┐\n"
															 "│                                                                             │\n"
															 "│                          ┌─────────────────────┐                            │\n"
															 "│                          │ MAGIA Y HABILIDADES │                            │\n"
															 "│                          └─────────────────────┘                            │\n"
															 "│                                                                             │\n"
															 "│ La magia que domina un personaje viene determinada por su raza.             │\n"
															 "│ El personaje dispone de cinco usos para su magia, que se pueden recargar en │\n"
															 "│ determinados eventos.                                                       │\n"
															 "│ La afinidad entre elementos magicos se explica en SISTEMA DE COMBATE.       │\n"                         
															 "│                                                                             │\n"
															 "│                                                                             │\n"
															 "│ Cada personaje tendra una habilidad de raza, dos habilidades de clase y una │\n"
															 "│ habilidad de subclase.                                                      │\n"
															 "│ Las habilidades se podran usar en combate, y tendran un determinado numero  │\n"
															 "│ de usos, que tambien es posible recargar en eventos.                        │\n"
															 "│ Las habilidades son muy variadas y van desde poderosos ataques, a aumentos  │\n"
															 "│ temporales de atributos o alteracion de estados.                            │\n"
															 "│                                                                             │\n"
															 "│                                                                             │\n"
															 "└─────────────────────────────────────────────────────────────────────────────┘\n";

const std::string canvasSistemaDeCombate = 					 "┌─────────────────────────────────────────────────────────────────────────────┐\n"
										   					 "│                                                                             │\n"
										   					 "│                           ┌─────────────────────┐                           │\n"
										   					 "│                           │ SISTEMA DEL COMBATE │                           │\n"
										   					 "│                           └─────────────────────┘                           │\n"
										   					 "│                                                                             │\n"
															 "│                                                                             │\n"                     
										   					 "│                                                                             │\n"
										   					 "│                                                                             │\n"
										   					 "│                         1. Fundamentos del combate                          │\n"
										   					 "│                                                                             │\n"
										   					 "│                         2. Calculo del dano                                 │\n"
										   					 "│                                                                             │\n"
										   					 "│                         3. Afinidades elementales                           │\n"
										   					 "│                                                                             │\n" 
										   					 "│                         4. Volver                                           │\n"   
										   					 "│                                                                             │\n"
										   					 "│                                                                             │\n"
										   					 "│                                                                             │\n"
										   					 "│                                                                             │\n"
										   					 "└─────────────────────────────────────────────────────────────────────────────┘\n";

const std::vector<std::string> opcionesPantallaSistemaDeCombate = {"1", "2", "3", "4"};

const std::string canvasFundamentosCombate = 				 "┌─────────────────────────────────────────────────────────────────────────────┐\n"
											 				 "│                                                                             │\n"
											 				 "│                         ┌─────────────────────────┐                         │\n"
											 				 "│                         │ FUNDAMENTOS DEL COMBATE │                         │\n"
											 				 "│                         └─────────────────────────┘                         │\n"
											 				 "│                                                                             │\n"
											 				 "│                                                                             │\n"
											 				 "│ Cuando de comienzo un combate, se mostrara en pantalla el personaje con sus │\n"
											 				 "│ puntos de salud, sus atributos y las acciones que puede realizar.           │\n"
											 				 "│                                                                             │\n"
											 				 "│ Tambien se muestra la salud del enemigo y su afinidad elemental.            │\n"
											 				 "│                                                                             │\n"
											 				 "│ El combate se organiza por turnos, comenzando con quien tenga mayor         │\n" 
											 				 "│ velocidad.                                                                  │\n"   
											 				 "│                                                                             │\n"                     
											 				 "│ En cada turno se realiza una accion y el combate acaba cuando el personaje  │\n"
											 				 "│ o el enemigo se quedan sin puntos de salud.                                 │\n"
											 				 "│                                                                             │\n"
											 				 "│                                                                             │\n"
											 				 "│                                                                             │\n"
											 				 "└─────────────────────────────────────────────────────────────────────────────┘\n";

const std::string canvasCalculoDano =                        "┌─────────────────────────────────────────────────────────────────────────────┐\n"
															 "│                                                                             │\n"
															 "│                            ┌──────────────────┐                             │\n"
															 "│                            │ CALCULO DEL DANO │                             │\n"
															 "│                            └──────────────────┘                             │\n"
															 "│                                                                             │\n"
															 "│ Existen dos tipos de dano, el fisico y el magico.                           │\n"
															 "│ El fisico se calcula a partir del ataque fisico del personaje y el arma que │\n"
															 "│ empune, y el magico se calcula a partir del ataque magico.                  │\n"
															 "│                                                                             │\n"
															 "│ La reduccion de dano de un ataque fisico, se calcula a partir de la defensa │\n"
															 "│ fisica, y la reduccion de un ataque magico, con la defensa magica.          │\n"
															 "│                                                                             │\n" 
															 "│ Si realizamos un ataque fisico, existe la posibilidad de fallar el ataque.  │\n"   
															 "│ Esto depende de la precision del arma.                                      │\n"                     
															 "│ Por otra parte, los ataques magicos siempre aciertan.                       │\n"
															 "│                                                                             │\n"
															 "│ Los ataque fisicos tambien pueden ser criticos, lo que hara un dano mucho   │\n"
															 "│ mayor. Este parametro tambien lo determina el arma.                         │\n"
															 "│                                                                             │\n"
															 "└─────────────────────────────────────────────────────────────────────────────┘\n";

const std::string canvasAfinidadesElementales =              "┌─────────────────────────────────────────────────────────────────────────────┐\n"
															 "│                                                                             │\n"
															 "│                         ┌────────────────────────┐                          │\n"
															 "│                         │ AFINIDADES ELEMENTALES │                          │\n"
															 "│                         └────────────────────────┘                          │\n"
															 "│                                                                             │\n"
															 "│ Existen cinco elementos, de los cuales cada uno es debil o fuerte contra    │\n"
															 "│ otro.                                                                       │\n"
															 "│                                                                             │\n"
															 "│                                   " + imprimirVerde("tierra") + "                                    │\n"
															 "│                                                                             │\n"
															 "│                                ↗           ↘                                │\n"
															 "│                                                                             │\n"
															 "│                           " + imprimirCyan("hielo") + "            " + imprimirAmarillo("rayo") + "                             │\n" 
															 "│                                                                             │\n"   
															 "│                             ↑                ↓                              │\n"
															 "│                                                                             │\n"                     
															 "│                           " + imprimirRojo("fuego") + "     ←      " + imprimirAzul("agua") + "                             │\n"
															 "│                                                                             │\n"
															 "│                                                                             │\n"
															 "└─────────────────────────────────────────────────────────────────────────────┘\n";

const std::string canvasEventos =                            "┌─────────────────────────────────────────────────────────────────────────────┐\n"
															 "│                                                                             │\n"
															 "│                                 ┌─────────┐                                 │\n"
															 "│                                 │ EVENTOS │                                 │\n"
															 "│                                 └─────────┘                                 │\n"
															 "│                                                                             │\n"
															 "│ Los eventos son situaciones que pueden suceder aleatoriamente segun         │\n"
															 "│ avancemos en la mazmorra.                                                   │\n"
															 "│                                                                             │\n"
															 "│ Antes de cada evento se pregunta al jugador si quiere omitirlo o            │\n"
															 "│ presenciarlo, de manera que ningun evento es obligatorio.                   │\n"
															 "│                                                                             │\n"
															 "│ Los eventos pueden ser beneficiosos o perjudiciales, pero esto no se sabe   │\n" 
															 "│ hasta que no se accede a el.                                                │\n"   
															 "│                                                                             │\n"                     
															 "│ Entre el piso 5 y el piso 6 hay un evento fijo en el que se cura al         │\n"
															 "│ personaje y se restauran su magia y habilidades.                            │\n"
															 "│                                                                             │\n"
															 "│                                                                             │\n"
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


// MENU PANTALLA SISTEMA DE COMBATE
//
// Subpantalla dentro de ComoJugar > SistemaDeCombate
//
void menuPantallaComoJugarSistemaDeCombate(std::string opcion);

#endif //PANTALLA_COMO_JUGAR
