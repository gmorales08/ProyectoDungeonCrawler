#include <algorithm>
#include "../../include/pantallaMejoraPersonaje.hpp"
#include "../../include/pantallaInformacionPersonaje.hpp"


std::string seleccionActualMejora = "";
/* seleccionActualNumericaMejora contiene los atributos a mejorar
 * 1 = vida
 * 2 = ataque
 * 3 = ataque magico
 * 4 = defensa
 * 5 = defensa magica
 * 6 = velocidad
 * 7 = evasion
 *
 * Ejemplo: {0, 0, 3} mejora dos veces la vida y una vez el ataque magico.
 */
std::vector<int> seleccionActualNumericaMejora = {0, 0, 0};
std::string mensajeLogMejora = "";
bool atributo1 = false;
bool atributo2 = false;
bool atributo3 = false;

void menuMejoraPersonaje(std::string opcion, Jugador& jugador) {
    if (opcion == "1") {
        if (atributo1 == false) {
            seleccionActualMejora += "Vida, ";
            seleccionActualNumericaMejora[0] = 1;
            mensajeLogMejora = "Escoja el segundo atributo a mejorar (1-7)";
            atributo1 = true;
        } else if (atributo2 == false) {
            seleccionActualMejora += "Vida y ";
            seleccionActualNumericaMejora[1] = 1;
            mensajeLogMejora = "Escoja el ultimo atributo a mejorar (1-7)";
            atributo2 = true;
        } else if (atributo3 == false) {
            seleccionActualMejora += "Vida.";
            seleccionActualNumericaMejora[2] = 1;
            mensajeLogMejora = "Es correcta su seleccion? (s/n)";
            atributo3 = true;
        }
    } else if (opcion == "2") {
        if (atributo1 == false) {
            seleccionActualMejora += "Ataque, ";
            seleccionActualNumericaMejora[0] = 2;
            mensajeLogMejora = "Escoja el segundo atributo a mejorar (1-7)";
            atributo1 = true;
        } else if (atributo2 == false) {
            seleccionActualMejora += "Ataque y ";
            seleccionActualNumericaMejora[1] = 2;
            mensajeLogMejora = "Escoja el ultimo atributo a mejorar (1-7)";
            atributo2 = true;
        } else if (atributo3 == false) {
            seleccionActualMejora += "Ataque.";
            seleccionActualNumericaMejora[2] = 2;
            mensajeLogMejora = "Es correcta su seleccion? (s/n)";
            atributo3 = true;
        }
    } else if (opcion == "3") {
        if (atributo1 == false) {
            seleccionActualMejora += "Ataque M., ";
            seleccionActualNumericaMejora[0] = 3;
            mensajeLogMejora = "Escoja el segundo atributo a mejorar (1-7)";
            atributo1 = true;
        } else if (atributo2 == false) {
            seleccionActualMejora += "Ataque M. y ";
            seleccionActualNumericaMejora[1] = 3;
            mensajeLogMejora = "Escoja el ultimo atributo a mejorar (1-7)";
            atributo2 = true;
        } else if (atributo3 == false) {
            seleccionActualMejora += "Ataque M.";
            seleccionActualNumericaMejora[2] = 3;
            mensajeLogMejora = "Es correcta su seleccion? (s/n)";
            atributo3 = true;
        }

    } else if (opcion == "4") {
        if (atributo1 == false) {
            seleccionActualMejora += "Defensa, ";
            seleccionActualNumericaMejora[0] = 4;
            mensajeLogMejora = "Escoja el segundo atributo a mejorar (1-7)";
            atributo1 = true;
        } else if (atributo2 == false) {
            seleccionActualMejora += "Defensa y ";
            seleccionActualNumericaMejora[1] = 4;
            mensajeLogMejora = "Escoja el ultimo atributo a mejorar (1-7)";
            atributo2 = true;
        } else if (atributo3 == false) {
            seleccionActualMejora += "Defensa.";
            seleccionActualNumericaMejora[2] = 4;
            mensajeLogMejora = "Es correcta su seleccion? (s/n)";
            atributo3 = true;
        }

    } else if (opcion == "5") {
        if (atributo1 == false) {
            seleccionActualMejora += "Defensa M., ";
            seleccionActualNumericaMejora[0] = 5;
            mensajeLogMejora = "Escoja el segundo atributo a mejorar (1-7)";
            atributo1 = true;
        } else if (atributo2 == false) {
            seleccionActualMejora += "Defensa M. y ";
            seleccionActualNumericaMejora[1] = 5;
            mensajeLogMejora = "Escoja el ultimo atributo a mejorar (1-7)";
            atributo2 = true;
        } else if (atributo3 == false) {
            seleccionActualMejora += "Defensa M.";
            seleccionActualNumericaMejora[2] = 5;
            mensajeLogMejora = "Es correcta su seleccion? (s/n)";
            atributo3 = true;
        }

    } else if (opcion == "6") {
        if (atributo1 == false) {
            seleccionActualMejora += "Velocidad, ";
            seleccionActualNumericaMejora[0] = 6;
            mensajeLogMejora = "Escoja el segundo atributo a mejorar (1-7)";
            atributo1 = true;
        } else if (atributo2 == false) {
            seleccionActualMejora += "Velocidad y ";
            seleccionActualNumericaMejora[1] = 6;
            mensajeLogMejora = "Escoja el ultimo atributo a mejorar (1-7)";
            atributo2 = true;
        } else if (atributo3 == false) {
            seleccionActualMejora += "Velocidad.";
            seleccionActualNumericaMejora[2] = 6;
            mensajeLogMejora = "Es correcta su seleccion? (s/n)";
            atributo3 = true;
        }

    } else if (opcion == "7") {
        if (atributo1 == false) {
            seleccionActualMejora += "Evasion, ";
            seleccionActualNumericaMejora[0] = 7;
            mensajeLogMejora = "Escoja el segundo atributo a mejorar (1-7)";
            atributo1 = true;
        } else if (atributo2 == false) {
            seleccionActualMejora += "Evasion y ";
            seleccionActualNumericaMejora[1] = 7;
            mensajeLogMejora = "Escoja el ultimo atributo a mejorar (1-7)";
            atributo2 = true;
        } else if (atributo3 == false) {
            seleccionActualMejora += "Evasion.";
            seleccionActualNumericaMejora[2] = 7;
            mensajeLogMejora = "Es correcta su seleccion? (s/n)";
            atributo3 = true;
        }
    }

    if (atributo1 == true && atributo2 == true && atributo3 == true) {
        if (opcion == "s" || opcion == "S") {
           imprimirPantallaEstatica(pantallaPersonajeMejorado(jugador,
                                        seleccionActualNumericaMejora));
           imprimirPantallaEstatica(pantallaInformacion(jugador));
        } else if (opcion == "n" || opcion == "N") {
            seleccionActualMejora = "";
            seleccionActualNumericaMejora = {0, 0, 0};
            mensajeLogMejora = "";
            atributo1 = false;
            atributo2 = false;
            atributo3 = false;
            menuMejoraPersonaje(cargarPantalla(
                pantallaMejoraPersonaje(jugador, {0, 0, 0}),
                opcionesMejoraPersonaje,
                imprimirLog(0,
                    "Seleccion actual: ",
                    "Seleccione el primer atributo a mejorar"),
                    "Seleccion actual: \nDebe escribir un numero del 1 al 7"),
                jugador);
        } else {
            menuMejoraPersonaje(cargarPantalla(
                pantallaMejoraPersonaje(jugador, seleccionActualNumericaMejora),
                {"s", "S", "n", "N"},
                imprimirLog(0, "Seleccion actual: " + seleccionActualMejora,
                    mensajeLogMejora),
                "Seleccion actual: " + seleccionActualMejora +
                "\nEs correcta su seleccion? Debe escribir s o n"),
                jugador);
        }
    } else {
        menuMejoraPersonaje(cargarPantalla(
            pantallaMejoraPersonaje(jugador, seleccionActualNumericaMejora),
            opcionesMejoraPersonaje,
            imprimirLog(0, "Seleccion actual: " + seleccionActualMejora, mensajeLogMejora),
            "Seleccion actual: " + seleccionActualMejora +
            "\nDebe escribir un numero del 1 al 7"),
            jugador);
    }
}


