            #include "dialog1.h"
#include "ui_dialog1.h"

Dialog1::Dialog1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog1)
{
    ui->setupUi(this);
}

Dialog1::~Dialog1()
{
    delete ui;
}

QString Dialog1::sFindWord()
{
    return ui->findWord->toPlainText();
}

QString Dialog1::sReplaceWord()
{
    return ui->replaceWord->toPlain