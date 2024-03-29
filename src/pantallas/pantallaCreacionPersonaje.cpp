#include "../../include/pantallaCreacionPersonaje.hpp"
#include "../../include/pantallaMejoraPersonaje.hpp"
#include "../../include/partida.hpp"
#include <random>


std::string seleccionActual = "";
std::string nombrePersonaje = "Personaje";
/* seleccionActualNumerica contiene { Raza, Clase, Subclase, Arma } */
std::vector<int> seleccionActualNumerica = {0, 0, 0, 0};
std::string mensajeLog = "";
bool raza = false, clase = false, subclase = false;

void menuTipoCreacionPersonaje(std::string opcion) {
    if (opcion == "a" || opcion == "A") {
        Jugador jugador("Aleatorio",
                        numeroAleatorio(1,6),
                        numeroAleatorio(1,6),
                        numeroAleatorio(1,6),
                        numeroAleatorio(1,10));

        std::vector<int> mejoras = {
            numeroAleatorio(1,7),
            numeroAleatorio(1,7),
            numeroAleatorio(1,7)
        };
        std::vector<int> atributosAMejorar = {0, 0, 0, 0, 0, 0, 0};
        for (int i = 0; i < (int) mejoras.size(); i++) {
            atributosAMejorar[mejoras[i] - 1]++;
        }
        imprimirPantallaEstatica(pantallaPersonajeMejorado(jugador, mejoras));
        imprimirPantallaEstatica(pantallaInformacion(jugador));
        Partida partida(jugador);
        partida.iniciarPartida();
    } else if (opcion == "m" || opcion == "M") {
        menuCreacionPersonaje(cargarPantalla(
            canvasCreacionPersonaje,
            opcionesCreacionPersonaje,
            imprimirLog(0, "Seleccion actual: ", "Selecione una raza (1-6) "),
			"Seleccion actual: \nDebe escribir un numero del 1 al 6"));
    } else {
        menuTipoCreacionPersonaje(cargarPantalla(
            canvasTipoCreacionPersonaje,
            opcionesTipoCreacionPersonaje,
            imprimirLog(0, "Escriba 'a' para crear un personaje aleatorio o", "'m' para crearlo manualmente."),
            "Debe escribir a o m\n"));
    }
}

void menuCreacionPersonaje(std::string opcion) {
    if (opcion == "1") {
        if (!raza) 	{
            seleccionActual += "Humano, ";
            seleccionActualNumerica[0] = 1;
            mensajeLog = "Elija una clase (1-6)";
            raza = true;
        } else if (!clase) {
            seleccionActual += "Guerrero, ";
            seleccionActualNumerica[1] = 1;
            mensajeLog = "Elija una subclase (1-6)";
            clase = true;
        } else if (!subclase) {
            seleccionActual += "Herrero.";
            seleccionActualNumerica[2] = 1;
            mensajeLog = "Es correcta su seleccion? (s/n)";
            subclase = true;
        }
    } else if (opcion == "2") {
        if (!raza) 	{
            seleccionActual += "Enano, ";
            seleccionActualNumerica[0] = 2;
            mensajeLog = "Elija una clase (1-6)";
            raza = true;
        } else if (!clase) {
            seleccionActual += "Mago, ";
            seleccionActualNumerica[1] = 2;
            mensajeLog = "Elija una subclase (1-6)";
            clase = true;
        } else if (!subclase) {
            seleccionActual += "Alquimista.";
            seleccionActualNumerica[2] = 2;
            mensajeLog = "Es correcta su seleccion? (s/n)";
            subclase = true;
        }
    } else if (opcion == "3") {
        if (!raza) 	{
            seleccionActual += "Elfo, ";
            seleccionActualNumerica[0] = 3;
            mensajeLog = "Elija una clase (1-6)";
            raza = true;
        } else if (!clase) {
            seleccionActual += "Monje, ";
            seleccionActualNumerica[1] = 3;
            mensajeLog = "Elija una subclase (1-6)";
            clase = true;
        } else if (!subclase) {
            seleccionActual += "Gladiador.";
            seleccionActualNumerica[2] = 3;
            mensajeLog = "Es correcta su seleccion? (s/n)";
            subclase = true;
        }
    } else if (opcion == "4") {
        if (!raza) 	{
            seleccionActual += "Ogro, ";
            seleccionActualNumerica[0] = 4;
            mensajeLog = "Elija una clase (1-6)";
            raza = true;
        } else if (!clase) {
            seleccionActual += "Clerigo, ";
            seleccionActualNumerica[1] = 4;
            mensajeLog = "Elija una subclase (1-6)";
            clase = true;
        } else if (!subclase) {
            seleccionActual += "Boticario.";
            seleccionActualNumerica[2] = 4;
            mensajeLog = "Es correcta su seleccion? (s/n)";
            subclase = true;
        }
    } else if (opcion == "5") {
        if (!raza) 	{
            seleccionActual += "Triton, ";
            seleccionActualNumerica[0] = 5;
            mensajeLog = "Elija una clase (1-6)";
            raza = true;
        } else if (!clase) {
            seleccionActual += "Ladron, ";
            seleccionActualNumerica[1] = 5;
            mensajeLog = "Elija una subclase (1-6)";
            clase = true;
        } else if (!subclase) {
            seleccionActual += "Druida.";
            seleccionActualNumerica[2] = 5;
            mensajeLog = "Es correcta su seleccion? (s/n)";
            subclase = true;
        }
    } else if (opcion == "6") {
        if (!raza) 	{
            seleccionActual += "Bestia, ";
            seleccionActualNumerica[0] = 6;
            mensajeLog = "Elija una clase (1-6)";
            raza = true;
        } else if (!clase) {
            seleccionActual += "Trovador, ";
            seleccionActualNumerica[1] = 6;
            mensajeLog = "Elija una subclase (1-6)";
            clase = true;
        } else if (!subclase) {
            seleccionActual += "Mercenario.";
            seleccionActualNumerica[2] = 6;
            mensajeLog = "Es correcta su seleccion? (s/n)";
            subclase = true;
        }
    }

    if (raza & clase & subclase) {
        if (opcion == "s" || opcion == "S") {
            nombrePersonaje = cargarPantalla(
                canvasCreacionPersonaje,
                "Introduzca el nombre del personaje\n");
            menuSeleccionArma(cargarPantalla(
                canvasSeleccionArma,
                opcionesSeleccionArma,
                imprimirLog(0, "Personaje actual: "  + seleccionActual,
                            "Seleccione un arma (1-10) "),
                            "Personaje actual: " + seleccionActual +
                            "\nDebe escribir un numero del 1 al 10"));
        } else if (opcion == "n" || opcion == "N") {
            seleccionActual = "";
            mensajeLog = "";
            raza = false, clase = false, subclase = false;
            menuCreacionPersonaje(cargarPantalla(
                canvasCreacionPersonaje,
                opcionesCreacionPersonaje,
                imprimirLog(0,
                    "Seleccion actual: ",
                    "Selecione una raza (1-6) "),
                    "Seleccion actual: \nDebe escribir un numero del 1 al 6"));
        } else {
            menuCreacionPersonaje(cargarPantalla(
                canvasCreacionPersonaje,
                {"s", "S", "n", "N"},
                imprimirLog(0, "Seleccion actual: " + seleccionActual,
                            mensajeLog),
                "Seleccion actual: " + seleccionActual +
                "\nEs correcta su seleccion? Debe escribir s o n"));
        }
    } else {
        menuCreacionPersonaje(cargarPantalla(
            canvasCreacionPersonaje,
            opcionesCreacionPersonaje,
            imprimirLog(0, "Seleccion actual: " + seleccionActual, mensajeLog),
            "Seleccion actual: " + seleccionActual +
            "\nDebe escribir un numero del 1 al 6"));
    }
}

