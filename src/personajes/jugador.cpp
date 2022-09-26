#include "../../include/jugador.h"


Jugador::Jugador(std::string _nombre, int _raza, int _clase, int _subclase, int _arma) : Personaje(_nombre) {

	raza =     (Raza)_raza;
	clase =    (Clase)_clase;
	subclase = (Subclase)_subclase;
	arma =     (Arma)_arma;
	elemento = obtenerElemento(raza);
};


Elemento Jugador::obtenerElemento(Raza raza) {

	Elemento elementoPersonaje;
	switch (raza) {

		case Humano:     elementoPersonaje = Neutro; break;
		case Enano:      elementoPersonaje = Tierra; break;
		case Elfo:       elementoPersonaje = Hielo;  break;
		case Ogro:       elementoPersonaje = Fuego;  break;
		case Triton:     elementoPersonaje = Agua;   break;
		case Licantropo: elementoPersonaje = Rayo;   break;
	}

	return elementoPersonaje;
}

