
#ifndef BASE_WINDOWNOTIFIER_HPP
#define BASE_WINDOWNOTIFIER_HPP

#ifdef _WIN32

// Own
#include<Export.hpp>

// Qt
#include<QWidget>

/**
 * Internal helper class that notifies windows if the
 * DWM compositing state changes and updates the widget
 * flags correspondingly.
 */
class BASE_EXPORT WindowNotifier : public QWidget
{
    //Q_OBJECT
public:
	WindowNotifier(QWidget * pParent = 0): QWidget(pParent) {
        winId();
    }
    void addWidget(QWidget *widget) {
        widgets.append(widget);
    }
    void removeWidget(QWidget *widget) {
        widgets.removeAll(widget);
    }
    bool winEvent(MSG *message, long *result);

private:
    QWidgetList widgets;
};

#endif

#endif
