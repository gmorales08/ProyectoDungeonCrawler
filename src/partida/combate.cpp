#include "../../include/utilidadesDeTerminal.hpp"
#include "../../include/habilidad.hpp"
#include "../../include/combate.hpp"
#include "../../include/pantallaCombate.hpp"


bool iniciarCombate(Partida* partida) {
    bool jugadorSobrevive = true;
    bool enemigoSobrevive = true;
    /* Se copia el Jugador para que los cambios de estadisticas no se mantegan
     * despues del combate. Se hace lo mismo con el Enemigo */
    Jugador j(partida->getJugador());
    // Jugador* jp = &j;
    Enemigo e(partida->generarEnemigo());
    // Enemigo* ep = &e;
    int turno = 1;
    std::string logTurno   = "";
    std::string logJugador = "";
    std::string logEnemigo = "";

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
        logTurno   = "Turno " + std::to_string(turno) + ".\n";
        logJugador = "";
        logEnemigo = "";
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
        logJugador.append("> " + j.getNombre() + ":\n");
        if (comando == "a" || comando == "A") {
            logJugador.append("Ha atacado con el arma equipada.\n");
            logJugador.append(j.atacar(e) + "\n");
        } else if (comando == "1") {
            if (j.getHabilidades().at(0).getUsosRestantes() == 0) {
                logJugador.append("Ha atacado con el arma equipada.\n");
            } else {
                logJugador.append("Ha usado " +
                    j.getHabilidades().at(0).getNombre() + ".\n");
            }
            logJugador += j.getHabilidades().at(0).usar(j, e);
        }  else if (comando == "2") {
            if (j.getHabilidades().at(1).getUsosRestantes() == 0) {
                logJugador.append("Ha atacado con el arma equipada.\n");
            } else {
                logJugador.append("Ha usado " +
                    j.getHabilidades().at(1).getNombre() + ".\n");
            }
            logJugador += j.getHabilidades().at(1).usar(j, e);
        } else if (comando == "3") {
           if (j.getHabilidades().at(2).getUsosRestantes() == 0) {
                logJugador.append("Ha atacado con el arma equipada.\n");
            } else {
                logJugador.append("Ha usado " +
                    j.getHabilidades().at(2).getNombre() + ".\n");
            }
            logJugador += j.getHabilidades().at(2).usar(j, e);
        } else if (comando == "4") {
            if (j.getHabilidades().at(3).getUsosRestantes() == 0) {
                logJugador.append("Ha atacado con el arma equipada.\n");
            } else {
                logJugador.append("Ha usado " +
                    j.getHabilidades().at(3).getNombre() + ".\n");
            }
            logJugador += j.getHabilidades().at(3).usar(j, e);
        } else if (comando == "5") {
            if (j.getHabilidades().at(4).getUsosRestantes() == 0) {
                logJugador.append("Ha atacado con el arma equipada.\n");
            } else {
                logJugador.append("Ha usado " +
                    j.getHabilidades().at(4).getNombre() + ".\n");
            }
            logJugador += j.getHabilidades().at(4).usar(j, e);
        }
        logTurno.append(logJugador);
        limpiarPantalla();
        std::cout << (pantallaCombate(turno, j, e, logTurno)) << std::endl;
        pausar(1000);
        /* Accion enemigo */
        logEnemigo = "> " + e.getNombre() + "\n";
        logEnemigo.append(e.elegirAccion(j));
        logTurno.append(logEnemigo);
        imprimirPantallaEstatica((pantallaCombate(turno, j, e, logTurno)));

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

