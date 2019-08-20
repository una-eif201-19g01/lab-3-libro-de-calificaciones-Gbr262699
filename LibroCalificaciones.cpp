/*
 * =====================================================================================
 *
 *       Filename:  LibroCalificaciones.cpp
 *
 *    Description:  Reporte de calificaciones
 *
 *        Created:  2019-08-12
 *
 *         Author:  Gaston Berdasco Romero
 *   Organization:  Universidad Nacional de Costa Rica
 *
 * =====================================================================================
 */

#include "LibroCalificaciones.h"
#include <iomanip>
#include <iostream>

LibroCalificaciones::LibroCalificaciones() {
}

LibroCalificaciones::LibroCalificaciones(const std::string& nombreCurso, int matrizCalificaciones[ESTUDIANTES][EXAMENES])
{
	setnombreCurso(nombreCurso);

	for (int estudi = 0; estudi < ESTUDIANTES; ++estudi) {
		for (int exam = 0; exam < EXAMENES; ++exam) {
			Calificaciones[estudi][exam] = 0;
		}
	}
}






int LibroCalificaciones::obtenerNotaMinima()
{
	int notaMinima = 100;
	for (int estu = 0; estu < ESTUDIANTES; estu++) {
		for (int ex = 0; ex < EXAMENES; ex++) {
			if (Calificaciones[estu][ex] < notaMinima) {
				notaMinima = Calificaciones[estu][ex];
			}
		}
	}

	return notaMinima;
}


int LibroCalificaciones::obtenerNotaMaxima()
{
	int notaMaxima = 0;
	for (int estu = 0; estu < ESTUDIANTES; estu++) {
		for (int ex = 0; ex < EXAMENES; ex++) {
			if (Calificaciones[estu][ex] > notaMaxima) {
				notaMaxima = Calificaciones[estu][ex];
			}
		}
	}
	return notaMaxima;
}

double LibroCalificaciones::obtenerPromedio(const int estu,const int exam)
{
	float suma = 0;
	float promedio = 0;


	for (int exame = 0; exame < exam; exame++) {
		suma = suma + Calificaciones[estu][exame];

	}
	promedio = suma / 3;
	return promedio;
}



std::string LibroCalificaciones::obtenerReporteNotas()
{
	std::string reporteNotas = "\nLas siguientes son las notas del curso [Curso Progra I] :\n\t\t\t\Examen 1\tExamen 2\tExamen 3\tPromedio";
	for (int estu = 0; estu < ESTUDIANTES; estu++) {
		reporteNotas = reporteNotas + "\nEstudiante[" + std::to_string(estu) + "]\t\t" + std::to_string(Calificaciones[estu][0]) + "\t\t"
			+ std::to_string(Calificaciones[estu][1]) + "\t\t" + std::to_string(Calificaciones[estu][2]) + "\t\t"
			+ std::to_string(obtenerPromedio(estu, 3)) + "\t\t";
	}
	return reporteNotas;

}

const std::string LibroCalificaciones::obtenerReporteNotasMaxMin() {
	std::string reporte = "";

	reporte = "\n	Nota minima es: [" + std::to_string(obtenerNotaMinima()) + "]\n";
	reporte += "\n Nota maxima es: [" + std::to_string(obtenerNotaMaxima()) + "]\n";

	return reporte;
}

const std::string LibroCalificaciones::getnombreCurso()
{
	return nombreCurso;
}



void LibroCalificaciones::setnombreCurso(const std::string& nombreCurso)
{
	LibroCalificaciones::nombreCurso = nombreCurso;
}
