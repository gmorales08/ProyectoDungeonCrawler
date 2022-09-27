#include "../include/pantallas.h"
#include "../include/pantallaInicio.h"


int main() {


	srand((unsigned) time(0)); // Semilla que se usuara para operaciones con numeros pseudo-aleatorios

	menuPantallaInicio(cargarPantalla(canvasPantallaInicio, opcionesPantallaInicio, ""));

	return 0;
}
