#ifndef ACTOR_H
#define ACTOR_H

#include <iostream>
#include <string>
using namespace std;

/**
 * clase Actor
 *
 * ACTOR
 * - id: Integer
 * - nombre: String
 *
 * Tiene constructor default, un constructor con todos los parámetros,
 * métodos de acceso y modificación para todos sus atributos y un método
 * muestra.
 */
class Actor
{
    private:
		/**
		 * Atributos
		 */
        int iID;
        string sNombre;

    public:
		/**
		 * Constructor default
		 */
        Actor();

		/**
		 * Constructor con todos los parámetros
		 */
        Actor(int, string);

		/**
		 * Métodos de acceso
		 */
        int getID();
        string getNombre();

		/**
		 * Métodos de modificación
		 */
        void setID(int);
        void setNombre(string);

		/**
		 * Método muestra
		 */
        void toString();
};

Actor::Actor()
{
    iID = -1;
    sNombre = "N/A";
}

Actor::Actor(int iID, string sN)
{
    this -> iID = iID;
    sNombre = sN;
}

int Actor::getID()
{
    return iID;
}

string Actor::getNombre()
{
    return sNombre;
}

void Actor::setID(int iID)
{
    this -> iID = iID;
}

void Actor::setNombre(string sN)
{
    sNombre = sN;
}

void Actor::toString()
{
    cout << "Actor" << endl;
    cout << "  ID: " << iID << endl;
    cout << "  Nombre: " << sNombre << endl;
}

#endif
