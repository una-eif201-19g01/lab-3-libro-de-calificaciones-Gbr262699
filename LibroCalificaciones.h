/*
 * =====================================================================================
 *
 *       Filename:  LibroCalificaciones.h
 *
 *    Description:  Reporte de calificaciones
 *
 *        Created:  2019-08-12
 *
 *         Author:  Gaston  Berdasco romero
 *   Organization:  Universidad Nacional de Costa Rica
 *
 * =====================================================================================
 */


#ifndef CALIFICACIONES_LIBROCALIFICACIONES_H
#define CALIFICACIONES_LIBROCALIFICACIONES_H

#include <string>
#include<iostream>
using namespace std;

class LibroCalificaciones {
	static const int  ESTUDIANTES = 10;
	static const int EXAMENES = 3;
	int obtenerNotaMinima();
	int obtenerNotaMaxima();
	double obtenerPromedio(const int,const int);
	std ::string nombreCurso();
	int Calificaciones[ESTUDIANTES][EXAMENES];

public:

	LibroCalificaciones();
	LibroCalificaciones(const std::string& nombreCurso, int matrizCalificaciones[ESTUDIANTES][EXAMENES]);
	std::string obtenerReporteNotas();
	const std::string obtenerReporteNotasMaxMin();
	const std ::string getnombreCurso();
	void setnombreCurso(const string& nombreCurso);


};

#endif //CALIFICACIONES_LIBROCALIFICACIONES_H
