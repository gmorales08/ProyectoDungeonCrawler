#include "../../include/jugador.h"


Jugador::Jugador(std::string _nombre, int _raza, int _clase, int _subclase, int _arma) : Personaje(_nombre) {

	raza =     (Raza)_raza;
	clase =    (Clase)_clase;
	subclase = (Subclase)_subclase;
	arma =     (Arma)_arma;
	elemento = obtenerElemento(raza);
	
	afinidades = obtenerAfinidades(raza, clase, subclase);
};


Raza        Jugador::getRaza()       { return raza; }
Clase       Jugador::getClase()      { return clase; }
Subclase    Jugador::getSubClase()   { return subclase; }
Arma        Jugador::getArma()       { return arma; }
std::string Jugador::getAfinidades() { return afinidades; }


Elemento Jugador::obtenerElemento(Raza raza) {

	Elemento elementoPersonaje;
	switch (raza) {

		case Humano: elementoPersonaje = Neutro; break;
		case Enano:  elementoPersonaje = Tierra; break;
		case Elfo:   elementoPersonaje = Hielo;  break;
		case Ogro:   elementoPersonaje = Fuego;  break;
		case Triton: elementoPersonaje = Agua;   break;
		case Bestia: elementoPersonaje = Rayo;   break;
	}

	return elementoPersonaje;
}

std::string Jugador::obtenerAfinidades(Raza raza, Clase clase, Subclase subclase) {

	std::string afinidades = "";

	switch (raza) {

		case Humano: afinidades += "Espada, ";    break;
		case Enano:  afinidades += "Martillos, "; break;
		case Elfo:   afinidades += "Arcos, ";     break;
		case Ogro:   afinidades += "Hachas, ";    break;
		case Triton: afinidades += "Lanzas, ";    break;
		case Bestia: afinidades += "Garras, ";    break;
	}

	switch (clase) {

		case Guerrero: afinidades += "mandobles, "; break;
		case Mago:     afinidades += "baculos, ";   break;
		case Monje:    afinidades += "garras, ";    break;
		case Clerigo:  afinidades += "baculos, ";   break;
		case Ladron:   afinidades += "dagas, ";     break;
		case Trovador: afinidades += "estoques, ";  break;
	}

	switch (subclase) {

		case Herrero:    afinidades += "martillos."; break;
		case Alquimista: afinidades += "lanzas.";    break;
		case Gladiador:  afinidades += "mandobles."; break;
		case Boticario:  afinidades += "dagas.";     break;
		case Druida:     afinidades += "arcos.";     break;
		case Mercenario: afinidades += "espadas.";   break;
	}

	return afinidades;
}
