#include <QApplication>
#include "MainWindow.hpp"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow window;
    window.setWindowTitle("Role-Based Game");
    window.show();

    return app.exec();
}
