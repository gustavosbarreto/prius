#ifndef QMLVIEW_HPP
#define QMLVIEW_HPP

#include <platform.hpp>

class QQuickView;

class QmlView: public Platform
{
public:
    QmlView();

    void load(const QUrl &url);
    void show();
    void addModule(const QString &name, QObject *obj);

private:
    QQuickView *m_quickView;
};

#endif // QMLVIEW_HPP
