#include "../../include/utilidadesDeTerminal.hpp"
#include "../../include/pantalla.hpp"
#include "../../include/pantallaInicio.hpp"
#include "../../include/pantallaComoJugar.hpp"
#include "../../include/pantallaCreacionPersonaje.hpp"


void menuPantallaInicio(std::string opcion) {
    if (opcion == "1") {
        menuCreacionPersonaje(cargarPantalla(
            canvasCreacionPersonaje,
            opcionesCreacionPersonaje,
            imprimirLog(0, "Seleccion actual: ", "Selecione una raza (1-6) "),
			"Seleccion actual: \nDebe escribir un numero del 1 al 6"));
    } else if (opcion == "2") {
		menuPantallaComoJugar(cargarPantalla(canvasPantallaComoJugar,
                                             opcionesPantallaComoJugar, ""));
	} else if (opcion == "3") {
        limpiarPantalla();
        std::cout << imprimirAmarillo("Gracias por jugar!\nHasta pronto\n");
        pausar(1.5);
	}
}
