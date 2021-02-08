#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "text.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonLettersInTheText_clicked(){

    text tForm;
    QString sMainString = ui->mainTextEdit->toPlainText();
    try {
        if(sMainString.isEmpty()) {
            throw 12;
        }
        tForm.SetString(sMainString);
        QMessageBox::information(this, "Liter", tForm.CheckWords(" "));
    }
    catch(int i) {
        QMessageBox::critical(this, "Warning", "Немає тексту Помилка №" + QString::number(i));
    }
}

void MainWindow::on_pushButtonAllSymbol_clicked(){

    text tForm;
    QString sMainString = ui->mainTextEdit->toPlainText();;
    tForm.SetString(sMainString);
    try {
        if(sMainString.isEmpty()) {
            throw 14;
        }
        QMessageBox::information(this, "Liter", tForm.CheckSigns(" "));
    }
    catch(int i) {
        QMessageBox::critical(this, "Warning", "Немає тексту Помилка №" + QString::number(i));
    }
}

void MainWindow::on_pushButtonReplaceWord_clicked() {
    dialog1 = new Dialog1(this);
    if(dialog1->exec() == QDialog::Accepted) {
        text tForm;
        QString sMainString = ui->mainTextEdit->toPlainText();
        QString findWordss = dialog1->sFindWord();
        QString replaceWordss = dialog1->sReplaceWord();
        tForm.SetString(sMainString);

        try {
            if((findWordss.isEmpty() && replaceWordss.isEmpty()) || (sMainString.contains(findWordss, Qt::CaseInsensitive) == false)) {
                throw 10;
            }
            QMessageBox::information(this, "Count of replace", tForm.ChangeWord(ui->mainTextEdit, findWordss, replaceWordss, " "));
            sMainString = ui->mainTextEdit->toPlainText();
            tForm.SetString(sMainString);

            QMessageBox msgBox;
            msgBox.setText("Зберегти новий текст в файл?");
            msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
            msgBox.setIcon(QMessageBox::Information);
            msgBox.setDefaultButton(QMessageBox::Ok);
            int res = msgBox.exec();
            if (res == QMessageBox::Ok) {
                QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), QDir::currentPath(),
                                                                      tr("Text Files (*.txt)"));
                QFile fileOut(fileName);
                if(fileOut.open(QIODevice::WriteOnly | QIODevice::Text)) {
                    QTextStream writeStream(&fileOut);
                    writeStream << ui->mainTextEdit->toPlainText();
                    fileOut.close();
                }
            }
        }
        catch(int i) {
            QMessageBox::critical(this, "Warning", "Некоректно введені дані Помилка №" + QString::number(i));
        }



    }
}

void MainWindow::on_pushButtonCalculationWords_clicked() {
    text tForm;
    QString sMainString = ui->mainTextEdit->toPlainText();
    tForm.SetString(sMainString);
    try {
        if(sMainString.isEmpty()) {
            throw 14;
        }
        QMessageBox::information(this, "Calculation", tForm.CalculationWord(" "));
    }
    catch(int i) {
        QMessageBox::critical(this, "Warning", "Немає тексту Помилка №" + QString::number(i));
        }
}

void MainWindow::on_pushButtonReadFromFile_clicked() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "",
            tr("Text Files (*.txt)"));
    QFile file(fileName);
    if((file.exists()) && (file.open(QIODevice::ReadOnly))) {
        QString str = "";
        while(!file.atEnd()) {
            str=str+file.readLine();
            }
        ui->mainTextEdit->setText(str);
        file.close();
    }
}

void MainWindow::on_pushButton10Words_clicked() {
    text tForm;
    QString sMainString = ui->mainTextEdit->toPlainText();
    tForm.SetString(sMainString);
    try {
        if(sMainString.isEmpty()) {
            throw 16;
        }
        if(tForm.Find10(" ") == "") {
            throw 17;
        }
        if(tForm.Find10(" ") == " ") {
            throw 18;
        }
        QMessageBox::information(this, "10 Words", tForm.Find10(" "));
    }
    catch(int i) {
        QMessageBox::critical(this, "Warning", "Не коректний текст для функції Помилка №" + QString::number(i));
    }
}
