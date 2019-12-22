#include <QApplication>
#include <QDir>
#include <QCommandLineParser>

#include "prius.hpp"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QCommandLineParser parser;
    parser.addHelpOption();
    parser.addPositionalArgument("path", "Path to directory containing prius.json file");
    parser.process(app);

    const QStringList args = parser.positionalArguments();

    Prius *prius = new Prius();
    prius->loadApplication(args.size() == 0 ? QDir::currentPath() : args[0]);

    return app.exec();
}
