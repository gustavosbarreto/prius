#include "htmlview.hpp"

#include <QWebEngineView>
#include <QWebEnginePage>
#include <QWebChannel>
#include <QWebEngineScript>
#include <QWebEngineScriptCollection>
#include <QFile>
#include <QDir>

HtmlView::HtmlView()
{
    m_webView = new QWebEngineView();
    m_webChannel = new QWebChannel();

    m_webView->page()->setWebChannel(m_webChannel);

    injectModules();
}

void HtmlView::load(const QUrl &url)
{
    m_webView->load(QUrl::fromUserInput(url.toString(), QDir::currentPath()));
}

void HtmlView::show()
{
    m_webView->show();
}

void HtmlView::addModule(const QString &name, QObject *obj)
{
    m_webChannel->registerObject(name, obj);
}

void HtmlView::injectModules()
{
    QFile webChannel(":/qtwebchannel/qwebchannel.js");
    if (!webChannel.open(QFile::ReadOnly)) {
        qFatal("Cannot open qwebchannel.js");
    }

    QByteArray webChannelData = webChannel.readAll();
    webChannelData.append(R"(
(window.onload = function() {
  window.onload = null;
  new QWebChannel(qt.webChannelTransport, function (channel) {
    for (var obj in channel.objects) {
      window[obj] = channel.objects[obj];
    }
    dispatchEvent(new Event('load'));
  });
})();
)");

    QWebEngineScript script;
    script.setSourceCode(webChannelData);
    script.setWorldId(QWebEngineScript::MainWorld);
    script.setInjectionPoint(QWebEngineScript::DocumentCreation);
    script.setRunsOnSubFrames(false);

    m_webView->page()->scripts().insert(script);
}
