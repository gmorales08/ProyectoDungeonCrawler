#include "../../include/enemigo.hpp"

Enemigo::Enemigo(std::string nombre, int nivel,
                 Personaje::Elemento elemento):
                 Personaje(nombre, nivel, elemento) {
    generarAtributos(nivel);
}

std::vector<Habilidad> Enemigo::getHabilidades() {
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
    setVidaMaxima((escogerDados(4) + escogerDados(4)) * 10);
	setVida(getVidaMaxima());
	setAtaqueFisico(escogerDados(2));
	setAtaqueMagico(escogerDados(2));
	setDefensaFisica(escogerDados(2));
	setDefensaMagica(escogerDados(2));
	setVelocidad(escogerDados(2));
    setEvasion(escogerDados(2));

    for (int i = 0; i < nivel; i++) {
        aumentarAtributos();
    }
}

void Enemigo::elegirAccion() {
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
            //Pesonaje.atacar()
            break;
        } else if (accion <= probabilidades.at(i)) {
            if (getHabilidades().at(i - 1).getUsosRestantes() > 0) {
                getHabilidades().at(i - 1).usar();
            } else {
                elegirAccion();
            }
            break;
        }
    }
}