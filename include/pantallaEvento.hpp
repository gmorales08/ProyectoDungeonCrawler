#ifndef PANTALLA_EVENTO
#define PANTALLA_EVENTO

#include "pantalla.hpp"
#include "evento.hpp"

/*
 * PANTALLA_EVENTO
 *
 * Genera la pantalla del evento con su informacion.
 */
std::string pantallaEvento(Evento& evento);
const std::vector<std::string> opcionesPantallaEvento = {"a", "A", "r", "R"};

/*
 * PANTALLA_EVENTO_RESUELTO
 *
 * Muestra la misma pantalla de evento, pero rellena el campo resultado
 * Se imprime como pantalla estatica
 * Resolucion puede valer 0 si el evento resulta positivo, o 1 si el evento
 * resulta negativo
 */
std::string pantallaEventoResuelto(Evento& evento, int resolucion);

/* El control de la pantalla evento se hace en pantalla piso */

#endif // PANTALLA_EVENTO
