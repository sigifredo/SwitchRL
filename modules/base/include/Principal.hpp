
#ifndef BASE_PRINCIPAL_HPP
#define BASE_PRINCIPAL_HPP

// Own
#include<Export.hpp>

// Qt
#include<QWidget>

class Label;
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
     * \brief Agregamos un servidor.
     *
     */
    void agregar();

    /**
     * \brief Elimina un servidor de la lista.
     *
     */
    void eliminar();

    /**
     * \brief Iniciar el juego.
     *
     */
    void iniciarJuego();

    /**
     * \brief Llena la lista de servidores.
     *
     */
    void llenarLista();

    /**
     * \brief Cambiamos el directorio donde está guardado el juego.
     *
     */
    void cambiarDirectorio();

protected:

    /**
     * Mensaje que se mostrará al usuario indicando donde está el directorio.
     */
    Label * _pDirectorio;

    /**
     * Muestra el diálogo "Acerca de..."
     */
    QPushButton * _pAyuda;

    /**
     * Lista de servidores.
     */
    QListWidget * _pServidores;

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

    /**
     * Directorio del juego.
     */
    QString _sDirectorio;

};

#endif