std::string pantallaMejoraPersonaje(Jugador& jugador, std::vector<int> mejoras) {
    std::string dadosMejoraVida      = "";
    std::string dadosMejoraAtaque    = "";
    std::string dadosMejoraAtaqueM   = "";
    std::string dadosMejoraDefensa   = "";
    std::string dadosMejoraDefensaM  = "";
    std::string dadosMejoraVelocidad = "";
    std::string dadosMejoraEvasion   = "";

    for (int i = 0; i < (int) mejoras.size(); i++) {
       if (mejoras[i] == 1) {
           dadosMejoraVida += "*";
       } else if (mejoras[i] == 2) {
           dadosMejoraAtaque += "*";
       } else if (mejoras[i] == 3) {
           dadosMejoraAtaqueM += "*";
       } else if (mejoras[i] == 4) {
           dadosMejoraDefensa += "*";
       } else if (mejoras[i] == 5) {
           dadosMejoraDefensaM += "*";
       } else if (mejoras[i] == 6) {
           dadosMejoraVelocidad += "*";
       } else if (mejoras[i] == 7) {
           dadosMejoraEvasion += "*";
       }
    }

    std::string pantallaMejora = "";
    pantallaMejora.append(
    "┌──────────────────────────────────────────────────────────────────────────────┐\n");
    pantallaMejora.append(centrarTexto("MEJORA DEL PERSONAJE",
                                            anchoPantalla) + "\n");
    pantallaMejora.append(centrarTexto("", anchoPantalla) + "\n");
    std::string infoJugador = jugador.getNombre() + ". " +
        jugador.getRazaString() + ", " + jugador.getClaseString() + ", " +
        jugador.getSubclaseString() + ".";
    std::transform(infoJugador.begin(), infoJugador.end(), infoJugador.begin(),
        ::toupper);
    pantallaMejora.append(centrarTexto(infoJugador, anchoPantalla) +
        "\n");
    pantallaMejora.append(centrarTexto("", anchoPantalla) + "\n");
    pantallaMejora.append(centrarTexto("Arma: " + jugador.getArmaString()
        + ", Elemento: " + jugador.getElementoString(), anchoPantalla + 10) +
        "\n");
    /* Se anade 22 espacios al ancho de pantalla para que calcule correctamente
    * el ancho al anadir informacion del color a la cadena de texto (metodo
    * imprimirColor de utlidadesTerminal)
    */
    pantallaMejora.append(centrarTexto("", anchoPantalla) + "\n");
    pantallaMejora.append(centrarTexto("Atributos:",
                                            (anchoPantalla) / 2,
                                            tuberia, " "));
    pantallaMejora.append(centrarTexto("Habilidades:",
                                            (anchoPantalla) / 2,
                                            " ", tuberia) + "\n");
    pantallaMejora.append(centrarTexto("", anchoPantalla) + "\n");

    pantallaMejora.append(centrarTexto("(1)Vida: " +
        std::to_string(jugador.getVida()) + "/" +
        std::to_string(jugador.getVidaMaxima()) + dadosMejoraVida,
                                            (anchoPantalla) / 2,
                                            tuberia, " "));
    pantallaMejora.append(alinearIzquierda(
        "  " + jugador.getHabilidades().at(0).getNombre() + ". Usos (" +
        std::to_string(jugador.getHabilidades().at(0).getUsosRestantes()) + "/"
        + std::to_string(jugador.getHabilidades().at(0).getUsosTotales()) +
        ") ",
        (anchoPantalla) / 2, " ", tuberia) + "\n");

    pantallaMejora.append(centrarTexto(
        "(2)Ataque: " + std::to_string(jugador.getAtaqueFisico()) + dadosMejoraAtaque,
        (anchoPantalla) / 2,
        tuberia, " "));
    pantallaMejora.append(alinearIzquierda(
        "  " + jugador.getHabilidades().at(1).getNombre() + ". Usos (" +
        std::to_string(jugador.getHabilidades().at(1).getUsosRestantes()) + "/"
        + std::to_string(jugador.getHabilidades().at(1).getUsosTotales()) +
        ") ",
        (anchoPantalla) / 2, " ", tuberia) + "\n");

    pantallaMejora.append(centrarTexto(
        "(3)Ataque magico: " + std::to_string(jugador.getAtaqueMagico()) + dadosMejoraAtaqueM,
        (anchoPantalla) / 2, tuberia, " "));
    pantallaMejora.append(alinearIzquierda(
        "   -" + jugador.getHabilidades().at(1).getDescripcion() + " " ,
        (anchoPantalla) / 2, " ", tuberia) + "\n");

    pantallaMejora.append(centrarTexto(
        "(4)Defensa: " + std::to_string(jugador.getDefensaFisica()) + dadosMejoraDefensa,
        (anchoPantalla) / 2, tuberia, " "));
    pantallaMejora.append(alinearIzquierda(
        "  " + jugador.getHabilidades().at(2).getNombre() + ". Usos (" +
        std::to_string(jugador.getHabilidades().at(2).getUsosRestantes()) +
        "/" + std::to_string(jugador.getHabilidades().at(2).getUsosTotales()) +
        ") ",
        (anchoPantalla) / 2, " ", tuberia) + "\n");

    pantallaMejora.append(centrarTexto(
        "(5)Defensa magica: " + std::to_string(jugador.getDefensaMagica()) + dadosMejoraDefensaM,
        (anchoPantalla) / 2, tuberia, " "));
    pantallaMejora.append(alinearIzquierda(
        "   -" + jugador.getHabilidades().at(2).getDescripcion() + " " ,
        (anchoPantalla) / 2, " ", tuberia) + "\n");

    pantallaMejora.append(centrarTexto(
        "(6)Velocidad: " + std::to_string(jugador.getVelocidad()) + dadosMejoraVelocidad,
        (anchoPantalla) / 2, tuberia, " "));
    pantallaMejora.append(alinearIzquierda(
        "  " + jugador.getHabilidades().at(3).getNombre() + ". Usos (" +
        std::to_string(jugador.getHabilidades().at(3).getUsosRestantes()) +
        "/" + std::to_string(jugador.getHabilidades().at(3).getUsosTotales()) +
        ") ",
        (anchoPantalla) / 2, " ", tuberia) + "\n");

    pantallaMejora.append(centrarTexto(
        "(7)Evasion: " + std::to_string(jugador.getEvasion()) + "%" + dadosMejoraEvasion,
        (anchoPantalla) / 2, tuberia, " "));
    pantallaMejora.append(alinearIzquierda(
        "   -" + jugador.getHabilidades().at(3).getDescripcion() + " " ,
        (anchoPantalla) / 2, " ", tuberia) + "\n");

    pantallaMejora.append(centrarTexto(
        "Precision: " + std::to_string(jugador.getPrecision()) + "%",
        (anchoPantalla) / 2, tuberia, " "));
    pantallaMejora.append(alinearIzquierda(
        "  " + jugador.getHabilidades().at(4).getNombre() + ". Usos (" +
        std::to_string(jugador.getHabilidades().at(4).getUsosRestantes()) +
        "/" + std::to_string(jugador.getHabilidades().at(4).getUsosTotales()) +
        ") ",
        (anchoPantalla) / 2, " ", tuberia) + "\n");

    pantallaMejora.append(centrarTexto(
        "Critico: " + std::to_string(jugador.getCritico()) + "%",
        (anchoPantalla) / 2, tuberia, " "));
    pantallaMejora.append(alinearIzquierda(
        "   -" + jugador.getHabilidades().at(4).getDescripcion() + " " ,
        (anchoPantalla) / 2, " ", tuberia) + "\n");
    pantallaMejora.append(centrarTexto("", anchoPantalla) + "\n");
    pantallaMejora.append(centrarTexto("", anchoPantalla) + "\n");
    pantallaMejora.append(
    "└──────────────────────────────────────────────────────────────────────────────┘\n");

    return pantallaMejora;
}

