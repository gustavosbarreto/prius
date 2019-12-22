#include "application.hpp"

#include <QJsonDocument>
#include <QFile>
#include <QDir>
#include <QJsonObject>
#include <QDebug>

Application::Application(const QString &manifestFilePath):
    m_manifestFilePath(manifestFilePath)
{
}

bool Application::parseManifest()
{
    QFile file(QDir(m_manifestFilePath).filePath("prius.json"));

    if (!file.open(QFile::ReadOnly)) {
        return false;
    }

    QJsonParseError error;
    QJsonDocument manifest = QJsonDocument::fromJson(file.readAll(), &error);

    if (error.error != QJsonParseError::NoError) {
        qDebug() << error.errorString();
        return false;
    } else {
        if (manifest.object().contains("main")) {
            m_main = manifest.object().value("main").toString();
        } else {
            return false;
        }

        if (manifest.object().contains("platform")) {
            m_platform = manifest.object().value("platform").toString();
        } else {
            return false;
        }

        return true;
    }
}
