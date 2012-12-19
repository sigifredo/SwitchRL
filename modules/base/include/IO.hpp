/*
    Este programa es una utilidad libre para la administraci�n sencilla de servidores para WoW.
    Copyright (C) 2012 Sigifredo Escobar G�mez (sigifredo89@gmail.com).

    Este programa es software libre: usted puede redistribuirlo y/o modificarlo
    bajo los t�rminos de la Licencia P�blica General GNU publicada
    por la Fundaci�n para el Software Libre, ya sea la versi�n 3
    de la Licencia, o (a su elecci�n) cualquier versi�n posterior.

    Este programa se distribuye con la esperanza de que sea útil, pero
    SIN GARANT�A ALGUNA; ni siquiera la garant�a impl�cita
    MERCANTIL o de APTITUD PARA UN PROP�SITO DETERMINADO.
    Consulte los detalles de la Licencia P�blica General GNU para obtener
    una informaci�n m�s detallada.

    Deber� haber recibido una copia de la Licencia P�blica General GNU
    junto a este programa.
    En caso contrario, consulte <http://www.gnu.org/licenses/>.
*/

#ifndef BASE_IO_HPP
#define BASE_IO_HPP

// Own
#include<Export.hpp>

class QString;
class QStringList;

namespace IO
{

/**
 * \brief Elimina un servidor.
 *
 * @param sServidor Nombre del servidor a eliminar.
 *
 */
BASE_EXPORT bool eliminarServidor(const QString &sServidor);

/**
 * \brief Elimina un directorio de juego.
 *
 * @param sDirectorio Nombre del directorio a eliminar.
 *
 */
BASE_EXPORT bool eliminarDirectorio(const QString &Directorio);

/**
* \brief Guardamos el directorio donde está el juego.
*
* @param sDirectorio Ruta del directorio donde est� el juego.
*
*/
BASE_EXPORT bool guardarDirectorio(const QString &sDirectorio);

/**
 * \brief Guardamos un servidor.
 *
 * @param sServidor Servidor a guardar.
 *
 */
BASE_EXPORT bool guardarServidor(const QString &sServidor);

/**
 * \brief Leemos el directorio donde est� el juego.
 *
 * @param directorios Lista de directorios.
 *
 */
BASE_EXPORT QString leerDirectorio(const QString &directorio);

/**
 * \brief Leemos el directorio donde est� el juego.
 *
 * @param directorios Lista de directorios.
 *
 */
BASE_EXPORT void leerDirectorios(QStringList &directorios);

/**
 * \brief Entregamos la lista de los servidores disponibles.
 *
 * @param servidores Lista de servidores.
 *
 */
BASE_EXPORT void leerServidores(QStringList &servidores);

/**
* \brief Escribe el archivo realmlist.wtf con el servidor pasado a la funci�n.
*
* @param sdirectorio Ruta al directorio donde est� el juego.
* @param sServidor Servidor a agregar en el realmlist.wtf
*
*/
BASE_EXPORT bool configurarJuego(QString sDirectorio, QString sServidor);

}

#endif
