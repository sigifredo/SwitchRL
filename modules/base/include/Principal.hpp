/*
    Este programa es una utilidad libre para la administración sencilla de servidores para WoW.
    Copyright (C) 2012 Sigifredo Escobar Gómez.

    Este programa es software libre: usted puede redistribuirlo y/o modificarlo
    bajo los términos de la Licencia Pública General GNU publicada
    por la Fundación para el Software Libre, ya sea la versión 3
    de la Licencia, o (a su elección) cualquier versión posterior.

    Este programa se distribuye con la esperanza de que sea útil, pero
    SIN GARANTÍA ALGUNA; ni siquiera la garantía implícita
    MERCANTIL o de APTITUD PARA UN PROPÓSITO DETERMINADO.
    Consulte los detalles de la Licencia Pública General GNU para obtener
    una información más detallada.

    Debería haber recibido una copia de la Licencia Pública General GNU
    junto a este programa.
    En caso contrario, consulte <http://www.gnu.org/licenses/>.
*/

#ifndef BASE_PRINCIPAL_HPP
#define BASE_PRINCIPAL_HPP

// Own
#include<Export.hpp>

// Qt
#include<QWidget>

class QLabel;
class QListWidget;
class QPushButton;
class QSpacerItem;

class BASE_EXPORT Principal: public QWidget
{
    Q_OBJECT

public:
    /**
     * \brief Constructor por defecto.
     *
     * @param pParent Puntero al objeto padre.
     *
     */
    Principal(QWidget * pPadre = 0);

public slots:

    /**
     * \brief Muestra el cuadro de diálogo "Acerca de..."
     *
     */
    void acercaDe();

    /**
     * \brief Agregamos un directorio.
     *
     */
    void agregarDirectorio();

    /**
     * \brief Elimina un directorio de la lista.
     *
     */
    void eliminarDirectorio();

    /**
     * \brief Agregamos un servidor.
     *
     */
    void agregarServidor();

    /**
     * \brief Elimina un servidor de la lista.
     *
     */
    void eliminarServidor();

    /**
     * \brief Iniciar el juego.
     *
     */
    void iniciarJuego();

    /**
     * \brief Llena la lista de directorios.
     *
     */
    void llenarListaDirectorios();

    /**
     * \brief Llena la lista de servidores.
     *
     */
    void llenarListaServidores();

protected:

    /**
     * Etiqueta que indica que la lista situada a continuación corresponde a los directorios del juego.
     */
    QLabel * _pDirectorio;

    /**
     * Etiqueta que indica que la lista situada a continuación corresponde a los servidores del juego.
     */
    QLabel * _pServidor;

    /**
     * Muestra el diálogo "Acerca de..."
     */
    QPushButton * _pAyuda;

    /**
     * Lista de directorios, en los cuales se encuentran las diferentes versiones del juego (WoW).
     */
    QListWidget * _pDirectorios;

    /**
     * Lista de servidores.
     */
    QListWidget * _pServidores;

    /**
     * Botón para agregar directorio.
     */
    QPushButton * _pAgregarDirectorio;

    /**
     * Botón para eliminar directorio.
     */
    QPushButton * _pEliminarDirectorio;

    /**
     * Botón para agregar servidor.
     */
    QPushButton * _pAgregarServidor;

    /**
     * Botón para eliminar servidor.
     */
    QPushButton * _pEliminarServidor;

    /**
     * Botón para iniciar el juego.
     */
    QPushButton * _pIniciarJuego;

    /**
     * Espaciador usado para separar los botones _pAgregarServidor y _pEliminarServidor, de _pIniciarJuego.
     */
    QSpacerItem * _pSpacer;
};

#endif
