#include <string>
#include "../../include/pantallaPiso.hpp"
#include "../../include/pantallaEvento.hpp"
#include "../../include/combate.hpp"
#include "../../include/pantallaInformacionPersonaje.hpp"

std::string pantallaPiso(int numeroPiso, int pisosRestantes) {
    std::string pantalla = "";
    pantalla.append(
"┌──────────────────────────────────────────────────────────────────────────────┐\n");
    pantalla.append(centrarTexto("", anchoPantalla) + "\n");
    pantalla.append(centrarTexto("PISO " + std::to_string(numeroPiso),
                                 anchoPantalla) + "\n");
    pantalla.append(centrarTexto("", anchoPantalla) + "\n");
    pantalla.append(centrarTexto("", anchoPantalla) + "\n");
    pantalla.append(centrarTexto("", anchoPantalla) + "\n");
    pantalla.append(centrarTexto("(a) --|===> SEGUIR AVANZANDO <===|--",
                                 anchoPantalla) + "\n");
    pantalla.append(centrarTexto("", anchoPantalla) + "\n");
    pantalla.append(centrarTexto("", anchoPantalla) + "\n");
    pantalla.append(centrarTexto("(i)    Informacion del personaje    ",
                                anchoPantalla) + "\n");
    pantalla.append(centrarTexto("", anchoPantalla) + "\n");
    pantalla.append(centrarTexto("", anchoPantalla) + "\n");
    pantalla.append(centrarTexto("(e)          Estadisticas           ",
                                 anchoPantalla) + "\n");

    pantalla.append(centrarTexto("", anchoPantalla) + "\n");
    pantalla.append(centrarTexto("", anchoPantalla) + "\n");
    pantalla.append(centrarTexto("Quedan " + std::to_string(pisosRestantes) +
                                 " pisos para el final", anchoPantalla) + "\n");
    pantalla.append(centrarTexto("", anchoPantalla) + "\n");
    pantalla.append(centrarTexto("", anchoPantalla) + "\n");
    pantalla.append(centrarTexto("", anchoPantalla) + "\n");
    pantalla.append(centrarTexto("", anchoPantalla) + "\n");
    pantalla.append(
"└──────────────────────────────────────────────────────────────────────────────┘\n");

    return pantalla;
}

void menuPantallaPiso(std::string opcion, Partida* partida) {
    if (opcion == "a" || opcion == "A") {
        /* 80% -> combate ; 20% -> evento
         * Entre el piso 5 y 6 hay un evento asegurado
         * El piso 10 es siempre un combate
         */
        if (partida->getPisoActual() == 5) {
            Evento& evento = partida->generarEvento();
            std::string respuesta = cargarPantalla(
                pantallaEvento(evento),
                opcionesPantallaEvento,
                imprimirLog(0,
                "¿Quiere aceptar el evento? Escriba 'a' para aceptarlo o 'r'",
                "para rechazarlo."),
                "Opcion no permitida. Debe escribir 'a' o 'r'.\n");
            if (respuesta == "a" || respuesta == "A") {
                int resultado = evento.aceptarEvento(partida->getJugador(),
                                                    partida);
                imprimirPantallaEstatica(pantallaEventoResuelto(evento, resultado));
            }
            /* Si la respuesta es r, no se hace nada */
        } else if (partida->getPisoActual() == 10) {
            bool jugadorVivo = iniciarCombate(partida);
        } else {
            int tirada = Personaje::tirarDado(10);
            if (tirada <= 8) {
                bool jugadorVivo = iniciarCombate(partida);
            } else {
                // Evento
                /* Se muestra la pantalla del evento y se lee si el usuario lo
                * acepta.
                */
                Evento& evento = partida->generarEvento();
                std::string respuesta = cargarPantalla(
                    pantallaEvento(evento),
                    opcionesPantallaEvento,
                    imprimirLog(0,
                    "¿Quiere aceptar el evento? Escriba 'a' para aceptarlo o 'r'",
                    "para rechazarlo."),
                    "Opcion no permitida. Debe escribir 'a' o 'r'.\n");
                if (respuesta == "a" || respuesta == "A") {
                    int resultado = evento.aceptarEvento(partida->getJugador(),
                                                        partida);
                    imprimirPantallaEstatica(pantallaEventoResuelto(evento, resultado));
                }
                /* Si la respuesta es r, no se hace nada */
            }
        }
    } else if (opcion == "i" || opcion == "I") {
        imprimirPantallaEstatica(pantallaInformacion(partida->getJugador()));
        partida->retrocederPiso();
    } else if (opcion == "e" || opcion == "E") {
        // estadisticas
    }
}
