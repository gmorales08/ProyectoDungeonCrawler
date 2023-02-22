#include "../../include/habilidad.hpp"
#include <string>

Habilidad::Habilidad(Habilidad::Usuario usuario, std::string nombre,
                     std::string descripcion, Tipo tipo, int valor) {
    setUsuario(usuario);
	setNombre(nombre);
	setDescripcion(descripcion);
    setTipo(tipo);
    setValor(valor);
    setUsosTotales(3);
	setUsosRestantes(3);

    // setUsuarioJugador(nullptr);
    // setUsuarioEnemigo(nullptr);
    // setObjetivoJugador(nullptr);
    // setObjetivoEnemigo(nullptr);
}

Habilidad::Habilidad(Habilidad::Usuario usuario, std::string nombre,
                     std::string descripcion, Tipo tipo, Atributo atributo,
                     int valor) {
	setUsuario(usuario);
    setNombre(nombre);
	setDescripcion(descripcion);
    setTipo(tipo);
    setAtributo(atributo);
    setValor(valor);
    setUsosTotales(3);
	setUsosRestantes(3);

//    setUsuarioJugador(nullptr);
    // setUsuarioEnemigo(nullptr);
    // setObjetivoJugador(nullptr);
    // setObjetivoEnemigo(nullptr);
}

Habilidad::Habilidad(Habilidad::Usuario usuario, std::string nombre,
                     std::string descripcion, Tipo tipo,
                     Personaje::Elemento elemento) {
    setUsuario(usuario);
    setNombre(nombre);
	setDescripcion(descripcion);
    setTipo(tipo);
    setElemento(elemento);
    setValor(valor);
    setUsosTotales(3);
	setUsosRestantes(3);

//    setUsuarioJugador(nullptr);
    // setUsuarioEnemigo(nullptr);
    // setObjetivoJugador(nullptr);
    // setObjetivoEnemigo(nullptr);
}

Habilidad::Habilidad(Habilidad::Usuario usuario, Tipo tipo, int valor) {
    setUsuario(usuario);
    setNombre("");
    setDescripcion("");
    setTipo(tipo);
    setValor(valor);
    setUsosTotales(3);
    setUsosRestantes(3);

//    setUsuarioJugador(nullptr);
    // setUsuarioEnemigo(nullptr);
    // setObjetivoJugador(nullptr);
    // setObjetivoEnemigo(nullptr);
}

Habilidad::Habilidad(Habilidad::Usuario usuario, Tipo tipo, Atributo atributo,
                     int valor) {
    setUsuario(usuario);
    setNombre("");
    setDescripcion("");
    setTipo(tipo);
    setAtributo(atributo);
    setValor(valor);
    setUsosTotales(3);
    setUsosRestantes(3);

  //  setUsuarioJugador(nullptr);
    // setUsuarioEnemigo(nullptr);
    // setObjetivoJugador(nullptr);
    // setObjetivoEnemigo(nullptr);
}

Habilidad::Habilidad(Habilidad::Usuario usuario, Tipo tipo,
                     Personaje::Elemento elemento) {
    setUsuario(usuario);
    setNombre("");
    setDescripcion("");
    setTipo(tipo);
    setElemento(elemento);
    setUsosTotales(3);
    setUsosRestantes(3);

   // setUsuarioJugador(nullptr);
    // setUsuarioEnemigo(nullptr);
    // setObjetivoJugador(nullptr);
    // setObjetivoEnemigo(nullptr);
}

/* Getters */
Habilidad::Usuario  Habilidad::getUsuario()         { return usuario; }
std::string         Habilidad::getNombre()          { return nombre; }
std::string         Habilidad::getDescripcion()     { return descripcion; }
Habilidad::Tipo     Habilidad::getTipo()            { return tipo; }
Habilidad::Atributo Habilidad::getAtributo()        { return atributo; }
Personaje::Elemento Habilidad::getElemento()        { return elemento; }
int                 Habilidad::getValor()           { return valor; }
// Jugador*            Habilidad::getUsuarioJugador()  { return usuarioJugador; }
// Jugador*            Habilidad::getObjetivoJugador() { return objetivoJugador; }
// Enemigo*            Habilidad::getUsuarioEnemigo()  { return usuarioEnemigo; }
// Enemigo*            Habilidad::getObjetivoEnemigo() { return objetivoEnemigo; }
int                 Habilidad::getUsosRestantes()   { return usosRestantes; }
int                 Habilidad::getUsosTotales()     { return usosTotales; }

/* Setters */
void Habilidad::setUsuario(Usuario _usuario) {
    usuario = _usuario;
}

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

// void Habilidad::setUsuarioJugador(Jugador& _usuario) {
//     usuarioJugador = &_usuario;
// }

// void Habilidad::setObjetivoJugador(Jugador* _objetivo) {
//     objetivoJugador = _objetivo;
// }

// void Habilidad::setUsuarioEnemigo(Enemigo* _usuario) {
//     usuarioEnemigo = _usuario;
// }

// void Habilidad::setObjetivoEnemigo(Enemigo* _objetivo) {
//     objetivoEnemigo = _objetivo;
// }

