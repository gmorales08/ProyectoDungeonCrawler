#include "../../include/evento.hpp"
#include "../../include/partida.hpp"

Evento::Evento(std::array<std::string, 3> descripcion,
               std::array<std::string, 3> resultadoPositivo,
               std::array<std::string, 3> resultadoNegativo,
               bool resultadoPositivoAsegurado,
               EventoPositivo eventoPositivo,
               EventoNegativo eventoNegativo) {
    setDescripcion(descripcion);
    setResultadoPositivo(resultadoPositivo);
    setResultadoNegativo(resultadoNegativo);
    setResultadoPositivoAsegurado(resultadoPositivoAsegurado);
    setEventoPositivo(eventoPositivo);
    setEventoNegativo(eventoNegativo);
}
Evento::Evento(std::array<std::string, 3> descripcion,
               std::array<std::string, 3> resultadoPositivo,
               bool resultadoPositivoAsegurado,
               EventoPositivo eventoPositivo) {
    setDescripcion(descripcion);
    setResultadoPositivo(resultadoPositivo);
    setResultadoPositivoAsegurado(resultadoPositivoAsegurado);
    setEventoPositivo(eventoPositivo);
}

/* Getters */
std::array<std::string, 3> Evento::getDescripcion() {
    return descripcion;
}
std::array<std::string, 3> Evento::getResultadoPositivo() {
    return resultadoPositivo;
}
std::array<std::string, 3> Evento::getResultadoNegativo() {
    return resultadoNegativo;
}
bool Evento::isResultadoPositivoAsegurado() {
    return resultadoPositivoAsegurado;
}
Evento::EventoPositivo Evento::getEventoPositivo() {
    return eventoPositivo;
}
Evento::EventoNegativo Evento::getEventoNegativo() {
    return eventoNegativo;
}
/* Fin getters */
/* Setters */
void Evento::setDescripcion(std::array<std::string, 3> _descripcion) {
    descripcion = _descripcion;
}
void Evento::setResultadoPositivo(std::array<std::string, 3> _resultado) {
    resultadoPositivo = _resultado;;
}
void Evento::setResultadoNegativo(std::array<std::string, 3> _resultado) {
    resultadoNegativo = _resultado;
}
void Evento::setResultadoPositivoAsegurado(bool _resultadoPositivoAsegurado) {
    resultadoPositivoAsegurado = _resultadoPositivoAsegurado;
}
void Evento::setEventoPositivo(Evento::EventoPositivo evento) {
    eventoPositivo = evento;
}
void Evento::setEventoNegativo(Evento::EventoNegativo evento) {
    eventoNegativo = evento;
}
/* Fin setters */

int Evento::aceptarEvento(Jugador& jugador, Partida* partida) {
    int salida = -1;
    if (isResultadoPositivoAsegurado() == true) {
        if (getEventoPositivo() == EventoPositivo::RECUPERACION_TOTAL) {
            /* Se cura toda la vida */
            jugador.aumentarVida(jugador.getVidaMaxima());
            /* Se recuperan los usos de habilidades */
            jugador.getHabilidades().at(0).setUsosRestantes(3);
            jugador.getHabilidades().at(1).setUsosRestantes(3);
            jugador.getHabilidades().at(2).setUsosRestantes(3);
            jugador.getHabilidades().at(3).setUsosRestantes(3);
            jugador.getHabilidades().at(4).setUsosRestantes(3);
        }
        salida = 0;
    } else {
        int resultado = Jugador::tirarDado(2); // 1 -> positivo, 2 -> negativo
        if (resultado == 1) {
            if (getEventoPositivo() == EventoPositivo::INCREMENTAR_ATRIBUTOS) {
                jugador.aumentarAtributos();
            } else if (getEventoPositivo() == EventoPositivo::CURACION) {
                jugador.aumentarVida(jugador.getVidaMaxima() / 4);
            } else if (getEventoPositivo() ==
                    EventoPositivo::RECUPERAR_HABILIDADES) {
                jugador.getHabilidades().at(0).setUsosRestantes(
                        jugador.getHabilidades().at(0).getUsosRestantes() + 1
                        );
                jugador.getHabilidades().at(1).setUsosRestantes(
                        jugador.getHabilidades().at(1).getUsosRestantes() + 1
                        );
                jugador.getHabilidades().at(2).setUsosRestantes(
                        jugador.getHabilidades().at(2).getUsosRestantes() + 1
                        );
                jugador.getHabilidades().at(3).setUsosRestantes(
                        jugador.getHabilidades().at(3).getUsosRestantes() + 1
                        );
                jugador.getHabilidades().at(4).setUsosRestantes(
                        jugador.getHabilidades().at(4).getUsosRestantes() + 1
                        );
            }
            salida = 0;
        } else if (resultado == 2) {
            if (getEventoNegativo() == EventoNegativo::DISMINUIR_ATRIBUTOS) {
                jugador.disminuirAtributos();
            } else if (getEventoNegativo() == EventoNegativo::PERDER_VIDA) {
                jugador.aumentarVida(-1 * (jugador.getVidaMaxima() / 10));
            } else if (getEventoNegativo() ==
                    EventoNegativo::NO_AVANZAR_PISO) {
                partida->retrocederPiso();
            }
            salida = 1;
        }
    }
    partida->setEventosPresenciados(partida->getEventosPresenciados() + 1);
    if (salida == 0) {
        partida->setEventosExitosos(partida->getEventosExitosos() + 1);
    } else if (salida == 1) {
        partida->setEventosFallidos(partida->getEventosFallidos() + 1);
    }

    return salida;
}
