#ifndef EVENTO
#define EVENTO

#include <array>
#include "jugador.hpp"
#include "partida.hpp"

/*
 * CLASE EVENTO
 *
 * Clase que contiene informacion sobre los eventos que se pueden producir
 * a lo largo de la partida.
 */
class Evento {
public:
    /* Enumerados para determinar que tipo de accion se realizara dependiendo
     * del resultado del evento
     */
    enum class EventoPositivo {
        INCREMENTAR_ATRIBUTOS,
        CURACION,
        RECUPERAR_HABILIDADES,
        RECUPERACION_TOTAL // Recupera vida y habilidades
    };

    enum class EventoNegativo {
        DISMINUIR_ATRIBUTOS,
        PERDER_VIDA,
        NO_AVANZAR_PISO
    };

    /* Constructor */
    Evento(std::array<std::string, 3> descripcion,
           std::array<std::string, 3> resultadoPositivo,
           std::array<std::string, 3> resultadoNegativo,
           bool resultadoPositivoAsegurado,
           EventoPositivo eventoPositivo,
           EventoNegativo eventoNegativo);
    /* Constructor alternativo para eventos con suceso positivo asegurado */
    Evento(std::array<std::string, 3> descripcion,
           std::array<std::string, 3> resultadoPositivo,
           std::array<std::string, 3> resultadoNegativo,
           bool resultadoPositivoAsegurado,
           EventoPositivo eventoPositivo);

    std::array<std::string, 3> getDescripcion();
    std::array<std::string, 3> getResultadoPositivo();
    std::array<std::string, 3> getResultadoNegativo();
    bool isResultadoPositivoAsegurado();
    EventoPositivo getEventoPositivo();
    EventoNegativo getEventoNegativo();

    void setDescripcion(std::array<std::string, 3> descripcion);
    void setResultadoPositivo(std::array<std::string, 3> resultado);
    void setResultadoNegativo(std::array<std::string, 3> resultado);
    void setResultadoPositivoAsegurado(bool resultado);
    void setEventoPositivo(EventoPositivo evento);
    void setEventoNegativo(EventoNegativo evento);
    /*
     * ACEPTAR_EVENTO
     *
     * Se determina si el evento sale bien o mal, y se aplican las
     * modificaciones correspondientes sobre el Jugador o la Partida.
     * Se devuelve el resultado para que pueda ser mostrado en la pantalla del
     * evento.
     */
    std::array<std::string, 3> aceptarEvento(Jugador& jugador,
                                             Partida& partida);

private:
    /* Descripcion contiene hasta 3 lineas con comentarios sobre el evento */
    std::array<std::string, 3> descripcion;
    /* Los mensaje sobre el resultado del evento tambien tienen 3 lineas */
    std::array<std::string, 3> resultadoPositivo;
    std::array<std::string, 3> resultadoNegativo;
    /* Resultado positivo asegurado se usa cuando la probabilidad de exito
     * es 100%
     */
    bool resultadoPositivoAsegurado;
    EventoPositivo eventoPositivo;
    EventoNegativo eventoNegativo;
};

#endif // EVENTO
