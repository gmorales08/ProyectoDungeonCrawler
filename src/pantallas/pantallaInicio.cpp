#include "../../include/utilidadesDeTerminal.h"
#include "../../include/pantallas.h"
#include "../../include/pantallaInicio.h"
#include "../../include/pantallaComoJugar.h"
#include "../../include/pantallaCreacionPersonaje.h"

void menuPantallaInicio(std::string opcion) {

	if (opcion == "1") { 
		
		menuCreacionPersonaje(cargarPantalla(canvasCreacionPersonaje, opcionesCreacionPersonaje, imprimirLog(0, "Seleccion actual: ", "Selecione una raza (1-6) "),
					"Seleccion actual: \nDebe escribir un numero del 1 al 6"));

	} else if (opcion == "2") { 

		menuPantallaComoJugar(cargarPantalla(canvasPantallaComoJugar, opcionesPantallaComoJugar, "")); 
	
	} else if (opcion == "3") {

		limpiarPantalla();
		std::cout << imprimirAmarillo("Gracias por jugar!\nHasta pronto\n");
		pausar(1.5);
	}

}
