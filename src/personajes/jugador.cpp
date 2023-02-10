#include "../../include/jugador.hpp"
#include "../../include/habilidad.hpp"
#include <iostream>
#include <string>

Jugador::Jugador() {}
Jugador::Jugador(std::string _nombre, int _raza, int _clase, int _subclase,
                 int _arma) : Personaje(_nombre) {
	raza        = (Jugador::Jugador::Raza)_raza;
	clase       = (Jugador::Clase)_clase;
	subclase    = (Jugador::Subclase)_subclase;
	arma        = (Jugador::Arma)_arma;
	elemento    = obtenerElemento();
	afinidades  = obtenerAfinidades(raza, clase, subclase);

	generarAtributos(clase, subclase, arma);
	generarHabilidades();
}

Jugador::Raza        Jugador::getRaza()       { return raza; }
Jugador::Clase       Jugador::getClase()      { return clase; }
Jugador::Subclase    Jugador::getSubclase()   { return subclase; }
Jugador::Arma        Jugador::getArma()       { return arma; }
std::string          Jugador::getAfinidades() { return afinidades; }

std::string Jugador::getRazaString() {
	std::string razaString = "";
	switch (getRaza()) {
        case Raza::HUMANO: razaString = "Humano"; break;
        case Raza::ENANO:  razaString = "Enano";  break;
        case Raza::ELFO:   razaString = "Elfo";   break;
        case Raza::OGRO:   razaString = "Ogro";   break;
        case Raza::TRITON: razaString = "Triton"; break;
        case Raza::BESTIA: razaString = "Bestia"; break;
	}

	return razaString;
}

std::string Jugador::getClaseString() {
	std::string claseString = "";
	switch (getClase()) {
        case Clase::GUERRERO: claseString = "GUERRERO"; break;
		case Clase::MAGO:     claseString = "MAGO";     break;
		case Clase::MONJE:    claseString = "MONJE";    break;
		case Clase::CLERIGO:  claseString = "CLERIGO";  break;
		case Clase::LADRON:   claseString = "LADRON";   break;
		case Clase::TROVADOR: claseString = "TROVADOR"; break;
	}

	return claseString;
}

std::string Jugador::getSubclaseString() {
	std::string subClaseString = "";
	switch (getSubclase()) {
        case Subclase::HERRERO:    subClaseString = "HERRERO";    break;
		case Subclase::ALQUIMISTA: subClaseString = "ALQUIMISTA"; break;
		case Subclase::GLADIADOR:  subClaseString = "GLADIADOR";  break;
		case Subclase::BOTICARIO:  subClaseString = "BOTICARIO";  break;
		case Subclase::DRUIDA:     subClaseString = "DRUIDA";     break;
		case Subclase::MERCENARIO: subClaseString = "MERCENARIO"; break;
	}

	return subClaseString;
}

std::string Jugador::getArmaString() {
	std::string armaString = "";
	switch (getArma()) {
        case Arma::ESPADA:   armaString = "ESPADA";   break;
		case Arma::ESTOQUE:  armaString = "ESTOQUE";  break;
		case Arma::DAGA:     armaString = "DAGA";     break;
		case Arma::MANDOBLE: armaString = "MANDOBLE"; break;
		case Arma::BACULO:   armaString = "BACULO";   break;
		case Arma::HACHA:    armaString = "HACHA";    break;
		case Arma::LANZA:    armaString = "LANZA";    break;
		case Arma::ARCO:     armaString = "ARCO";     break;
		case Arma::MARTILLO: armaString = "MARTILLO"; break;
		case Arma::GARRAS:   armaString = "GARRAS";   break;
	}

	return armaString;
}

std::vector<Habilidad> Jugador::getHabilidades() { return habilidades; }

