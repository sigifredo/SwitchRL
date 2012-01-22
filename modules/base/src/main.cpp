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

// Own
#include <Principal.hpp>

// Qt
#include <QApplication>
#include <QTextCodec>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QTextCodec * pCodec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForTr(pCodec);
    QTextCodec::setCodecForCStrings(pCodec);
    QTextCodec::setCodecForLocale(pCodec);

#ifdef _WIN32
    app.addLibraryPath(QCoreApplication::applicationDirPath());
#endif

    Principal p;
    p.setWindowTitle("SwitchRL");
    p.show();

    return app.exec();
}
