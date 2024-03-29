#include "../../include/pantallaEvento.hpp"


std::string pantallaEvento(Evento& evento) {
    std::string pantalla =
"┌──────────────────────────────────────────────────────────────────────────────┐\n"
"│                                                                              │\n"
"│                                 ┌────────┐                                   │\n"
"│                                 │ EVENTO │                                   │\n"
"│                                 └────────┘                                   │\n"
"│                                                                              │\n"
"│┌─────────────────────────────────SUCESO─────────────────────────────────────┐│\n"
"││                                                                            ││\n";
    pantalla += tuberia + tuberia
             + alinearIzquierda(evento.getDescripcion()[0],
                                (anchoPantalla) - 4, " ", " ") + tuberia +
                                tuberia;
    pantalla += "\n";
    pantalla += tuberia + tuberia
             + alinearIzquierda(evento.getDescripcion()[1],
                                (anchoPantalla) - 4, " ", " ") + tuberia +
                                tuberia;
    pantalla += "\n";
    pantalla += tuberia + tuberia
             + alinearIzquierda(evento.getDescripcion()[2],
                                (anchoPantalla) - 4, " ", " ") + tuberia +
                                tuberia;
    pantalla += "\n";
    pantalla +=
"││                                                                            ││\n"
"│└────────────────────────────────────────────────────────────────────────────┘│\n"
"│┌───────────────────────────────RESULTADO────────────────────────────────────┐│\n"
"││                                                                            ││\n"
"││                                                                            ││\n"
"││                                                                            ││\n"
"││                                                                            ││\n"
"││                                                                            ││\n"
"│└────────────────────────────────────────────────────────────────────────────┘│\n"
"└──────────────────────────────────────────────────────────────────────────────┘\n";

    return pantalla;
}

std::string pantallaEventoResuelto(Evento& evento, int resolucion) {
    std::string pantalla =
"┌──────────────────────────────────────────────────────────────────────────────┐\n"
"│                                                                              │\n"
"│                                 ┌────────┐                                   │\n"
"│                                 │ EVENTO │                                   │\n"
"│                                 └────────┘                                   │\n"
"│                                                                              │\n"
"│┌─────────────────────────────────SUCESO─────────────────────────────────────┐│\n"
"││                                                                            ││\n";
    pantalla += tuberia + tuberia
             + alinearIzquierda(evento.getDescripcion()[0],
                                (anchoPantalla) - 4, " ", " ") + tuberia +
                                tuberia;
    pantalla += "\n";
    pantalla += tuberia + tuberia
             + alinearIzquierda(evento.getDescripcion()[1],
                                (anchoPantalla) - 4, " ", " ") + tuberia +
                                tuberia;
    pantalla += "\n";
    pantalla += tuberia + tuberia
             + alinearIzquierda(evento.getDescripcion()[2],
                                (anchoPantalla) - 4, " ", " ") + tuberia +
                                tuberia;
    pantalla += "\n";
    pantalla +=
"││                                                                            ││\n"
"│└────────────────────────────────────────────────────────────────────────────┘│\n"
"│┌───────────────────────────────RESULTADO────────────────────────────────────┐│\n"
"││                                                                            ││\n";
    if (resolucion == 0) {
        pantalla += tuberia + tuberia + alinearIzquierda(
            evento.getResultadoPositivo()[0], anchoPantalla - 4, " ", " ")
            + tuberia + tuberia;
        pantalla += "\n";
        pantalla += tuberia + tuberia + alinearIzquierda(
            evento.getResultadoPositivo()[1], anchoPantalla - 4, " ", " ")
            + tuberia + tuberia;
        pantalla += "\n";
        pantalla += tuberia + tuberia + alinearIzquierda(
            evento.getResultadoPositivo()[2], anchoPantalla - 4, " ", " ")
            + tuberia + tuberia;
        pantalla += "\n";
    } else if (resolucion == 1) {
        pantalla += tuberia + tuberia + alinearIzquierda(
            evento.getResultadoNegativo()[0], anchoPantalla - 4, " ", " ")
            + tuberia + tuberia;
        pantalla += "\n";
        pantalla += tuberia + tuberia + alinearIzquierda(
            evento.getResultadoNegativo()[1], anchoPantalla - 4, " ", " ")
            + tuberia + tuberia;
        pantalla += "\n";
        pantalla += tuberia + tuberia + alinearIzquierda(
            evento.getResultadoNegativo()[2], anchoPantalla - 4, " ", " ")
            + tuberia + tuberia;
        pantalla += "\n";
    }
    pantalla +=
"││                                                                            ││\n"
"│└────────────────────────────────────────────────────────────────────────────┘│\n"
"└──────────────────────────────────────────────────────────────────────────────┘\n";

    return pantalla;
}