void Habilidad::setUsosRestantes(int _usosRestantes) {
    if (_usosRestantes > getUsosTotales()) {
        usosRestantes = getUsosTotales();
    } else {
        usosRestantes = _usosRestantes;
    }

    if (getUsosRestantes() < 0) {
        usosRestantes = 0;
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


std::string Habilidad::usar(Jugador& j, Enemigo& e) {
    std::string log = "";
    /* Si no se puede usar la habilidad, realiza un ataque */
    if (getUsosRestantes() == 0) {
        if (getUsuario() == Usuario::USUARIO_JUGADOR) {
            log = j.atacar(e) + "\n";
        } else if (getUsuario() == Usuario::USUARIO_ENEMIGO) {
            log = e.atacar(j) + "\n";
        }

        return log;
    }

    /* Si el jugador usa la habilidad */
    if (getUsuario() == Usuario::USUARIO_JUGADOR) {
        if (getTipo() == Tipo::OFENSIVA) {
            if (getAtributo() == Atributo::ATAQUE) {
                log = j.atacar(e, calcularValor(getValor()));
            } else if (getAtributo() == Atributo::ATAQUE_MAGICO) {
                log = j.usarMagia(e), calcularValor(getValor());
            }
        } else if (getTipo() == Tipo::BUFF) {
            if (getAtributo() == Atributo::ATAQUE) {
                j.aumentarAtaqueFisico(getValor());
                log = "Su ataque aumenta " + std::to_string(getValor()) +
                    " puntos.";
            } else if (getAtributo() == Atributo::ATAQUE_MAGICO) {
                j.aumentarAtaqueMagico(getValor());
                log = "Su ataque magico aumenta " + std::to_string(getValor()) +
                    " puntos.";
            } else if (getAtributo() == Atributo::DEFENSAS) {
                j.aumentarDefensaFisica(getValor());
                j.aumentarDefensaMagica(getValor());
                log = "Sus defensas aumentan " + std::to_string(getValor()) +
                    " puntos.";
            } else if (getAtributo() == Atributo::VELOCIDAD_Y_EVASION) {
                j.aumentarVelocidad(getValor());
                j.aumentarEvasion(getValor());
                log = "Su vel. y eva. aumentan " + std::to_string(getValor()) +
                    " puntos.";
            } else if (getAtributo() == Atributo::PRECISION_Y_CRITICO) {
                j.aumentarPrecision(getValor());
                j.aumentarCritico(getValor());
                log = "Su pre. y cri. aumentan " + std::to_string(getValor()) +
                    " puntos.";
            }
        } else if (getTipo() == Tipo::DEBUFF) {
            if (getAtributo() == Atributo::ATAQUES) {
                e.aumentarAtaqueFisico((-1) * getValor());
                e.aumentarAtaqueMagico((-1) * getValor());
                log = "Los atqs. del rival bajan " + std::to_string(getValor()) +
                    " ptos.";
            } else if (getAtributo() == Atributo::DEFENSAS) {
                e.aumentarDefensaFisica((-1) * getValor());
                e.aumentarDefensaMagica((-1) * getValor());
                log = "Las defs. del rival bajan " + std::to_string(getValor()) +
                    " ptos.";
            }
        } else if (getTipo() == Tipo::CURATIVA) {
            j.aumentarVida(getValor());
            log = "Ha recuperado " + std::to_string(getValor()) + " puntos de vida.";
        } else if (getTipo() == Tipo::MAGIA) {
            log = j.usarMagia(e);
        }
    /* Si un enemigo usa la habilidad */
    } else if (getUsuario() == Usuario::USUARIO_ENEMIGO) {
        if (getTipo() == Tipo::OFENSIVA) {
            if (getAtributo() == Atributo::ATAQUE) {
                log = e.atacar(j, calcularValor(getValor()));
            } else if (getAtributo() == Atributo::ATAQUE_MAGICO) {
                log = e.usarMagia(j), calcularValor(getValor());
            }
        } else if (getTipo() == Tipo::BUFF) {
            if (getAtributo() == Atributo::ATAQUE) {
                e.aumentarAtaqueFisico(getValor());
                log = "Su ataque aumenta " + std::to_string(getValor()) +
                    " puntos.";
            } else if (getAtributo() == Atributo::ATAQUE_MAGICO) {
                e.aumentarAtaqueMagico(getValor());
                log = "Su ataque magico aumenta " + std::to_string(getValor()) +
                    " puntos.";
            } else if (getAtributo() == Atributo::DEFENSAS) {
                e.aumentarDefensaFisica(getValor());
                e.aumentarDefensaMagica(getValor());
                log = "Sus defensas aumentan " + std::to_string(getValor()) +
                    " puntos.";
            } else if (getAtributo() == Atributo::VELOCIDAD_Y_EVASION) {
                e.aumentarVelocidad(getValor());
                e.aumentarEvasion(getValor());
                log = "Su vel. y eva. aumentan " + std::to_string(getValor()) +
                    " puntos.";
            } else if (getAtributo() == Atributo::PRECISION_Y_CRITICO) {
                e.aumentarPrecision(getValor());
                e.aumentarCritico(getValor());
                log = "Su pre. y cri. aumentan " + std::to_string(getValor()) +
                    " puntos.";
            }
        } else if (getTipo() == Tipo::DEBUFF) {
            if (getAtributo() == Atributo::ATAQUES) {
                j.aumentarAtaqueFisico((-1) * getValor());
                j.aumentarAtaqueMagico((-1) * getValor());
                log = "Los atqs. del rival bajan " + std::to_string(getValor()) +
                    " ptos.";
            } else if (getAtributo() == Atributo::DEFENSAS) {
                j.aumentarDefensaFisica((-1) * getValor());
                j.aumentarDefensaMagica((-1) * getValor());
                log = "Las defs. del rival bajan " + std::to_string(getValor()) +
                    " ptos.";
            }
        } else if (getTipo() == Tipo::CURATIVA) {
            e.aumentarVida(getValor());
            log = "Ha recuperado " + std::to_string(getValor()) + " puntos de vida.";
        } else if (getTipo() == Tipo::MAGIA) {
            log = e.usarMagia(j);
        }
    }
    setUsosRestantes(getUsosRestantes() - 1);
    return log;
}
