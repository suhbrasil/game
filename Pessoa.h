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
    friend ostream& operator<<(ostream& os, const Pessoa& dados) {
         os << dados.nome << "\n";
        return os;
    }
};
