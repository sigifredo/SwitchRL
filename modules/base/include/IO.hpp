
#ifndef BASE_IO_HPP
#define BASE_IO_HPP

// Own
#include<Export.hpp>

class QString;
class QStringList;

/**
 * \brief Elimina un servidor.
 *
 * @param sServidor Nombre del servidor a eliminar.
 *
 */
BASE_EXPORT bool eliminarServidor(const QString &sServidor);

/**
 * \brief Leemos el directorio donde está el juego.
 *
 */
BASE_EXPORT QString leerDirectorio();

/**
* \brief Guardamos el directorio donde está el juego.
*
* @param sDirectorio Ruta del directorio donde está el juego.
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
 * \brief Entregamos la lista de los servidores disponibles.
 *
 * @param servidores Lista de servidores.
 *
 */
BASE_EXPORT void leerServidores(QStringList &servidores);

/**
* \brief Escribe el archivo realmlist.wtf con el servidor pasado a la función.
*
* @param sdirectorio Ruta al directorio donde está el juego.
* @param sServidor Servidor a agregar en el realmlist.wtf
*
*/
BASE_EXPORT bool configurarJuego(QString sDirectorio, QString sServidor);

#endif
