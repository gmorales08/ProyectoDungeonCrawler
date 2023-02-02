#include <vector>
#include <algorithm>
#include <ctime>
#include <random>
#include "../../include/utilidadesDeTerminal.hpp"
#include "../../include/personaje.hpp"


Personaje::Personaje(std::string _nombre) {
	nombre = _nombre;
}

/* Getters */
std::string Personaje::getNombre()        { return nombre; }
int         Personaje::getVida()          { return vida; }
int         Personaje::getVidaMaxima()    { return vidaMaxima; }
int         Personaje::getAtaqueFisico()  { return ataqueFisico; }
int         Personaje::getAtaqueMagico()  { return ataqueMagico; }
int         Personaje::getDefensaFisica() { return defensaFisica; }
int         Personaje::getDefensaMagica() { return defensaMagica; }
int         Personaje::getVelocidad()     { return velocidad; }
int         Personaje::getEvasion()       { return evasion;}
int         Personaje::getPrecision()     { return precision; }
int         Personaje::getCritico()       { return critico; }

Elemento Personaje::getElemento()                  { return elemento; }
std::vector<Habilidad> Personaje::getHabilidades() { return habilidades; }

std::string Personaje::getElementoString() {
	std::string elementoString = "";
	switch(getElemento()) {
		case Agua:   elementoString = imprimirAzul("Agua");     break;
		case Fuego:  elementoString = imprimirRojo("Fuego");    break;
		case Hielo:  elementoString = imprimirCyan("Hielo");    break;
		case Tierra: elementoString = imprimirVerde("Tierra");  break;
		case Rayo:   elementoString = imprimirAmarillo("Rayo"); break;
		case Neutro: elementoString = imprimirBlanco("Neutro"); break;
	}

	return elementoString;
}
/* Fin Getters */

/* Setters */
void Personaje::setVida(int _vida) {
    vida = _vida;
}

void Personaje::setVidaMaxima(int _vidaMaxima) {
    vidaMaxima = _vidaMaxima;
}

void Personaje::setAtaqueFisico(int _ataqueFisico) {
    ataqueFisico = _ataqueFisico;
}

void Personaje::setAtaqueMagico(int _ataqueMagico) {
    ataqueMagico = _ataqueMagico;
}

void Personaje::setDefensaFisica(int _defensaFisica) {
    defensaFisica = _defensaFisica;
}

void Personaje::setDefensaMagica(int _defensaMagica) {
    defensaMagica = _defensaMagica;
}

void Personaje::setVelocidad(int _velocidad) {
    velocidad = _velocidad;
}

void Personaje::setEvasion(int _evasion) {
    evasion = _evasion;
}

void Personaje::setPrecision(int _precision) {
    precision = _precision;
}

void Personaje::setCritico(int _critico) {
    critico = _critico;
}
/* Fin setters */

/* Aumentar atributos */
void Personaje::aumentarVida(int _vida) {
    setVida(getVida() + _vida);
}
void Personaje::aumentarVidaMaxima(int _vida) {
    setVidaMaxima(getVidaMaxima() + _vida);
}
void Personaje::aumentarAtaqueFisico(int _ataque) {
    setAtaqueFisico(getAtaqueFisico() + _ataque);
}
void Personaje::aumentarAtaqueMagico(int _ataquem) {
    setAtaqueMagico(getAtaqueMagico() + _ataquem);
}
void Personaje::aumentarDefensaFisica(int _defensa) {
    setDefensaFisica(getDefensaFisica() + _defensa);
}
void Personaje::aumentarDefensaMagica(int _defensam) {
    setDefensaMagica(getDefensaMagica() + _defensam);
}
void Personaje::aumentarVelocidad(int _velocidad) {
    setVelocidad(getVelocidad() + _velocidad);
}
void Personaje::aumentarEvasion(int _evasion) {
    setEvasion(getEvasion() + _evasion);
}
void Personaje::aumentarPrecision(int _precision) {
    setPrecision(getPrecision() + _precision);
}
void Personaje::aumentarCritico(int _critico) {
    setCritico(getCritico() + _critico);
}
/* Fin modificar atributos */

std::string Personaje::generarBarraDeVida() {
	std::string vida = "";

	/* 1. Calcular el % de vida que le queda al personaje */
	int porcentajeVida = (getVida() * 100) / getVidaMaxima();
	/* 2. Imprimimos un "█" por cada 5% de vida */
	int contador = porcentajeVida;
	while (contador > 0) {
		vida += "█";
		contador -= 5;
	}
	/* 3. Imprimos el color correspondiente al % de vida restante */
	if (porcentajeVida > 50) {
        vida = imprimirVerde(vida);
    } else if (porcentajeVida <= 50 && porcentajeVida > 25) {
        vida = imprimirAmarillo(vida);
    } else if (porcentajeVida <= 25) {
        vida = imprimirRojo(vida);
    }

	return vida;
}

int Personaje::tirarDado() {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1,6);

    return dist6(rng);
}

int Personaje::tirarDados(int numeroDeDados) {
    int suma = 0;
    for (int i = 0; i < numeroDeDados; i++) {
        suma += tirarDado();
    }

    return suma;
}

int Personaje::escogerDados(int numeroTiradas) {
    std::vector<int> numeros;

    for (int i = 0; i < numeroTiradas; i++) {
        numeros.push_back(tirarDado());
    }
	std::sort(numeros.begin(), numeros.end());

	return (numeros[numeros.size() - 1] + numeros[numeros.size() - 2] +
           numeros[numeros.size() - 3]);
}

int Personaje::escogerDados(int numeroTiradas, int dadosAEscoger) {
    std::vector<int> numeros;

    for (int i = 0; i < numeroTiradas; i++) {
        numeros.push_back(tirarDado());
    }
    std::sort(numeros.begin(), numeros.end());

    int sumaTotal = 0;
    for (int i = 0; i < dadosAEscoger; i++) {
        sumaTotal += (numeros[numeros.size()] - 1 - i);
    }

    return sumaTotal;
}
