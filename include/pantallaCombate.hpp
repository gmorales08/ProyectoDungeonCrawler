#ifndef PANTALLA_COMBATE
#define PANTALLA_COMBATE

#include "pantalla.hpp"
#include "combate.hpp"

/*
 * PANTALLA_COMBATE
 *
 * Genera la pantalla de turno en base al turno actual y los Personajes
 */
std::string pantallaCombate(int turno, Jugador& j, Enemigo& e);
const std::vector<std::string> opcionesPantallaCombate =
    {"a", "1", "2", "3", "4", "5"};

#endif // PANTALLA_COMBATE
