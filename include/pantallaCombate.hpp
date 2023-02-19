#ifndef PANTALLA_COMBATE
#define PANTALLA_COMBATE

#include "pantalla.hpp"
#include "combate.hpp"

/*
 * PANTALLA_COMBATE
 *
 * Genera la pantalla de turno en base al turno actual y los Personajes.
 * LogTurno contiene un string con toda la informacion del turno, separada por
 * \n entre cada linea. Dentro del metodo se muestra cada linea en su espacio
 * correspondiente.
 */
std::string pantallaCombate(int turno, Jugador& j, Enemigo& e,
                            std::string logTurno);
const std::vector<std::string> opcionesPantallaCombate =
    {"a", "A", "1", "2", "3", "4", "5"};

#endif // PANTALLA_COMBATE