std::string pantallaPersonajeMejorado(Jugador& jugador,
                                      std::vector<int> mejoras) {
    std::vector<int> atributosAMejorar = {0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < (int) mejoras.size(); i++) {
        atributosAMejorar[mejoras[i] - 1]++;
    }

    int cantidadMejoraVida      = Personaje::tirarDados(atributosAMejorar[0]) *
        10;
    int cantidadMejoraAtaque    = Personaje::tirarDados(atributosAMejorar[1]);
    int cantidadMejoraAtaqueM   = Personaje::tirarDados(atributosAMejorar[2]);
    int cantidadMejoraDefensa   = Personaje::tirarDados(atributosAMejorar[3]);
    int cantidadMejoraDefensaM  = Personaje::tirarDados(atributosAMejorar[4]);
    int cantidadMejoraVelocidad = Personaje::tirarDados(atributosAMejorar[5]);
    int cantidadMejoraEvasion   = Personaje::tirarDados(atributosAMejorar[6]);

    std::string pantallaMejora = "";
    pantallaMejora.append(
    "┌──────────────────────────────────────────────────────────────────────────────┐\n");
    pantallaMejora.append(centrarTexto("MEJORA DEL PERSONAJE",
                                            anchoPantalla) + "\n");
    pantallaMejora.append(centrarTexto("", anchoPantalla) + "\n");
    std::string infoJugador = jugador.getNombre() + ". " +
        jugador.getRazaString() + ", " + jugador.getClaseString() + ", " +
        jugador.getSubclaseString() + ".";
    std::transform(infoJugador.begin(), infoJugador.end(), infoJugador.begin(),
        ::toupper);
    pantallaMejora.append(centrarTexto(infoJugador, anchoPantalla) +
        "\n");
    pantallaMejora.append(centrarTexto("", anchoPantalla) + "\n");
    pantallaMejora.append(centrarTexto("Arma: " + jugador.getArmaString()
        + ", Elemento: " + jugador.getElementoString(), anchoPantalla + 10) +
        "\n");
    /* Se anade 22 espacios al ancho de pantalla para que calcule correctamente
    * el ancho al anadir informacion del color a la cadena de texto (metodo
    * imprimirColor de utlidadesTerminal)
    */
    pantallaMejora.append(centrarTexto("", anchoPantalla) + "\n");
    pantallaMejora.append(centrarTexto("Atributos:",
                                            (anchoPantalla) / 2,
                                            tuberia, " "));
    pantallaMejora.append(centrarTexto("Habilidades:",
                                            (anchoPantalla) / 2,
                                            " ", tuberia) + "\n");
    pantallaMejora.append(centrarTexto("", anchoPantalla) + "\n");

    pantallaMejora.append(centrarTexto("Vida: " +
        std::to_string(jugador.getVida()) + "/" +
        std::to_string(jugador.getVidaMaxima()) + " (+" +
        std::to_string(cantidadMejoraVida) + ")",
                                            (anchoPantalla) / 2,
                                            tuberia, " "));
    pantallaMejora.append(alinearIzquierda(
        "  " + jugador.getHabilidades().at(0).getNombre() + ". Usos (" +
        std::to_string(jugador.getHabilidades().at(0).getUsosRestantes()) + "/"
        + std::to_string(jugador.getHabilidades().at(0).getUsosTotales()) +
        ") ",
        (anchoPantalla) / 2, " ", tuberia) + "\n");

    pantallaMejora.append(centrarTexto(
        "Ataque: " + std::to_string(jugador.getAtaqueFisico()) + " (+" +
        std::to_string(cantidadMejoraAtaque) + ")",
        (anchoPantalla) / 2,
        tuberia, " "));
    pantallaMejora.append(alinearIzquierda(
        "  " + jugador.getHabilidades().at(1).getNombre() + ". Usos (" +
        std::to_string(jugador.getHabilidades().at(1).getUsosRestantes()) + "/"
        + std::to_string(jugador.getHabilidades().at(1).getUsosTotales()) +
        ") ",
        (anchoPantalla) / 2, " ", tuberia) + "\n");

    pantallaMejora.append(centrarTexto(
        "Ataque magico: " + std::to_string(jugador.getAtaqueMagico()) + " (+" +
        std::to_string(cantidadMejoraAtaqueM) + ")",
        (anchoPantalla) / 2, tuberia, " "));
    pantallaMejora.append(alinearIzquierda(
        "   -" + jugador.getHabilidades().at(1).getDescripcion() + " " ,
        (anchoPantalla) / 2, " ", tuberia) + "\n");

    pantallaMejora.append(centrarTexto(
        "Defensa: " + std::to_string(jugador.getDefensaFisica()) + " (+" +
        std::to_string(cantidadMejoraDefensa) + ")",
        (anchoPantalla) / 2, tuberia, " "));
    pantallaMejora.append(alinearIzquierda(
        "  " + jugador.getHabilidades().at(2).getNombre() + ". Usos (" +
        std::to_string(jugador.getHabilidades().at(2).getUsosRestantes()) +
        "/" + std::to_string(jugador.getHabilidades().at(2).getUsosTotales()) +
        ") ",
        (anchoPantalla) / 2, " ", tuberia) + "\n");

    pantallaMejora.append(centrarTexto(
        "Defensa magica: " + std::to_string(jugador.getDefensaMagica()) + " (+"
        + std::to_string(cantidadMejoraDefensaM) + ")",
        (anchoPantalla) / 2, tuberia, " "));
    pantallaMejora.append(alinearIzquierda(
        "   -" + jugador.getHabilidades().at(2).getDescripcion() + " " ,
        (anchoPantalla) / 2, " ", tuberia) + "\n");

    pantallaMejora.append(centrarTexto(
        "Velocidad: " + std::to_string(jugador.getVelocidad()) + " (+" +
        std::to_string(cantidadMejoraVelocidad) + ")",
        (anchoPantalla) / 2, tuberia, " "));
    pantallaMejora.append(alinearIzquierda(
        "  " + jugador.getHabilidades().at(3).getNombre() + ". Usos (" +
        std::to_string(jugador.getHabilidades().at(3).getUsosRestantes()) +
        "/" + std::to_string(jugador.getHabilidades().at(3).getUsosTotales()) +
        ") ",
        (anchoPantalla) / 2, " ", tuberia) + "\n");

    pantallaMejora.append(centrarTexto(
        "Evasion: " + std::to_string(jugador.getEvasion()) + "%" + " (+" +
        std::to_string(cantidadMejoraEvasion) + "%)",
        (anchoPantalla) / 2, tuberia, " "));
    pantallaMejora.append(alinearIzquierda(
        "   -" + jugador.getHabilidades().at(3).getDescripcion() + " " ,
        (anchoPantalla) / 2, " ", tuberia) + "\n");

    pantallaMejora.append(centrarTexto(
        "Precision: " + std::to_string(jugador.getPrecision()) + "%",
        (anchoPantalla) / 2, tuberia, " "));
    pantallaMejora.append(alinearIzquierda(
        "  " + jugador.getHabilidades().at(4).getNombre() + ". Usos (" +
        std::to_string(jugador.getHabilidades().at(4).getUsosRestantes()) +
        "/" + std::to_string(jugador.getHabilidades().at(4).getUsosTotales()) +
        ") ",
        (anchoPantalla) / 2, " ", tuberia) + "\n");

    pantallaMejora.append(centrarTexto(
        "Critico: " + std::to_string(jugador.getCritico()) + "%",
        (anchoPantalla) / 2, tuberia, " "));
    pantallaMejora.append(alinearIzquierda(
        "   -" + jugador.getHabilidades().at(4).getDescripcion() + " " ,
        (anchoPantalla) / 2, " ", tuberia) + "\n");
    pantallaMejora.append(centrarTexto("", anchoPantalla) + "\n");
    pantallaMejora.append(centrarTexto("", anchoPantalla) + "\n");
    pantallaMejora.append(
    "└──────────────────────────────────────────────────────────────────────────────┘\n");

    /* Asignacion de valores de las mejoras  al jugador */
    jugador.aumentarVidaMaxima(cantidadMejoraVida);
    jugador.aumentarVida(cantidadMejoraVida);
    jugador.aumentarAtaqueFisico(cantidadMejoraAtaque);
    jugador.aumentarAtaqueMagico(cantidadMejoraAtaqueM);
    jugador.aumentarDefensaFisica(cantidadMejoraDefensa);
    jugador.aumentarDefensaMagica(cantidadMejoraDefensaM);
    jugador.aumentarVelocidad(cantidadMejoraVelocidad);
    jugador.aumentarEvasion(cantidadMejoraEvasion);

    return pantallaMejora;
}
