#ifndef PARTIDA
#define PARTIDA

#include "habilidad.hpp"
#include "evento.hpp"

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

    /* Setters */
    void setPartidaTerminada(bool partidaTerminada);

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
    /*
     * GENERARA_ENEMIGO
     *
     * Devuelve un enemigo aleatorio en base al piso actual.
     * El nivel del enemigo devuelto estara en un rango(piso - 1 a piso + 1)
     */
    Enemigo& generarEnemigo();
    /* GENERAR_EVENTO
     *
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

const std::string pantallaVictoria =
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

const std::string pantallaDerrota =
"┌──────────────────────────────────────────────────────────────────────────────┐\n"
"│                                                                              │\n"
"│  A TU PERSONAJE NO LE QUEDAN PUNTOS DE SALUD Y NO PUEDES SEGUIR AVANZANDO.   │\n"
"│                    NO HAS PODIDO ESCAPAR DE LA MAZMORRA.                     │\n"
"│                                                                              │\n"
"│ PUEDES INTENTARLO DE NUEVO CREANDO OTRO PERSONAJE Y EMPEZANDO DESDE EL       │\n"
"│                                 PRIMER PISO.                                 │\n"
"│                                                                              │\n"
"│  PRUEBA DIFERENTES COMBINACIONES DE RAZA, CLASE Y SUBCLASE, Y ASEGURATE DE   │\n"
"│                   USAR UN ARMA CON LA QUE TENGAS AFINIDAD.                   │\n"
"│                                                                              │\n"
"│ TAMBIEN ES IMPORTANTE LA DISTRIBUCION DE PUNTOS DE MEJORA AL COMIENZO DE LA  │\n"
"│             PARTIDA. PIENSA BIEN EN QUE ATRIBUTOS LOS INVIERTES.             │\n"
"│                                                                              │\n"
"│ SI HAY DETALLES DE LA PARTIDA QUE NO ENTIENDES, SIEMPRE PUEDES CONSULTAR EL  │\n"
"│                       MANUAL EN LA PANTALLA DE INICIO.                       │\n"
"│                                                                              │\n"
"│                                                                              │\n"
"│                SUERTE EN TU PROXIMA INCURSION, AVENTURERO/A.                 │\n"
"│                                                                              │\n"
"└──────────────────────────────────────────────────────────────────────────────┘\n";

#endif // PARTIDA
