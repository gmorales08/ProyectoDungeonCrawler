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
                     std::string descripcion, Tipo tipo,
                     Habilidad::Atributo atributo, int valor) {
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

Habilidad::Habilidad(Habilidad::Usuario usuario, Tipo tipo,
                     Habilidad::Atributo atributo, int valor) {
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
    if (valor == 1) {
        valorFinal = Personaje::tirarDado();
    } if (valor == 2) {
        valorFinal = Personaje::escogerDados(2, 1);
    } else if (valor == 3) {
        valorFinal = Personaje::escogerDados(3, 2);
    }

    if (getTipo() == Tipo::OFENSIVA) {
        valorFinal = valorFinal * 5;
    } else if (getTipo() == Tipo::CURATIVA) {
        valorFinal = valorFinal * 10;
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

    int valorHabilidad = calcularValor(getValor());
    /* Si el jugador usa la habilidad */
    if (getUsuario() == Usuario::USUARIO_JUGADOR) {
        if (getTipo() == Tipo::OFENSIVA) {
            if (getAtributo() == Atributo::ATAQUE) {
                log = j.atacar(e, valorHabilidad);
            } else if (getAtributo() == Atributo::ATAQUE_MAGICO) {
                log = j.usarMagia(e, valorHabilidad);
            }
        } else if (getTipo() == Tipo::BUFF) {
            if (getAtributo() == Atributo::ATAQUE) {
                j.aumentarAtaqueFisico(valorHabilidad);
                log = "Su ataque aumenta " + std::to_string(valorHabilidad) +
                    " puntos.";
            } else if (getAtributo() == Atributo::ATAQUE_MAGICO) {
                j.aumentarAtaqueMagico(valorHabilidad);
                log = "Su ataque magico aumenta " + std::to_string(valorHabilidad) +
                    " puntos.";
            } else if (getAtributo() == Atributo::DEFENSAS) {
                j.aumentarDefensaFisica(valorHabilidad);
                j.aumentarDefensaMagica(valorHabilidad);
                log = "Sus defensas aumentan " + std::to_string(valorHabilidad) +
                    " puntos.";
            } else if (getAtributo() == Atributo::VELOCIDAD_Y_EVASION) {
                j.aumentarVelocidad(valorHabilidad);
                j.aumentarEvasion(valorHabilidad);
                log = "Su vel. y eva. aumentan " + std::to_string(valorHabilidad) +
                    " puntos.";
            } else if (getAtributo() == Atributo::PRECISION_Y_CRITICO) {
                j.aumentarPrecision(valorHabilidad);
                j.aumentarCritico(valorHabilidad);
                log = "Su pre. y cri. aumentan " + std::to_string(valorHabilidad) +
                    " puntos.";
            }
        } else if (getTipo() == Tipo::DEBUFF) {
            if (getAtributo() == Atributo::ATAQUES) {
                e.aumentarAtaqueFisico((-1) * valorHabilidad);
                e.aumentarAtaqueMagico((-1) * valorHabilidad);
                log = "Los atqs. del rival bajan " + std::to_string(valorHabilidad) +
                    " ptos.";
            } else if (getAtributo() == Atributo::DEFENSAS) {
                e.aumentarDefensaFisica((-1) * valorHabilidad);
                e.aumentarDefensaMagica((-1) * valorHabilidad);
                log = "Las defs. del rival bajan " + std::to_string(valorHabilidad) +
                    " ptos.";
            }
        } else if (getTipo() == Tipo::CURATIVA) {
            j.aumentarVida(valorHabilidad);
            log = "Ha recuperado " + std::to_string(valorHabilidad) + " puntos de vida.";
        } else if (getTipo() == Tipo::MAGIA) {
            log = j.usarMagia(e);
        }
    /* Si un enemigo usa la habilidad */
    } else if (getUsuario() == Usuario::USUARIO_ENEMIGO) {
        if (getTipo() == Tipo::OFENSIVA) {
            if (getAtributo() == Atributo::ATAQUE) {
                log = e.atacar(j, valorHabilidad);
            } else if (getAtributo() == Atributo::ATAQUE_MAGICO) {
                log = e.usarMagia(j, valorHabilidad);
            }
        } else if (getTipo() == Tipo::BUFF) {
            if (getAtributo() == Atributo::ATAQUE) {
                e.aumentarAtaqueFisico(valorHabilidad);
                log = "Su ataque aumenta " + std::to_string(valorHabilidad) +
                    " puntos.";
            } else if (getAtributo() == Atributo::ATAQUE_MAGICO) {
                e.aumentarAtaqueMagico(valorHabilidad);
                log = "Su ataque magico aumenta " + std::to_string(valorHabilidad) +
                    " puntos.";
            } else if (getAtributo() == Atributo::DEFENSAS) {
                e.aumentarDefensaFisica(valorHabilidad);
                e.aumentarDefensaMagica(valorHabilidad);
                log = "Sus defensas aumentan " + std::to_string(valorHabilidad) +
                    " puntos.";
            } else if (getAtributo() == Atributo::VELOCIDAD_Y_EVASION) {
                e.aumentarVelocidad(valorHabilidad);
                e.aumentarEvasion(valorHabilidad);
                log = "Su vel. y eva. aumentan " + std::to_string(valorHabilidad) +
                    " puntos.";
            } else if (getAtributo() == Atributo::PRECISION_Y_CRITICO) {
                e.aumentarPrecision(valorHabilidad);
                e.aumentarCritico(valorHabilidad);
                log = "Su pre. y cri. aumentan " + std::to_string(valorHabilidad) +
                    " puntos.";
            }
        } else if (getTipo() == Tipo::DEBUFF) {
            if (getAtributo() == Atributo::ATAQUES) {
                j.aumentarAtaqueFisico((-1) * valorHabilidad);
                j.aumentarAtaqueMagico((-1) * valorHabilidad);
                log = "Los atqs. del rival bajan " + std::to_string(valorHabilidad) +
                    " ptos.";
            } else if (getAtributo() == Atributo::DEFENSAS) {
                j.aumentarDefensaFisica((-1) * valorHabilidad);
                j.aumentarDefensaMagica((-1) * valorHabilidad);
                log = "Las defs. del rival bajan " + std::to_string(valorHabilidad) +
                    " ptos.";
            }
        } else if (getTipo() == Tipo::CURATIVA) {
            e.aumentarVida(valorHabilidad);
            log = "Ha recuperado " + std::to_string(valorHabilidad) + " puntos de vida.";
        } else if (getTipo() == Tipo::MAGIA) {
            log = e.usarMagia(j);
        }
    }
    log.append("\n");
    setUsosRestantes(getUsosRestantes() - 1);
    return log;
}
