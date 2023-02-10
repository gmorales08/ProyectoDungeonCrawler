#ifndef PANTALLA_PISO
#define PANTALLA_PISO

#include "pantalla.hpp"
#include "jugador.hpp"
/*
 * PANTALLA_PISO
 *
 * Genera la pantalla del piso.
 */
std::string pantallaPiso(int numeroPiso, int pisosRestantes);
const std::vector<std::string> opcionesPantallaPiso =
    {"a", "A", "i", "I", "e", "E"};

/*
 * MENU_PANTALLA_PISO
 *
 * Controla la seleccion en el menu de piso
 */
void menuPantallaPiso(std::string opcion, Jugador& jugador);

#endif // PANTALLA_PISO
