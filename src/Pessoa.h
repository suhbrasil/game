#include "Menu.h"

class Pessoa
{
private:
    string nome;
public:
    Pessoa() {}
    ~Pessoa() {}

    string& getNome() { return nome; }
    void setNome(string& n) { nome = n; }
    // sobrecarga do operador de fluxo de saída
    // a função friend retorna uma refência para "ostream" que é uma das classes definidas em "iostream.h"
    friend ostream& operator<<(ostream& os, const Pessoa& dados) {
        // os é uma referência a "ostream"
         os << dados.nome << "\n";
        return os;
    }
};
