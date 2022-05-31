#ifndef _IDSDESENHAVEIS_H_
#define _IDSDESENHAVEIS_H_

namespace entidades {
    // enum faz criar um tipo (nesse caso desenhaveis) que assume os valores colocados (jogador e inimigo nesse caso)
    // #define IDsDesenhaveis.jogador = 0
    // #define IDsDesenhaveis.inimigo = 1
    namespace IdsDesenhaveis {
        enum IdsDesenhaveis {
            jogador,
            inimigo,
            carta,
            gato
        };
    }
}

#endif
