#ifndef SBCHILDWIDGET_H
#define SBCHILDWIDGET_H

#include <QWidget>
#include <QX11EmbedWidget>

namespace Ui {
class SBChildWidget;
}

class SBChildWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SBChildWidget(QWidget *parent = 0);
    ~SBChildWidget();

private slots:
    void on_lineEdit_returnPressed();

private:
    Ui::SBChildWidget *ui;
};

#endif // SBCHILDWIDGET_H
