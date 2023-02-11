#include "./../include/pantalla.hpp"
#include "./../include/pantallaInicio.hpp"


int main() {
    menuPantallaInicio(
        cargarPantalla(canvasPantallaInicio, opcionesPantallaInicio, "\n",
                       "Opcion no permitida. Debe escribir un numero del 1 al 3.\n"));

	return 0;
}
