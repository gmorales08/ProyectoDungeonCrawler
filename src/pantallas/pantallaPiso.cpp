#include <string>
#include "../../include/pantallaPiso.hpp"
#include "../../include/pantallaInformacionPersonaje.hpp"

std::string pantallaPiso(int numeroPiso, int pisosRestantes) {
    std::string pantalla = "";
    pantalla.append(
"┌─────────────────────────────────────────────────────────────────────────────┐\n");
    pantalla.append(centrarTexto("", anchoPantalla) + "\n");
    pantalla.append(centrarTexto("PISO " + std::to_string(numeroPiso), 
                                 anchoPantalla) + "\n");
    pantalla.append(centrarTexto("", anchoPantalla) + "\n");
    pantalla.append(centrarTexto("", anchoPantalla) + "\n");
    pantalla.append(centrarTexto("", anchoPantalla) + "\n");
    pantalla.append(centrarTexto("(a) --|===> SEGUIR AVANZANDO <===|--",
                                 anchoPantalla) + "\n");
    pantalla.append(centrarTexto("", anchoPantalla) + "\n");
    pantalla.append(centrarTexto("", anchoPantalla) + "\n");
    pantalla.append(centrarTexto("(i)    Informacion del personaje    ",
                                anchoPantalla) + "\n");
    pantalla.append(centrarTexto("", anchoPantalla) + "\n");
    pantalla.append(centrarTexto("", anchoPantalla) + "\n");
    pantalla.append(centrarTexto("(e)          Estadisticas           ",
                                 anchoPantalla) + "\n");
    pantalla.append(centrarTexto("", anchoPantalla) + "\n");
    pantalla.append(centrarTexto("", anchoPantalla) + "\n");
    pantalla.append(centrarTexto("Quedan " + std::to_string(pisosRestantes) +
                                 " pisos para el final", anchoPantalla) + "\n");
    pantalla.append(centrarTexto("", anchoPantalla) + "\n");
    pantalla.append(centrarTexto("", anchoPantalla) + "\n");
    pantalla.append(centrarTexto("", anchoPantalla) + "\n");
    pantalla.append(centrarTexto("", anchoPantalla) + "\n");
    pantalla.append(
"└─────────────────────────────────────────────────────────────────────────────┘\n");

    return pantalla;
}

void menuPantallaPiso(std::string opcion, Jugador& jugador) {
    if (opcion == "a" || opcion == "A") {
        // avanzar
    } else if (opcion == "i" || opcion == "I") {
        imprimirPantallaEstatica(pantallaInformacion(jugador));
    } else if (opcion == "e" || opcion == "E") {
        // estadisticas
    }
}
