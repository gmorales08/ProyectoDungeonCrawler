#include <iostream>
#include <limits>

#include "../../include/utilidadesDeTerminal.h"
#include "../../include/pantallaInicio.h"


void imprimirPantallaInicio() {

	limpiarPantalla();
	
	std::cout << canvasPantallaInicio;
}


void menuPantallaInicio() {

	int opcionSeleccionadaPantallaInicio; 

	do {
		
		imprimirPantallaInicio();
		std::cin >> opcionSeleccionadaPantallaInicio;

		switch (opcionSeleccionadaPantallaInicio) {

			case 1: //jugar();
				break;
			
			case 2: //comoJugar();
				break;

			case 3: 
				break;

			default:
				//poner un mensaje en el log
				std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

	} while (opcionSeleccionadaPantallaInicio != 3);

	// detener programa y mostrar despedida
}
