                            #ifndef DIALOG1_H
#define DIALOG1_H

#include <QDialog>
#include <QString>

namespace Ui {
class Dialog1;
}

class Dialog1 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog1(QWidget *parent = 0);
    ~Dialog1();
    QString sFindWord();
    QString sReplaceWord();

private:
    Ui::Dialog1 *ui;