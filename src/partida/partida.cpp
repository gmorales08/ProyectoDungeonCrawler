#include "../../include/partida.hpp"
#include "../../include/utilidadesDeTerminal.hpp"
#include "../../include/pantalla.hpp"
#include "../../include/pantallaPiso.hpp"

Partida::Partida(Jugador& jugador) {
    setJugador(jugador);
    setPisoActual(1);
    setPisosRestantes(10);
    setPartidaTerminada(false);
    setEnemigosDerrotados(0);
    setEventosPresenciados(0);
    setEventosExitosos(0);
    setEventosFallidos(0);
    generarListaEnemigos();
    generarListaEventos();
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
int Partida::getEnemigosDerrotados() {
    return enemigosDerrotados;
}
int Partida::getEventosPresenciados() {
    return eventosPresenciados;
}
int Partida::getEventosExitosos() {
    return eventosExitosos;
}
int Partida::getEventosFallidos() {
    return eventosFallidos;
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
void Partida::setEnemigosDerrotados(int _enemigos) {
    enemigosDerrotados = _enemigos;
}
void Partida::setEventosPresenciados(int _eventos) {
    eventosPresenciados = _eventos;
}
void Partida::setEventosExitosos(int _eventos) {
    eventosExitosos = _eventos;
}
void Partida::setEventosFallidos(int _eventos) {
    eventosFallidos = _eventos;
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
            this);
        descenderPiso();
        if (getPisosRestantes() == 0) {
            imprimirPantallaEstatica(pantallaVictoria);
            break;
        }
    }

    if (getPartidaTerminada() == true) {
        imprimirPantallaEstatica(pantallaDerrota);
    }

    limpiarPantalla();
        std::cout << imprimirAmarillo("Gracias por jugar!\nHasta pronto\n");
        pausar(1500);
}

void Partida::descenderPiso() {
    setPisoActual(getPisoActual() + 1);
    setPisosRestantes(getPisosRestantes() - 1);
}

void Partida::retrocederPiso() {
    setPisoActual(getPisoActual() - 1);
    setPisosRestantes(getPisosRestantes() + 1);
}