void menuSeleccionArma(std::string opcion) {
    mensajeLog = "Es correcta su seleccion? (s/n)";
    std::string seleccionActualArma = "";

    if (opcion == "1") {
        seleccionActualArma = "Espada.";
        seleccionActualNumerica[3] = 1;
    } else if (opcion == "2") {
        seleccionActualArma = "Estoque.";
        seleccionActualNumerica[3] = 2;
    } else if (opcion == "3") {
        seleccionActualArma = "Daga.";
        seleccionActualNumerica[3] = 3;
    } else if (opcion == "4") {
        seleccionActualArma = "Mandoble.";
        seleccionActualNumerica[3] = 4;
    } else if (opcion == "5") {
        seleccionActualArma = "Baculo.";
        seleccionActualNumerica[3] = 5;
    } else if (opcion == "6") {
        seleccionActualArma = "Hacha";
        seleccionActualNumerica[3] = 6;
    } else if (opcion == "7") {
        seleccionActualArma = "Lanza";
        seleccionActualNumerica[3] = 7;
    } else if (opcion == "8") {
        seleccionActualArma = "Arco";
        seleccionActualNumerica[3] = 8;
    } else if (opcion == "9") {
        seleccionActualArma = "Martillo";
        seleccionActualNumerica[3] = 9;
    } else if (opcion == "10") {
        seleccionActualArma = "Garras";
        seleccionActualNumerica[3] = 10;
    }

    if (opcion == "s" || opcion == "S") {
        Jugador jugador(nombrePersonaje,
                        seleccionActualNumerica[0],
                        seleccionActualNumerica[1],
                        seleccionActualNumerica[2],
                        seleccionActualNumerica[3]);
        imprimirPantallaEstatica(pantallaInformacion(jugador),
        "Tiene la oportunidad de mejorar hasta tres atributos.",
        "Puede mejorar varias veces el mismo atributo.");
        menuMejoraPersonaje(cargarPantalla(
            pantallaMejoraPersonaje(jugador, {0, 0, 0}),
            opcionesMejoraPersonaje,
            imprimirLog(0,
                "Seleccion actual: ",
                "Seleccione el primer atributo a mejorar (1-7)"),
                "Seleccion actual: \nDebe escribir un numero del 1 al 7"),
            jugador);
        imprimirPantallaEstatica(pantallaInformacion(jugador));
        Partida partida(jugador);
        partida.iniciarPartida();
    } else if (opcion == "n" || opcion == "N") {
        menuSeleccionArma(cargarPantalla(
            canvasSeleccionArma,
            opcionesSeleccionArma,
            imprimirLog(0,
                "Personaje actual: "  + seleccionActual + " " +
                seleccionActualArma,
                "Seleccione un arma (1-10) "),
            "Personaje actual: " + seleccionActual + " " + seleccionActualArma +
            "\nDebe escribir un numero del 1 al 10"));
    } else {
        menuSeleccionArma(cargarPantalla(
            canvasSeleccionArma,
            {"s", "S", "n", "N"},
            imprimirLog(0,
                "Seleccion actual: " + seleccionActual + " " +
                seleccionActualArma,
                mensajeLog),
            "Seleccion actual: " + seleccionActual + " " + seleccionActualArma +
            "\nEs correcta su seleccion? Debe escribir s o n"));
    }
}

int numeroAleatorio(int min, int max) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(min,max);

    return dist6(rng);
}
