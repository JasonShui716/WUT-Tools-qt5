#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "../../HttpReq.h"
#include "../../LoginReq.h"
#include "../../TimeTableReq.h"
#include "../../ScoreTableReq.h"
#include <QDebug>
#include <QDialog>


LoginWindow::LoginWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
//    pWebView->minimumSize(500, 500);

    pUserLineEdit = new QLineEdit(this);
    pPasswordLineEdit = new QLineEdit(this);
    pPasswordLineEdit->setEchoMode(QLineEdit::Password);

    pLoginButton = new QPushButton();
    pLoginButton->setText("登录");

    connect(pLoginButton, &QPushButton::clicked, this, &LoginWindow::login);

    pLayout = new QFormLayout();

    pLayout->addRow(QStringLiteral("学号："), pUserLineEdit);
    pLayout->addRow(QStringLiteral("教务系统密码:"), pPasswordLineEdit);
    pLayout->addRow(pLoginButton);
    pLayout->setAlignment(pLoginButton, Qt::AlignHCenter);
    pLayout->setAlignment(Qt::AlignVCenter);
    pLayout->setSpacing(10);
    pLayout->setMargin(50);
    setLayout(pLayout);
}

void LoginWindow::login(){
    HttpReq hr;
    LoginReq lr;
    TimeTableReq tr;
    ScoreTableReq sr;
    RETcode ret;
//    qDebug() << ((pUserLineEdit->text()).toStdString()).c_str() << endl;
    hr.globalInit();

    lr.QGetInfo((pUserLineEdit->text()).toStdString(), (pPasswordLineEdit->text()).toStdString());

    lr.makeForm();
    ret = lr.login("http://sso.jwc.whut.edu.cn/Certification//login.do");
    if (ret != 0)
        qDebug() << "Error in HttpReq::login(), info: " << findError(ret) << endl;

    ret = tr.enterPage("http://202.114.90.180/Course/");
    if (ret != 0)
        qDebug() << "Error in TimeTableReq::enterPage(), info: " << findError(ret) << endl;

    ret = tr.getTable("http://202.114.90.180/Course/grkbList.do", "TimeTable.html");
    if (ret != 0)
        qDebug() << "Error in TimeTableReq::getTable(), info: " << findError(ret) << endl;

    ret = sr.enterPage("http://202.114.90.180/Score/", "mid.html");
    if (ret != 0)
        qDebug() << "Error in ScoreTableReq::enterPage(), info: " << findError(ret) << endl;

    sr.getSnkey("mid.html");
    sr.makeForm();

    ret = sr.getTable("http://202.114.90.180/Score/lscjList.do", "ScoreTable.html");
    if (ret != 0)
        qDebug() << "Error in ScoreTableReq::getTable(), info: " << findError(ret) << endl;


}

LoginWindow::~LoginWindow()
{
    delete ui;
}
