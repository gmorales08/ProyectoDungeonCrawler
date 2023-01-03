#include "../../include/jugador.hpp"


Jugador::Jugador(std::string _nombre, int _raza, int _clase, int _subclase,
                 int _arma) : Personaje(_nombre) {
	raza =       (Jugador::Jugador::Raza)_raza;
	clase =      (Jugador::Clase)_clase;
	subclase =   (Jugador::Subclase)_subclase;
	arma =       (Jugador::Arma)_arma;
	elemento =   obtenerElemento();
	afinidades = obtenerAfinidades(raza, clase, subclase);

	generarAtributos(clase, subclase, arma);
	generarHabilidades();
};

Jugador::Raza        Jugador::getRaza()       { return raza; }
Jugador::Clase       Jugador::getClase()      { return clase; }
Jugador::Subclase    Jugador::getSubclase()   { return subclase; }
Jugador::Arma        Jugador::getArma()       { return arma; }
std::string          Jugador::getAfinidades() { return afinidades; }

std::string Jugador::getRazaString() {
	std::string razaString = "";
	switch (getRaza()) {
		case HUMANO: razaString = "Humano"; break;
		case ENANO:  razaString = "Enano";  break;
		case ELFO:   razaString = "Elfo";   break;
		case OGRO:   razaString = "Ogro";   break;
		case TRITON: razaString = "Triton"; break;
		case BESTIA: razaString = "Bestia"; break;
	}

	return razaString;
}

std::string Jugador::getClaseString() {
	std::string claseString = "";
	switch (getClase()) {
		case GUERRERO: claseString = "GUERRERO"; break;
		case MAGO:     claseString = "MAGO";     break;
		case MONJE:    claseString = "MONJE";    break;
		case CLERIGO:  claseString = "CLERIGO";  break;
		case LADRON:   claseString = "LADRON";   break;
		case TROVADOR: claseString = "TROVADOR"; break;
	}

	return claseString;
}

std::string Jugador::getSubclaseString() {
	std::string subClaseString = "";
	switch (getSubclase()) {
		case HERRERO:    subClaseString = "HERRERO";    break;
		case ALQUIMISTA: subClaseString = "ALQUIMISTA"; break;
		case GLADIADOR:  subClaseString = "GLADIADOR";  break;
		case BOTICARIO:  subClaseString = "BOTICARIO";  break;
		case DRUIDA:     subClaseString = "DRUIDA";     break;
		case MERCENARIO: subClaseString = "MERCENARIO"; break;
	}

	return subClaseString;
}

std::string Jugador::getArmaString() {
	std::string armaString = "";
	switch (getArma()) {
		case ESPADA:   armaString = "ESPADA";   break;
		case ESTOQUE:  armaString = "ESTOQUE";  break;
		case DAGA:     armaString = "DAGA";     break;
		case MANDOBLE: armaString = "MANDOBLE"; break;
		case BACULO:   armaString = "BACULO";   break;
		case HACHA:    armaString = "HACHA";    break;
		case LANZA:    armaString = "LANZA";    break;
		case ARCO:     armaString = "ARCO";     break;
		case MARTILLO: armaString = "MARTILLO"; break;
		case GARRAS:   armaString = "GARRAS";   break;
	}

	return armaString;
}

Elemento Jugador::obtenerElemento() {
	Elemento elementoPersonaje;
	switch (getRaza()) {
		case HUMANO: elementoPersonaje = Neutro; break;
		case ENANO:  elementoPersonaje = Tierra; break;
		case ELFO:   elementoPersonaje = Hielo;  break;
		case OGRO:   elementoPersonaje = Fuego;  break;
		case TRITON: elementoPersonaje = Agua;   break;
		case BESTIA: elementoPersonaje = Rayo;   break;
	}

	return elementoPersonaje;
}

std::string Jugador::obtenerAfinidades(Jugador::Raza raza, Jugador::Clase clase,
                                       Jugador::Subclase subclase) {
	std::string afinidades = "";
	switch (raza) {
		case HUMANO: afinidades += "ESPADA, ";    break;
		case ENANO:  afinidades += "MARTILLOs, "; break;
		case ELFO:   afinidades += "ARCOs, ";     break;
		case OGRO:   afinidades += "HACHAs, ";    break;
        case TRITON: afinidades += "LANZAs, ";    break;
        case BESTIA: afinidades += "GARRAS, ";    break;
	}

	switch (clase) {
		case GUERRERO: afinidades += "mandobles, "; break;
		case MAGO:     afinidades += "baculos, ";   break;
		case MONJE:    afinidades += "garras, ";    break;
		case CLERIGO:  afinidades += "baculos, ";   break;
		case LADRON:   afinidades += "dagas, ";     break;
		case TROVADOR: afinidades += "estoques, ";  break;
	}

	switch (subclase) {
		case HERRERO:    afinidades += "martillos."; break;
		case ALQUIMISTA: afinidades += "lanzas.";    break;
		case GLADIADOR:  afinidades += "mandobles."; break;
		case BOTICARIO:  afinidades += "dagas.";     break;
		case DRUIDA:     afinidades += "arcos.";     break;
		case MERCENARIO: afinidades += "espadas.";   break;
	}

	return afinidades;
}

void Jugador::generarAtributos(Jugador::Clase clase, Jugador::Subclase subclase,
                               Jugador::Arma arma) {
	int dadosAtaqueFisico  = 3;
    int dadosAtaqueMagico  = 3;
    int dadosDefensaFisica = 3;
    int dadosDefensaMagica = 3;
    int dadosVelocidad     = 3;
	int precision;
    int critico;

	switch (clase) {
		case GUERRERO: dadosDefensaFisica += 1; break;
		case MAGO:     dadosAtaqueMagico  += 1; break;
		case MONJE:    dadosAtaqueFisico  += 1; break;
		case CLERIGO:  dadosDefensaMagica += 1; break;
		case LADRON:   dadosVelocidad += 1;     break;
		case TROVADOR: dadosVelocidad += 1;     break;
	}

	switch (subclase) {
		case HERRERO:    dadosDefensaFisica += 1; break;
		case ALQUIMISTA: dadosAtaqueMagico  += 1; break;
		case GLADIADOR:  dadosAtaqueFisico  += 1; break;
		case BOTICARIO:  dadosDefensaMagica += 1; break;
		case DRUIDA:     dadosDefensaMagica += 1; break;
		case MERCENARIO: dadosVelocidad     += 1; break;
	}

	switch (arma) {
		case ESPADA:   setPrecision(95),  setCritico(15); break;
		case ESTOQUE:  setPrecision(100), setCritico(10); break;
		case DAGA:     setPrecision(90),  setCritico(20); break;
		case MANDOBLE: setPrecision(90),  setCritico(20); break;
		case BACULO:   setPrecision(90),  setCritico(20); break;
		case HACHA:    setPrecision(90),  setCritico(20); break;
		case LANZA:    setPrecision(95),  setCritico(15); break;
		case ARCO:     setPrecision(100), setCritico(10); break;
		case MARTILLO: setPrecision(90),  setCritico(20); break;
		case GARRAS:   setPrecision(95),  setCritico(15); break;
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
