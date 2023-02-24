#include <iostream>
#include <string>
//#include "../../include/jugador.hpp" incluido en habilidad.hpp
#include "../../include/habilidad.hpp"


Jugador::Jugador() : Personaje() {}
Jugador::Jugador(std::string nombre, int raza, int clase, int subclase,
                 int arma) : Personaje(nombre) {

    setRaza(raza);
    setClase(clase);
    setSubclase(subclase);
    setArma(arma);
	elemento    = obtenerElemento();
	afinidades  = obtenerAfinidades(getRaza(), getClase(), getSubclase());

	generarAtributos(getClase(), getSubclase(), getArma());
	generarHabilidades();
}

Jugador::Raza                 Jugador::getRaza()       { return raza; }
Jugador::Clase                Jugador::getClase()      { return clase; }
Jugador::Subclase             Jugador::getSubclase()   { return subclase; }
Jugador::Arma                 Jugador::getArma()       { return arma; }
std::vector<Jugador::Arma>    Jugador::getAfinidades() { return afinidades; }

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

std::vector<Habilidad>& Jugador::getHabilidades() { return habilidades; }

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

/* Setters */
void Jugador::setRaza(int _raza) {
    raza = (Jugador::Raza)_raza;
}

void Jugador::setClase(int _clase) {
    clase = (Jugador::Clase)_clase;
}

void Jugador::setSubclase(int _subclase) {
    subclase = (Jugador::Subclase)_subclase;
}

void Jugador::setArma(int _arma) {
    arma = (Jugador::Arma)_arma;
}

void Jugador::setAfinidades(std::vector<Arma> _afinidades) {
    afinidades = _afinidades;
}

void Jugador::setHabilidades(std::vector<Habilidad> _habilidades) {
    habilidades = _habilidades;
}

/* Fin setters */

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

