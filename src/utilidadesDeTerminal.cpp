#include <cstdio>
#include <string>
#include <iostream>
#include "utilidadesDeTerminal.h"


/*void configurarVentana() {

	#ifdef __linux__

	system("resize -s 24 80");  //termimal pequeña
	//system("resize -s 43 132"); terminal grande	

	#endif //__linux__
}*/


void limpiarPantalla() {

	printf("\033[H\033[J");
	printf("\033[38;5;231m");
	printf("\033[48;5;016m");
}


std::string imprimirAzul(std::string texto) {

	return ("\033[38;5;021m" + texto + "\033[38;5;231m");
}

std::string imprimirVerde(std::string texto) {

	return ("\033[38;5;046m" + texto + "\033[38;5;231m");
}
std::string imprimirCyan(std::string texto) {

	return ("\033[38;5;051m" + texto + "\033[38;5;231m");
}
std::string imprimirRojo(std::string texto) {

	return ("\033[38;5;196m" + texto + "\033[38;5;231m");
}
std::string imprimirMagenta(std::string texto) {

	return ("\033[38;5;201m" + texto + "\033[38;5;231m");
}
std::string imprimirAmarillo(std::string texto) {

	return ("\033[38;5;0226m" + texto + "\033[38;5;231m");
}

std::string imprimirBlanco(std::string texto) {
	
	return ("\033[38;5;231m" + texto);
}
