#include "../../include/pantalla.hpp"
#include "../../include/pantallaInicio.hpp"
#include "../../include/pantallaComoJugar.hpp"


void menuPantallaComoJugar(std::string opcion) {
    if (opcion == "1") {
        imprimirPantallaEstatica(canvasPantallaObjetivo);
        menuPantallaComoJugar(cargarPantalla(canvasPantallaComoJugar,
                                             opcionesPantallaComoJugar, "\n",
                "Opcion no permitida. Debe escribir un numero del 1 al 5.\n"));

    } else if (opcion == "2") {
		menuPantallaComoJugarCreacionPersonaje(cargarPantalla(
            canvasPantallaComoJugarCreacionPersonaje,
            opcionesPantallaComoJugarCreacionPersonaje, "\n",
            "Opcion no permitida. Debe escribir un numero del 1 al 7.\n"));
    } else if (opcion == "3") {
        menuPantallaComoJugarSistemaDeCombate(cargarPantalla(
            canvasSistemaDeCombate,
            opcionesPantallaComoJugarCreacionPersonaje, "\n",
            "Opcion no permitida. Debe escribir un numero del 1 al 4.\n"));
    } else if (opcion == "4") {
        imprimirPantallaEstatica(canvasEventos);
        menuPantallaComoJugar(cargarPantalla(canvasPantallaComoJugar,
                                             opcionesPantallaComoJugar, "\n",
            "Opcion no permitida. Debe escribir un numero del 1 al 5.\n"));
    } else {
        menuPantallaInicio(cargarPantalla(canvasPantallaInicio,
                                          opcionesPantallaInicio, "\n",
            "Opcion no permitida. Debe escribir un numero del 1 al 3.\n"));
    }
}

void menuPantallaComoJugarCreacionPersonaje(std::string opcion) {
    if (opcion == "1") {
        imprimirPantallaEstatica(canvasPantallaRaza);
        menuPantallaComoJugarCreacionPersonaje(cargarPantalla(
            canvasPantallaComoJugarCreacionPersonaje,
            opcionesPantallaComoJugarCreacionPersonaje, "\n",
            "Opcion no permitida. Debe escribir un numero del 1 al 7.\n"));
	} else if (opcion == "2") {
		imprimirPantallaEstatica(canvasPantallaClase);
		menuPantallaComoJugarCreacionPersonaje(cargarPantalla(
            canvasPantallaComoJugarCreacionPersonaje,
            opcionesPantallaComoJugarCreacionPersonaje, "\n",
            "Opcion no permitida. Debe escribir un numero del 1 al 7.\n"));
	} else if (opcion == "3") {
		imprimirPantallaEstatica(canvasPantallaSubclase);
		menuPantallaComoJugarCreacionPersonaje(cargarPantalla(
            canvasPantallaComoJugarCreacionPersonaje,
            opcionesPantallaComoJugarCreacionPersonaje, "\n",
            "Opcion no permitida. Debe escribir un numero del 1 al 7.\n"));
	} else if (opcion == "4") {
		imprimirPantallaEstatica(canvasPantallaArma);
		menuPantallaComoJugarCreacionPersonaje(cargarPantalla(
            canvasPantallaComoJugarCreacionPersonaje,
            opcionesPantallaComoJugarCreacionPersonaje, "\n",
            "Opcion no permitida. Debe escribir un numero del 1 al 7.\n"));
	} else if (opcion == "5") {
		imprimirPantallaEstatica(canvasAtributos);
		menuPantallaComoJugarCreacionPersonaje(cargarPantalla(
            canvasPantallaComoJugarCreacionPersonaje,
            opcionesPantallaComoJugarCreacionPersonaje, "\n",
            "Opcion no permitida. Debe escribir un numero del 1 al 7.\n"));
	} else if (opcion == "6") {
		imprimirPantallaEstatica(canvasMagiaYHabilidades);
		menuPantallaComoJugarCreacionPersonaje(cargarPantalla(
            canvasPantallaComoJugarCreacionPersonaje,
            opcionesPantallaComoJugarCreacionPersonaje, "\n",
            "Opcion no permitida. Debe escribir un numero del 1 al 7.\n"));
	} else {
		menuPantallaComoJugar(cargarPantalla(canvasPantallaComoJugar,
                                             opcionesPantallaComoJugar, "\n",
            "Opcion no permitida. Debe escribir un numero del 1 al 5.\n"));
	}
}

void menuPantallaComoJugarSistemaDeCombate(std::string opcion) {
	if (opcion == "1") {
		imprimirPantallaEstatica(canvasFundamentosCombate);
		menuPantallaComoJugarSistemaDeCombate(cargarPantalla(
            canvasSistemaDeCombate,
            opcionesPantallaSistemaDeCombate, "\n",
            "Opcion no permitida. Debe escribir un numero del 1 al 4.\n"));
	} else if (opcion == "2") {
		imprimirPantallaEstatica(canvasCalculoDano);
		menuPantallaComoJugarSistemaDeCombate(cargarPantalla(
            canvasSistemaDeCombate,
            opcionesPantallaSistemaDeCombate, "\n",
            "Opcion no permitida. Debe escribir un numero del 1 al 4.\n"));
	} else if (opcion == "3") {
		imprimirPantallaEstatica(canvasAfinidadesElementales);
		menuPantallaComoJugarSistemaDeCombate(cargarPantalla(
            canvasSistemaDeCombate,
            opcionesPantallaSistemaDeCombate, "\n",
            "Opcion no permitida. Debe escribir un numero del 1 al 4.\n"));
	} else {
		menuPantallaComoJugar(cargarPantalla(canvasPantallaComoJugar,
                                             opcionesPantallaComoJugar, "\n",
            "Opcion no permitida. Debe escribir un numero del 1 al 5.\n"));
	}
}
