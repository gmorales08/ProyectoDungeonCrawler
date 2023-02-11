#include "../../include/partida.hpp"
#include "../../include/pantalla.hpp"
#include "../../include/pantallaPiso.hpp"

Partida::Partida(Jugador& jugador) {
    setJugador(jugador);
    setPisoActual(1);
    setPisosRestantes(10);
    setPartidaTerminada(false);
}

/* Getters */
Jugador& Partida::getJugador() {
    return jugador;
}
int Partida::getPisoActual() {
    return pisoActual;
}
int Partida::getPisosRestantes() {
    return pisosRestantes;
}
bool Partida::getPartidaTerminada() {
    return partidaTerminada;
}

/* Setters */
void Partida::setJugador(Jugador& _jugador) {
   jugador = _jugador; 
}
void Partida::setPisoActual(int _pisoActual) {
    pisoActual = _pisoActual;
}
void Partida::setPisosRestantes(int _pisosRestantes) {
    pisosRestantes = _pisosRestantes;
}
void Partida::setPartidaTerminada(bool _partidaTerminada) {
    partidaTerminada = _partidaTerminada;
}

/* Metodos */ 
void Partida::iniciarPartida() {
    while (getPartidaTerminada() == false) {
        menuPantallaPiso(
            cargarPantalla(
                pantallaPiso(getPisoActual(), getPisosRestantes()),
                opcionesPantallaPiso,
                imprimirLog(0, 
                    "Seleccione 'a' para avanzar al siguiente piso, 'i' para",
                    "informacion del personaje o 'e' para estadisticas."),
                "Opcion no permitida. Debe escribir 'a', 'e' o 'i'.\n"),
            getJugador()); 
    }    
}

void Partida::descenderPiso() {
    setPisoActual(getPisoActual() + 1);
    setPisosRestantes(getPisosRestantes() - 1);
}
