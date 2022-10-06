#include "../../include/jugador.h"


Jugador::Jugador(std::string _nombre, int _raza, int _clase, int _subclase, int _arma) : Personaje(_nombre) {

	raza =     (Raza)_raza;
	clase =    (Clase)_clase;
	subclase = (Subclase)_subclase;
	arma =     (Arma)_arma;
	elemento = obtenerElemento();
	
	afinidades = obtenerAfinidades(raza, clase, subclase);

	generarAtributos(clase, subclase, arma);
	generarHabilidades();
};


Raza        Jugador::getRaza()       { return raza; }
Clase       Jugador::getClase()      { return clase; }
Subclase    Jugador::getSubClase()   { return subclase; }
Arma        Jugador::getArma()       { return arma; }
std::string Jugador::getAfinidades() { return afinidades; }


std::string Jugador::getRazaString() {

	std::string razaString = "";	
	switch (getRaza()) {

		case Humano: razaString = "Humano"; break; 
		case Enano:  razaString = "Enano";  break;
		case Elfo:   razaString = "Elfo";   break;
		case Ogro:   razaString = "Ogro";   break;
		case Triton: razaString = "Triton"; break;
		case Bestia: razaString = "Bestia"; break;
	}

	return razaString;
}

std::string Jugador::getClaseString() {

	std::string claseString = "";
	switch (getClase()) {
		
		case Guerrero: claseString = "Guerrero"; break;
		case Mago:     claseString = "Mago";     break;
		case Monje:    claseString = "Monje";    break;
		case Clerigo:  claseString = "Clerigo";  break;
		case Ladron:   claseString = "Ladron";   break;
		case Trovador: claseString = "Trovador"; break;
	}

	return claseString;
}

std::string Jugador::getSubClaseString() {

	std::string subClaseString = "";
	switch (getSubClase()) {
		
		case Herrero:    subClaseString = "Herrero";    break;
		case Alquimista: subClaseString = "Alquimista"; break;
		case Gladiador:  subClaseString = "Gladiador";  break;
		case Boticario:  subClaseString = "Boticario";  break;
		case Druida:     subClaseString = "Druida";     break;
		case Mercenario: subClaseString = "Mercenario"; break;
	}

	return subClaseString;
}

std::string Jugador::getArmaString() {

	std::string armaString = "";
	switch (getArma()) {

		case Espada:   armaString = "Espada";   break;
		case Estoque:  armaString = "Estoque";  break;
		case Daga:     armaString = "Daga";     break;
		case Mandoble: armaString = "Mandoble"; break;
		case Baculo:   armaString = "Baculo";   break;
		case Hacha:    armaString = "Hacha";    break;
		case Lanza:    armaString = "Lanza";    break;
		case Arco:     armaString = "Arco";     break;
		case Martillo: armaString = "Martillo"; break;
		case Garras:   armaString = "Garras";   break;
	}

	return armaString;
}


Elemento Jugador::obtenerElemento() {

	Elemento elementoPersonaje;
	switch (getRaza()) {

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


void Jugador::generarAtributos(Clase clase, Subclase subclase, Arma arma) {

	int dadosAtaqueFisico = 3, dadosAtaqueMagico = 3, dadosDefensaFisica = 3, dadosDefensaMagica = 3, dadosVelocidad = 3;
	int precision, critico;

	switch (clase) {

		case Guerrero: dadosDefensaFisica += 1; break;
		case Mago:     dadosAtaqueMagico  += 1; break;
		case Monje:    dadosAtaqueFisico  += 1; break;
		case Clerigo:  dadosDefensaMagica += 1; break;
		case Ladron:   dadosVelocidad += 1;     break;
		case Trovador: dadosVelocidad += 1;     break;
	}

	switch (subclase) {

		case Herrero:    dadosDefensaFisica += 1; break;
		case Alquimista: dadosAtaqueMagico  += 1; break;
		case Gladiador:  dadosAtaqueFisico  += 1; break;
		case Boticario:  dadosDefensaMagica += 1; break;
		case Druida:     dadosDefensaMagica += 1; break;
		case Mercenario: dadosVelocidad     += 1; break;
	}

	switch (arma) {
		
		case Espada:   setPrecision(95),  setCritico(15); break;
		case Estoque:  setPrecision(100), setCritico(10); break;
		case Daga:     setPrecision(90),  setCritico(20); break;
		case Mandoble: setPrecision(90),  setCritico(20); break;
		case Baculo:   setPrecision(90),  setCritico(20); break;
		case Hacha:    setPrecision(90),  setCritico(20); break;
		case Lanza:    setPrecision(95),  setCritico(15); break;
		case Arco:     setPrecision(100), setCritico(10); break;
		case Martillo: setPrecision(90),  setCritico(20); break;
		case Garras:   setPrecision(95),  setCritico(15); break;
	}


	setVidaMaxima((escogerDados(3) + escogerDados(3)) * 10);
	setVida(getVidaMaxima());
	setAtaqueFisico(escogerDados(dadosAtaqueFisico));
	setAtaqueMagico(escogerDados(dadosAtaqueMagico));
	setDefensaFisica(escogerDados(dadosDefensaFisica));
	setDefensaMagica(escogerDados(dadosDefensaMagica));
	setVelocidad(escogerDados(dadosVelocidad));
	
}


void Jugador::generarHabilidades() {

	Habilidad habilidad1 ("habilidad1", "descripcion habilidad 1", 5);
	Habilidad habilidad2 ("habilidad2", "descripcion habilidad 2", 5);
	Habilidad habilidad3 ("habilidad3", "descripcion habilidad 3", 5);
	Habilidad habilidad4 ("habilidad4", "descripcion habilidad 4", 5);
	Habilidad habilidad5 ("habilidad5", "descripcion habilidad 5", 5);
	Habilidad habilidad6 ("habilidad6", "descripcion habilidad 6", 5);
	habilidades.push_back(habilidad1);
	habilidades.push_back(habilidad2);
	habilidades.push_back(habilidad3);
	habilidades.push_back(habilidad4);
	habilidades.push_back(habilidad5);
	habilidades.push_back(habilidad6);
}
