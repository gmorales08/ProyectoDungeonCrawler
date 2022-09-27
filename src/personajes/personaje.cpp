#include "../../include/personaje.h"
#include <vector>
#include <algorithm>
#include <ctime>

Personaje::Personaje(std::string _nombre) {
	
	nombre = _nombre;
}

// Getters
std::string Personaje::getNombre()        { return nombre; }
int         Personaje::getVida()          { return vida; }
int         Personaje::getAtaqueFisico()  { return ataqueFisico; }
int         Personaje::getAtaqueMagico()  { return ataqueMagico; }
int         Personaje::getDefensaFisica() { return defensaFisica; }
int         Personaje::getDefensaMagica() { return defensaMagica; }
int         Personaje::getVelocidad()     { return velocidad; }
int         Personaje::getPrecision()     { return precision; }
int         Personaje::getCritico()       { return critico; }

// Setters
void Personaje::setVida(int _vida)                   { vida = _vida; }
void Personaje::setAtaqueFisico(int _ataqueFisico)   { ataqueFisico = _ataqueFisico; }
void Personaje::setAtaqueMagico(int _ataqueMagico)   { ataqueMagico = _ataqueMagico; }
void Personaje::setDefensaFisica(int _defensaFisica) { defensaFisica = _defensaFisica; }
void Personaje::setDefensaMagica(int _defensaMagica) { defensaMagica = _defensaMagica; }
void Personaje::setVelocidad(int _velocidad)         { velocidad = _velocidad; }
void Personaje::setPrecision(int _precision)         { precision = _precision; }
void Personaje::setCritico(int _critico)             { critico = _critico; }


int Personaje::tirarDado() {
	
	return rand() % 6 + 1;
}

int Personaje::escogerDados(int numeroTiradas) {

	std::vector<int> numeros;

	for (int i = 0; i < numeroTiradas; i++) {
		
		numeros.push_back(tirarDado());
	}

	std::sort(numeros.begin(), numeros.end());

	return numeros[numeros.size() - 1] + numeros[numeros.size() - 2] + numeros[numeros.size() -3];
}
