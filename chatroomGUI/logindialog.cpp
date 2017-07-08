#include "logindialog.h"
#include "ui_logindialog.h"
#include <QPushButton>
#include <QGraphicsPixmapItem>
#include <QMessageBox>
#include <QString>
#include <string>
#include <chatroom.h>
extern User user;

void LoginDialog::on_loginbutton_clicked()
{
    QString QName=ui->lineEdit->text();
    std::string name=QName.toStdString();
    if (name.length()!=0&&name.find(' ') == std::string::npos&&name.length() <= 19)
    {
        accept();
    }

    //non-empty check
    else if (name.length()==0) QMessageBox::warning(this,
                                               QString::fromLocal8Bit("提示"),
                                               QString::fromLocal8Bit("昵称不可为空"),
                                               QMessageBox::Ok);
    //non-space check
    else if (name.find(' ') != std::string::npos) QMessageBox::warning(this,
                                                                     QString::fromLocal8Bit("提示"),
                                                                     QString::fromLocal8Bit("昵称中不可包含空格"),
                                                                     QMessageBox::Ok);
    //length check
    else if (name.length() > 19) QMessageBox::warning(this,
                                                         QString::fromLocal8Bit("提示"),
                                                         QString::fromLocal8Bit("昵称不可超过6个字"),
                                                         QMessageBox::Ok);
    user.SetName(name);
    user.SetUtfName(name);
}

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);

    ui->setupUi(this);

    ui->buttonBox->button(QDialogButtonBox::Ok)->setText(QString::fromLocal8Bit("确定"));
    ui->buttonBox->button(QDialogButtonBox::Cancel)->setText(QString::fromLocal8Bit("取消"));

    connect(ui->buttonBox->button(QDialogButtonBox::Ok),SIGNAL(clicked()),this,SLOT(on_loginbutton_clicked()));
}

LoginDialog::~LoginDialog()
{
    delete ui;
}
