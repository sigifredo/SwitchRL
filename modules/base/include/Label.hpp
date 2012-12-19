/*
    Este programa es una utilidad libre para la administración sencilla de servidores para WoW.
    Copyright (C) 2012 Sigifredo Escobar Gómez (sigifredo89@gmail.com).

    Este programa es software libre: usted puede redistribuirlo y/o modificarlo
    bajo los términos de la Licencia Pública General GNU publicada
    por la Fundación para el Software Libre, ya sea la versión 3
    de la Licencia, o (a su elección) cualquier versión posterior.

    Este programa se distribuye con la esperanza de que sea Ãºtil, pero
    SIN GARANTÍA ALGUNA; ni siquiera la garantía implícita
    MERCANTIL o de APTITUD PARA UN PROPÓSITO DETERMINADO.
    Consulte los detalles de la Licencia Pública General GNU para obtener
    una información más detallada.

    Deberá haber recibido una copia de la Licencia Pública General GNU
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
     * @param sTexto Texto que se mostrará.
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
