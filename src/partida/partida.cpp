#include "../../include/partida.hpp"
#include "../../include/pantalla.hpp"
#include "../../include/pantallaPiso.hpp"

Partida::Partida(Jugador& jugador) {
    setJugador(jugador);
    setPisoActual(1);
    setPisosRestantes(10);
    setPartidaTerminada(false);
    generarListaEnemigos();
}

/* Getters */
Jugador& Partida::getJugador() {
    return jugador;
}
int Partida::getPisoActual() {
    return pisoActual;
}
int Partida::getPisosRestantes() {
    return pisosRestantes;
}
bool Partida::getPartidaTerminada() {
    return partidaTerminada;
}

/* Setters */
void Partida::setJugador(Jugador& _jugador) {
   jugador = _jugador;
}
void Partida::setPisoActual(int _pisoActual) {
    pisoActual = _pisoActual;
}
void Partida::setPisosRestantes(int _pisosRestantes) {
    pisosRestantes = _pisosRestantes;
}
void Partida::setPartidaTerminada(bool _partidaTerminada) {
    partidaTerminada = _partidaTerminada;
}

/* Metodos */
void Partida::iniciarPartida() {
    while (getPartidaTerminada() == false) {
        menuPantallaPiso(
            cargarPantalla(
                pantallaPiso(getPisoActual(), getPisosRestantes()),
                opcionesPantallaPiso,
                imprimirLog(0,
                    "Seleccione 'a' para avanzar al siguiente piso, 'i' para",
                    "informacion del personaje o 'e' para estadisticas."),
                "Opcion no permitida. Debe escribir 'a', 'e' o 'i'.\n"),
            getJugador());
    }
}

void Partida::descenderPiso() {
    setPisoActual(getPisoActual() + 1);
    setPisosRestantes(getPisosRestantes() - 1);
}

