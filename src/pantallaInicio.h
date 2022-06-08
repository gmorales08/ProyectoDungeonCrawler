#ifndef PANTALLA_INICIO
#define PANTALLA_INICIO

#define FILAS 24                      // Numero de filas que va a tener la ventana de inicio
#define COLUMNAS 80                   // Numero de columnas que va a tener la ventana de inicio
#define CARACTER_HORIZONTAL       "─" ///////////////////
#define CARACTER_VERTICAL         "│" // Caracteres    //
#define CARACTER_ESQUINA_SUP_DCHA "┐" // para dibujar  //
#define CARACTER_ESQUINA_SUP_IZDA "┌" // los bordes    //
#define CARACTER_ESQUINA_INF_DCHA "┘" // de la ventana //
#define CARACTER_ESQUINA_INF_IZDA "└" ///////////////////


// IMPRIMIR PANTALLA INICIO
//
// Imprime una ventana de FILAS x COLUMNAS
//
// Las constantes FILAS y COLUMNAS valen por defecto 24 y 80 respectivamente
//
void imprimirPantallaInicio();

#endif //PANTALLA_INICIO

