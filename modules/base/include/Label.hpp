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

#ifndef BASE_LABEL_HPP
#define BASE_LABEL_HPP

// Own
#include<Export.hpp>

// Qt
#include<QLabel>

class BASE_EXPORT Label: public QLabel
{
    Q_OBJECT

public:
    /**
     * \brief Constructor por defecto.
     *
     * @param sTexto Texto que se mostrar�.
     * @param pPadre Puntero al objeto padre.
     *
     */
    Label(const QString &sTexto = "", QWidget * pPadre = 0): QLabel(sTexto, pPadre) {}

signals:
    void doubleClick();

protected:
    /**
     * \brief Reescribimos el evento desde la clase base.
     *
     * @param event Manejador del evento.
     *
     */
    virtual void mouseDoubleClickEvent(QMouseEvent * event);
};

#endif
