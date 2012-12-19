
// Own
#include<About.hpp>
#include<QtWin.hpp>

// Qt
#include<QGridLayout>
#include<QLabel>
#include<QTextEdit>
#include<QTabWidget>
#include<QDialogButtonBox>

About::About():
    QDialog(pParent)
{
    init();

    QStringList idiomas;
    leerIdiomas(idiomas);

    QString sDescription = QString::fromUtf8("SwitchRL es una utilidad creada para todas aquellas personas que\njuegan en mas de un servidor de WoW. El programa administra de\nforma autom�tica el archivo \"realmlist.wtf\" para que el jugador no se\ntenga que preocupar por editar archivos para cambiar de servidor.\n\nEste programa es distribuido bajo licencia GPLv3, no hace parte de\nBlizzard, no modifica ninguna funcionalidad del juego.\n\nIdiomas soportados:\n" + idiomas.join(","));


    _sAppName = "SwitchRL";
    _pAppInfoLabel->setText("<font size=\"5\">" + sAppName + "</font><br><i>" + QString::fromUtf8("Versión ") + SWRL_VERSION "</i><br>Usando la biblioteca de desarrollo Qt " + qVersion());
    _pDescriptionLabel->setText(sDescription);
    setWindowTitle("Acerca de " + sAppName);
}

void About::addAuthor(const QString &sName, const QString &sTask, const QString &sEmail, const QString &sWebAddress)
{
    QString sAuthor = "<br><b>" + sName + "</b><br><i>" + sTask + "</i><br><font color=\"#0000ff\"><u>" + sEmail;
    if(sWebAddress.trimmed() != "")
        sAuthor += "<br>" + sWebAddress + "</u></font><br>";
    else
        sAuthor += "</u></font><br>";
    _pAuthorsLabel->setText(_pAuthorsLabel->text() + sAuthor);
}

void About::setImage(const QString &sImagePath)
{
    _pIconLabel->setPixmap(QPixmap(sImagePath));
}

void About::init()
{
    QGridLayout * pLayout = new QGridLayout(this);

    // Label donde estará el icono.
    _pIconLabel = new QLabel(this);
    _pIconLabel->setPixmap(QPixmap(QString::fromUtf8(":/GfifDev/logo90.png")));
    pLayout->addWidget(_pIconLabel, 0, 0, 1, 1);

    // Donde estará la información de la aplicación.
    _pAppInfoLabel = new QLabel(this);
    pLayout->addWidget(_pAppInfoLabel, 0, 1, 1, 1);

    // QTabWidget que tendrá la aplicación.
    _pTabWidget = new QTabWidget(this);

    // Pestaña de "Acerca de...". Aquí va la descripción.
    {
        QWidget * pAboutTab = new QWidget(_pTabWidget);
        QVBoxLayout * pAboutLayout = new QVBoxLayout(pAboutTab);
        _pDescriptionLabel = new QLabel(pAboutTab);
        pAboutLayout->addWidget(_pDescriptionLabel);
QSpacerItem * pSpacer = new QSpacerItem(10, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);
pAboutLayout->addItem(pSpacer);
        _pTabWidget->addTab(pAboutTab, "Acerca de...");
    }

    QDialogButtonBox * pButtonBox = new QDialogButtonBox(this);
    pButtonBox->setOrientation(Qt::Horizontal);
    pButtonBox->setStandardButtons(QDialogButtonBox::Close);

    pLayout->addWidget(pButtonBox, 2, 1, 1, 1);

    // Pestaña de autores
    {
        QWidget * pAuthorTab = new QWidget(_pTabWidget);
        QVBoxLayout * pAuthorsLayout = new QVBoxLayout(pAuthorTab);
        _pAuthorsLabel = new QLabel(pAuthorTab);
        addAuthor("Sigifredo Escobar Gómez", "Desarrollador", "sigifredo89@gmail.com", "sigifredo-eg.blogspot.com");
        pAuthorsLayout->addWidget(_pAuthorsLabel);
        QSpacerItem * pSpacer = new QSpacerItem(10, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);
        pAuthorsLayout->addItem(pSpacer);
        _pTabWidget->addTab(pAuthorTab, "Autores");
    }

    // Pestaña de licencia
    {
        QWidget * pLicenceTab = new QWidget(_pTabWidget);
        QVBoxLayout * pLicenceLayout = new QVBoxLayout(pLicenceTab);
        _pLicenceTextEdit = new QTextEdit(pLicenceTab);
        _pLicenceTextEdit->setReadOnly(true);
        QString str1 = QString::fromUtf8("\
Este programa es una utilidad libre para la administración sencilla de servidores para WoW.\n\
Copyright (C) 2012 Sigifredo Escobar Gómez.\n\
\n\
Este programa es software libre: usted puede redistribuirlo y/o modificarlo\n\
bajo los términos de la Licencia Pública General GNU publicada\n\
por la Fundación para el Software Libre, ya sea la versión 3\n\
de la Licencia, o (a su elección) cualquier versión posterior.\n\
\n\
Este programa se distribuye con la esperanza de que sea útil, pero\n\
SIN GARANTÍA ALGUNA; ni siquiera la garantía implícita\n\
MERCANTIL o de APTITUD PARA UN PROPÓSITO DETERMINADO.\n\
Consulte los detalles de la Licencia Pública General GNU para obtener\n\
una información más detallada.\n\
\n\
Debería haber recibido una copia de la Licencia Pública General GNU\n\
junto a este programa.\n\
En caso contrario, consulte <http://www.gnu.org/licenses/>.\n\
");
        _pLicenceTextEdit->setText(str1);
        pLicenceLayout->addWidget(_pLicenceTextEdit);
        _pTabWidget->addTab(pLicenceTab, "Licencia");
    }

    pLayout->addWidget(_pTabWidget, 1, 0, 1, 2);

    connect(pButtonBox, SIGNAL(rejected()), this, SLOT(reject()));

    // Transparencia (Solo Windows 7)
#ifdef _WIN32
	// verificamos que esté activada la transparencia en el sistema
    if(QtWin::isCompositionEnabled())
	{
        this->setAttribute(Qt::WA_TranslucentBackground);
        this->setAttribute(Qt::WA_NoSystemBackground, false);
        QPalette pal = this->palette();
        QColor bg = pal.window().color();
        bg.setAlpha(0x0);
        pal.setColor(QPalette::Window, bg);
        this->setPalette(pal);
        this->ensurePolished(); // workaround Oxygen filling the background
        this->setAttribute(Qt::WA_StyledBackground, false);

	    QtWin::extendFrameIntoClientArea(this);
	    this->setContentsMargins(0, 0, 0, 0);
	}
#endif
}