void Jugador::jugadorLog() {
    std::string log = "LOG DEL JUGADOR\n";
    log += "Nombre vida vidaMax ataq ataqm def defm vel eva pre cri";
    log += "Nombre: " + getNombre() + "\n" +
           "Vida: " + std::to_string(getVida()) + "/" +
                      std::to_string(getVidaMaxima()) + "\n" +
           "Ataque: " + std::to_string(getAtaqueFisico()) + "\n" +
           "Ataque M.: " + std::to_string(getAtaqueMagico()) + "\n" +
           "Defensa: " + std::to_string(getDefensaFisica()) + "\n" +
           "Defensa M.: " + std::to_string(getDefensaMagica()) + "\n" +
           "Velocidad: " + std::to_string(getVelocidad()) + "\n" +
           "Evasion: " + std::to_string(getEvasion()) + "\n" +
           "Precision: " + std::to_string(getPrecision()) + "\n" +
           "Critico: " + std::to_string(getCritico()) + "\n\n" +
           "Raza: " + getRazaString() + "\n" +
           "Clase: " + getClaseString() + "\n" +
           "Subclase: " + getSubclaseString() + "\n" +
           "Arma: " + getArmaString() + "\n";

    std::cout << log << std::endl;
}

Personaje::Elemento Jugador::obtenerElemento() {
	Elemento elementoPersonaje;
	switch (getRaza()) {
        case Raza::HUMANO:
            elementoPersonaje = Personaje::Elemento::NEUTRO;
            break;
		case Raza::ENANO:
            elementoPersonaje = Personaje::Elemento::TIERRA;
            break;
		case Raza::ELFO:
            elementoPersonaje = Personaje::Elemento::HIELO;
            break;
		case Raza::OGRO:
            elementoPersonaje = Personaje::Elemento::FUEGO;
            break;
		case Raza::TRITON:
            elementoPersonaje = Personaje::Elemento::AGUA;
            break;
		case Raza::BESTIA:
            elementoPersonaje = Personaje::Elemento::RAYO;
            break;
	}

	return elementoPersonaje;
}

