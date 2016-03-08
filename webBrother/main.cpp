#include <QApplication>
#include "browthermainwindow.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    BrotherMainWindow mainWindow;

    mainWindow.show();
    return app.exec();
}
