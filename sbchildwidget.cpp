#include "sbchildwidget.h"
#include "ui_sbchildwidget.h"
#include <seccomp.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/prctl.h>

SBChildWidget::SBChildWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SBChildWidget)
{
    ui->setupUi(this);

    scmp_filter_ctx ctx;
    ctx = seccomp_init(SCMP_ACT_ALLOW);

    seccomp_rule_add(ctx, SCMP_ACT_KILL, SCMP_SYS(fork), 0);

    prctl(PR_SET_NO_NEW_PRIVS, 1, 0, 0, 0);

    seccomp_load(ctx);
    seccomp_release(ctx);

}

SBChildWidget::~SBChildWidget()
{
    delete ui;
}

void SBChildWidget::on_lineEdit_returnPressed()
{
    ui->webView->setUrl(QUrl(ui->lineEdit->text()));
}
