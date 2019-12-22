#ifndef FILESYSTEM_HPP
#define FILESYSTEM_HPP

#include <QObject>
#include <QVariantMap>

class FileSystem: public QObject
{
    Q_OBJECT

public:
    explicit FileSystem(QObject *parent = 0);

public slots:
    QVariantMap info(const QString &path);
    bool exists(const QString &path);
    bool rm(const QString &path);
    bool copy(const QString &src, const QString &dst);
    QStringList list(const QString &path);
    QByteArray readFile(const QString &path);
    bool writeFile(const QString &path, const QByteArray &data);
    bool mkdir(const QString &path);
    bool rmdir(const QString &path);
};

#endif // FILESYSTEM_HPP
