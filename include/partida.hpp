#ifndef PARTIDA
#define PARTIDA

#include "jugador.hpp"

/*
 * CLASE PARTIDA
 *
 * Sirve para gestionar las estadisticas de la partida, asi como iniciar los 
 * combates.
 */
class Partida {
public:
    Partida(Jugador& jugador);
    
    /*
     * INICIAR_PARTIDA
     *
     * Inicia la partida, mostrando la primera pantalla de piso
     */
    void iniciarPartida();

    /* DESCENDER_PISO 
     * 
     * Baja un piso e incrementa el piso actual y los restantes
     */
    void descenderPiso();

private:
    /* Atributos */
    Jugador  jugador;
    int      pisoActual;
    int      pisosRestantes;
    bool     partidaTerminada;
    
    /* Getters */
    Jugador&  getJugador();
    int       getPisoActual();
    int       getPisosRestantes();
    bool      getPartidaTerminada();

    /* Setters */
    void setJugador(Jugador& jugador);
    void setPisoActual(int pisoActual);
    void setPisosRestantes(int pisosRestantes);
    void setPartidaTerminada(bool partidaTerminada);
};

#endif // PARTIDA
