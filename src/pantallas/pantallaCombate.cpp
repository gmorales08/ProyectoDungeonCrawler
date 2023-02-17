#include "../../include/pantallaCombate.hpp"
#include <string>

std::string pantallaCombate(int turno, Jugador& j, Enemigo& e) {
    std::string pantalla = "";
    pantalla.append(
"┌──────────────────────────────────────────────────────────────────────────────┐\n");
    /* Nombre personajes */
    std::string nombreJugador = centrarTexto(j.getNombre(),
                                (anchoPantalla / 2) - 2, " ", " ");
    std::string nombreEnemigo = centrarTexto(e.getNombre(),
                                (anchoPantalla / 2) - 2, " ", " ");
    pantalla.append(tuberia + nombreJugador + nombreEnemigo + tuberia + "\n");
    /* Vida personajes */
    std::string vidaJugador = "    Vida:" + j.generarBarraDeVida();
    vidaJugador += alinearIzquierda(std::to_string(j.getVida()) + "/" +
        std::to_string(j.getVidaMaxima()), 10, " ", " ");
    std::string vidaEnemigo = "    Vida:" + e.generarBarraDeVida();
    vidaEnemigo += alinearIzquierda(std::to_string(e.getVida()) + "/" +
        std::to_string(e.getVidaMaxima()), 10, " ", " ");
    pantalla.append(tuberia + vidaJugador + vidaEnemigo + tuberia + "\n");
    /* Nivel y elemento */
    std::string nivelJugador = "    Nivel " + std::to_string(j.getNivel()) +
        ". Elemento: " + j.getElementoString();
    std::string nivelEnemigo = "    Nivel " + std::to_string(e.getNivel()) +
        ". Elemento: " + e.getElementoString();
    pantalla.append(tuberia + nivelJugador + nivelEnemigo + tuberia + "\n");
    /* Linea en blanco */
    pantalla.append(centrarTexto("", anchoPantalla, tuberia, tuberia + "\n"));
    /* Paneles de comandos, atributos e informacion de la batalla */
    // TODO

    return pantalla;
}
