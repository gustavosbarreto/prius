#include "prius.hpp"
#include "application.hpp"

#include <htmlview/htmlview.hpp>
#include <qmlview/qmlview.hpp>

#include <modules/filesystem.hpp>
#include <modules/process.hpp>

#include <QDir>
#include <QDebug>

Prius::Prius():
    m_application(NULL)
{
}

void Prius::loadApplication(const QString &path)
{
    if (m_application) {
        delete m_application;
    }

    m_application = new Application(path);

    if (!m_application->parseManifest()) {
        qDebug() << "Failed to load manifest file";
    }

    QDir::setCurrent(path);

    Platform *platform = NULL;

    if (m_application->platform() == "html") {
        platform = new HtmlView();
    } else if (m_application->platform() == "qml") {
        platform = new QmlView();
    }

    platform->addModule("ProcessAPI", new Process);
    platform->addModule("FileSystemAPI", new FileSystem);
    platform->load(m_application->main());
    platform->show();
}
