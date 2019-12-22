#include "qmlview.hpp"

#include <QQuickView>
#include <QQmlEngine>
#include <QQmlContext>

QmlView::QmlView()
{
    m_quickView = new QQuickView();
}

void QmlView::load(const QUrl &url)
{
    m_quickView->setSource(url);
}

void QmlView::show()
{
    m_quickView->show();
}

void QmlView::addModule(const QString &name, QObject *obj)
{
    m_quickView->engine()->rootContext()->setContextProperty(name, obj);
}