std::vector<Jugador::Arma> Jugador::obtenerAfinidades(Jugador::Raza raza,
                                                Jugador::Clase clase,
                                                Jugador::Subclase subclase) {
	std::vector<Arma> afinidades;
	switch (raza) {
		case Raza::HUMANO: afinidades.push_back(Arma::ESPADA);   break;
		case Raza::ENANO:  afinidades.push_back(Arma::MARTILLO); break;
		case Raza::ELFO:   afinidades.push_back(Arma::ARCO);     break;
		case Raza::OGRO:   afinidades.push_back(Arma::HACHA);    break;
        case Raza::TRITON: afinidades.push_back(Arma::LANZA);    break;
        case Raza::BESTIA: afinidades.push_back(Arma::GARRAS);   break;
	}

	switch (clase) {
        case Clase::GUERRERO: afinidades.push_back(Arma::MANDOBLE); break;
		case Clase::MAGO:     afinidades.push_back(Arma::BACULO);   break;
		case Clase::MONJE:    afinidades.push_back(Arma::GARRAS);   break;
		case Clase::CLERIGO:  afinidades.push_back(Arma::BACULO);   break;
		case Clase::LADRON:   afinidades.push_back(Arma::DAGA);     break;
		case Clase::TROVADOR: afinidades.push_back(Arma::ESTOQUE);  break;
	}

	switch (subclase) {
        case Subclase::HERRERO:    afinidades.push_back(Arma::MARTILLO); break;
		case Subclase::ALQUIMISTA: afinidades.push_back(Arma::LANZA);    break;
		case Subclase::GLADIADOR:  afinidades.push_back(Arma::MANDOBLE); break;
		case Subclase::BOTICARIO:  afinidades.push_back(Arma::DAGA);     break;
		case Subclase::DRUIDA:     afinidades.push_back(Arma::ARCO);     break;
		case Subclase::MERCENARIO: afinidades.push_back(Arma::ESPADA);   break;
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

    int mejoraAtaqueFisico = 1;
    int mejoraAtaqueMagico = 0;
	switch (arma) {
        case Arma::ESPADA:   setPrecision(95),  setCritico(15); break;
		case Arma::ESTOQUE:  setPrecision(100), setCritico(10); break;
		case Arma::DAGA:     setPrecision(90),  setCritico(20); break;
		case Arma::MANDOBLE: setPrecision(90),  setCritico(20); break;
		case Arma::BACULO:
            setPrecision(90),  setCritico(20);
            mejoraAtaqueFisico = 0;
            mejoraAtaqueMagico = 3;
            break;
		case Arma::HACHA:    setPrecision(90),  setCritico(20); break;
		case Arma::LANZA:    setPrecision(95),  setCritico(15); break;
		case Arma::ARCO:     setPrecision(100), setCritico(10); break;
		case Arma::MARTILLO: setPrecision(90),  setCritico(20); break;
		case Arma::GARRAS:   setPrecision(95),  setCritico(15); break;
	}

	setVidaMaxima((escogerDados(5) + escogerDados(5)) * 10);
	setVida(getVidaMaxima());
	setAtaqueFisico(escogerDados(dadosAtaqueFisico) + mejoraAtaqueFisico);
	setAtaqueMagico(escogerDados(dadosAtaqueMagico) + mejoraAtaqueMagico);
	setDefensaFisica(escogerDados(dadosDefensaFisica));
	setDefensaMagica(escogerDados(dadosDefensaMagica));
	setVelocidad(escogerDados(dadosVelocidad));
    setEvasion(escogerDados(dadosEvasion));
}


void Jugador::generarHabilidades() {
    switch (getRaza()) {
		case Raza::HUMANO: {
            getHabilidades().emplace_back(
                Habilidad::Usuario::USUARIO_JUGADOR,
                "Magia no elemental",
                "magia no elemental",
                Habilidad::Tipo::MAGIA,
                Personaje::Elemento::NEUTRO
            );
            getHabilidades().emplace_back(
                Habilidad::Usuario::USUARIO_JUGADOR,
                "Golpe contundente",
                "Poderoso ataque fisico",
                Habilidad::Tipo::OFENSIVA,
                Habilidad::Atributo::ATAQUE, 2
            );
            break;
        }
        case Raza::ENANO: {
            getHabilidades().emplace_back(
                Habilidad::Usuario::USUARIO_JUGADOR,
                "Magia de tierra",
                "magia de tierra",
                Habilidad::Tipo::MAGIA,
                Personaje::Elemento::TIERRA
            );
            getHabilidades().emplace_back(
                Habilidad::Usuario::USUARIO_JUGADOR,
                "Fortalecimiento",
                "Aumenta las defensas",
                Habilidad::Tipo::BUFF,
                Habilidad::Atributo::DEFENSAS, 2
            );
            break;
        }
		case Raza::ELFO: {
            getHabilidades().emplace_back(
                Habilidad::Usuario::USUARIO_JUGADOR,
                "Magia de hielo",
                "magia de hielo",
                Habilidad::Tipo::MAGIA,
                Personaje::Elemento::HIELO
            );
            getHabilidades().emplace_back(
                Habilidad::Usuario::USUARIO_JUGADOR,
                "Curacion",
                "Curacion de vida",
                Habilidad::Tipo::CURATIVA, 2
            );
            break;
        }
		case Raza::OGRO: {
            getHabilidades().emplace_back(
                Habilidad::Usuario::USUARIO_JUGADOR,
                "Magia de fuego",
                "magia de fuego",
                Habilidad::Tipo::MAGIA,
                Personaje::Elemento::FUEGO
            );
            getHabilidades().emplace_back(
                Habilidad::Usuario::USUARIO_JUGADOR,
                "Intimidacion",
                "Disminuye el ataque enemigo",
                Habilidad::Tipo::DEBUFF,
                Habilidad::Atributo::ATAQUES, 2
            );
            break;
        }
        case Raza::TRITON: {
            getHabilidades().emplace_back(
                Habilidad::Usuario::USUARIO_JUGADOR,
                "Magia de agua",
                "magia de agua",
                Habilidad::Tipo::MAGIA,
                Personaje::Elemento::AGUA
            );
            getHabilidades().emplace_back(
                Habilidad::Usuario::USUARIO_JUGADOR,
                "Curacion",
                "Curacion de vida",
                Habilidad::Tipo::CURATIVA, 2
            );
            break;
        }
        case Raza::BESTIA: {
            getHabilidades().emplace_back(
                Habilidad::Usuario::USUARIO_JUGADOR,
                "Magia de rayo",
                "magia de rayo",
                Habilidad::Tipo::MAGIA,
                Personaje::Elemento::RAYO
            );
            getHabilidades().emplace_back(
                Habilidad::Usuario::USUARIO_JUGADOR,
                "Grito de guerra",
                "Aumenta el ataque fisico",
                Habilidad::Tipo::BUFF,
                Habilidad::Atributo::ATAQUE, 2);
            break;
        }
	}

	switch (clase) {
        case Clase::GUERRERO: {
            getHabilidades().emplace_back(
                Habilidad::Usuario::USUARIO_JUGADOR,
                "Distraccion",
                "Disminuye las defensas enemigas",
                Habilidad::Tipo::DEBUFF,
                Habilidad::Atributo::DEFENSAS, 2
            );
            getHabilidades().emplace_back(
                Habilidad::Usuario::USUARIO_JUGADOR,
                "Fortalecimiento",
                "Aumenta las defensas",
                Habilidad::Tipo::BUFF,
                Habilidad::Atributo::DEFENSAS, 2
            );
            break;
        }
		case Clase::MAGO: {
            getHabilidades().emplace_back(
                Habilidad::Usuario::USUARIO_JUGADOR,
                "Mentalizacion+",
                "Aumenta mucho el ataque magico",
                Habilidad::Tipo::BUFF,
                Habilidad::Atributo::ATAQUE_MAGICO, 3
            );
            getHabilidades().emplace_back(
                Habilidad::Usuario::USUARIO_JUGADOR,
                "Rafaga de energia",
                "Magia no elemental muy poderosa",
                Habilidad::Tipo::OFENSIVA,
                Habilidad::Atributo::ATAQUE_MAGICO, 3
            );
            break;
        }
		case Clase::MONJE: {
            getHabilidades().emplace_back(
                Habilidad::Usuario::USUARIO_JUGADOR,
                "Meditacion",
                "Aumenta mucho el ataque fisico",
                Habilidad::Tipo::BUFF,
                Habilidad::Atributo::ATAQUE, 3
            );
            getHabilidades().emplace_back(
                Habilidad::Usuario::USUARIO_JUGADOR,
                "Tecnica del dragon",
                "Ataque fisico muy poderoso",
                Habilidad::Tipo::OFENSIVA,
                Habilidad::Atributo::ATAQUE, 3
            );
            break;
        }
		case Clase::CLERIGO: {
            getHabilidades().emplace_back(
                Habilidad::Usuario::USUARIO_JUGADOR,
                "Curacion+",
                "Elevada curacion de vida",
                Habilidad::Tipo::CURATIVA, 3
            );
            getHabilidades().emplace_back(
                Habilidad::Usuario::USUARIO_JUGADOR,
                "Distraccion",
                "Disminuye las defensas enemigas",
                Habilidad::Tipo::DEBUFF,
                Habilidad::Atributo::DEFENSAS, 2
            );
            break;
        }
		case Clase::LADRON: {
            getHabilidades().emplace_back(
                Habilidad::Usuario::USUARIO_JUGADOR,
                "Tacticas evasivas",
                "Aumenta velocidad y evasion",
                Habilidad::Tipo::BUFF,
                Habilidad::Atributo::VELOCIDAD_Y_EVASION, 2
            );
            getHabilidades().emplace_back(
                Habilidad::Usuario::USUARIO_JUGADOR,
                "Afilar arma",
                "Aumenta la precision y el critico",
                Habilidad::Tipo::BUFF,
                Habilidad::Atributo::PRECISION_Y_CRITICO, 2
            );
            break;
        }
		case Clase::TROVADOR: {
            getHabilidades().emplace_back(
                Habilidad::Usuario::USUARIO_JUGADOR,
                "Curacion",
                "Curacion de vida",
                Habilidad::Tipo::CURATIVA, 2
            );
            getHabilidades().emplace_back(
                Habilidad::Usuario::USUARIO_JUGADOR,
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
            getHabilidades().emplace_back(
                Habilidad::Usuario::USUARIO_JUGADOR,
                "Golpe contundente",
                "Poderoso ataque fisico",
                Habilidad::Tipo::OFENSIVA,
                Habilidad::Atributo::ATAQUE, 2
            );
            break;
        }
		case Subclase::ALQUIMISTA: {
            getHabilidades().emplace_back(
                Habilidad::Usuario::USUARIO_JUGADOR,
                "Mentalizacion",
                "Aumenta el ataque magico",
                Habilidad::Tipo::BUFF,
                Habilidad::Atributo::ATAQUE_MAGICO, 2
            );
            break;
        }
		case Subclase::GLADIADOR: {
            getHabilidades().emplace_back(
                Habilidad::Usuario::USUARIO_JUGADOR,
                "Intimidacion",
                "Disminuye el ataque enemigo",
                Habilidad::Tipo::DEBUFF,
                Habilidad::Atributo::ATAQUES, 2
            );
            break;
        }
		case Subclase::BOTICARIO: {
            getHabilidades().emplace_back(
                Habilidad::Usuario::USUARIO_JUGADOR,
                "Curacion+",
                "Elevada curacion de vida",
                Habilidad::Tipo::CURATIVA, 3
            );
            break;
        }
		case Subclase::DRUIDA: {
            getHabilidades().emplace_back(
                Habilidad::Usuario::USUARIO_JUGADOR,
                "Curacion",
                "Curacion de vida",
                Habilidad::Tipo::CURATIVA, 2
            );
            break;
        }
		case Subclase::MERCENARIO: {
            getHabilidades().emplace_back(
                Habilidad::Usuario::USUARIO_JUGADOR,
                "Afilar arma",
                "Aumenta la precision y el critico",
                Habilidad::Tipo::BUFF,
                Habilidad::Atributo::PRECISION_Y_CRITICO, 2
            );
            break;
        }
	}
}

std::string Jugador::atacar(Personaje& p) {
    std::string log = "";
    bool critico = esCritico();
    /* Bonuses */
    float bonuses = 0.0f; // %
    for (int i = 0; i < (int) getAfinidades().size(); i++) {
        if (getArma() == getAfinidades().at(i)) {
            bonuses += 0.05f;
            break;
        }
    }

    if (critico == true) {
        bonuses += 0.5f;
    }

    if (getNivel() > p.getNivel()) {
        bonuses += 0.05f;
    } else if (getNivel() < p.getNivel()) {
        bonuses -= 0.05f;
    }

    /* Variacion */
    float variacion = static_cast<float>(generarAleatorio(80, 120)) / 100.0f;

    /* Formula de dano */
    int dmg = (getAtaqueFisico() * getAtaqueFisico() / (getAtaqueFisico() +
              p.getDefensaFisica())) * 3;
    dmg = static_cast<int>(static_cast<float>(dmg) * (bonuses + variacion));

    /* Realizar el ataque */
    p.aumentarVida(-1 * dmg);

    if (critico == false) {
        log = "Ha realizado " + std::to_string(dmg) + " puntos de dano.";
    } else {
        log = "Golpe critico. " + std::to_string(dmg) + " puntos de dano.";
    }

    return log;
}

std::string Jugador::atacar(Personaje& p, int ataqueFisico) {
    std::string log = "";
    bool critico = esCritico();
    /* Bonuses */
    float bonuses = 0.0f; // %
    for (int i = 0; i < (int) getAfinidades().size(); i++) {
        if (getArma() == getAfinidades().at(i)) {
            bonuses += 0.05f;
            break;
        }
    }

    if (critico == true) {
        bonuses += 0.5f;
    }

    if (getNivel() > p.getNivel()) {
        bonuses += 0.05f;
    } else if (getNivel() < p.getNivel()) {
        bonuses -= 0.05f;
    }

    /* Variacion */
    float variacion = static_cast<float>(generarAleatorio(80, 120)) / 100.0f;

    /* Formula de dano */
    int dmg = (ataqueFisico * ataqueFisico / (ataqueFisico +
              p.getDefensaFisica())) * 3;
    dmg = static_cast<int>(static_cast<float>(dmg) * (bonuses + variacion));

    /* Realizar el ataque */
    p.aumentarVida(-1 * dmg);

    if (critico == false) {
        log = "Ha realizado " + std::to_string(dmg) + " puntos de dano.";
    } else {
        log = "Golpe critico. " + std::to_string(dmg) + " puntos de dano.";
    }

    return log;
}

