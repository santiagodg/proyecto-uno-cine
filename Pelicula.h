#ifndef PELICULA_H
#define PELICULA_H

#include <string>
using namespace std;

/**
 * clase Pelicula
 *
 * PELICULA
 * - numPeli: Integer
 * - titulo: String
 * - año: Integer
 * - duracion: Int
 * - genero: String
 * - listaActores: Integer[]
 * - cantidadActores: Integer
 *
 * Tiene un constructor default,
 */
class Pelicula
{
    private:

		/**
		 * Atributos
		 */
        int iNumPeli;
        string sTitulo;
        int iAno;
        int iDuracion;
        string sGenero;

		/**
		 * listaActores: Integer[]
		 *
		 * El atributo listaActores es un arreglo de 10 elementos, en este
		 * arreglo se almacena el id de los actores principales de la
		 * película.
		 */
        int iListaActores[10];

		/**
		 * cantidadActores: Integer
		 *
		 * El atributo catidadActores es para almacenar la cantidad de actores
		 * que hay en el arreglo listaActores.
		 */
        int iCantActores;

    public:

		/**
		 * El constructor default inicializa la película con la lista de
		 * actores vacía y valores default para los demás atributos.
		 */
        Pelicula();

		/**
		 * Métodos de acceso y modificación para sus atributos numPeli,
		 * titulo, año, duracion y género.
		 */
        int getNumPeli();
        string getTitulo();
        int getAno();
        int getDuracion();
        string getGenero();
        void setNumPeli(int);
        void setTitulo(string);
        void setAno(int);
        void setDuracion(int);
        void setGenero(string);

		/**
		 * El atributo cantidadActores solo tiene método de acceso, porque no
		 * es posible modificar la cantidad de actores directamente.
		 */
		int getCantActores();

		/**
		 * Método de acceso para el atributo listaActores, recibe como
		 * parámetro un índice de cuál actor (cuál subíndice del arreglo)
		 * se quiere accesar.
		 */
        int getIDActor(int);

		/**
		 * Método para agregar un actor a la lista de actores, este método
		 * recibe como parámetro el id del actor que se va a agregar.
		 * El método agrega el id del actor al arreglo listaActores y ajusta
		 * el atributo cantidadActores.
		 * Tiene como valor de retorno un valor booleano que indica si se pudo
		 * agregar o no el actor a la película, no se puede agregar si se
		 * duplica o si el arreglo ya tiene los 10 actores.
		 */
        bool agregarActor(int);
};

Pelicula::Pelicula()
{
    iNumPeli = -1;
    sTitulo = "N/A";
    iAno = -1;
    iDuracion = -1;
    sGenero = "N/A";
    iCantActores = 0;
}

int Pelicula::getNumPeli()
{
    return iNumPeli;
}

string Pelicula::getTitulo()
{
    return sTitulo;
}

int Pelicula::getAno()
{
    return iAno;
}

int Pelicula::getDuracion()
{
    return iDuracion;
}

string Pelicula::getGenero()
{
    return sGenero;
}

int Pelicula::getCantActores()
{
    return iCantActores;
}

void Pelicula::setNumPeli(int iNP)
{
    iNumPeli = iNP;
}

void Pelicula::setTitulo(string sT)
{
    sTitulo = sT;
}

void Pelicula::setAno(int iA)
{
    iAno = iA;
}

void Pelicula::setDuracion(int iD)
{
    iDuracion = iD;
}

void Pelicula::setGenero(string sG)
{
    sGenero = sG;
}

int Pelicula::getIDActor(int iIndice)
{
    return iListaActores[iIndice];
}

bool Pelicula::agregarActor(int iID)
{
    if (iCantActores < 10)
    {
        for (int i = 0; i < iCantActores; ++i)
        {
            if (iID == iListaActores[i])
            {
                return false;
            }
        }
        iListaActores[iCantActores] = iID;
        ++iCantActores;
        return true;
    }
    else
    {
        return false;
    }
}

#endif
