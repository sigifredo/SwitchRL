#ifndef BASE_ABOUT_HPP
#define BASE_ABOUT_HPP

// Own
#include<Export.hpp>

// Qt
#include<QDialog>

class QLabel;
class QTextEdit;
class QTabWidget;

/**
 * @class About
 * \brief Cuadro de dialogo "Acerca de..."
 *
 * Clase que inplementa un cuadro de dialogo con toda la información que se quiere mostrar al usuario acerca de nuestra aplicación.
 *
 */
class BASE_EXPORT About: public QDialog
{
    Q_OBJECT
public:

    /**
     * \brief Constructor de la clase.
     *
     */
    About(QWidget * pParent = 0);

    /**
     * \brief Agregamos un nuevo autor.
     *
     * @param sName Nombre del autor.
     * @param sTask Tarea/Cargo del autor.
     * @param sEmail Correo electrónico del autor.
     * @param sWebAddress Dirección web del autor.
     *
     */
    void addAuthor(const QString &sName, const QString &sTask, const QString &sEmail, const QString &sWebAddress = QString(""));

    /**
     * \brief Obtenemos el nombre de la aplicación.
     *
     * @return Nombre de la aplicación.
     *
     */
    QString appName() const;

    /**
     * \brief Establece la imagen que se mostrará en el cuadro de dialogo.
     *
     * @param sImagePath Ruta de la imagen a mostrar.
     *
     */
    void setImage(const QString &sImagePath);

protected:

    /**
     * Etiqueta con el icono de la empresa.
     */
    QLabel * _pIconLabel;

    /**
     * Etiqueta con la información de la aplicación, como la versión e información de la plataforma de desarrollo.
     */
    QLabel * _pAppInfoLabel;

    /**
     * Descripción de la aplicación, que estará en la pestaña "About".
     */
    QLabel * _pDescriptionLabel;

    /**
     * Información sobre los autores, que estará en la pestaña "Authors".
     */
    QLabel * _pAuthorsLabel;

    /**
     * Licencia de la aplicación.
     */
    QTextEdit * _pLicenceTextEdit;

    /**
     * Nombre de la aplicación.
     */
    QString _sAppName;

    /**
     * QTabWidget con toda la información del dialogo.
     */
    QTabWidget * _pTabWidget;

private:
    /**
     * \brief Instanciamos el ambiente gráfico.
     *
     */
    void init();
};

inline QString About::appName() const
{
    return _sAppName;
}

#endif
