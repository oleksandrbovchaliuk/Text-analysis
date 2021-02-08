#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <mainwindow.h>
#include <QMainWindow>
#include "dialog1.h"
#include <QMessageBox>
#include <QTextStream>
#include <algorithm>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonLettersInTheText_clicked();

    void on_pushButtonAllSymbol_clicked();

    void on_pushButtonReplaceWord_clicked();

    void on_pushButtonCalculationWords_clicked();

    void on_pushButtonReadFromFile_clicked();

    void on_pushButton10Words_clicked();

private:
    Ui::MainWindow *ui;
    Dialog1 *dialog1;
};

#endif // MAINWINDOW_H
