#ifndef PROCESS_HPP
#define PROCESS_HPP

#include <QObject>
#include <QMap>
#include <QProcess>

class Process: public QObject
{
    Q_OBJECT

public:
    explicit Process(QObject *parent = 0);

public slots:
    qint64 exec(const QString &program, const QStringList &arguments);
    void kill(qint64 pid);
    void terminate(qint64 pid);

signals:
    void finished(qint64 pid, int exitCode, QProcess::ExitStatus exitStatus);
    void standardOutput(qint64 pid, const QByteArray &data);
    void standardError(qint64 pid, const QByteArray &data);

private:
    QMap<qint64, QProcess *> m_processes;
};

#endif // PROCESS_HPP
