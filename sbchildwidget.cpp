#include "sbchildwidget.h"
#include "ui_sbchildwidget.h"

SBChildWidget::SBChildWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SBChildWidget)
{
    ui->setupUi(this);
}

SBChildWidget::~SBChildWidget()
{
    delete ui;
}

void SBChildWidget::on_lineEdit_returnPressed()
{
    ui->webView->setUrl(QUrl(ui->lineEdit->text()));
}
