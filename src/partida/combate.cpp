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
        logTurno = "Turno " + std::to_string(turno) + ":\n";
        std::string comando = cargarPantalla(
            pantallaCombate(turno, j, e, logTurno),
            opcionesPantallaCombate,
            imprimirLog(0,
                "Elija un comando: 'a': Atacar, '1-5': Usar Habilidades\n"),
                "Debe escribir 'a' o un numero del 1 al 5.\n");
        /* 2. Determinar quien empieza el turno */
        int dadosJ = 2;
        int dadosE = 2;
        if (j.getVelocidad() > 2 * e.getVelocidad()) {
            dadosJ += 2;
        } else if (e.getVelocidad() > 2 * j.getVelocidad()) {
            dadosE += 2;
        } else if (j.getVelocidad() >= e.getVelocidad()) {
            dadosJ++;
        } else if (e.getVelocidad() > j.getVelocidad()) {
            dadosE++;
        }
        int tiradaTurnoJ = j.tirarDados(dadosJ);
        int tiradaTurnoE = e.tirarDados(dadosE);

        bool empiezaJugador;
        if (tiradaTurnoJ >= tiradaTurnoE) {
            empiezaJugador = true;
        } else if (tiradaTurnoJ < tiradaTurnoE) {
            empiezaJugador = false;
        }

        /* 3. Determinar la accion que elijan los personajes */
        /* Accion jugador */
        logTurno += "-JUGADOR: ";
        if (comando == "a" || comando == "A") {
            logTurno += j.atacar(e) + "\n";
        } else if (comando == "1") {
            logTurno += " Ha usado magia.\n";
            j.getHabilidades().at(0).setUsuario(j);
            j.getHabilidades().at(0).setObjetivo(e);
            logTurno += j.getHabilidades().at(0).usar();
        } else if (comando == "2") {
            if (j.getHabilidades().at(1).getTipo() ==
                    Habilidad::Tipo::OFENSIVA) {
                j.getHabilidades().at(1).setUsuario(j);
                j.getHabilidades().at(1).setObjetivo(e);
                logTurno += j.getHabilidades().at(1).usar();
            } else {
                j.getHabilidades().at(1).setObjetivo(j);
            }
        } else if (comando == "3") {

        } else if (comando == "4") {

        } else if (comando == "5") {

        }
        /* Accion enemigo */

        // mostrar turno personaje1 -> dos segundos -> mostrar turno personaje2

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

