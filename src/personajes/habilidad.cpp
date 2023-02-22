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
	setUsosRestantes(usosTotales);
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
	setUsosRestantes(usosTotales);
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
	setUsosRestantes(usosTotales);
}

Habilidad::Habilidad(Habilidad::Usuario usuario, Tipo tipo, int valor) {
    setUsuario(usuario);
    setNombre("");
    setDescripcion("");
    setTipo(tipo);
    setValor(valor);
    setUsosTotales(3);
    setUsosRestantes(3);
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
}

/* Getters */
Habilidad::Usuario  Habilidad::getUsuario()         { return usuario; }
std::string         Habilidad::getNombre()          { return nombre; }
std::string         Habilidad::getDescripcion()     { return descripcion; }
Habilidad::Tipo     Habilidad::getTipo()            { return tipo; }
Habilidad::Atributo Habilidad::getAtributo()        { return atributo; }
Personaje::Elemento Habilidad::getElemento()        { return elemento; }
int                 Habilidad::getValor()           { return valor; }
Jugador*            Habilidad::getUsuarioJugador()  { return usuarioJugador; }
Jugador*            Habilidad::getObjetivoJugador() { return objetivoJugador; }
Enemigo*            Habilidad::getUsuarioEnemigo()  { return usuarioEnemigo; }
Enemigo*            Habilidad::getObjetivoEnemigo() { return objetivoEnemigo; }
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

void Habilidad::setUsuarioJugador(Jugador* _usuario) {
    usuarioJugador = _usuario;
}

void Habilidad::setObjetivoJugador(Jugador* _objetivo) {
    objetivoJugador = _objetivo;
}

void Habilidad::setUsuarioEnemigo(Enemigo* _usuario) {
    usuarioEnemigo = _usuario;
}

