#include "filesystem.hpp"

#include <QFile>
#include <QDir>

FileSystem::FileSystem(QObject *parent): QObject(parent)
{
}

QVariantMap FileSystem::info(const QString &path)
{
    QFileInfo info(path);

    QVariantMap map;
    map["size"] = info.size();
    map["isDir"] = info.isDir();
    map["isFile"] = info.isFile();

    return map;
}

bool FileSystem::exists(const QString &path)
{
    return QFileInfo(path).exists();
}

bool FileSystem::rm(const QString &path)
{
    return QFile::remove(path);
}

bool FileSystem::copy(const QString &src, const QString &dst)
{
    if (QFile::exists(dst)) {
        QFile::remove(dst);
    }

    return QFile::copy(src, dst);
}

QStringList FileSystem::list(const QString &path)
{
    return QDir(path).entryList(QStringList(), QDir::AllEntries | QDir::Hidden);
}

QByteArray FileSystem::readFile(const QString &path)
{
    QFile file(path);
    file.open(QFile::ReadOnly);
    return file.readAll();
}

bool FileSystem::writeFile(const QString &path, const QByteArray &data)
{
    QFile file(path);
    if (!file.open(QFile::WriteOnly)) {
        return false;
    }

    return file.write(data);
}

bool FileSystem::mkdir(const QString &path)
{
    return QDir().mkpath(path);
}

bool FileSystem::rmdir(const QString &path)
{
    return QDir().rmpath(path);
}
