#ifndef PARTIDA
#define PARTIDA

#include "jugador.hpp"
#include "enemigo.hpp"
#include "evento.hpp"

const std::string pantallaFin =
"┌──────────────────────────────────────────────────────────────────────────────┐\n"
"│                                                                              │\n"
"│                   ****************************************           V       │\n"
"│        V          * ENOHARABUENA, HAS CONSEGUIDO ESCAPAR *                   │\n"
"│                   ****************************************      +            │\n"
"│               +                 +                                         V  │\n"
"│      V          ____                         +                 _____         │\n"
"│               _/    \\   V   __                 ____      +    /     \\        │\n"
"│              /       \\     /  \\_              /    \\         / _/    |       │\n"
"│           __/   /     |  _/     \\    ,|,     |  _/  \\       |         \\      │\n"
"│     +   _/    _/       \\/   _    \\  --o--   /        |     /     _/    |     │\n"
"│        /     /    _/    \\_   \\    |  ´|`   |   /      \\   |     /       \\    │\n"
"│       /  ##     _/    _   \\   \\    \\     _/   /  ##    \\ /    _/    /    |   │\n"
"│      |  ###    /     /    |        |  _/    _/  ###    |     /    _/     \\   │\n"
"│     /   ###        _/       \\_       \\/    /   ####      \\       /    ##   | │\n"
"│    |     |                    \\     _/           |        \\_         ###    \\│\n"
"│^  ## ^  ^|^ ^   ^^`  ^^  ^^ ^^ ^^^`^^^^^ ^^  ^ ^ |^^^^`  ^^^ ^ ^^ ^^^^|^   ^^│\n"
"│ ^###^^   ^^^  ´  ´   ^^^       ´   ^^^^      `    ´ ^^   ^^^ ^    ´^^ |^^^^  │\n"
"│   |  `      ^^^^             ^^^^           ^^^       ^^^       ´   ^^^      │\n"
"│         `         ^^            ´        `          ^^   ´     ^^^   `       │\n"
"└──────────────────────────────────────────────────────────────────────────────┘\n";

/*
 * CLASE PARTIDA
 *
 * Sirve para gestionar las estadisticas de la partida, asi como iniciar los
 * combates.
 */
class Partida {
public:
    Partida(Jugador& jugador);

    /* Getters */
    Jugador&  getJugador();
    int       getPisoActual();

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
    /* RETROCEDER_PISO
     *
     * Retrocede un piso y disminuye el piso actual e incrementa los restantes
     */
    void retrocederPiso();
    /* GENERAR_EVENTO
     * Lee un evento de la lista de eventos y lo devuelve
     */
    Evento& generarEvento();

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
    std::vector<Evento>               listaEventos;

    /* Getters */
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
    /* GENERAR_LISTA_EVENTOS
     * Genera una lista con todos los eventos que pueden ocurrir en la partida.
     * El evento de la posicion 0, es un evento que siempre sucede entre los
     * pisos 5 y 6, y no puede salir en el resto de pisos.
     */
    void generarListaEventos();
};

#endif // PARTIDA
