//#include "../../include/enemigo.hpp" incluido en habilidad.hpp
#include "../../include/habilidad.hpp"

Enemigo::Enemigo(std::string nombre, int nivel,
                 Personaje::Elemento elemento):
                 Personaje(nombre, nivel, elemento) {
    generarAtributos(nivel);
}

std::vector<Habilidad>& Enemigo::getHabilidades() {
    return habilidades;
}
std::vector<int> Enemigo::getProbabilidades() {
    return probabilidadHabilidades;
}

void Enemigo::setHabilidades(std::vector<Habilidad> _habilidades) {
    habilidades = _habilidades;
}
void Enemigo::setProbabilidades(std::vector<int> _probabilidades) {
    probabilidadHabilidades = _probabilidades;
}

void Enemigo::generarAtributos(int nivel) {
    setVidaMaxima((escogerDados(3, 2) + escogerDados(3, 2)) * 10);
	setVida(getVidaMaxima());
	setAtaqueFisico(escogerDados(2));
	setAtaqueMagico(escogerDados(2));
	setDefensaFisica(escogerDados(2));
	setDefensaMagica(escogerDados(2));
	setVelocidad(escogerDados(2));
    setEvasion(escogerDados(2));
    setEvasion(escogerDados(2));
    setPrecision(90);
    setCritico(10);

    for (int i = 0; i < nivel; i++) {
        aumentarAtributos();
    }
}

std::string Enemigo::elegirAccion(Jugador& j) {
    std::string log = "";

    int accion = tirarDado(100); // accion = numero del 1 al 100
    /* Se genera un vector con las frecuencias acumuladas */
    std::vector<int> probabilidades;
    int frecuenciaAcumulada = 0;
    for (int i = 0; i < (int) getProbabilidades().size(); i++) {
        probabilidades.emplace_back(getProbabilidades().at(i) +
                                    frecuenciaAcumulada);
        frecuenciaAcumulada += getProbabilidades().at(i);
    }
    /* Se determina el rango en el que se encuentra accion */
    for (int i = 0; i < (int) probabilidades.size(); i++) {
        if (accion <= probabilidades.at(0)) {
            log = "Ha realizado un ataque fisico.\n";
                if (haAcertado() == true) {
                    if (j.haEsquivado() == false) {
                        log.append(this->atacar(j) + "\n");
                    } else {
                        log.append("Pero el jugador esquiva el ataque.\n");
                    }
                } else {
                    log.append("Pero ha fallado el ataque.\n");
                }
            break;
        } else if (accion <= probabilidades.at(i)) {
            if (getHabilidades().at(i - 1).getUsosRestantes() > 0) {
                log = "Ha usado " + getHabilidades().at(i - 1).getDescripcion() + "\n";
                log.append(getHabilidades().at(i - 1).usar(j, *this));
            } else {
                return elegirAccion(j);
            }
            break;
        }
    }

    return log;
}

std::string Enemigo::atacar(Personaje& p) {
    std::string log = "";
    bool critico = esCritico();
    /* Bonuses */
    float bonuses = 0.0f; // %

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
              p.getDefensaFisica())) * 4;
    dmg = static_cast<int>(static_cast<float>(dmg) * (bonuses + variacion));

    /* Realizar el ataque */
    p.aumentarVida(-1 * dmg);

    if (critico == false) {
        log = "Ha realizado " + std::to_string(static_cast<int>(dmg))
            + " puntos de dano.";
    } else {
        log = "Golpe critico. " + std::to_string(static_cast<int>(dmg)) +
              " puntos de dano.";
    }

    return log;
}

std::string Enemigo::atacar(Personaje& p, int ataqueFisico) {
    std::string log = "";
    bool critico = esCritico();
    /* Bonuses */
    float bonuses = 0.0f; // %

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
              p.getDefensaFisica())) * 4;
    dmg = static_cast<int>(static_cast<float>(dmg) * (bonuses + variacion));

    /* Realizar el ataque */
    p.aumentarVida(-1 * dmg);

    if (critico == false) {
        log = "Ha realizado " + std::to_string(static_cast<int>(dmg))
            + " puntos de dano.";
    } else {
        log = "Golpe critico. " + std::to_string(static_cast<int>(dmg)) +
              " puntos de dano.";
    }

    return log;
}