void Partida::generarListaEnemigos() {
    Enemigo slime("Slime", 1, Personaje::Elemento::AGUA);
    slime.setProbabilidades({100});
    std::vector<Enemigo> nivel1 = { slime };

    Enemigo goblin("Goblin", 2, Personaje::Elemento::FUEGO);
    goblin.getHabilidades().emplace_back(Habilidad::Tipo::MAGIA, Personaje::Elemento::FUEGO);
    goblin.setProbabilidades({70,30});
    Enemigo esqueleto("Esqueleto", 2, Personaje::Elemento::HIELO);
    esqueleto.getHabilidades().emplace_back(Habilidad::Tipo::MAGIA, Personaje::Elemento::HIELO);
    esqueleto.setProbabilidades({70,30});
    Enemigo basilisco("Basilisco", 2, Personaje::Elemento::RAYO);
    basilisco.getHabilidades().emplace_back(Habilidad::Tipo::MAGIA, Personaje::Elemento::AGUA);
    basilisco.getHabilidades().emplace_back(Habilidad::Tipo::MAGIA, Personaje::Elemento::RAYO);
    basilisco.getHabilidades().emplace_back(Habilidad::Tipo::MAGIA, Personaje::Elemento::TIERRA);
    basilisco.setProbabilidades({10,30,30,30});
    std::vector<Enemigo> nivel2 = { goblin, esqueleto, basilisco };

    Enemigo licantropo("Licantropo", 3, Personaje::Elemento::HIELO);
    licantropo.getHabilidades().emplace_back(Habilidad::Tipo::OFENSIVA, Habilidad::Atributo::ATAQUE, 1);
    licantropo.setProbabilidades({70,30});
    Enemigo gargola("Gargola", 3, Personaje::Elemento::TIERRA);
    gargola.getHabilidades().emplace_back(Habilidad::Tipo::MAGIA, Personaje::Elemento::TIERRA);
    gargola.setProbabilidades({70,30});
    std::vector<Enemigo> nivel3 = { licantropo, gargola };

    Enemigo serpienteGigante("Serpiente gigante", 4, Personaje::Elemento::RAYO);
    serpienteGigante.getHabilidades().emplace_back(Habilidad::Tipo::BUFF, Habilidad::Atributo::ATAQUE, 1);
    serpienteGigante.setProbabilidades({60,40});
    Enemigo hipocampo("Hipocampo", 4, Personaje::Elemento::AGUA);
    hipocampo.getHabilidades().emplace_back(Habilidad::Tipo::BUFF, Habilidad::Atributo::DEFENSAS, 1);
    hipocampo.setProbabilidades({60,40});
    std::vector<Enemigo> nivel4 = { serpienteGigante, hipocampo };

    Enemigo panteraSalvaje("Pantera salvaje", 5, Personaje::Elemento::NEUTRO);
    panteraSalvaje.getHabilidades().emplace_back(Habilidad::Tipo::DEBUFF, Habilidad::Atributo::ATAQUES, 1);
    panteraSalvaje.setProbabilidades({60,40});
    Enemigo centauro("Centauro", 5, Personaje::Elemento::NEUTRO);
    centauro.getHabilidades().emplace_back(Habilidad::Tipo::DEBUFF, Habilidad::Atributo::DEFENSAS, 1);
    centauro.getHabilidades().emplace_back(Habilidad::Tipo::CURATIVA, 1);
    centauro.setProbabilidades({60,20,20});
    std::vector<Enemigo> nivel5 = { panteraSalvaje, centauro };

    Enemigo grifo("Grifo", 6, Personaje::Elemento::RAYO);
    grifo.getHabilidades().emplace_back(Habilidad::Tipo::MAGIA, Personaje::Elemento::FUEGO);
    grifo.getHabilidades().emplace_back(Habilidad::Tipo::MAGIA, Personaje::Elemento::AGUA);
    grifo.getHabilidades().emplace_back(Habilidad::Tipo::MAGIA, Personaje::Elemento::RAYO);
    grifo.setProbabilidades({30,30,20,20});
    Enemigo quimera("Quimera", 6, Personaje::Elemento::FUEGO);
    quimera.getHabilidades().emplace_back(Habilidad::Tipo::DEBUFF, Habilidad::Atributo::ATAQUES, 2);
    quimera.getHabilidades().emplace_back(Habilidad::Tipo::DEBUFF, Habilidad::Atributo::DEFENSAS, 2);
    quimera.setProbabilidades({60,20,20});
    std::vector<Enemigo> nivel6 = { grifo, quimera };

    Enemigo manticora("Manticora", 7, Personaje::Elemento::AGUA);
    manticora.getHabilidades().emplace_back(Habilidad::Tipo::DEBUFF, Habilidad::Atributo::DEFENSAS, 2);
    manticora.getHabilidades().emplace_back(Habilidad::Tipo::CURATIVA, 2);
    manticora.setProbabilidades({60,20,20});
    Enemigo yeti("Yeti", 7, Personaje::Elemento::HIELO);
    yeti.getHabilidades().emplace_back(Habilidad::Tipo::OFENSIVA, Habilidad::Atributo::ATAQUE, 2);
    yeti.getHabilidades().emplace_back(Habilidad::Tipo::MAGIA, Personaje::Elemento::HIELO);
    yeti.setProbabilidades({60,20,20});
    std::vector<Enemigo> nivel7 = { manticora, yeti };

    Enemigo troll("Troll", 8, Personaje::Elemento::FUEGO);
    troll.getHabilidades().emplace_back(Habilidad::Tipo::OFENSIVA, Habilidad::Atributo::ATAQUE, 2);
    troll.getHabilidades().emplace_back(Habilidad::Tipo::BUFF, Habilidad::Atributo::ATAQUES, 2);
    troll.setProbabilidades({60,20,20});
    Enemigo minotauro("Minotauro", 8, Personaje::Elemento::TIERRA);
    minotauro.getHabilidades().emplace_back(Habilidad::Tipo::OFENSIVA, Habilidad::Atributo::ATAQUE, 2);
    minotauro.getHabilidades().emplace_back(Habilidad::Tipo::BUFF, Habilidad::Atributo::ATAQUES, 2);
    minotauro.setProbabilidades({60,20,20});
    std::vector<Enemigo> nivel8 = { troll, minotauro };

    Enemigo ciclope("Ciclope", 9, Personaje::Elemento::NEUTRO);
    ciclope.getHabilidades().emplace_back(Habilidad::Tipo::BUFF, Habilidad::Atributo::DEFENSAS, 2);
    ciclope.getHabilidades().emplace_back(Habilidad::Tipo::CURATIVA, 2);
    ciclope.setProbabilidades({60,20,20});
    Enemigo golem("Golem", 9, Personaje::Elemento::TIERRA);
    golem.getHabilidades().emplace_back(Habilidad::Tipo::BUFF, Habilidad::Atributo::DEFENSAS, 2);
    golem.getHabilidades().emplace_back(Habilidad::Tipo::CURATIVA, 2);
    golem.setProbabilidades({60,20,20});
    std::vector<Enemigo> nivel9 = { ciclope, golem };

    Enemigo dragon("Dragon", 10, Personaje::Elemento::NEUTRO);
    dragon.getHabilidades().emplace_back(Habilidad::Tipo::MAGIA, Personaje::Elemento::FUEGO);
    dragon.getHabilidades().emplace_back(Habilidad::Tipo::MAGIA, Personaje::Elemento::HIELO);
    dragon.getHabilidades().emplace_back(Habilidad::Tipo::MAGIA, Personaje::Elemento::TIERRA);
    dragon.getHabilidades().emplace_back(Habilidad::Tipo::MAGIA, Personaje::Elemento::RAYO);
    dragon.getHabilidades().emplace_back(Habilidad::Tipo::MAGIA, Personaje::Elemento::AGUA);
    dragon.getHabilidades().emplace_back(Habilidad::Tipo::CURATIVA, 3);
    dragon.setProbabilidades({40,10,10,10,10,10,10});
    Enemigo hidra("Hidra", 10, Personaje::Elemento::NEUTRO);
    hidra.getHabilidades().emplace_back(Habilidad::Tipo::MAGIA, Personaje::Elemento::FUEGO);
    hidra.getHabilidades().emplace_back(Habilidad::Tipo::MAGIA, Personaje::Elemento::HIELO);
    hidra.getHabilidades().emplace_back(Habilidad::Tipo::MAGIA, Personaje::Elemento::TIERRA);
    hidra.getHabilidades().emplace_back(Habilidad::Tipo::MAGIA, Personaje::Elemento::RAYO);
    hidra.getHabilidades().emplace_back(Habilidad::Tipo::MAGIA, Personaje::Elemento::AGUA);
    hidra.getHabilidades().emplace_back(Habilidad::Tipo::CURATIVA, 3);
    hidra.setProbabilidades({40,10,10,10,10,10,10});
    std::vector<Enemigo> nivel10 = { dragon, hidra };

    listaEnemigos.push_back(nivel1);
    listaEnemigos.push_back(nivel2);
    listaEnemigos.push_back(nivel3);
    listaEnemigos.push_back(nivel4);
    listaEnemigos.push_back(nivel5);
    listaEnemigos.push_back(nivel6);
    listaEnemigos.push_back(nivel7);
    listaEnemigos.push_back(nivel8);
    listaEnemigos.push_back(nivel9);
    listaEnemigos.push_back(nivel10);
}
