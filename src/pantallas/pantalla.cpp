#include <ios>
#include <limits>
#include "../../include/utilidadesDeTerminal.hpp"
#include "../../include/pantalla.hpp"


void limpiarBufferEntrada() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::string imprimirLog(int tipoDeMensaje, std::string mensaje) {
    if (tipoDeMensaje == 0) {
        mensaje = imprimirAmarillo("Mensaje del Sistema: ") + mensaje;
    } else if (tipoDeMensaje == 1) {
        mensaje = imprimirRojo("Mensaje del Sistema: ") + mensaje;
    }

    return (mensaje);
}

std::string imprimirLog(int tipoDeMensaje, std::string mensaje1,
                        std::string mensaje2) {
    std::string mensajeFinal;
    if (tipoDeMensaje == 0) {
        mensajeFinal = imprimirAmarillo("Mensaje del Sistema: ") + mensaje1 +
                       "\n                     " + mensaje2;
    } else if (tipoDeMensaje == 1) {
        mensajeFinal = imprimirRojo("Mensaje del Sistema: ") + mensaje1 +
                       "\n                     " + mensaje2;
    }

    return (mensajeFinal);
}

bool validarOpcion(std::string opcion, std::vector<std::string> opcionesMenu) {
    bool valido = false;
    for (int i = 0; i < (int) opcionesMenu.size(); i++) {
        if (opcion == opcionesMenu[i]) valido = true;
    }

	return valido;
}

std::string cargarPantalla(std::string canvasPantalla,
                           std::vector<std::string> opcionesMenu,
                           std::string log) {
    limpiarPantalla();
    std::cout << canvasPantalla;
    std::cout << log << "\n";
    std::cout << "Opcion: ";
    std::string opcion;
    std::cin >> opcion;
    limpiarBufferEntrada();

    if (!validarOpcion(opcion, opcionesMenu)) {
        opcion = cargarPantalla(canvasPantalla, opcionesMenu,
                                imprimirLog(1, "Opcion no permitida"));
    }

    return opcion;
}

std::string cargarPantalla(std::string canvasPantalla,
                           std::vector<std::string> opcionesMenu,
                           std::string log, std::string logError) {
    limpiarPantalla();
    std::cout << canvasPantalla;
    std::cout << log << "\n";
    std::cout << "Opcion: ";
    std::string opcion;
    std::cin >> opcion;
    limpiarBufferEntrada();

    if (!validarOpcion(opcion, opcionesMenu)) {
        opcion = cargarPantalla(canvasPantalla, opcionesMenu, 
                 imprimirLog(1, logError), logError);
    }

    return opcion;
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
    std::cout << "\nPulse intro para continuar";
    limpiarBufferEntrada();
}

void imprimirPantallaEstatica(std::string canvasPantalla, std::string log) {
    limpiarPantalla();
    std::cout << canvasPantalla;
    std::cout << imprimirLog(0, log);
    std::cout << "\nPulse intro para continuar";
    limpiarBufferEntrada();
}

void imprimirPantallaEstatica(std::string canvasPantalla, std::string log1,
        std::string log2) {
    limpiarPantalla();
    std::cout << canvasPantalla;
    std::cout << imprimirLog(0, log1, log2);
    std::cout << "\nPulse intro para continuar";
    limpiarBufferEntrada();
}

std::string centrarTexto(std::string texto, int longitudLinea) {
    std::string lineaADevolver = "│";
    int espaciosDcha;
    int espaciosIzda;

    /* Comprobamos que el texto cabe en una linea */
	if (texto.length() <= (long unsigned int) longitudLinea) {
        espaciosIzda = (longitudLinea - 2 - texto.length()) / 2;
        /* Comprobamos si el numero de espacios disponible es par o impar */
        if ((longitudLinea - 2 - texto.length()) % 2 == 0) {
            espaciosDcha = espaciosIzda;
        } else {
            espaciosDcha = espaciosIzda + 1;
        }
    } else {
        return "";
    } // Si la linea no cabe, no la imprime

    for (int i = 0; i < espaciosIzda; i++) {
        lineaADevolver += " ";
    }
	lineaADevolver += texto;
    for (int i = 0; i < espaciosDcha; i++) {
        lineaADevolver += " ";
    }
	lineaADevolver += "│";

    return lineaADevolver;
}

std::string centrarTexto(std::string texto, int longitudLinea,
                         std::string caracterInicial,
                         std::string caracterFinal) {
    std::string lineaADevolver = caracterInicial;
    int espaciosDcha;
    int espaciosIzda;

    /* Comprobamos que el texto cabe en una linea */
	if (texto.length() <= (long unsigned int) longitudLinea) {
        espaciosIzda = (longitudLinea - 2 - texto.length()) / 2;
        /* Comprobamos si el numero de espacios disponible es par o impar */
        if ((longitudLinea - 2 - texto.length()) % 2 == 0) {
            espaciosDcha = espaciosIzda;
        } else {
            espaciosDcha = espaciosIzda + 1;
        }
    } else {
        return "";
    } // Si la linea no cabe, no la imprime

    for (int i = 0; i < espaciosIzda; i++) {
        lineaADevolver += " ";
    }
	lineaADevolver += texto;
    for (int i = 0; i < espaciosDcha; i++) {
        lineaADevolver += " ";
    }
	lineaADevolver += caracterFinal;

    return lineaADevolver;
}

