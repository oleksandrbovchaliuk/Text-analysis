#ifndef TEXT_H
#define TEXT_H

#include <QString>
#include <QTextEdit>
#include <QFile>
#include <QDialog>
#include <QFileDialog>
#include <qdialog.h>
#include <QMainWindow>
#include "mainwindow.h"

class text {
private:
    QString sMainString;
public:
    text();
    void SetString(QString sMainString);
    QString GetString();
    QString CheckWords(QString sString);
    QString CheckSigns(QString sString);
    QString ChangeWord(QTextEdit *field, QString sFindWord, QString sReplaceWord, QString sCountOfReplace);
    QString Find10(QString s10Words);
    QString CalculationWord(QString QSwordCount);
};

#endif // TEXT_H
