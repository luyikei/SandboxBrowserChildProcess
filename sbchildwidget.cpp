#include "sbchildwidget.h"
#include "ui_sbchildwidget.h"
#include <seccomp.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/prctl.h>
#include <sys/stat.h>

#include <unistd.h>

#include <QKeyEvent>
#include <QMessageBox>
#include <pwd.h>
#include <grp.h>

#include <sys/time.h>
#include <sys/resource.h>

SBChildWidget::SBChildWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SBChildWidget)
{
    ui->setupUi(this);

    // seccomp
//    {
//        scmp_filter_ctx ctx;
//        ctx = seccomp_init(SCMP_ACT_ALLOW);

//        seccomp_rule_add(ctx, SCMP_ACT_KILL, SCMP_SYS(fork), 0);
//        seccomp_rule_add(ctx, SCMP_ACT_KILL, SCMP_SYS(write), 0);

//        prctl(PR_SET_NO_NEW_PRIVS, 1, 0, 0, 0);

//        seccomp_load(ctx);
//        seccomp_release(ctx);

//    }

    // rlimit
    {
//        struct rlimit nofile;
//        nofile.rlim_cur = 0;nofile.rlim_max=0;
//        setrlimit(RLIMIT_FSIZE, &nofile);
    }

    // setguid
    {
//        struct passwd *pw = NULL;
//        pw = getpwnam("sbchild");

//        if(pw == NULL)
//            return;

//        QMessageBox::warning(this, QString::number(getuid()), QString::number(getuid()));
//        setgid(pw->pw_gid);
//        setuid(pw->pw_uid);
//        QMessageBox::warning(this, QString::number(getuid()), QString::number(getuid()));

//        chroot("/tmp");
//        chdir ("/");
    }
    raise();
    activateWindow();
    setFocus();

    QCoreApplication::postEvent(ui->urlEdit,
                                new QFocusEvent(QEvent::FocusIn, Qt::OtherFocusReason));

}

SBChildWidget::~SBChildWidget()
{
    delete ui;
}

void SBChildWidget::on_urlsEdit_returnPressed()
{
    ui->webView->setUrl(QUrl(ui->urlEdit->text()));
}
