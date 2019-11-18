/**
 * Se incluyen las clases Pelicula, Actor, Funcion y Hora.
 */
#include "Pelicula.h"
#include "Actor.h"
#include "Funcion.h"
#include "Hora.h"

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	/**
	 * Se declaran arreglos de objetos de tipo Actor (con un máximo de 20
	 * actores), Funcion (con un máximo de 20 funciones) y Película (con un
	 * máximo de 20 películas).
	 */
	Actor actores[20];
	Funcion funciones[20];
	Pelicula peliculas[20];

	/**
	 * Se cargan los datos para el arreglo de Actores de un archivo de texto
	 * que contiene en cada renglón el id del Actor y el nombre del actor
	 * que es un string de varias palabras.
	 */
	ifstream ifActores;
	ifActores.open("Actores.txt");
	int iContadorActores = 0;
	while (!ifActores.eof() && iContadorActores < 20)
	{
		int iIDActor;
		string sNombreActor;
		ifActores >> iIDActor;
		ifActores.ignore();
		getline(ifActores, sNombreActor);
		actores[iContadorActores] = Actor(iIDActor, sNombreActor);
		++iContadorActores;
	}
	ifActores.close();

	/**
	 * Se cargan los datos para el arreglo de Películas de un archivo de texto
	 * que contiene en cada renglón el número de película, el año en que se
	 * hizo, su duración, su género, la cantidad de actores que se agregarán
	 * y la lista de id de los actores, y finalmente, el título de la película
	 * que es un string que puede contener varias palabras.
	 */
	ifstream ifPeliculas;
	ifPeliculas.open("Peliculas.txt");
	int iContadorPeliculas = 0;
	while (!ifPeliculas.eof() && iContadorPeliculas < 20)
	{
		int iNumPeli, iAno, iDuracion, iCantActores;
		string sGenero, sTitulo;
		ifPeliculas >> iNumPeli;
		ifPeliculas >> iAno;
		ifPeliculas >> iDuracion;
		ifPeliculas >> sGenero;
		ifPeliculas >> iCantActores;
		for (int j = 0; j < iCantActores; ++j)
		{
			int iIDActor;
			ifPeliculas >> iIDActor;
			peliculas[iContadorPeliculas].agregarActor(iIDActor);
		}
		ifPeliculas.ignore();
		getline(ifPeliculas, sTitulo);
		peliculas[iContadorPeliculas].setNumPeli(iNumPeli);
		peliculas[iContadorPeliculas].setAno(iAno);
		peliculas[iContadorPeliculas].setDuracion(iDuracion);
		peliculas[iContadorPeliculas].setGenero(sGenero);
		peliculas[iContadorPeliculas].setTitulo(sTitulo);
		++iContadorPeliculas;
	}
	ifPeliculas.close();

	/**
	 * Se pide al usuario que teclee los datos para cada una de las funciones
	 * disponibles del día.
	 * Se piden hasta que el usuario decida no dar de alta más funciones.
	 */
	int iContadorFunciones = 0;
	char cContinuar;
	do
	{
		string sClaveFuncion;
		int iNumPeli, iSala, iHoras, iMinutos;
		cout << "Ingrese la clave de la función: ";
		cin >> sClaveFuncion;
		bool bClaveEncontrada;
		do
		{
			bClaveEncontrada = false;
			for (int i = 0; i < iContadorFunciones; ++i)
			{
				if (sClaveFuncion == funciones[i].getClave())
				{
					bClaveEncontrada = true;
					cout << "Clave ya esta en uso." << endl;
					cout << "Ingrese otra clave: ";
					cin >> sClaveFuncion;
				}
			}
		} while (bClaveEncontrada);
		cout << "Ingrese el numero de pelicula: ";
		cin >> iNumPeli;
		bool bPeliEncontrada;
		do
		{
			bPeliEncontrada = false;
			for (int i = 0; i < iContadorPeliculas; ++i)
			{
				if (iNumPeli == peliculas[i].getNumPeli())
				{
					bPeliEncontrada = true;
					break;
				}
			}
			if (!bPeliEncontrada)
			{
				cout << "No se encontro pelicula." << endl;
				cout << "Ingrese otro numero de pelicula: ";
				cin >> iNumPeli;
			}
		} while (!bPeliEncontrada);
		cout << "Ingrese la hora (HH MM): ";
		cin >> iHoras >> iMinutos;
		while (!(0 <= iHoras && iHoras < 24 && 0 <= iMinutos && iMinutos < 60))
		{
			cout << "Hora invalida." << endl;
			cout << "Ingrese otra hora (HH MM): ";
			cin >> iHoras >> iMinutos;
		}
		Hora hora(iHoras, iMinutos);
		cout << "Ingrese la sala: ";
		cin >> iSala;
		bool bSalaOcupada;
		do
		{
			bSalaOcupada = false;
			for (int i = 0; i < iContadorFunciones; ++i)
			{
				if (iSala == funciones[i].getSala()
				  && hora.getHoras() == funciones[i].getHora().getHoras()
				  && hora.getMinutos() == funciones[i].getHora().getMinutos())
				{
					bSalaOcupada = true;
				}
			}
			if (bSalaOcupada)
			{
				cout << "La sala ya esta ocupada a esa hora." << endl;
				cout << "Ingrese otra sala: ";
				cin >> iSala;
			}
		} while (bSalaOcupada);
		funciones[iContadorFunciones] = Funcion(
			sClaveFuncion,
			iNumPeli,
			hora,
			iSala);
		++iContadorFunciones;
		cout << "Desea ingresar otra funcion? (y/n): ";
		cin >> cContinuar;
		while (cContinuar != 'Y'
		  && cContinuar != 'y'
		  && cContinuar != 'N'
		  && cContinuar != 'n')
		{
			cout << "Caracter invalido." << endl;
			cout << "Desea agregar otra funcion? (y/n): ";
			cin >> cContinuar;
		}
	} while (!(cContinuar == 'n' || cContinuar == 'N'));

	/**
	 * Menú
	 */
	char cOpcion = ' ';
	while (cOpcion != 'g')
	{
		cout << "MENU" << endl;
		cout << "a) Consulta de todos los actores" << endl;
		cout << "b) Consulta de todas las peliculas" << endl;
		cout << "c) Consulta de todas las funciones" << endl;
		cout << "d) Consulta funciones por hora" << endl;
		cout << "e) Consulta funcion por clave" << endl;
		cout << "f) Consulta peliculas de actor" << endl;
		cout << "g) Terminar" << endl;
		cout << "Ingrese la opcion deseada: ";
		cin >> cOpcion;

		switch (cOpcion)
		{
			/**
			 * a) Consulta de todos los actores que están en la lista.
			 * Muestra todos los datos del actor.
			 */
			case 'a':
			{
				for (int i = 0; i < iContadorActores; ++i)
				{
					actores[i].toString();
				}
				break;
			}

			/**
			 * b) Consulta de todas las películas que están en la lista.
			 * Muestra el título, año, duración, género y lista de los nombres
			 * de los actores que participan en una película.
			 */
			case 'b':
			{
				for (int i = 0; i < iContadorPeliculas; ++i)
				{
					cout << "Pelicula" << endl;
					cout << "  Titulo: " << peliculas[i].getTitulo() << endl;
					cout << "  Ano: " << peliculas[i].getAno() << endl;
					cout << "  Duracion: ";
					cout << peliculas[i].getDuracion() << endl;
					cout << "  Genero: " << peliculas[i].getGenero() << endl;
					cout << "  Actores:" << endl;
					for (int j = 0; j < peliculas[i].getCantActores(); ++j)
					{
						int iIDActor = peliculas[i].getIDActor(j);
						for (int k = 0; k < iContadorActores; ++k)
						{
							if (iIDActor == actores[k].getID())
							{
								cout << "    "
									<< actores[k].getNombre()
									<< endl;
								break;
							}
						}
					}
				}
				break;
			}

			/**
			 * c) Consulta de todas las funciones disponibles.
			 * Muestra la clave de la función, el nombre de la película,
			 * el número de sala en la que está y la hora a la que se presenta.
			 */
			case 'c':
			{
				for (int i = 0; i < iContadorFunciones; ++i)
				{
					cout << "Funcion" << endl;
					cout << "  Clave: " << funciones[i].getClave() << endl;
					cout << "  Nombre de Película: ";
					for (int j = 0; j < iContadorPeliculas; ++j)
					{
						Pelicula peli = peliculas[j];
						if (funciones[i].getNumPeli() == peli.getNumPeli())
						{
							cout << peli.getTitulo() << endl;
							break;
						}
					}
					cout << "  Sala: " << funciones[i].getSala() << endl;
					Hora hora = funciones[i].getHora();
					cout << "  Hora: ";
					if (hora.getHoras() < 10)
					{
						cout << "0";
						cout << hora.getHoras();
					}
					else
					{
						cout << hora.getHoras();
					}
					cout << ":";
					if (hora.getMinutos() < 10)
					{
						cout << "0";
						cout << hora.getMinutos() << endl;
					}
					else
					{
						cout << hora.getMinutos() << endl;
					}
				}
				break;
			}

			/**
			 * d) Consulta funciones por hora.
			 * Se pide al usuario la hora, verifica que sea válida, y muestra
			 * el título de la película y el número de sala de todas las
			 * funciones que se presentan en esa hora.
			 */
			case 'd':
			{
				int iHoras, iMinutos;
				cout << "Ingrese la hora (HH MM): ";
				cin >> iHoras >> iMinutos;
				while (!((-1 < iHoras && iHoras < 24)
				  && (-1 < iMinutos && iMinutos < 60)))
				{
					cout << "Hora invalida." << endl;
					cout << "Ingrese otra hora (HH MM): ";
					cin >> iHoras >> iMinutos;
				}
				Hora hora(iHoras, iMinutos);
				for (int i = 0; i < iContadorFunciones; ++i)
				{
					Hora hora2 = funciones[i].getHora();
					if (hora.getHoras() == hora2.getHoras() &&
						hora.getMinutos() == hora2.getMinutos())
					{
						cout << "Funcion" << endl;
						cout << "  Titulo de pelicula: ";
						for (int j = 0; j < iContadorPeliculas; ++j)
						{
							Pelicula peli = peliculas[j];
							if (funciones[i].getNumPeli() == peli.getNumPeli())
							{
								cout << peli.getTitulo() << endl;
								break;
							}
						}
						cout << "  Sala: " << funciones[i].getSala() << endl;
					}
				}
				break;
			}

			/**
			 * e) Consulta por clave de función.
			 * Se valida que la clave de la función exista y muestra en la
			 * pantalla el número de sala, el título de la película, la hora
			 * a la que se presenta, la duración, el género y los nombres de
			 * los actores que participan en la película.
			 */
			case 'e':
			{
				string sClave;
				cout << "Ingrese la clave: ";
				cin >> sClave;
				bool bEncontrado = false;
				for (int i = 0; i < iContadorFunciones; ++i)
				{
					Funcion func = funciones[i];
					if (sClave == func.getClave())
					{
						bEncontrado = true;
						cout << "Funcion" << endl;
						cout << "  Sala: " << func.getSala() << endl;
						cout << "  Titulo de pelicula: ";
						Pelicula peli;
						for (int j = 0; j < iContadorPeliculas; ++j)
						{
							if (func.getNumPeli() == peliculas[j].getNumPeli())
							{
								peli = peliculas[j];
								cout << peli.getTitulo() << endl;
								break;
							}
						}
						cout << "  Hora: ";
						Hora hora = func.getHora();
						if (hora.getHoras() < 10)
						{
							cout << "0";
							cout << hora.getHoras();
						}
						else
						{
							cout << hora.getHoras();
						}
						cout << ":";
						if (hora.getMinutos() < 10)
						{
							cout << "0";
							cout << hora.getMinutos() << endl;
						}
						else
						{
							cout << hora.getMinutos() << endl;
						}
						cout << "  Duracion: " << peli.getDuracion() << endl;
						cout << "  Genero: " << peli.getGenero() << endl;
						cout << "  Actores:" << endl;
						for (int j = 0; j < peli.getCantActores(); ++j)
						{
							int iIDActor = peli.getIDActor(j);
							for (int k = 0; k < iContadorActores; ++k)
							{
								Actor act = actores[k];
								if (iIDActor == act.getID())
								{
									cout << "    " << act.getNombre() << endl;
									break;
								}
							}
						}
						break;
					}
				}
				if (!bEncontrado)
				{
					cout << "No se encontro la funcion." << endl;
				}
				break;
			}

			/**
			 * f) Consulta la lista películas en las que participa un actor.
			 * Se pide el id del actor, se valida que exista, y se muestra
			 * en la pantalla el título y año de todas las películas en las
			 * que participa ese actor.
			 */
			case 'f':
			{
				int iIDActor;
				cout << "Ingrese el ID del actor: ";
				cin >> iIDActor;
				bool bEncontrado = false;
				for (int i = 0; i < iContadorPeliculas; ++i)
				{
					Pelicula peli = peliculas[i];
					for (int j = 0; j < peli.getCantActores(); ++j)
					{
						if (iIDActor == peli.getIDActor(j))
						{
							bEncontrado = true;
							cout << "Pelicula" << endl;
							cout << "  Titulo: " << peli.getTitulo() << endl;
							cout << "  Ano: " << peli.getAno() << endl;
							break;
						}
					}
				}
				if (!bEncontrado)
				{
					cout << "No se encontro al actor." << endl;
				}
				break;
			}

			/**
			 * g) Terminar
			 */
			case 'g':
			{
				break;
			}

			default:
			{
				cout << "Ingrese otra opcion (a-g): ";
				cin >> cOpcion;
				break;
			}
		}
	}

	return 0;
}
