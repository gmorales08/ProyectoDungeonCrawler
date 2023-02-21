#include "../../include/habilidad.hpp"
#include <string>

Habilidad::Habilidad(std::string nombre, std::string descripcion, Tipo tipo,
                     int valor) {
	setNombre(nombre);
	setDescripcion(descripcion);
    setTipo(tipo);
    setValor(valor);
    setUsosTotales(3);
	setUsosRestantes(usosTotales);
}

Habilidad::Habilidad(std::string nombre, std::string descripcion, Tipo tipo,
                     Atributo atributo, int valor) {
	setNombre(nombre);
	setDescripcion(descripcion);
    setTipo(tipo);
    setAtributo(atributo);
    setValor(valor);
    setUsosTotales(3);
	setUsosRestantes(usosTotales);
}

Habilidad::Habilidad(std::string nombre, std::string descripcion, Tipo tipo,
                     Personaje::Elemento elemento) {
    setNombre(nombre);
	setDescripcion(descripcion);
    setTipo(tipo);
    setElemento(elemento);
    setValor(valor);
    setUsosTotales(3);
	setUsosRestantes(usosTotales);
}

Habilidad::Habilidad(Tipo tipo, int valor) {
    setNombre("");
    setDescripcion("");
    setTipo(tipo);
    setValor(valor);
    setUsosTotales(3);
    setUsosRestantes(3);
}

Habilidad::Habilidad(Tipo tipo, Atributo atributo, int valor) {
    setNombre("");
    setDescripcion("");
    setTipo(tipo);
    setAtributo(atributo);
    setValor(valor);
    setUsosTotales(3);
    setUsosRestantes(3);
}

Habilidad::Habilidad(Tipo tipo, Personaje::Elemento elemento) {
    setNombre("");
    setDescripcion("");
    setTipo(tipo);
    setElemento(elemento);
    setUsosTotales(3);
    setUsosRestantes(3);
}

/* Getters */
std::string         Habilidad::getNombre()         { return nombre; }
std::string         Habilidad::getDescripcion()    { return descripcion; }
Habilidad::Tipo     Habilidad::getTipo()           { return tipo; }
Habilidad::Atributo Habilidad::getAtributo()       { return atributo; }
Personaje::Elemento Habilidad::getElemento()       { return elemento; }
int                 Habilidad::getValor()          { return valor; }
Personaje           Habilidad::getUsuario()        { return usuario; }
Personaje           Habilidad::getObjetivo()       { return objetivo; }
int                 Habilidad::getUsosRestantes()  { return usosRestantes; }
int                 Habilidad::getUsosTotales()    { return usosTotales; }

/* Setters */
void Habilidad::setNombre(std::string _nombre) {
    nombre = _nombre;
}

void Habilidad::setDescripcion(std::string _descripcion) {
    descripcion = _descripcion;
}

void Habilidad::setTipo(Tipo _tipo) {
    tipo = _tipo;
}

void Habilidad::setAtributo(Atributo _atributo) {
    atributo = _atributo;
}

void Habilidad::setElemento(Personaje::Elemento _elemento) {
    elemento = _elemento;
}

void Habilidad::setValor(int _valor) {
    valor = _valor;
}

void Habilidad::setUsuario(Personaje& _usuario) {
    usuario = _usuario;
}

void Habilidad::setObjetivo(Personaje& _objetivo) {
    objetivo = _objetivo;
}

void Habilidad::setUsosRestantes(int _usosRestantes) {
    if (_usosRestantes > getUsosTotales()) {
        usosRestantes = usosTotales;
    } else {
        usosRestantes = _usosRestantes;
    }
}

void Habilidad::setUsosTotales(int _usosTotales) {
    usosTotales = _usosTotales;
}

int Habilidad::calcularValor(int valor) {
    int valorFinal = 0;
    if (valor == 2) {
        valorFinal = Personaje::escogerDados(2, 1);
    } else if (valor == 3) {
        valorFinal = Personaje::escogerDados(3, 2);
    }

    return valorFinal;
}


std::string Habilidad::usar() {
    std::string log = "";
    if (getTipo() == Tipo::OFENSIVA) {
        if (getAtributo() == Atributo::ATAQUE) {
            log = getUsuario().atacar(getObjetivo(),
                                      calcularValor(getValor()));
        } else if (getAtributo() == Atributo::ATAQUE_MAGICO) {
            log = getUsuario().usarMagia(getObjetivo(),
                                         calcularValor(getValor()));
        }
    } else if (getTipo() == Tipo::BUFF) {
        if (getAtributo() == Atributo::ATAQUE) {
            getObjetivo().aumentarAtaqueFisico(getValor());
            log = "Su ataque aumenta " + std::to_string(getValor()) +
                  " puntos.";
        } else if (getAtributo() == Atributo::ATAQUE_MAGICO) {
            getObjetivo().aumentarAtaqueMagico(getValor());
            log = "Su ataque magico aumenta " + std::to_string(getValor()) +
                  " puntos.";
        } else if (getAtributo() == Atributo::DEFENSAS) {
            getObjetivo().aumentarDefensaFisica(getValor());
            getObjetivo().aumentarDefensaMagica(getValor());
            log = "Sus defensas aumentan " + std::to_string(getValor()) +
                  " puntos.";
        } else if (getAtributo() == Atributo::VELOCIDAD_Y_EVASION) {
            getObjetivo().aumentarVelocidad(getValor());
            getObjetivo().aumentarEvasion(getValor());
            log = "Su vel. y eva. aumentan " + std::to_string(getValor()) +
                  " puntos.";
        } else if (getAtributo() == Atributo::PRECISION_Y_CRITICO) {
            getObjetivo().aumentarPrecision(getValor());
            getObjetivo().aumentarCritico(getValor());
            log = "Su pre. y cri. aumentan " + std::to_string(getValor()) +
                  " puntos.";
        }
    } else if (getTipo() == Tipo::DEBUFF) {
        if (getAtributo() == Atributo::ATAQUES) {
            getObjetivo().aumentarAtaqueFisico((-1) * getValor());
            getObjetivo().aumentarAtaqueMagico((-1) * getValor());
            log = "Los atqs. del rival bajan " + std::to_string(getValor()) +
                  " ptos.";
        } else if (getAtributo() == Atributo::DEFENSAS) {
            getObjetivo().aumentarDefensaFisica((-1) * getValor());
            getObjetivo().aumentarDefensaMagica((-1) * getValor());
            log = "Las defs. del rival bajan " + std::to_string(getValor()) +
                  " ptos.";
        }
    } else if (getTipo() == Tipo::CURATIVA) {
        getObjetivo().aumentarVida(getValor());
        log = "Ha recuperado " + std::to_string(getValor()) + " puntos de vida.";
    } else if (getTipo() == Tipo::MAGIA) {
        log = getUsuario().usarMagia(getObjetivo());
    }
    setUsosRestantes(getUsosRestantes() - 1);

    return log;
}
