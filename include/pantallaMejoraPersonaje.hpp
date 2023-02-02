#ifndef PANTALLA_MEJORA_PERSONAJE
#define PANTALLA_MEJORA_PERSONAJE

#include "pantalla.hpp"
#include "jugador.hpp"

const std::vector<std::string> opcionesMejoraPersonaje = 
    {"1", "2", "3", "4", "5", "6", "7"};

/*
 * MENU_MEJORA_PERSONAJE
 *
 * Metodo que controla la seleccion del usuario en la pantalla de mejora de 
 * personaje
 * Tambien se le pasa por parametro el jugador que se va a mejorar
 */
void menuMejoraPersonaje(std::string opcion, Jugador& jugador);

/*
 * PANTALLA_MEJORA_PERSONAJE
 *
 * Imprime una pantalla donde se pueden ver los atributos elegidos para mejorar.
 * Cada atributo elegido para mejorar tendra un * detras de su valor actual.
 */
std::string pantallaMejoraPersonaje(Jugador& jugador, std::vector<int> mejoras);

/*
 * PANTALLA_PERONSAJE_MEJORADO
 *
 * Imprime la pantalla de informacion del personaje con los atributos mejorados.
 * Se le pasa el vector de atributos que se mejoran y calcula los valores de la 
 * mejora de manera aleatoria.
 */
std::string pantallaPersonajeMejorado(Jugador& jugador, 
                                      std::vector<int> mejoras);

#endif // PANTALLA_MEJORA_PERSONAJE