void Habilidad::setObjetivoEnemigo(Enemigo* _objetivo) {
    objetivoEnemigo = _objetivo;
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
    /* Si el jugador usa la habilidad */
    if (getUsuario() == Usuario::USUARIO_JUGADOR) {
        Enemigo& objetivo = *(getObjetivoEnemigo());
        if (getTipo() == Tipo::OFENSIVA) {
            if (getAtributo() == Atributo::ATAQUE) {
                log = getUsuarioJugador()->atacar(objetivo,
                                        calcularValor(getValor()));
            } else if (getAtributo() == Atributo::ATAQUE_MAGICO) {
                log = getUsuarioJugador()->usarMagia(objetivo),
                                            calcularValor(getValor());
            }
        } else if (getTipo() == Tipo::BUFF) {
            if (getAtributo() == Atributo::ATAQUE) {
                getUsuarioJugador()->aumentarAtaqueFisico(getValor());
                log = "Su ataque aumenta " + std::to_string(getValor()) +
                    " puntos.";
            } else if (getAtributo() == Atributo::ATAQUE_MAGICO) {
                getUsuarioJugador()->aumentarAtaqueMagico(getValor());
                log = "Su ataque magico aumenta " + std::to_string(getValor()) +
                    " puntos.";
            } else if (getAtributo() == Atributo::DEFENSAS) {
                getUsuarioJugador()->aumentarDefensaFisica(getValor());
                getUsuarioJugador()->aumentarDefensaMagica(getValor());
                log = "Sus defensas aumentan " + std::to_string(getValor()) +
                    " puntos.";
            } else if (getAtributo() == Atributo::VELOCIDAD_Y_EVASION) {
                getUsuarioJugador()->aumentarVelocidad(getValor());
                getUsuarioJugador()->aumentarEvasion(getValor());
                log = "Su vel. y eva. aumentan " + std::to_string(getValor()) +
                    " puntos.";
            } else if (getAtributo() == Atributo::PRECISION_Y_CRITICO) {
                getUsuarioJugador()->aumentarPrecision(getValor());
                getUsuarioJugador()->aumentarCritico(getValor());
                log = "Su pre. y cri. aumentan " + std::to_string(getValor()) +
                    " puntos.";
            }
        } else if (getTipo() == Tipo::DEBUFF) {
            if (getAtributo() == Atributo::ATAQUES) {
                getObjetivoEnemigo()->aumentarAtaqueFisico((-1) * getValor());
                getObjetivoEnemigo()->aumentarAtaqueMagico((-1) * getValor());
                log = "Los atqs. del rival bajan " + std::to_string(getValor()) +
                    " ptos.";
            } else if (getAtributo() == Atributo::DEFENSAS) {
                getObjetivoEnemigo()->aumentarDefensaFisica((-1) * getValor());
                getObjetivoEnemigo()->aumentarDefensaMagica((-1) * getValor());
                log = "Las defs. del rival bajan " + std::to_string(getValor()) +
                    " ptos.";
            }
        } else if (getTipo() == Tipo::CURATIVA) {
            getUsuarioJugador()->aumentarVida(getValor());
            log = "Ha recuperado " + std::to_string(getValor()) + " puntos de vida.";
        } else if (getTipo() == Tipo::MAGIA) {
            log = getUsuarioJugador()->usarMagia(objetivo);
        }
    /* Si un enemigo usa la habilidad */
    } else if (getUsuario() == Usuario::USUARIO_ENEMIGO) {
        Jugador& objetivo = *(getObjetivoJugador());
        if (getTipo() == Tipo::OFENSIVA) {
            if (getAtributo() == Atributo::ATAQUE) {
                log = getUsuarioEnemigo()->atacar(objetivo,
                                        calcularValor(getValor()));
            } else if (getAtributo() == Atributo::ATAQUE_MAGICO) {
                log = getUsuarioEnemigo()->usarMagia(objetivo),
                                            calcularValor(getValor());
            }
        } else if (getTipo() == Tipo::BUFF) {
            if (getAtributo() == Atributo::ATAQUE) {
                getUsuarioEnemigo()->aumentarAtaqueFisico(getValor());
                log = "Su ataque aumenta " + std::to_string(getValor()) +
                    " puntos.";
            } else if (getAtributo() == Atributo::ATAQUE_MAGICO) {
                getUsuarioEnemigo()->aumentarAtaqueMagico(getValor());
                log = "Su ataque magico aumenta " + std::to_string(getValor()) +
                    " puntos.";
            } else if (getAtributo() == Atributo::DEFENSAS) {
                getUsuarioEnemigo()->aumentarDefensaFisica(getValor());
                getUsuarioEnemigo()->aumentarDefensaMagica(getValor());
                log = "Sus defensas aumentan " + std::to_string(getValor()) +
                    " puntos.";
            } else if (getAtributo() == Atributo::VELOCIDAD_Y_EVASION) {
                getUsuarioEnemigo()->aumentarVelocidad(getValor());
                getUsuarioEnemigo()->aumentarEvasion(getValor());
                log = "Su vel. y eva. aumentan " + std::to_string(getValor()) +
                    " puntos.";
            } else if (getAtributo() == Atributo::PRECISION_Y_CRITICO) {
                getUsuarioEnemigo()->aumentarPrecision(getValor());
                getUsuarioEnemigo()->aumentarCritico(getValor());
                log = "Su pre. y cri. aumentan " + std::to_string(getValor()) +
                    " puntos.";
            }
        } else if (getTipo() == Tipo::DEBUFF) {
            if (getAtributo() == Atributo::ATAQUES) {
                getObjetivoJugador()->aumentarAtaqueFisico((-1) * getValor());
                getObjetivoJugador()->aumentarAtaqueMagico((-1) * getValor());
                log = "Los atqs. del rival bajan " + std::to_string(getValor()) +
                    " ptos.";
            } else if (getAtributo() == Atributo::DEFENSAS) {
                getObjetivoJugador()->aumentarDefensaFisica((-1) * getValor());
                getObjetivoJugador()->aumentarDefensaMagica((-1) * getValor());
                log = "Las defs. del rival bajan " + std::to_string(getValor()) +
                    " ptos.";
            }
        } else if (getTipo() == Tipo::CURATIVA) {
            getUsuarioEnemigo()->aumentarVida(getValor());
            log = "Ha recuperado " + std::to_string(getValor()) + " puntos de vida.";
        } else if (getTipo() == Tipo::MAGIA) {
            log = getUsuarioEnemigo()->usarMagia(objetivo);
        }
    }
    setUsosRestantes(getUsosRestantes() - 1);

    return log;
}
