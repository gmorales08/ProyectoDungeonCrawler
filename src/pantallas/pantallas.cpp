#include <limits>
#include "../../include/utilidadesDeTerminal.h"
#include "../../include/pantallas.h"
#include "../../include/pantallaInicio.h"


void limpiarBufferEntrada() {

	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


std::string imprimirLog(std::string mensaje) {

	if (mensaje == "") return "\n";
	else return  (imprimirRojo("Mensaje del Sistema: ") + mensaje);
}


bool validarOpcion(std::string opcion, std::vector<std::string> opcionesMenu) {

	bool valido = false;
	for (int i = 0; i < (int) opcionesMenu.size(); i++)
		if (opcion == opcionesMenu[i]) valido = true;	

	return valido;
}


void cargarPantalla(std::string canvasPantalla, std::vector<std::string> opcionesMenu, std::string log) {


	limpiarPantalla();
	std::cout << canvasPantalla;
	std::cout << log            << "\n";
	std::cout << "Opcion: ";
	
	std::string opcion;
	std::cin >> opcion;
	limpiarBufferEntrada();

	if (validarOpcion(opcion, opcionesMenu)) 
		menuPantallaInicio(opcion);
	else 
		cargarPantalla(canvasPantalla, opcionesMenu, imprimirLog("Opcion no permitida\n")); 

}
