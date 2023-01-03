#include "../../include/pantalla.hpp"
#include "../../include/pantallaInicio.hpp"
#include "../../include/pantallaComoJugar.hpp"


void menuPantallaComoJugar(std::string opcion) {
    if (opcion == "1") {
        imprimirPantallaEstatica(canvasPantallaObjetivo);
        menuPantallaComoJugar(cargarPantalla(canvasPantallaComoJugar,
                                             opcionesPantallaComoJugar, ""));
    } else if (opcion == "2") {
		menuPantallaComoJugarCreacionPersonaje(cargarPantalla(
            canvasPantallaComoJugarCreacionPersonaje,
            opcionesPantallaComoJugarCreacionPersonaje, ""));
    } else if (opcion == "3") {
        menuPantallaComoJugarSistemaDeCombate(cargarPantalla(
            canvasSistemaDeCombate,
            opcionesPantallaComoJugarCreacionPersonaje, ""));
    } else if (opcion == "4") {
        imprimirPantallaEstatica(canvasEventos);
        menuPantallaComoJugar(cargarPantalla(canvasPantallaComoJugar,
                                             opcionesPantallaComoJugar, ""));
    } else {
        menuPantallaInicio(cargarPantalla(canvasPantallaInicio,
                                          opcionesPantallaInicio, ""));
    }
}

void menuPantallaComoJugarCreacionPersonaje(std::string opcion) {
    if (opcion == "1") {
        imprimirPantallaEstatica(canvasPantallaRaza);
        menuPantallaComoJugarCreacionPersonaje(cargarPantalla(
            canvasPantallaComoJugarCreacionPersonaje,
            opcionesPantallaComoJugarCreacionPersonaje, ""));
	} else if (opcion == "2") {
		imprimirPantallaEstatica(canvasPantallaClase);
		menuPantallaComoJugarCreacionPersonaje(cargarPantalla(
            canvasPantallaComoJugarCreacionPersonaje,
            opcionesPantallaComoJugarCreacionPersonaje, ""));
	} else if (opcion == "3") {
		imprimirPantallaEstatica(canvasPantallaSubclase);
		menuPantallaComoJugarCreacionPersonaje(cargarPantalla(
            canvasPantallaComoJugarCreacionPersonaje,
            opcionesPantallaComoJugarCreacionPersonaje, ""));
	} else if (opcion == "4") {
		imprimirPantallaEstatica(canvasPantallaArma);
		menuPantallaComoJugarCreacionPersonaje(cargarPantalla(
            canvasPantallaComoJugarCreacionPersonaje,
            opcionesPantallaComoJugarCreacionPersonaje, ""));
	} else if (opcion == "5") {
		imprimirPantallaEstatica(canvasAtributos);
		menuPantallaComoJugarCreacionPersonaje(cargarPantalla(
            canvasPantallaComoJugarCreacionPersonaje,
            opcionesPantallaComoJugarCreacionPersonaje, ""));
	} else if (opcion == "6") {
		imprimirPantallaEstatica(canvasMagiaYHabilidades);
		menuPantallaComoJugarCreacionPersonaje(cargarPantalla(
            canvasPantallaComoJugarCreacionPersonaje,
            opcionesPantallaComoJugarCreacionPersonaje, ""));
	} else {
		menuPantallaComoJugar(cargarPantalla(canvasPantallaComoJugar,
                                             opcionesPantallaComoJugar, ""));
	}
}


void menuPantallaComoJugarSistemaDeCombate(std::string opcion) {
	if (opcion == "1") {
		imprimirPantallaEstatica(canvasFundamentosCombate);
		menuPantallaComoJugarSistemaDeCombate(cargarPantalla(
            canvasSistemaDeCombate,
            opcionesPantallaSistemaDeCombate, ""));
	} else if (opcion == "2") {
		imprimirPantallaEstatica(canvasCalculoDano);
		menuPantallaComoJugarSistemaDeCombate(cargarPantalla(
            canvasSistemaDeCombate,
            opcionesPantallaSistemaDeCombate, ""));
	} else if (opcion == "3") {
		imprimirPantallaEstatica(canvasAfinidadesElementales);
		menuPantallaComoJugarSistemaDeCombate(cargarPantalla(
            canvasSistemaDeCombate,
            opcionesPantallaSistemaDeCombate, ""));
	} else {
		menuPantallaComoJugar(cargarPantalla(canvasPantallaComoJugar,
                                             opcionesPantallaComoJugar, ""));
	}
}
