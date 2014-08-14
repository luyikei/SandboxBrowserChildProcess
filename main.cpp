#include "sbchildwidget.h"
#include <QApplication>
#include <QVBoxLayout>
#include <QX11EmbedWidget>
#include <QDebug>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString windowId(a.arguments()[1]);

    QVBoxLayout* layout = new QVBoxLayout;

    QX11EmbedWidget *embed = new QX11EmbedWidget;
    embed -> setMinimumSize(500,500);
    embed -> setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    SBChildWidget w;

    layout -> addWidget(&w);
    embed -> setLayout(layout);
    embed -> embedInto(windowId.toULong());
    embed -> show();

    return a.exec();
}
