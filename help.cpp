#include "help.h"
#include "ui_help.h"

Help::Help(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Help)
{
    ui->setupUi(this);
    connect(ui->pushButton_2,&QPushButton::clicked,[=]{
        this->close();
        flag=true;
    });
}

Help::~Help()
{
    delete ui;
}
