#include "../../include/habilidad.hpp"
#include <string>

Habilidad::Habilidad(std::string nombre, std::string descripcion, Tipo tipo,
                     int valor) {
	setNombre(nombre);
	setDescripcion(descripcion);
    setTipo(tipo);
    setValor(valor);
    //setObjetivo(objetivo);
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
    //setObjetivo(objetivo);
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
    //setObjetivo(objetivo);
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
std::string         Habilidad::getNombre()        { return nombre; }
std::string         Habilidad::getDescripcion()   { return descripcion; }
Habilidad::Tipo     Habilidad::getTipo()          { return tipo; }
Habilidad::Atributo Habilidad::getAtributo()      { return atributo; }
Personaje::Elemento Habilidad::getElemento()      { return elemento; }
int                 Habilidad::getValor()         { return valor; }
Personaje           Habilidad::getObjetivo()      { return objetivo; }
int                 Habilidad::getUsosRestantes() { return usosRestantes; }
int                 Habilidad::getUsosTotales()   { return usosTotales; }

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


std::string Habilidad::usar() {
    std::string log = "";

    if (getTipo() == Tipo::OFENSIVA) {
        getObjetivo().aumentarVida((-1) * getValor());
        log = getObjetivo().getNombre() + " ha perdido " +
                std::to_string(getValor()) + " puntos de vida.";
    } else if (getTipo() == Tipo::BUFF) {
        if (getAtributo() == Atributo::ATAQUE) {
            getObjetivo().aumentarAtaqueFisico(getValor());
            log = "El ataque de " + getObjetivo().getNombre() +
                  " ha aumentado " + std::to_string(getValor()) + " puntos.";
        } else if (getAtributo() == Atributo::ATAQUE_MAGICO) {
            getObjetivo().aumentarAtaqueMagico(getValor());
            log = "El ataque magico de " + getObjetivo().getNombre() +
                  " ha aumentado " + std::to_string(getValor()) + " puntos.";
        } else if (getAtributo() == Atributo::DEFENSAS) {
            getObjetivo().aumentarDefensaFisica(getValor());
            getObjetivo().aumentarDefensaMagica(getValor());
            log = "La defensa fisica y magica de " + getObjetivo().getNombre() +
                  " ha aumentado " + std::to_string(getValor()) + " puntos.";
        } else if (getAtributo() == Atributo::VELOCIDAD_Y_EVASION) {
            getObjetivo().aumentarVelocidad(getValor());
            getObjetivo().aumentarEvasion(getValor());
            log = "La velocidad y evasion de " + getObjetivo().getNombre() +
                  " han aumentado " + std::to_string(getValor()) + " puntos.";
        } else if (getAtributo() == Atributo::PRECISION_Y_CRITICO) {
            getObjetivo().aumentarPrecision(getValor());
            getObjetivo().aumentarCritico(getValor());
            log = "La precision y posibilidad de critico de " +
                getObjetivo().getNombre() + " han aumentado " +
                std::to_string(getValor()) + " puntos.";
        }
    } else if (getTipo() == Tipo::DEBUFF) {
        if (getAtributo() == Atributo::ATAQUES) {
            getObjetivo().aumentarAtaqueFisico((-1) * getValor());
            getObjetivo().aumentarAtaqueMagico((-1) * getValor());
            log = "El ataque y ataque magico de " + getObjetivo().getNombre() +
                " han disminuido " + std::to_string(getValor()) + " puntos.";
        } else if (getAtributo() == Atributo::DEFENSAS) {
            getObjetivo().aumentarDefensaFisica((-1) * getValor());
            getObjetivo().aumentarDefensaMagica((-1) * getValor());
            log = "La defensa y defensa magica de " + getObjetivo().getNombre()
                + " han disminuido " + std::to_string(getValor()) + " puntos.";
        }
    } else if (getTipo() == Tipo::CURATIVA) {
        getObjetivo().aumentarVida((1) * getValor());
        log = getObjetivo().getNombre() + " ha recuperado " +
              std::to_string(getValor()) + " puntos de vida.";
    } else if (getTipo() == Tipo::MAGIA) {
        // Ataque magico
    }
    setUsosRestantes(getUsosRestantes() - 1);

    return log;
}
