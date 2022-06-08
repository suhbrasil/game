#include "Ente.h"

Ente::Ente(const char* caminhoText) : caminho(caminhoText)
{
}
Ente::~Ente() {}

void Ente::desenharEnte() {
    grafico.desenhar(caminho);
}
