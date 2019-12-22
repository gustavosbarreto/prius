#ifndef HTMLVIEW_HPP
#define HTMLVIEW_HPP

#include <platform.hpp>

class QWebEngineView;
class QWebChannel;

class HtmlView: public Platform
{
public:
    HtmlView();

    void load(const QUrl &url);
    void show();
    void addModule(const QString &name, QObject *obj);

private:
    QWebEngineView *m_webView;
    QWebChannel *m_webChannel;

    void injectModules();
};

#endif // HTMLVIEW_HPP
