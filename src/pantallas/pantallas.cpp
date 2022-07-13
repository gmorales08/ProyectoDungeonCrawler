#include <limits>
#include "../../include/utilidadesDeTerminal.h"
#include "../../include/pantallas.h"


void limpiarBufferEntrada() {

	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


std::string imprimirLog(int tipoDeMensaje, std::string mensaje) {

	if (tipoDeMensaje == 0)  mensaje = imprimirAmarillo("Mensaje del Sistema: ") + mensaje;
	else if (tipoDeMensaje == 1) mensaje = imprimirRojo("Mensaje del Sistema: ") + mensaje;

	return (mensaje + "\n");
}

std::string imprimirLog(int tipoDeMensaje, std::string mensaje1, std::string mensaje2) {

	std::string mensajeFinal;
	if (tipoDeMensaje == 0)  mensajeFinal = imprimirAmarillo("Mensaje del Sistema: ") + mensaje1 + "\n                     " + mensaje2;
	else if (tipoDeMensaje == 1) mensajeFinal = imprimirRojo("Mensaje del Sistema: ") + mensaje1 + "\n                     " + mensaje2;

	return (mensajeFinal + "\n");
}



bool validarOpcion(std::string opcion, std::vector<std::string> opcionesMenu) {

	bool valido = false;
	for (int i = 0; i < (int) opcionesMenu.size(); i++)
		if (opcion == opcionesMenu[i]) valido = true;	

	return valido;
}


std::string cargarPantalla(std::string canvasPantalla, std::vector<std::string> opcionesMenu, std::string log) {

	limpiarPantalla();
	std::cout << canvasPantalla;
	std::cout << log << "\n";
	std::cout << "Opcion: ";
	
	std::string opcion;
	std::cin >> opcion;
	limpiarBufferEntrada();

	if (validarOpcion(opcion, opcionesMenu)) return opcion;
	else return cargarPantalla(canvasPantalla, opcionesMenu, imprimirLog(1, "Opcion no permitida")); 
}


std::string cargarPantalla(std::string canvasPantalla, std::vector<std::string> opcionesMenu, std::string log, std::string logError) {

	limpiarPantalla();
	std::cout << canvasPantalla;
	std::cout << log << "\n";
	std::cout << "Opcion: ";
	std::string opcion;
	std::cin >> opcion;
	limpiarBufferEntrada();

	if (validarOpcion(opcion, opcionesMenu)) return opcion;
	else return cargarPantalla(canvasPantalla, opcionesMenu, imprimirLog(1, logError), logError);

}


std::string cargarPantalla(std::string canvasPantalla, std::string log) {

	limpiarPantalla();
	std::cout << canvasPantalla;
	std::cout << log << "\n";
	std::cout << "Opcion: ";
	std::string opcion;
	std::cin >> opcion;
	limpiarBufferEntrada();

	return opcion;
}


void imprimirPantallaEstatica(std::string canvasPantalla) {

	limpiarPantalla();
	std::cout << canvasPantalla;
	std::cout << "\n\nPulse intro para continuar...";
	limpiarBufferEntrada();
}
