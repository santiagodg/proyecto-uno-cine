#ifndef FUNCION_H
#define FUNCION_H

#include "Hora.h"

#include <iostream>
#include <string>
using namespace std;

/**
 * clase Funcion
 *
 * FUNCION
 * - cveFuncion: String
 * - numPeli: Integer
 * - hora: Hora
 * - sala: Int
 *
 * Tiene constructor default, un constructor con todos los parámetros,
 * métodos de acceso y modificación para todos sus atributos y un método
 * muestra.
 */
class Funcion
{
    private:
		/**
		 * Atributos
		 */
        string sClave;
        int iNumPeli;
        Hora hora;
        int iSala;

    public:
		/**
		 * Constructor default
		 */
        Funcion();

		/**
		 * Constructor con todos los parámetros
		 */
        Funcion(string, int, Hora, int);

		/**
		 * Métodos de acceso
		 */
        string getClave();
        int getNumPeli();
        Hora getHora();
        int getSala();

		/**
		 * Métodos de modificación
		 */
        void setClave(string);
        void setNumPeli(int);
        void setHora(Hora);
        void setSala(int);

		/**
		 * Método muestra
		 */
        void toString();
};

Funcion::Funcion()
{
    sClave = "N/A";
    iNumPeli = -1;
    iSala = -1;
}

Funcion::Funcion(string sC, int iNP, Hora hora, int iS)
{
    sClave = sC;
    iNumPeli = iNP;
    this -> hora = hora;
    iSala = iS;
}

string Funcion::getClave()
{
    return sClave;
}

int Funcion::getNumPeli()
{
    return iNumPeli;
}

Hora Funcion::getHora()
{
    return hora;
}

int Funcion::getSala()
{
    return iSala;
}

void Funcion::setClave(string sC)
{
    sClave = sC;
}

void Funcion::setNumPeli(int iNP)
{
    iNumPeli = iNP;
}

void Funcion::setHora(Hora hora)
{
    this -> hora = hora;
}

void Funcion::setSala(int iS)
{
    iSala = iS;
}

void Funcion::toString()
{
    cout << "Funcion" << endl;
    cout << "  Clave: " << sClave << endl;
    cout << "  Numero de Pelicula: " << iNumPeli << endl;
    cout << "  Hora: " << hora.getHoras() << ":" << hora.getMinutos() << endl;
    cout << "  Sala: " << iSala << endl;
}

#endif
