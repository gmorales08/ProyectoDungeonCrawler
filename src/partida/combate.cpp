#include "../../include/combate.hpp"
#include "../../include/pantallaCombate.hpp"


bool iniciarCombate(Partida* partida) {
    bool jugadorSobrevive = true;
    bool enemigoSobrevive = true;
    /* Se copia el Jugador para que los cambios de estadisticas no se mantegan
     * despues del combate. Se hace lo mismo con el Enemigo */
    Jugador j = (Jugador) partida->getJugador();
    Enemigo e = (Enemigo) partida->generarEnemigo();
    int turno = 1;
    std::string logTurno = "";

    /* Estructura de cada turno del bucle de combate:
     *   1. Imprimir la pantalla de turno
     *   2. Determinar quien empieza el turno
     *   3. Determinar la accion que elijan los personajes
     *   4. Aplicar los efectos correspondientes y generar el logTurno
     *   5. Comprobar si los personajes siguen vivos
     *   6. Incrementar el contador de turnos
     */
    while (jugadorSobrevive == true && enemigoSobrevive == true) {
        /* 1. Imprimir la pantalla de turno */
        std::string comando = cargarPantalla(
            pantallaCombate(turno, j, e, logTurno),
            opcionesPantallaCombate,
            imprimirLog(0,
                "Elija un comando: 'a': Atacar, '1-5': Usar Habilidades\n"),
            "Debe escribir 'a' o un numero del 1 al 5.\n");
        /* 2. Determinar quien empieza el turno */


        /* 5. Comprobar si los Personajes siguen vivos */
        if (j.getVida() <= 0) {
            jugadorSobrevive = false;
        }
        if (e.getVida() <= 0) {
            enemigoSobrevive = false;
        }
        /* 6. Incrementar el contador de turnos */
        turno++;
    }

    return jugadorSobrevive;
}

