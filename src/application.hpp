#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <QString>

class Application
{
public:
    Application(const QString &manifestFilePath);

    inline QString platform() const { return m_platform; }
    inline QString main() const { return m_main; }

    bool parseManifest();

private:
    QString m_manifestFilePath;
    QString m_platform;
    QString m_main;
};

#endif // APPLICATION_HPP
