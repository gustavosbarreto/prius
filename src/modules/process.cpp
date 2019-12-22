#include "process.hpp"

#include <QProcess>

Process::Process(QObject *parent): QObject(parent)
{
}

qint64 Process::exec(const QString &program, const QStringList &arguments)
{
    QProcess  *process = new QProcess();

    connect(process, static_cast<void(QProcess::*)(int, QProcess::ExitStatus)>(&QProcess::finished), [=](int exitCode, QProcess::ExitStatus exitStatus) {
        emit finished(process->pid(), exitCode, exitStatus);
    });

    connect(process, &QProcess::readyReadStandardOutput, [=]() {
        emit standardOutput(process->processId(), process->readAllStandardOutput());
    });

    connect(process, &QProcess::readyReadStandardError, [=]() {
        emit standardError(process->processId(), process->readAllStandardError());
    });

    process->start(program, arguments);

    qint64 pid = process->processId();

    bool started = process->waitForStarted();
    if (started) {
        m_processes[pid] = process;
    }

    return pid;
}

void Process::kill(qint64 pid)
{
    QProcess *process = m_processes[pid];
    if (process) {
        process->kill();
    }
}

void Process::terminate(qint64 pid)
{
    QProcess *process = m_processes[pid];
    if (process) {
        process->terminate();
    }
}
