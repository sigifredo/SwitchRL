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

#include<Label.hpp>

void Label::mouseDoubleClickEvent(QMouseEvent * event)
{
    emit doubleClick();
}
