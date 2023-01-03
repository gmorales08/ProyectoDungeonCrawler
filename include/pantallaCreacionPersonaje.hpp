#ifndef PANTALLA_CREACION_PERSONAJE
#define PANTALLA_CREACION_PERSONAJE

#include "pantalla.hpp"
#include "pantallaInformacionPersonaje.hpp"

const std::string canvasCreacionPersonaje =
"┌─────────────────────────────────────────────────────────────────────────────┐\n"
"│                                                                             │\n"
"│                         ┌────────────────────────┐                          │\n"
"│                         │ CREACION DEL PERSONAJE │                          │\n"
"│                         └────────────────────────┘                          │\n"
"│                                                                             │\n"
"│                  RAZA              CLASE         SUBCLASE                   │\n"
"│                                                                             │\n"
"│                1. Humano        1. Guerrero    1. Herrero                   │\n"
"│                                                                             │\n"
"│                2. Enano         2. Mago        2. Alquimista                │\n"
"│                                                                             │\n"
"│                3. Elfo          3. Monje       3. Gladiador                 │\n"
"│                                                                             │\n"
"│                4. Ogro          4. Clerigo     4. Boticario                 │\n"
"│                                                                             │\n"
"│                5. Triton        5. Ladron      5. Druida                    │\n"
"│                                                                             │\n"
"│                6. Bestia        6. Trovador    6. Mercenario                │\n"
"│                                                                             │\n"
"└─────────────────────────────────────────────────────────────────────────────┘\n";
const std::vector<std::string> opcionesCreacionPersonaje =
    {"1", "2", "3", "4", "5", "6"};

const std::string canvasSeleccionArma =
"┌─────────────────────────────────────────────────────────────────────────────┐\n"
"│                                                                             │\n"
"│                                  ┌──────┐                                   │\n"
"│                                  │ ARMA │                                   │\n"
"│                                  └──────┘                                   │\n"
"│                                                                             │\n"
"│                                                                             │\n"
"│                                                                             │\n"
"│                         1. Espada      6. Hacha                             │\n"
"│                                                                             │\n"
"│                         2. Estoque     7. Lanza                             │\n"
"│                                                                             │\n"
"│                         3. Daga        8. Arco                              │\n"
"│                                                                             │\n"
"│                         4. Mandoble    9. Martillo                          │\n"
"│                                                                             │\n"
"│                         5. Baculo      10. Garras                           │\n"
"│                                                                             │\n"
"│                                                                             │\n"
"│                                                                             │\n"
"└─────────────────────────────────────────────────────────────────────────────┘\n";
const std::vector<std::string> opcionesSeleccionArma =
    {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};

/*
 * MENU_CREACION_PERSONAJE
 *
 * Metodo para controlar la seleccion del usuario en la pantalla* de creacion
 * de personaje
 */
void menuCreacionPersonaje(std::string opcion);

/*
 * MENU_SELECCION_ARMA
 *
 * Carga el menu de seleccion de arma
 * Cuando se selecciona el arma, se carga la pantalla de informacion de
 * personaje y se crea el personaje con los parametros seleccionados
 */
void menuSeleccionArma(std::string opcion);

#endif // PANTALLA_CREACION_PERSONAJE
