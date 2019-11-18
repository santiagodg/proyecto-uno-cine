#ifndef HORA_H
#define HORA_H

#include <iostream>
using namespace std;

/**
 * clase Hora
 *
 * HORA
 * - hh: Integer
 * - mm: Integer
 *
 * Tiene constructor default, un constructor con todos los parámetros,
 * métodos de acceso y modificación para todos sus atributos y un método
 * muestra.
 */
class Hora
{
    private:
		/**
		 * Atributos
		 */
        int iHoras;
        int iMinutos;

    public:
		/**
		 * Constructor default
		 */
        Hora();

		/**
		 * Constructor con todos los parámetros
		 */
        Hora(int, int);

		/**
		 * Métodos de acceso
		 */
        int getHoras();
        int getMinutos();

		/**
		 * Métodos de modificación
		 */
        void setHoras(int);
        void setMinutos(int);

		/**
		 * Método muestra
		 */
        void toString();
};

Hora::Hora()
{
    iHoras = 0;
    iMinutos = 0;
}

Hora::Hora(int iH, int iM)
{
    iHoras = iH;
    iMinutos = iM;
}

int Hora::getHoras()
{
    return iHoras;
}

int Hora::getMinutos()
{
    return iMinutos;
}

void Hora::setHoras(int iH)
{
    iHoras = iH;
}

void Hora::setMinutos(int iM)
{
    iMinutos = iM;
}

void Hora::toString()
{
    cout << "Hora" << endl;
	cout << "  Horas: " << iHoras << endl;
	cout << "  Minutos: " << iMinutos << endl;
}

#endif
