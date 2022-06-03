#pragma once

#include <iostream>


namespace entidades {

    class Entidades {
    
    protected:
        int x;
        int y;

    public:

        Entidades();
        ~Entidades();
        virtual void executar();


    
    };
}