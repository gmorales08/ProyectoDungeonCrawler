#include <vector>
#include <algorithm>
#include <ctime>
#include <random>
#include "../../include/utilidadesDeTerminal.hpp"
#include "../../include/personaje.hpp"

Personaje::Personaje() {
    setNombre("");
    setNivel(1);
}

Personaje::Personaje(std::string nombre) {
	setNombre(nombre);
    setNivel(1);
}

Personaje::Personaje(std::string nombre, int nivel, Elemento elemento) {
    setNombre(nombre);
    setNivel(nivel);
    setElemento(elemento);
}

/* Getters */
std::string Personaje::getNombre()        { return nombre; }
int         Personaje::getVida()          { return vida; }
int         Personaje::getVidaMaxima()    { return vidaMaxima; }
int         Personaje::getAtaqueFisico()  { return ataqueFisico; }
int         Personaje::getAtaqueMagico()  { return ataqueMagico; }
int         Personaje::getDefensaFisica() { return defensaFisica; }
int         Personaje::getDefensaMagica() { return defensaMagica; }
int         Personaje::getVelocidad()     { return velocidad; }
int         Personaje::getEvasion()       { return evasion;}
int         Personaje::getPrecision()     { return precision; }
int         Personaje::getCritico()       { return critico; }

int         Personaje::getNivel()         { return nivel; }

Personaje::Elemento Personaje::getElemento()                  { return elemento; }

std::string Personaje::getElementoString() {
	std::string elementoString = "";
	switch(getElemento()) {
		case Elemento::AGUA:   elementoString = imprimirAzul("Agua");     break;
		case Elemento::FUEGO:  elementoString = imprimirRojo("Fuego");    break;
		case Elemento::HIELO:  elementoString = imprimirCyan("Hielo");    break;
		case Elemento::TIERRA: elementoString = imprimirVerde("Tierra");  break;
		case Elemento::RAYO:   elementoString = imprimirAmarillo("Rayo"); break;
		case Elemento::NEUTRO: elementoString = imprimirBlanco("Neutro"); break;
	}

	return elementoString;
}
/* Fin Getters */

/* Setters */
void Personaje::setNombre(std::string _nombre) {
    nombre = _nombre;
}
void Personaje::setVida(int _vida) {
    vida = _vida;
}

void Personaje::setVidaMaxima(int _vidaMaxima) {
    vidaMaxima = _vidaMaxima;
}

void Personaje::setAtaqueFisico(int _ataqueFisico) {
    ataqueFisico = _ataqueFisico;
}

void Personaje::setAtaqueMagico(int _ataqueMagico) {
    ataqueMagico = _ataqueMagico;
}

void Personaje::setDefensaFisica(int _defensaFisica) {
    defensaFisica = _defensaFisica;
}

void Personaje::setDefensaMagica(int _defensaMagica) {
    defensaMagica = _defensaMagica;
}

void Personaje::setVelocidad(int _velocidad) {
    velocidad = _velocidad;
}

void Personaje::setEvasion(int _evasion) {
    evasion = _evasion;
}

void Personaje::setPrecision(int _precision) {
    precision = _precision;
}

void Personaje::setCritico(int _critico) {
    critico = _critico;
}

void Personaje::setNivel(int _nivel) {
    nivel = _nivel;
}

void Personaje::setElemento(Elemento _elemento) {
    elemento = _elemento;
}
/* Fin setters */

/* Modificar atributos */
void Personaje::aumentarVida(int _vida) {
    if ((getVida() + _vida) > getVidaMaxima()) {
        setVida(getVidaMaxima());
    } else if ((getVida() + _vida <= 0)) {
        setVida(0);
    } else {
        setVida(getVida() + _vida);
    }
}
void Personaje::aumentarVidaMaxima(int _vida) {
    setVidaMaxima(getVidaMaxima() + _vida);
}
void Personaje::aumentarAtaqueFisico(int _ataque) {
    if ((getAtaqueFisico() + _ataque) <= 0) {
        setAtaqueFisico(1);
    } else {
        setAtaqueFisico(getAtaqueFisico() + _ataque);
    }
}
void Personaje::aumentarAtaqueMagico(int _ataquem) {
    if ((getAtaqueMagico() + _ataquem) <= 0) {
        setAtaqueMagico(1);
    } else {
        setAtaqueMagico(getAtaqueMagico() + _ataquem);
    }
}
void Personaje::aumentarDefensaFisica(int _defensa) {
    if ((getDefensaFisica() + _defensa) <= 0) {
        setDefensaFisica(1);
    } else {
        setDefensaFisica(getDefensaFisica() + _defensa);
    }
}
void Personaje::aumentarDefensaMagica(int _defensam) {
    if ((getDefensaMagica() + _defensam) <= 0) {
        setDefensaMagica(1);
    } else {
        setDefensaMagica(getDefensaMagica() + _defensam);
    }
}
void Personaje::aumentarVelocidad(int _velocidad) {
    if ((getVelocidad() + _velocidad) <= 0) {
        setVelocidad(1);
    } else {
        setVelocidad(getVelocidad() + _velocidad);
    }
}
void Personaje::aumentarEvasion(int _evasion) {
    if ((getEvasion() + _evasion) >= 100) {
        setEvasion(100);
    } else if ((getEvasion() + _evasion <=0)) {
        setEvasion(0);
    } else {
        setEvasion(getEvasion() + _evasion);
    }
}
void Personaje::aumentarPrecision(int _precision) {
    if ((getPrecision() + _precision) >= 100) {
        setEvasion(100);
    } else if ((getPrecision() + _precision <=0)) {
        setPrecision(0);
    } else {
        setEvasion(getPrecision() + _precision);
    }
}
void Personaje::aumentarCritico(int _critico) {
    if ((getCritico() + _critico) >= 100) {
        setCritico(100);
    } else if ((getCritico() + _critico) <= 0) {
        setCritico(0);
    } else {
        setCritico(getCritico() + _critico);
    }
}
void Personaje::subirDeNivel() {
    setNivel(getNivel() + 1);
}

