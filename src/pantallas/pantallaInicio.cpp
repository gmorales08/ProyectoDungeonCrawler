#include "../../include/utilidadesDeTerminal.h"
#include "../../include/pantallaInicio.h"


void menuPantallaInicio(std::string opcion) {

	if (opcion == "1") { //JUGAR
	
	} else if (opcion == "2") { //COMO JUGAR
	
	} else if (opcion == "3") {

		limpiarPantalla();
		std::cout << imprimirAmarillo("Gracias por jugar!\nHasta pronto\n");
		pausar(2);
	}

}