void Partida::generarListaEnemigos() {
    Enemigo slime("Slime", 1, Personaje::Elemento::AGUA);
    slime.setProbabilidades({100});
    std::vector<Enemigo> nivel1 = { slime };

    Enemigo goblin("Goblin", 2, Personaje::Elemento::FUEGO);
    goblin.getHabilidades().emplace_back(Habilidad::Usuario::USUARIO_ENEMIGO,
        "", "magia de fuego.", Habilidad::Tipo::MAGIA,
        Personaje::Elemento::FUEGO);
    goblin.setProbabilidades({70,30});
    Enemigo esqueleto("Esqueleto", 2, Personaje::Elemento::HIELO);
    esqueleto.getHabilidades().emplace_back(Habilidad::Usuario::USUARIO_ENEMIGO,
        "", "magia de hielo.", Habilidad::Tipo::MAGIA, Personaje::Elemento::HIELO);
    esqueleto.setProbabilidades({70,30});
    Enemigo basilisco("Basilisco", 2, Personaje::Elemento::RAYO);
    basilisco.getHabilidades().emplace_back(Habilidad::Usuario::USUARIO_ENEMIGO,
        "", "magia de agua.", Habilidad::Tipo::MAGIA, Personaje::Elemento::AGUA);
    basilisco.getHabilidades().emplace_back(Habilidad::Usuario::USUARIO_ENEMIGO,
        "", "magia de rayo.", Habilidad::Tipo::MAGIA, Personaje::Elemento::RAYO);
    basilisco.getHabilidades().emplace_back(Habilidad::Usuario::USUARIO_ENEMIGO,
        "", "magia de tierra.", Habilidad::Tipo::MAGIA, Personaje::Elemento::TIERRA);
    basilisco.setProbabilidades({10,30,30,30});
    std::vector<Enemigo> nivel2 = { goblin, esqueleto, basilisco };

    Enemigo licantropo("Licantropo", 3, Personaje::Elemento::HIELO);
    licantropo.getHabilidades().emplace_back(Habilidad::Usuario::USUARIO_ENEMIGO,
        "", "aullido.", Habilidad::Tipo::OFENSIVA, Habilidad::Atributo::ATAQUE, 1);
    licantropo.setProbabilidades({70,30});
    Enemigo gargola("Gargola", 3, Personaje::Elemento::TIERRA);
    gargola.getHabilidades().emplace_back(Habilidad::Usuario::USUARIO_ENEMIGO,
        "", "magia de tierra.", Habilidad::Tipo::MAGIA, Personaje::Elemento::TIERRA);
    gargola.setProbabilidades({70,30});
    std::vector<Enemigo> nivel3 = { licantropo, gargola };

    Enemigo serpienteGigante("Serpiente gigante", 4, Personaje::Elemento::RAYO);
    serpienteGigante.getHabilidades().emplace_back(Habilidad::Usuario::USUARIO_ENEMIGO,
        "", " afilar colmillos.", Habilidad::Tipo::BUFF, Habilidad::Atributo::ATAQUE, 1);
    serpienteGigante.setProbabilidades({60,40});
    Enemigo hipocampo("Hipocampo", 4, Personaje::Elemento::AGUA);
    hipocampo.getHabilidades().emplace_back(Habilidad::Usuario::USUARIO_ENEMIGO,
        "", " llamada de los mares.", Habilidad::Tipo::BUFF, Habilidad::Atributo::DEFENSAS, 1);
    hipocampo.setProbabilidades({60,40});
    std::vector<Enemigo> nivel4 = { serpienteGigante, hipocampo };

    Enemigo panteraSalvaje("Pantera salvaje", 5, Personaje::Elemento::NEUTRO);
    panteraSalvaje.getHabilidades().emplace_back(Habilidad::Usuario::USUARIO_ENEMIGO,
        "", "rugido intimidatorio.", Habilidad::Tipo::DEBUFF, Habilidad::Atributo::ATAQUES, 1);
    panteraSalvaje.setProbabilidades({60,40});
    Enemigo centauro("Centauro", 5, Personaje::Elemento::NEUTRO);
    centauro.getHabilidades().emplace_back(Habilidad::Usuario::USUARIO_ENEMIGO,
        "", "desarmamiento.", Habilidad::Tipo::DEBUFF, Habilidad::Atributo::DEFENSAS, 1);
    centauro.getHabilidades().emplace_back(Habilidad::Usuario::USUARIO_ENEMIGO,
        "", "licor de los faunos.", Habilidad::Tipo::CURATIVA, 1);
    centauro.setProbabilidades({60,20,20});
    std::vector<Enemigo> nivel5 = { panteraSalvaje, centauro };

    Enemigo grifo("Grifo", 6, Personaje::Elemento::RAYO);
    grifo.getHabilidades().emplace_back(Habilidad::Usuario::USUARIO_ENEMIGO,
        "", "magia de fuego.", Habilidad::Tipo::MAGIA, Personaje::Elemento::FUEGO);
    grifo.getHabilidades().emplace_back(Habilidad::Usuario::USUARIO_ENEMIGO,
        "", "magia de agua.", Habilidad::Tipo::MAGIA, Personaje::Elemento::AGUA);
    grifo.getHabilidades().emplace_back(Habilidad::Usuario::USUARIO_ENEMIGO,
        "", "magia de rayo.", Habilidad::Tipo::MAGIA, Personaje::Elemento::RAYO);
    grifo.setProbabilidades({30,30,20,20});
    Enemigo quimera("Quimera", 6, Personaje::Elemento::FUEGO);
    quimera.getHabilidades().emplace_back(Habilidad::Usuario::USUARIO_ENEMIGO,
        "", "rugido potente.", Habilidad::Tipo::DEBUFF, Habilidad::Atributo::ATAQUES, 2);
    quimera.getHabilidades().emplace_back(Habilidad::Usuario::USUARIO_ENEMIGO,
        "", "graznido estridente.", Habilidad::Tipo::DEBUFF, Habilidad::Atributo::DEFENSAS, 2);
    quimera.setProbabilidades({60,20,20});
    std::vector<Enemigo> nivel6 = { grifo, quimera };

    Enemigo manticora("Manticora", 7, Personaje::Elemento::AGUA);
    manticora.getHabilidades().emplace_back(Habilidad::Usuario::USUARIO_ENEMIGO,
        "", "aliento paralizante.", Habilidad::Tipo::DEBUFF, Habilidad::Atributo::DEFENSAS, 2);
    manticora.getHabilidades().emplace_back(Habilidad::Usuario::USUARIO_ENEMIGO,
        "", "recuperacion.", Habilidad::Tipo::CURATIVA, 2);
    manticora.setProbabilidades({60,20,20});
    Enemigo yeti("Yeti", 7, Personaje::Elemento::HIELO);
    yeti.getHabilidades().emplace_back(Habilidad::Usuario::USUARIO_ENEMIGO,
        "", "zarpazo gelido.", Habilidad::Tipo::OFENSIVA, Habilidad::Atributo::ATAQUE, 2);
    yeti.getHabilidades().emplace_back(Habilidad::Usuario::USUARIO_ENEMIGO,
        "", "magia de hielo.", Habilidad::Tipo::MAGIA, Personaje::Elemento::HIELO);
    yeti.setProbabilidades({60,20,20});
    std::vector<Enemigo> nivel7 = { manticora, yeti };

    Enemigo troll("Troll", 8, Personaje::Elemento::FUEGO);
    troll.getHabilidades().emplace_back(Habilidad::Usuario::USUARIO_ENEMIGO,
        "", "ataque furioso.", Habilidad::Tipo::OFENSIVA, Habilidad::Atributo::ATAQUE, 2);
    troll.getHabilidades().emplace_back(Habilidad::Usuario::USUARIO_ENEMIGO,
        "", "grito de batalla.", Habilidad::Tipo::BUFF, Habilidad::Atributo::ATAQUES, 2);
    troll.setProbabilidades({60,20,20});
    Enemigo minotauro("Minotauro", 8, Personaje::Elemento::TIERRA);
    minotauro.getHabilidades().emplace_back(Habilidad::Usuario::USUARIO_ENEMIGO,
        "", "embestida.", Habilidad::Tipo::OFENSIVA, Habilidad::Atributo::ATAQUE, 2);
    minotauro.getHabilidades().emplace_back(Habilidad::Usuario::USUARIO_ENEMIGO,
        "", "afilar cuernos.", Habilidad::Tipo::BUFF, Habilidad::Atributo::ATAQUES, 2);
    minotauro.setProbabilidades({60,20,20});
    std::vector<Enemigo> nivel8 = { troll, minotauro };

    Enemigo ciclope("Ciclope", 9, Personaje::Elemento::NEUTRO);
    ciclope.getHabilidades().emplace_back(Habilidad::Usuario::USUARIO_ENEMIGO,
        "", "fortalecimiento.", Habilidad::Tipo::BUFF, Habilidad::Atributo::DEFENSAS, 2);
    ciclope.getHabilidades().emplace_back(Habilidad::Usuario::USUARIO_ENEMIGO,
        "", "recuperacion.", Habilidad::Tipo::CURATIVA, 2);
    ciclope.setProbabilidades({60,20,20});
    Enemigo golem("Golem", 9, Personaje::Elemento::TIERRA);
    golem.getHabilidades().emplace_back(Habilidad::Usuario::USUARIO_ENEMIGO,
        "", "endurecimiento.", Habilidad::Tipo::BUFF, Habilidad::Atributo::DEFENSAS, 2);
    golem.getHabilidades().emplace_back(Habilidad::Usuario::USUARIO_ENEMIGO,
        "", "recuperacion.", Habilidad::Tipo::CURATIVA, 2);
    golem.setProbabilidades({60,20,20});
    std::vector<Enemigo> nivel9 = { ciclope, golem };

    Enemigo dragon("Dragon", 10, Personaje::Elemento::NEUTRO);
    dragon.getHabilidades().emplace_back(Habilidad::Usuario::USUARIO_ENEMIGO,
        "", "magia de fuego.", Habilidad::Tipo::MAGIA, Personaje::Elemento::FUEGO);
    dragon.getHabilidades().emplace_back(Habilidad::Usuario::USUARIO_ENEMIGO,
        "", "magia de hielo.", Habilidad::Tipo::MAGIA, Personaje::Elemento::HIELO);
    dragon.getHabilidades().emplace_back(Habilidad::Usuario::USUARIO_ENEMIGO,
        "", "magia de tierra.", Habilidad::Tipo::MAGIA, Personaje::Elemento::TIERRA);
    dragon.getHabilidades().emplace_back(Habilidad::Usuario::USUARIO_ENEMIGO,
        "", "magia de rayo.", Habilidad::Tipo::MAGIA, Personaje::Elemento::RAYO);
    dragon.getHabilidades().emplace_back(Habilidad::Usuario::USUARIO_ENEMIGO,
        "", "magia de agua.", Habilidad::Tipo::MAGIA, Personaje::Elemento::AGUA);
    dragon.getHabilidades().emplace_back(Habilidad::Usuario::USUARIO_ENEMIGO,
        "", "recuperacion.", Habilidad::Tipo::CURATIVA, 3);
    dragon.setProbabilidades({40,10,10,10,10,10,10});
    Enemigo hidra("Hidra", 10, Personaje::Elemento::NEUTRO);
    hidra.getHabilidades().emplace_back(Habilidad::Usuario::USUARIO_ENEMIGO,
        "", "magia de fuego.", Habilidad::Tipo::MAGIA, Personaje::Elemento::FUEGO);
    hidra.getHabilidades().emplace_back(Habilidad::Usuario::USUARIO_ENEMIGO,
        "", "magia de hielo.", Habilidad::Tipo::MAGIA, Personaje::Elemento::HIELO);
    hidra.getHabilidades().emplace_back(Habilidad::Usuario::USUARIO_ENEMIGO,
        "", "magia de tierra.", Habilidad::Tipo::MAGIA, Personaje::Elemento::TIERRA);
    hidra.getHabilidades().emplace_back(Habilidad::Usuario::USUARIO_ENEMIGO,
        "", "magia de rayo.", Habilidad::Tipo::MAGIA, Personaje::Elemento::RAYO);
    hidra.getHabilidades().emplace_back(Habilidad::Usuario::USUARIO_ENEMIGO,
        "", "magia de agua.", Habilidad::Tipo::MAGIA, Personaje::Elemento::AGUA);
    hidra.getHabilidades().emplace_back(Habilidad::Usuario::USUARIO_ENEMIGO,
        "", "magia de recuperacion.", Habilidad::Tipo::CURATIVA, 3);
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

void Partida::generarListaEventos() {
    Evento evento0(
    {"Encuentras un remanso cerca de un pequeño lago. Parece que un aura magica ",
     "lo protege de adversidades. ¿Te quedas a descansar?                       ",
     ""},
    {"Tras descansar un rato recuperas toda la vida y los usos de tus",
     "habilidades.",
     ""},
    true, Evento::EventoPositivo::RECUPERACION_TOTAL);

    Evento evento1(
    {"Encuentras un bardo deambulando por la mazmorra, te quiere contar una",
     "historia. ¿La escuchas?                                                   ",
     ""},
    {"Tras escuchar la historia te sientes inspirado. Aumentan todos tus",
     "atributos.",
     ""},
    {"Has perdido mucho tiempo escuchando la historia y pronto va a anochecer,",
     "por lo que decides resguardarte en un refugio. No avanzas de piso.",
     ""},
    false,
    Evento::EventoPositivo::INCREMENTAR_ATRIBUTOS,
    Evento::EventoNegativo::NO_AVANZAR_PISO);

    Evento evento2(
    {"Encuentras una cueva de enanos, por dentro hay luz y parece que esta",
     "habitada. ¿Quieres entrar?                                                ",
     ""},
    {"Los enanos te invitan a comer y pasar la noche en la cueva. Recuperas un",
     "cuarto de tu vida maxima.",
     ""},
    {"No eres bienvenido y los enanos te echan a patadas. Pierdes un 10% de tu",
     "vida maxima.",
     ""},
     false,
     Evento::EventoPositivo::CURACION,
     Evento::EventoNegativo::PERDER_VIDA);

    Evento evento3(
    {"Encuentras una forja en el camino, observas que esta abierta y el herrero",
     "te ofrece sus servicios. ¿Aceptas su ayuda?                               ",
     ""},
    {"El herrero pone a punto tu equipo. Mejoras todos tus atributos.",
     "",
     ""},
    {"El herrero no tiene mucha experiencia y el estado de tu equipo empeora",
     "tras la puesta a punto. Tus atributos disminuyen.",
     ""},
     false,
     Evento::EventoPositivo::INCREMENTAR_ATRIBUTOS,
     Evento::EventoNegativo::DISMINUIR_ATRIBUTOS);

    Evento evento4(
    {"A lo lejos ves una caravana de mercaderes ambulantes. ¿Quieres acercarte y",
     "hacer negociaciones?",
     ""},
    {"Compras comida y varios utiles. Recuperas un uso de cada habilidad.",
     "",
     ""},
    {"Los mercaderes en realidad eran salteadores de caminos que habian robado",
     "los caballos. Te atacan y pierdes un 10% de vida.",
     ""},
     false,
     Evento::EventoPositivo::RECUPERAR_HABILIDADES,
     Evento::EventoNegativo::PERDER_VIDA);

    Evento evento5(
    {"Encuentras un claro en una zona frondosa con arboles y arbustos.",
     "¿Quieres descansar aqui?                                                  ",
     ""},
    {"Pasas la noche y te recuperas. Te curas un cuarto de la vida maxima. ",
     "",
     ""},
    {"Pasas la noche y al despertar te das cuenta que un grupo de duendes te han",
     "robado algunas de tus pertenencias. Decides ir al poblado mas cercano a",
     "reabastecerte. Has perdido mucho tiempo y no avanzas de piso."},
     false,
     Evento::EventoPositivo::CURACION,
     Evento::EventoNegativo::NO_AVANZAR_PISO);

    Evento evento6(
    {"Al fondo del piso observas una tenue luz. ¿Quieres acercarte para ver de  ",
     "que se trata?",
     ""},
    {"Resulta ser un espiritu de la montaña. Te otorga su bendicion y recuperas ",
     "un uso de cada habilidad.",
     ""},
    {"Resulta ser un farolillo que han colocado unos trasgos para tenderte una",
     "trampa. Te asaltan y consigues quitartelos de encima, pero tu armadura",
     "resulta dañada. Tus atributos disminuyen.                                 "},
     false,
     Evento::EventoPositivo::RECUPERAR_HABILIDADES,
     Evento::EventoNegativo::DISMINUIR_ATRIBUTOS);

    listaEventos.push_back(evento0);
    listaEventos.push_back(evento1);
    listaEventos.push_back(evento2);
    listaEventos.push_back(evento3);
    listaEventos.push_back(evento4);
    listaEventos.push_back(evento5);
    listaEventos.push_back(evento6);
}

Enemigo& Partida::generarEnemigo() {
    /* Si el piso actual es 1, devuelve enemigos de nivel 1 o 2*/
    if (getPisoActual() == 1) {
        int pisoAleatorio = Personaje::generarAleatorio(getPisoActual(),
                                                    getPisoActual() + 1) - 1;
        int numeroEnemigo = Personaje::generarAleatorio(
            0, listaEnemigos.at(pisoAleatorio).size() - 1);
        return (listaEnemigos.at(pisoAleatorio).at(numeroEnemigo));
    /* Si el piso actual es 10 devuelve enemigos de nivel 10*/
    } else if (getPisoActual() == 10) {
        int numeroEnemigo = Personaje::generarAleatorio(
            0, listaEnemigos.at(9).size() - 1);
        return (listaEnemigos.at(9).at(numeroEnemigo));
    } else {
        int pisoAleatorio = Personaje::generarAleatorio(getPisoActual() - 1,
                                                    getPisoActual() + 1) - 1;
        int numeroEnemigo = Personaje::generarAleatorio(
            0, listaEnemigos.at(pisoAleatorio).size() - 1);
        return (listaEnemigos.at(pisoAleatorio).at(numeroEnemigo));
    }
}

Evento& Partida::generarEvento() {
    if (getPisoActual() == 5) {
        return listaEventos.at(0);
    } else {
        int aleatorio = Personaje::tirarDado(6);
        return listaEventos.at(aleatorio);
    }
}

void Partida::generarEstadisticas() {
    std::string pantallaEstadisticas =
"┌──────────────────────────────────────────────────────────────────────────────┐\n"
"│                                                                              │\n"
"│                              ┌───────────────┐                               │\n"
"│                              │ ESTADISITICAS │                               │\n"
"│                              └───────────────┘                               │\n"
"│                                                                              │\n"
"│                                                                              │\n"
"│                                                                              │\n";
    pantallaEstadisticas.append(centrarTexto("Pisos superados:      " +
                                std::to_string(getPisoActual() - 1),
                                anchoPantalla, tuberia, tuberia) + "\n");
    pantallaEstadisticas.append(centrarTexto("", anchoPantalla, tuberia,
                                             tuberia) + "\n");
    pantallaEstadisticas.append(centrarTexto("Enemigos derrotados:  " +
                                std::to_string(getEnemigosDerrotados()),
                                anchoPantalla, tuberia, tuberia) + "\n");
    pantallaEstadisticas.append(centrarTexto("", anchoPantalla, tuberia,
                                             tuberia) + "\n");
    pantallaEstadisticas.append(centrarTexto("Eventos presenciados: " +
                                std::to_string(getEventosPresenciados()),
                                anchoPantalla, tuberia, tuberia) + "\n");
    pantallaEstadisticas.append(centrarTexto("", anchoPantalla, tuberia,
                                             tuberia) + "\n");
    pantallaEstadisticas.append(centrarTexto("  -Eventos exitosos:  " +
                                std::to_string(getEventosExitosos()),
                                anchoPantalla, tuberia, tuberia) + "\n");
    pantallaEstadisticas.append(centrarTexto("", anchoPantalla, tuberia,
                                             tuberia) + "\n");
    pantallaEstadisticas.append(centrarTexto("  -Eventos fallidos:  " +
                                std::to_string(getEventosFallidos()),
                                anchoPantalla, tuberia, tuberia) + "\n");
    pantallaEstadisticas.append(
"│                                                                              │\n"
"│                                                                              │\n"
"│                                                                              │\n"
"└──────────────────────────────────────────────────────────────────────────────┘\n");

    imprimirPantallaEstatica(pantallaEstadisticas);
}
