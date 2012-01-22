
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
