#ifndef COMBATE
#define COMBATE

#include "partida.hpp"

/*
 * INICIAR_COMBATE
 *
 * Metodo que inicia un combate entre un Jugador y un Enemigo aleatorio.
 * Se pasa como parametro la Partida, y a partir de esta se obtienen todos los
 * datos necesarios.
 *
 * Es un bucle que dura hasta que uno de los Personajes muera. Cuando esto
 * suceda, se devuelve true si ha sobrevivido el Jugador y false en caso
 * contrario.
 */
bool iniciarCombate(Partida* partida);

#endif // COMBATE
