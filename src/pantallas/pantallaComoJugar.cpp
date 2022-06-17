#include "../../include/pantallas.h"
#include "../../include/pantallaInicio.h"
#include "../../include/pantallaComoJugar.h"


void menuPantallaComoJugar(std::string opcion) {

	if (opcion == "1") {
		
		imprimirPantallaEstatica(canvasPantallaObjetivo);		 
		menuPantallaComoJugar(cargarPantalla(canvasPantallaComoJugar, opcionesPantallaComoJugar, ""));

	} else if (opcion == "2") {
		
		menuPantallaComoJugarCreacionPersonaje(cargarPantalla(canvasPantallaComoJugarCreacionPersonaje, opcionesPantallaComoJugarCreacionPersonaje, ""));

	} else if (opcion == "3") {

	} else if (opcion == "4") {

	} else {

		menuPantallaInicio(cargarPantalla(canvasPantallaInicio, opcionesPantallaInicio, ""));
	}
}

void menuPantallaComoJugarCreacionPersonaje(std::string opcion) {

	if (opcion == "1") {
		
		imprimirPantallaEstatica(canvasPantallaRaza);
		menuPantallaComoJugarCreacionPersonaje(cargarPantalla(canvasPantallaComoJugarCreacionPersonaje, opcionesPantallaComoJugarCreacionPersonaje, ""));

	} else if (opcion == "2") {

		imprimirPantallaEstatica(canvasPantallaClase);
		menuPantallaComoJugarCreacionPersonaje(cargarPantalla(canvasPantallaComoJugarCreacionPersonaje, opcionesPantallaComoJugarCreacionPersonaje, ""));

	} else if (opcion == "3") {

		imprimirPantallaEstatica(canvasPantallaSubclase);
		menuPantallaComoJugarCreacionPersonaje(cargarPantalla(canvasPantallaComoJugarCreacionPersonaje, opcionesPantallaComoJugarCreacionPersonaje, ""));

	} else if (opcion == "4") {

		imprimirPantallaEstatica(canvasPantallaArma);
		menuPantallaComoJugarCreacionPersonaje(cargarPantalla(canvasPantallaComoJugarCreacionPersonaje, opcionesPantallaComoJugarCreacionPersonaje, ""));

	} else if (opcion == "5") {
	
		imprimirPantallaEstatica(canvasAtributos);
		menuPantallaComoJugarCreacionPersonaje(cargarPantalla(canvasPantallaComoJugarCreacionPersonaje, opcionesPantallaComoJugarCreacionPersonaje, ""));

	} else {
		
		menuPantallaComoJugar(cargarPantalla(canvasPantallaComoJugar, opcionesPantallaComoJugar, ""));
	}
}
