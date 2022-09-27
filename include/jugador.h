#ifndef JUGADOR
#define JUGADOR


#include "personaje.h"


// CLASE JUGADOR
//
// Hereda de la clase personaje y contiene los atributos y metodos del jugador creado
//


// ENUMERADOS
//
// Contienen informacion de la Raza, Clase, Subclase y Arma del personaje
//
enum Raza     {Humano = 1, Enano = 2, Elfo = 3, Ogro = 4, Triton = 5, Bestia = 6};
enum Clase    {Guerrero = 1, Mago = 2, Monje = 3, Clerigo = 4, Ladron = 5, Trovador = 6};
enum Subclase {Herrero = 1, Alquimista = 2, Gladiador = 3, Boticario = 4, Druida = 5, Mercenario = 6};
enum Arma     {Espada = 1, Estoque = 2, Daga = 3, Mandoble = 4, Baculo = 5, Hacha = 6, Lanza = 7, Arco = 8, Martillo = 9, Garras = 10};


class Jugador : public Personaje {

public:

	Jugador(std::string _nombre, int _raza, int _clase, int _subclase, int _arma);

	// Getters
	Raza getRaza();
	Clase getClase();
	Subclase getSubClase();
	Arma getArma();
	std::string getAfinidades();

	/* Setters // Pendiente de saber si durante la partida se puede modificar el personaje
	void setRaza(Raza raza);
	void setClase(Clase clase);
	void setSubClase(Subclase subclase);
	void setArma(Arma arma);*/

private:

	Raza raza;
	Clase clase;
	Subclase subclase;
	Arma arma;	

	std::string afinidades; // Lista de las armas con las que tiene afinidad el jugador. Es informativa, para mostrar en la pantalla de Informacion del Jugador. 
	
	// OBTENER ELEMENTO
	//
	// Metodo para obtener el elemento correspondiente a la raza pasada por parametro
	//
	Elemento obtenerElemento(Raza raza);
	
	// OBTENER AFINIDADES
	//
	// Metodo para obtener las armas con las que tiene afinidad el jugador.
	//
	// Devuelve un string con la lista de armas. Se usara en la pantalla Informacion del Jugador
	//
	std::string obtenerAfinidades(Raza raza, Clase clase, Subclase subclase);

};


#endif //JUGADOR