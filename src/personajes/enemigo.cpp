#include "../../include/enemigo.hpp"

Enemigo::Enemigo(std::string nombre, int nivel, 
                 Personaje::Elemento elemento): 
                 Personaje(nombre, nivel, elemento) {
    generarAtributos(nivel);
}

std::vector<Habilidad> Enemigo::getHabilidades() {
    return habilidades;
}

void Enemigo::setHabilidades(
                        std::vector<Habilidad> _habilidades) {
    habilidades = _habilidades;
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
