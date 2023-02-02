#include "../../include/utilidadesDeTerminal.hpp"
#include "../../include/pantalla.hpp"
#include "../../include/pantallaInicio.hpp"
#include "../../include/pantallaComoJugar.hpp"
#include "../../include/pantallaCreacionPersonaje.hpp"


void menuPantallaInicio(std::string opcion) {
    if (opcion == "1") {
        menuTipoCreacionPersonaje(cargarPantalla(
            canvasTipoCreacionPersonaje,
            opcionesTipoCreacionPersonaje,
            imprimirLog(0, "Escriba 'a' para crear un personaje aleatorio o", "'m' para crearlo manualmente."),
            "Debe escribir a o m\n"));
    } else if (opcion == "2") {
		menuPantallaComoJugar(cargarPantalla(canvasPantallaComoJugar,
                                             opcionesPantallaComoJugar, ""));
	} else if (opcion == "3") {
        limpiarPantalla();
        std::cout << imprimirAmarillo("Gracias por jugar!\nHasta pronto\n");
        pausar(1.5);
	}
}
