#include <chrono>
#include <iostream>
#include "../include/utilidadesDeTerminal.hpp"


void limpiarPantalla() {
    std::cout << "\033[H\033[J" << std::endl; // Limpia la pantalla
    std::cout << "\033[97m"     << std::endl; // Letras blancas
    std::cout << "\033[40m"     << std::endl; // Fondo negro
}

void pausar(float milisegundos) {
    std::this_thread::sleep_for(std::chrono::milliseconds(
                                    (long) milisegundos));
}

std::string imprimirAzul(std::string texto) {
    return ("\033[94m" + texto + "\033[97m");
}

std::string imprimirVerde(std::string texto) {
    return ("\033[92m" + texto + "\033[97m");
}

std::string imprimirCyan(std::string texto) {
    return ("\033[96m" + texto + "\033[97m");
}

std::string imprimirRojo(std::string texto) {
    return ("\033[91m" + texto + "\033[97m");
}

std::string imprimirMagenta(std::string texto) {
    return ("\033[95m" + texto + "\033[97m");
}

std::string imprimirAmarillo(std::string texto) {
    return ("\033[93m" + texto + "\033[97m");
}

std::string imprimirBlanco(std::string texto) {
    return ("\033[97m" + texto + "\033[97m");
}





