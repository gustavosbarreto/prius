#ifndef PRIUS_HPP
#define PRIUS_HPP

#include <QString>

class Application;

class Prius
{
public:
    Prius();

    void loadApplication(const QString &path);

private:
    Application *m_application;
};

#endif // PRIUS_HPP
