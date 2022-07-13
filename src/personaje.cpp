#include "../include/personaje.h"


Personaje::Personaje(std::string _nombre, int _raza, int _clase, int _subclase) {
	
	nombre = _nombre;
	vida = 0;
	ataqueFisico = 0;
	ataqueMagico = 0;
	defensaFisica = 0;
	defensaMagica = 0;
	velocidad = 0;
	precision = 0;
	critico = 0;
	raza = (Raza)_raza; 
	clase = (Clase)_clase;
	subclase = (Subclase)_subclase;
	elemento = Neutro;
}
