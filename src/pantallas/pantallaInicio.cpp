#include "../../include/utilidadesDeTerminal.h"
#include "../../include/pantallas.h"
#include "../../include/pantallaInicio.h"
#include "../../include/pantallaComoJugar.h"

void menuPantallaInicio(std::string opcion) {

	if (opcion == "1") { //JUGAR
	
	} else if (opcion == "2") { 

		menuPantallaComoJugar(cargarPantalla(canvasPantallaComoJugar, opcionesPantallaComoJugar, "")); 
	
	} else if (opcion == "3") {

		limpiarPantalla();
		std::cout << imprimirAmarillo("Gracias por jugar!\nHasta pronto\n");
		pausar(1.5);
	}

}