void Personaje::aumentarAtributos() {
    int vida = (tirarDado(3) - 1) * 10;
    aumentarVidaMaxima(vida);
    aumentarVida(vida);
    aumentarAtaqueFisico(tirarDado(3) - 1);
    aumentarAtaqueMagico(tirarDado(3) - 1);
    aumentarDefensaFisica(tirarDado(3) - 1);
    aumentarDefensaMagica(tirarDado(3) - 1);
    aumentarVelocidad(tirarDado(3) - 1);
    aumentarEvasion(tirarDado(3) - 1);
    //Precision y critico los dejo igual
}

void Personaje::disminuirAtributos() {
    int vida = -1 * (tirarDado(3) - 1) * 10;
    aumentarVidaMaxima(vida);
    aumentarVida(vida);
    aumentarAtaqueFisico(-1 * (tirarDado(3) - 1));
    aumentarAtaqueMagico(-1 * (tirarDado(3) - 1));
    aumentarDefensaFisica(-1 * (tirarDado(3) - 1));
    aumentarDefensaMagica(-1 * (tirarDado(3) - 1));
    aumentarVelocidad(-1 * (tirarDado(3) - 1));
    aumentarEvasion(-1 * (tirarDado(3) - 1));
    //Precision y critico los dejo igual
}
/* Fin modificar atributos */

std::string Personaje::generarBarraDeVida() {
	std::string vida = "";

	/* 1. Calcular el % de vida que le queda al personaje */
    /* Se calcula el numero de bloques que hay que imprimir sabiendo que el
     * maximo son 20 bloques (vidaMaxima)*/
	int porcentajeVida = (getVida() * 20) / getVidaMaxima();
	/* 2. Imprimimos un "█" por cada 5% de vida */
	int contador = porcentajeVida;
	while (contador > 0) {
		vida += "█";
		contador -= 1;
	}
    /* Agregamos un ░ por cada 5% hasta llegar al 100% */
    int contador2 = 20 - porcentajeVida;
    while (contador2 > 0) {
        vida += "░";
        contador2 -= 1;
    }
	/* 3. Imprimos el color correspondiente al % de vida restante */
    /* 100% -> 20 bloques */
	if (porcentajeVida > 10) {
        vida = imprimirVerde(vida);
    } else if (porcentajeVida <= 10 && porcentajeVida > 5) {
        vida = imprimirAmarillo(vida);
    } else if (porcentajeVida <= 5) {
        vida = imprimirRojo(vida);
    }

	return vida;
}

int Personaje::tirarDado() {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1,6);

    return dist6(rng);
}

int Personaje::tirarDado(int numeroDeCaras) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1,
            numeroDeCaras);

    return dist6(rng);
}

int Personaje::tirarDados(int numeroDeDados) {
    int suma = 0;
    for (int i = 0; i < numeroDeDados; i++) {
        suma += tirarDado();
    }

    return suma;
}

int Personaje::escogerDados(int numeroTiradas) {
    std::vector<int> numeros;

    for (int i = 0; i < numeroTiradas; i++) {
        numeros.push_back(tirarDado());
    }
	std::sort(numeros.begin(), numeros.end());

	return (numeros[numeros.size() - 1] + numeros[numeros.size() - 2] +
           numeros[numeros.size() - 3]);
}

int Personaje::escogerDados(int numeroTiradas, int dadosAEscoger) {
    std::vector<int> numeros;

    for (int i = 0; i < numeroTiradas; i++) {
        numeros.push_back(tirarDado());
    }
    std::sort(numeros.begin(), numeros.end());

    int sumaTotal = 0;
    for (int i = 0; i < dadosAEscoger; i++) {
        sumaTotal += (numeros[numeros.size()] - 1 - i);
    }

    return sumaTotal;
}

int Personaje::generarAleatorio(int inicio, int fin) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(inicio, fin);

    return dist6(rng);

}