std::string Jugador::obtenerAfinidades(Jugador::Raza raza, Jugador::Clase clase,
                                       Jugador::Subclase subclase) {
	std::string afinidades = "";
	switch (raza) {
		case Raza::HUMANO: afinidades += "ESPADA, ";    break;
		case Raza::ENANO:  afinidades += "MARTILLOs, "; break;
		case Raza::ELFO:   afinidades += "ARCOs, ";     break;
		case Raza::OGRO:   afinidades += "HACHAs, ";    break;
        case Raza::TRITON: afinidades += "LANZAs, ";    break;
        case Raza::BESTIA: afinidades += "GARRAS, ";    break;
	}

	switch (clase) {
        case Clase::GUERRERO: afinidades += "mandobles, "; break;
		case Clase::MAGO:     afinidades += "baculos, ";   break;
		case Clase::MONJE:    afinidades += "garras, ";    break;
		case Clase::CLERIGO:  afinidades += "baculos, ";   break;
		case Clase::LADRON:   afinidades += "dagas, ";     break;
		case Clase::TROVADOR: afinidades += "estoques, ";  break;
	}

	switch (subclase) {
        case Subclase::HERRERO:    afinidades += "martillos."; break;
		case Subclase::ALQUIMISTA: afinidades += "lanzas.";    break;
		case Subclase::GLADIADOR:  afinidades += "mandobles."; break;
		case Subclase::BOTICARIO:  afinidades += "dagas.";     break;
		case Subclase::DRUIDA:     afinidades += "arcos.";     break;
		case Subclase::MERCENARIO: afinidades += "espadas.";   break;
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
	int dadosEvasion       = 3;

	switch (clase) {
        case Clase::GUERRERO: dadosDefensaFisica += 1; break;
		case Clase::MAGO:     dadosAtaqueMagico  += 1; break;
		case Clase::MONJE:    dadosAtaqueFisico  += 1; break;
		case Clase::CLERIGO:  dadosDefensaMagica += 1; break;
		case Clase::LADRON:   dadosVelocidad     += 1; break;
		case Clase::TROVADOR: dadosVelocidad     += 1; break;
	}

	switch (subclase) {
        case Subclase::HERRERO:    dadosDefensaFisica += 1; break;
		case Subclase::ALQUIMISTA: dadosAtaqueMagico  += 1; break;
		case Subclase::GLADIADOR:  dadosAtaqueFisico  += 1; break;
		case Subclase::BOTICARIO:  dadosDefensaMagica += 1; break;
		case Subclase::DRUIDA:     dadosDefensaMagica += 1; break;
		case Subclase::MERCENARIO: dadosVelocidad     += 1; break;
	}

	switch (arma) {
        case Arma::ESPADA:   setPrecision(95),  setCritico(15); break;
		case Arma::ESTOQUE:  setPrecision(100), setCritico(10); break;
		case Arma::DAGA:     setPrecision(90),  setCritico(20); break;
		case Arma::MANDOBLE: setPrecision(90),  setCritico(20); break;
		case Arma::BACULO:   setPrecision(90),  setCritico(20); break;
		case Arma::HACHA:    setPrecision(90),  setCritico(20); break;
		case Arma::LANZA:    setPrecision(95),  setCritico(15); break;
		case Arma::ARCO:     setPrecision(100), setCritico(10); break;
		case Arma::MARTILLO: setPrecision(90),  setCritico(20); break;
		case Arma::GARRAS:   setPrecision(95),  setCritico(15); break;
	}

	setVidaMaxima((escogerDados(5) + escogerDados(5)) * 10);
	setVida(getVidaMaxima());
	setAtaqueFisico(escogerDados(dadosAtaqueFisico));
	setAtaqueMagico(escogerDados(dadosAtaqueMagico));
	setDefensaFisica(escogerDados(dadosDefensaFisica));
	setDefensaMagica(escogerDados(dadosDefensaMagica));
	setVelocidad(escogerDados(dadosVelocidad));
    setEvasion(escogerDados(dadosEvasion));
}


void Jugador::generarHabilidades() {
    switch (getRaza()) {
		case Raza::HUMANO: {
            habilidades.emplace_back(
                "Magia no elemental",
                "",
                Habilidad::Tipo::MAGIA,
                Personaje::Elemento::NEUTRO
            );
            habilidades.emplace_back(
                "Golpe contundente",
                "Poderoso ataque fisico",
                Habilidad::Tipo::OFENSIVA, 2
            );
            break;
        }
        case Raza::ENANO: {
            habilidades.emplace_back(
                "Magia de tierra",
                "",
                Habilidad::Tipo::MAGIA,
                Personaje::Elemento::TIERRA
            );
            habilidades.emplace_back(
                "Fortalecimiento",
                "Aumenta las defensas",
                Habilidad::Tipo::BUFF,
                Habilidad::Atributo::DEFENSAS, 2
            );
            break;
        }
		case Raza::ELFO: {
            habilidades.emplace_back(
                "Magia de hielo",
                "",
                Habilidad::Tipo::MAGIA,
                Personaje::Elemento::HIELO
            );
            habilidades.emplace_back(
                "Curacion",
                "Curacion de vida",
                Habilidad::Tipo::CURATIVA, 2
            );
            break;
        }
		case Raza::OGRO: {
            habilidades.emplace_back(
                "Magia de fuego",
                "",
                Habilidad::Tipo::MAGIA,
                Personaje::Elemento::FUEGO
            );
            habilidades.emplace_back(
                "Intimidacion",
                "Disminuye el ataque enemigo",
                Habilidad::Tipo::DEBUFF,
                Habilidad::Atributo::ATAQUES, 2
            );
            break;
        }
        case Raza::TRITON: {
            habilidades.emplace_back(
                "Magia de agua",
                "",
                Habilidad::Tipo::MAGIA,
                Personaje::Elemento::AGUA
            );
            habilidades.emplace_back(
                "Curacion",
                "Curacion de vida",
                Habilidad::Tipo::CURATIVA, 2
            );
            break;
        }
        case Raza::BESTIA: {
            habilidades.emplace_back(
                "Magia de rayo",
                "",
                Habilidad::Tipo::MAGIA,
                Personaje::Elemento::RAYO
            );
            habilidades.emplace_back(
                "Grito de guerra",
                "Aumenta el ataque fisico",
                Habilidad::Tipo::BUFF,
                Habilidad::Atributo::ATAQUE, 2);
            break;
        }
	}

	switch (clase) {
        case Clase::GUERRERO: {
            habilidades.emplace_back(
                "Distraccion",
                "Disminuye las defensas enemigas",
                Habilidad::Tipo::DEBUFF,
                Habilidad::Atributo::DEFENSAS, 2
            );
            habilidades.emplace_back(
                "Fortalecimiento",
                "Aumenta las defensas",
                Habilidad::Tipo::BUFF,
                Habilidad::Atributo::DEFENSAS, 2
            );
            break;
        }
		case Clase::MAGO: {
            habilidades.emplace_back(
                "Mentalizacion+",
                "Aumenta mucho el ataque magico",
                Habilidad::Tipo::BUFF,
                Habilidad::Atributo::ATAQUE_MAGICO, 3
            );
            habilidades.emplace_back(
                "Rafaga de energia",
                "Magia no elemental muy poderosa",
                Habilidad::Tipo::OFENSIVA,
                Habilidad::Atributo::ATAQUE_MAGICO, 3
            );
            break;
        }
		case Clase::MONJE: {
            habilidades.emplace_back(
                "Meditacion",
                "Aumenta mucho el ataque fisico",
                Habilidad::Tipo::BUFF,
                Habilidad::Atributo::ATAQUE, 3
            );
            habilidades.emplace_back(
                "Tecnica del dragon",
                "Ataque fisico muy poderoso",
                Habilidad::Tipo::OFENSIVA,
                Habilidad::Atributo::ATAQUE, 3
            );
            break;
        }
		case Clase::CLERIGO: {
            habilidades.emplace_back(
                "Curacion+",
                "Elevada curacion de vida",
                Habilidad::Tipo::CURATIVA, 3
            );
            habilidades.emplace_back(
                "Distraccion",
                "Disminuye las defensas enemigas",
                Habilidad::Tipo::DEBUFF,
                Habilidad::Atributo::DEFENSAS, 2
            );
            break;
        }
		case Clase::LADRON: {
            habilidades.emplace_back(
                "Tacticas evasivas",
                "Aumenta velocidad y evasion",
                Habilidad::Tipo::BUFF,
                Habilidad::Atributo::VELOCIDAD_Y_EVASION, 2
            );
            habilidades.emplace_back(
                "Afilar arma",
                "Aumenta la precision y el critico",
                Habilidad::Tipo::BUFF,
                Habilidad::Atributo::PRECISION_Y_CRITICO, 2
            );
            break;
        }
		case Clase::TROVADOR: {
            habilidades.emplace_back(
                "Curacion",
                "Curacion de vida",
                Habilidad::Tipo::CURATIVA, 2
            );
            habilidades.emplace_back(
                "Tacticas evasivas",
                "Aumenta velocidad y evasion",
                Habilidad::Tipo::BUFF,
                Habilidad::Atributo::VELOCIDAD_Y_EVASION, 2
            );
            break;
        }
	}

	switch (subclase) {
        case Subclase::HERRERO: {
            habilidades.emplace_back(
                "Golpe contundente",
                "Poderoso ataque fisico",
                Habilidad::Tipo::OFENSIVA,
                Habilidad::Atributo::ATAQUE, 2
            );
            break;
        }
		case Subclase::ALQUIMISTA: {
            habilidades.emplace_back(
                "Mentalizacion",
                "Aumenta el ataque magico",
                Habilidad::Tipo::BUFF,
                Habilidad::Atributo::ATAQUE_MAGICO, 2
            );
            break;
        }
		case Subclase::GLADIADOR: {
            habilidades.emplace_back(
                "Intimidacion",
                "Disminuye el ataque enemigo",
                Habilidad::Tipo::DEBUFF,
                Habilidad::Atributo::ATAQUES, 2
            );
            break;
        }
		case Subclase::BOTICARIO: {
            habilidades.emplace_back(
                "Curacion+",
                "Elevada curacion de vida",
                Habilidad::Tipo::CURATIVA, 3
            );
            break;
        }
		case Subclase::DRUIDA: {
            habilidades.emplace_back(
                "Curacion",
                "Curacion de vida",
                Habilidad::Tipo::CURATIVA, 2
            );
            break;
        }
		case Subclase::MERCENARIO: {
            habilidades.emplace_back(
                "Afilar arma",
                "Aumenta la precision y el critico",
                Habilidad::Tipo::BUFF,
                Habilidad::Atributo::PRECISION_Y_CRITICO, 2
            );
            break;
        }
	}
}
