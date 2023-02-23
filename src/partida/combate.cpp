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
    std::string logFinal   = "";
    std::string comando = "";
    bool jugadorAcierta = false;
    bool enemigoEsquiva = false;

    /* Estructura de cada turno del bucle de combate:
     *   1. Imprimir la pantalla de turno si es el primer turno
     *   2. Determinar quien empieza el turno
     *   3. Determinar la accion que elijan los personajes
     *   4. Imprimir la pantalla de turno con el logTurno
     *   5. Comprobar si los personajes siguen vivos
     *   6. Incrementar el contador de turnos
     */
    while (jugadorSobrevive == true && enemigoSobrevive == true) {
        /* 1. Imprimir la pantalla de turno si es el primer turno */
        logTurno   = "Turno " + std::to_string(turno) + ".\n";
        logJugador = "";
        logEnemigo = "";
        logFinal.clear();
        jugadorAcierta = j.haAcertado();
        enemigoEsquiva = e.haEsquivado();

        if (turno == 1) {
            comando = cargarPantalla(
            pantallaCombate(turno, j, e, logTurno),
            opcionesPantallaCombate,
            imprimirLog(0,
                "Elija un comando: 'a': Atacar, '1-5': Usar Habilidades\n"),
                "Debe escribir 'a' o un numero del 1 al 5.\n");
        }
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

        /* 3. Determinar la accion que elijan los personajes e imprimir las
         * acciones en orden de actuacion */
        if (empiezaJugador == true) {
            /* Accion jugador */
            logJugador.append("> " + j.getNombre() + ":\n");
            if (comando == "a" || comando == "A") {
                logJugador.append("Ha atacado con el arma equipada.\n");
                if (jugadorAcierta == true) {
                    if (enemigoEsquiva == false) {
                        logJugador.append(j.atacar(e) + "\n");
                    } else {
                        logJugador.append("Pero el enemigo esquiva el ataque.\n");
                    }
                } else {
                    logJugador.append("Pero ha fallado el ataque.\n");
                }
            } else if (comando == "1") {
                if (j.getHabilidades().at(0).getUsosRestantes() == 0) {
                    logJugador.append("Ha atacado con el arma equipada.\n");
                    if (jugadorAcierta == true) {
                        if (enemigoEsquiva == false) {
                            logJugador.append(j.atacar(e) + "\n");
                        } else {
                            logJugador.append("Pero el enemigo esquiva el ataque.\n");
                        }
                    } else {
                        logJugador.append("Pero ha fallado el ataque.\n");
                    }
                } else {
                    logJugador.append("Ha usado " +
                        /* magia */
                        j.getHabilidades().at(0).getDescripcion() + ".\n");
                }
                logJugador.append(j.getHabilidades().at(0).usar(j, e));
            }  else if (comando == "2") {
                if (j.getHabilidades().at(1).getUsosRestantes() == 0) {
                    logJugador.append("Ha atacado con el arma equipada.\n");
                    if (jugadorAcierta == true) {
                        if (enemigoEsquiva == false) {
                            logJugador.append(j.atacar(e) + "\n");
                        } else {
                            logJugador.append("Pero el enemigo esquiva el ataque.\n");
                        }
                    } else {
                        logJugador.append("Pero ha fallado el ataque.\n");
                    }
                } else {
                    logJugador.append("Ha usado " +
                        j.getHabilidades().at(1).getNombre() + ".\n");
                }
                logJugador.append(j.getHabilidades().at(1).usar(j, e));
            } else if (comando == "3") {
            if (j.getHabilidades().at(2).getUsosRestantes() == 0) {
                    logJugador.append("Ha atacado con el arma equipada.\n");
                    if (jugadorAcierta == true) {
                        if (enemigoEsquiva == false) {
                            logJugador.append(j.atacar(e) + "\n");
                        } else {
                            logJugador.append("Pero el enemigo esquiva el ataque.\n");
                        }
                    } else {
                        logJugador.append("Pero ha fallado el ataque.\n");
                    }
                } else {
                    logJugador.append("Ha usado " +
                        j.getHabilidades().at(2).getNombre() + ".\n");
                }
                logJugador.append(j.getHabilidades().at(2).usar(j, e));
            } else if (comando == "4") {
                if (j.getHabilidades().at(3).getUsosRestantes() == 0) {
                    logJugador.append("Ha atacado con el arma equipada.\n");
                    if (jugadorAcierta == true) {
                        if (enemigoEsquiva == false) {
                            logJugador.append(j.atacar(e) + "\n");
                        } else {
                            logJugador.append("Pero el enemigo esquiva el ataque.\n");
                        }
                    } else {
                        logJugador.append("Pero ha fallado el ataque.\n");
                    }
                } else {
                    logJugador.append("Ha usado " +
                        j.getHabilidades().at(3).getNombre() + ".\n");
                }
                logJugador.append(j.getHabilidades().at(3).usar(j, e));
            } else if (comando == "5") {
                if (j.getHabilidades().at(4).getUsosRestantes() == 0) {
                    logJugador.append("Ha atacado con el arma equipada.\n");
                    if (jugadorAcierta == true) {
                        if (enemigoEsquiva == false) {
                            logJugador.append(j.atacar(e) + "\n");
                        } else {
                            logJugador.append("Pero el enemigo esquiva el ataque.\n");
                        }
                    } else {
                        logJugador.append("Pero ha fallado el ataque.\n");
                    }
                } else {
                    logJugador.append("Ha usado " +
                        j.getHabilidades().at(4).getNombre() + ".\n");
                }
                logJugador.append(j.getHabilidades().at(4).usar(j, e));
            }
            logFinal.append(logTurno + logJugador + "\n\n\n");
            limpiarPantalla();
            std::cout << (pantallaCombate(turno, j, e, logFinal)) + "\n" << std::endl;
            logFinal.clear();
            pausar(650);
            /* Accion enemigo */
            logEnemigo = "> " + e.getNombre() + ":\n";
            logEnemigo.append(e.elegirAccion(j));
            logFinal.append(logTurno + logJugador + logEnemigo);
        } else {
            /* Accion enemigo */
            logEnemigo = "> " + e.getNombre() + ":\n";
            logEnemigo.append(e.elegirAccion(j));
            logFinal.append(logTurno + "\n\n\n" + logEnemigo);
            limpiarPantalla();
            std::cout << (pantallaCombate(turno, j, e, logFinal)) + "\n" << std::endl;
            logFinal.clear();
            pausar(650);
            /* Accion jugador */
            logJugador.append("> " + j.getNombre() + ":\n");
            if (comando == "a" || comando == "A") {
                logJugador.append("Ha atacado con el arma equipada.\n");
                if (jugadorAcierta == true) {
                    if (enemigoEsquiva == false) {
                        logJugador.append(j.atacar(e) + "\n");
                    } else {
                        logJugador.append("Pero el enemigo esquiva el ataque.\n");
                    }
                } else {
                    logJugador.append("Pero ha fallado el ataque.\n");
                }
            } else if (comando == "1") {
                if (j.getHabilidades().at(0).getUsosRestantes() == 0) {
                    logJugador.append("Ha atacado con el arma equipada.\n");
                    if (jugadorAcierta == true) {
                        if (enemigoEsquiva == false) {
                            logJugador.append(j.atacar(e) + "\n");
                        } else {
                            logJugador.append("Pero el enemigo esquiva el ataque.\n");
                        }
                    } else {
                        logJugador.append("Pero ha fallado el ataque.\n");
                    }
                } else {
                    logJugador.append("Ha usado " +
                        /* magia */
                        j.getHabilidades().at(0).getDescripcion() + ".\n");
                }
                logJugador.append(j.getHabilidades().at(0).usar(j, e));
            }  else if (comando == "2") {
                if (j.getHabilidades().at(1).getUsosRestantes() == 0) {
                    logJugador.append("Ha atacado con el arma equipada.\n");
                    if (jugadorAcierta == true) {
                        if (enemigoEsquiva == false) {
                            logJugador.append(j.atacar(e) + "\n");
                        } else {
                            logJugador.append("Pero el enemigo esquiva el ataque.\n");
                        }
                    } else {
                        logJugador.append("Pero ha fallado el ataque.\n");
                    }
                } else {
                    logJugador.append("Ha usado " +
                        j.getHabilidades().at(1).getNombre() + ".\n");
                }
                logJugador.append(j.getHabilidades().at(1).usar(j, e));
            } else if (comando == "3") {
            if (j.getHabilidades().at(2).getUsosRestantes() == 0) {
                    logJugador.append("Ha atacado con el arma equipada.\n");
                    if (jugadorAcierta == true) {
                        if (enemigoEsquiva == false) {
                            logJugador.append(j.atacar(e) + "\n");
                        } else {
                            logJugador.append("Pero el enemigo esquiva el ataque.\n");
                        }
                    } else {
                        logJugador.append("Pero ha fallado el ataque.\n");
                    }
                } else {
                    logJugador.append("Ha usado " +
                        j.getHabilidades().at(2).getNombre() + ".\n");
                }
                logJugador.append(j.getHabilidades().at(2).usar(j, e));
            } else if (comando == "4") {
                if (j.getHabilidades().at(3).getUsosRestantes() == 0) {
                    logJugador.append("Ha atacado con el arma equipada.\n");
                    if (jugadorAcierta == true) {
                        if (enemigoEsquiva == false) {
                            logJugador.append(j.atacar(e) + "\n");
                        } else {
                            logJugador.append("Pero el enemigo esquiva el ataque.\n");
                        }
                    } else {
                        logJugador.append("Pero ha fallado el ataque.\n");
                    }
                } else {
                    logJugador.append("Ha usado " +
                        j.getHabilidades().at(3).getNombre() + ".\n");
                }
                logJugador.append(j.getHabilidades().at(3).usar(j, e));
            } else if (comando == "5") {
                if (j.getHabilidades().at(4).getUsosRestantes() == 0) {
                    logJugador.append("Ha atacado con el arma equipada.\n");
                    if (jugadorAcierta == true) {
                        if (enemigoEsquiva == false) {
                            logJugador.append(j.atacar(e) + "\n");
                        } else {
                            logJugador.append("Pero el enemigo esquiva el ataque.\n");
                        }
                    } else {
                        logJugador.append("Pero ha fallado el ataque.\n");
                    }
                } else {
                    logJugador.append("Ha usado " +
                        j.getHabilidades().at(4).getNombre() + ".\n");
                }
                logJugador.append(j.getHabilidades().at(4).usar(j, e));
            }
            logFinal.append(logTurno + logJugador + logEnemigo);
        }



        /* 4. Imprimir la pantalla de turno con el logTurno */
        /* 5. Comprobar si los Personajes siguen vivos */
        if (j.getVida() <= 0 || e.getVida() <= 0) {
            std::string ganador = "";
            if (j.getVida() <= 0) {
                /* Empate. Se mira quien ataco primero */
                if (e.getVida() <= 0) {
                    if (empiezaJugador == true) {
                        jugadorSobrevive = true;
                        enemigoSobrevive = false;
                    } else {
                        jugadorSobrevive = false;
                        enemigoSobrevive = true;
                    }
                } else {
                    jugadorSobrevive = false;
                    ganador = e.getNombre();
                }
            }
            if (e.getVida() <= 0) {
                enemigoSobrevive = false;
                ganador = j.getNombre() + ". Subes de nivel";
            }
            imprimirPantallaEstatica(pantallaCombate(turno, j, e, logFinal),
                                     "Combate terminado.",
                                     "Ha ganado " + ganador + ".");
        } else {
            comando = cargarPantalla(
            pantallaCombate(turno, j, e, logFinal),
            opcionesPantallaCombate,
            imprimirLog(0,
                "Elija un comando: 'a': Atacar, '1-5': Usar Habilidades\n"),
                "Debe escribir 'a' o un numero del 1 al 5.\n");
        }

        /* 6. Incrementar el contador de turnos */
        turno++;
    }

    /* Se graba la informacion del personaje en partida:
     *  -La vida restante y los usos de las habilidades se mantienen igual
     *   que en el combate
     *  -Los atributos se quedan como antes del combate
     */
    if (jugadorSobrevive == true) {
        partida->getJugador().setVida(j.getVida());
        for (int i = 0; i < static_cast<int>(j.getHabilidades().size()); i++) {
            partida->getJugador().getHabilidades().at(i).setUsosRestantes(
                j.getHabilidades().at(i).getUsosRestantes());
        }
    }

    return jugadorSobrevive;
}
