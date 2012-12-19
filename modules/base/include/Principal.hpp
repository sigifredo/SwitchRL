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
     * \brief Muestra el cuadro de di�logo "Acerca de..."
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
     * Etiqueta que indica que la lista situada a continuaci�n corresponde a los directorios del juego.
     */
    QLabel * _pDirectorio;

    /**
     * Etiqueta que indica que la lista situada a continuaci�n corresponde a los servidores del juego.
     */
    QLabel * _pServidor;

    /**
     * Muestra el di�logo "Acerca de..."
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
     * Bot�n para agregar directorio.
     */
    QPushButton * _pAgregarDirectorio;

    /**
     * Bot�n para eliminar directorio.
     */
    QPushButton * _pEliminarDirectorio;

    /**
     * Bot�n para agregar servidor.
     */
    QPushButton * _pAgregarServidor;

    /**
     * Bot�n para eliminar servidor.
     */
    QPushButton * _pEliminarServidor;

    /**
     * Bot�n para iniciar el juego.
     */
    QPushButton * _pIniciarJuego;

    /**
     * Espaciador usado para separar los botones _pAgregarServidor y _pEliminarServidor, de _pIniciarJuego.
     */
    QSpacerItem * _pSpacer;
};

#endif
