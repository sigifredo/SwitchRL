
#include<Label.hpp>

void Label::mouseDoubleClickEvent(QMouseEvent * event)
{
    emit doubleClick();
}
