#ifndef PARTIDA
#define PARTIDA

#include "jugador.hpp"
#include "enemigo.hpp"

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
    /* ListaEnemigos es una matriz que contiene todos los enemigos que pueden
     * aparecer en la partida.
     * Cada fila corresponde a un nivel de Enemigo, y cada columna a los 
     * diferentes Enemigos con ese nivel.
     * Ej: [[ene1nvl1, ene2nvl1],
     *      [ene1nvl2],
     *      [ene1nvl3, ene2nvl3, ene3nvl3],
     *      ...]
     */
    std::vector<std::vector<Enemigo>> listaEnemigos;
    
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

    /* Metodos */
    /* GENERAR_LISTA_ENEMIGOS
     * Genera todos los enemigos que pueden aparecer en la partida. Los guarda
     * en listaEnemigos
     */
    void generarListaEnemigos();
};

#endif // PARTIDA
