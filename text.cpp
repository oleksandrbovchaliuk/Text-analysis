#include "text.h"
#include <QMessageBox>

text::text() {

}

QString text::GetString() {
    return sMainString;
}

void text::SetString(QString sMainString) {
    this->sMainString = sMainString;
}

QString text::CheckWords(QString sString) {
    char cArrayOfSymbol[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    sString = "Кількість літер у тексті\n";
    sMainString = sMainString.toUpper();
    int iArrayOfSymbol[26] = {0};
    for(unsigned i = 0; i < sizeof(cArrayOfSymbol); ++i) {
        int iCountOfSymbol = sMainString.count(cArrayOfSymbol[i]);
        iArrayOfSymbol[i] = iCountOfSymbol;
    }
    int iTmp = 0;
    char cTmp = 0;
    bool exit = false;
    while(!exit) {
        exit = true;
        for(unsigned i = 0; i < sizeof(cArrayOfSymbol)-1; ++i) {
            if(iArrayOfSymbol[i] < iArrayOfSymbol[i+1]) {
                iTmp = iArrayOfSymbol[i];
                cTmp = cArrayOfSymbol[i];
                iArrayOfSymbol[i] = iArrayOfSymbol[i+1];
                cArrayOfSymbol[i] = cArrayOfSymbol[i+1];
                iArrayOfSymbol[i+1] = iTmp;
                cArrayOfSymbol[i+1] = cTmp;
                exit = false;
            }
        }
    }
    for(unsigned i = 0; i < sizeof(cArrayOfSymbol)-1; ++i) {
        if(iArrayOfSymbol[i] != 0) {
            sString = sString + cArrayOfSymbol[i] +  " | " + QString::number(iArrayOfSymbol[i]) + "\n";
            //field->setText(sString);
        }
    }
    return sString;
}

QString text::CheckSigns(QString sString) {
    char cArrayOfSymbol[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
                            '!','@','#','$','%','^','&','?','*','(',')','-','_','+','{','}','[',']',';',':','"','<','>',',','.','/'};
    sString = "Всі символи які є у тексті\n";
    sMainString = sMainString.toUpper();
    int iArrayOfSymbol[52] = {0};
    for(unsigned i = 0; i <= sizeof(cArrayOfSymbol) - 1; ++i) {
        int iCountOfSymbol = sMainString.count(cArrayOfSymbol[i]);
        iArrayOfSymbol[i] = iCountOfSymbol;
    }
    int iTmp = 0;
    char cTmp = 0;
    bool exit = false;
       while(!exit) {
           exit = true;
           for(unsigned i = 0; i < sizeof(cArrayOfSymbol) - 1; ++i) {
               if(iArrayOfSymbol[i] < iArrayOfSymbol[i+1]) {
                   iTmp = iArrayOfSymbol[i];
                   cTmp = cArrayOfSymbol[i];
                   iArrayOfSymbol[i] = iArrayOfSymbol[i+1];
                   cArrayOfSymbol[i] = cArrayOfSymbol[i+1];
                   iArrayOfSymbol[i+1] = iTmp;
                   cArrayOfSymbol[i+1] = cTmp;
                   exit = false;
               }
           }
       }
       for(unsigned i = 0; i < sizeof(cArrayOfSymbol) - 1; ++i) {
           if(iArrayOfSymbol[i] != 0) {
               sString = sString + cArrayOfSymbol[i] +  " | " + QString::number(iArrayOfSymbol[i]) + "\n";
               //field->setText(sString);
           }
       }
       return sString;
}

QString text::ChangeWord(QTextEdit *field, QString sFindWord, QString sReplaceWord, QString sCountOfReplace) {
    int countZamin = 1;
    unsigned countWords = sMainString.split(" ").count();
    if(sMainString.contains(sFindWord, Qt::CaseInsensitive) == true) {
        for(unsigned i = 0; i < countWords; ++i) {
            int index1 = sMainString.indexOf(sFindWord);
            sMainString.replace(index1, sFindWord.length(), sReplaceWord);
            if(sMainString.contains(sFindWord, Qt::CaseInsensitive) == true) {
                countZamin++;
            }
        }
    }
    field->setText(sMainString);
    sCountOfReplace = "Кількість замін = " + QString::number(countZamin);
    return sCountOfReplace;
}

QString text::CalculationWord(QString QSwordCount) {
    sMainString = sMainString.simplified();
    sMainString.remove(QRegExp("\\s+$"));
    int iWordCount = sMainString.split(QRegExp("( {1,})+")).count();
    QSwordCount = "Кількість слів у тексті = " + QString::number(iWordCount);
    return QSwordCount;
}

QString text::Find10(QString s10Words) {
    sMainString = sMainString.toLower();
    QRegExp reg("[?!.;,:]");
    QRegExp reg2("\n");
    QRegExp reg3("\\s+");
    s10Words = "";
    sMainString = sMainString.replace(reg, "");
    sMainString = sMainString.replace(reg2, " ");
    sMainString = sMainString.replace(reg3, " ");

    QStringList allWords = sMainString.split(' ');
    if(allWords.count() < 10) {
        return s10Words;
    }
    else {
        QMap<QString, int> wordsMap;
        QStringList::const_iterator iter;
        QMap<QString, int>::iterator it;
        for(iter = allWords.constBegin(); iter != allWords.constEnd(); ++iter) {
            if(!wordsMap.contains(*iter)) {
                wordsMap.insert((*iter), 1);
            }
            else {
                wordsMap[*iter]++;
            }
        }
        int max = 0;
            for(it = wordsMap.begin(); it != wordsMap.end(); ++it) {
                if(it.value() > max) {
                    max = it.value();
                }
            }
            int count = 0;
            int countOfPrint = 0;
            while(count != 10) {
                for(it = wordsMap.begin(); it != wordsMap.end(); ++it) {
                    if((it.value() == max) && (count != 10)) {
                        s10Words = s10Words + "\n" + it.key() + " = " + QString::number(it.value());
                        countOfPrint++;
                        count++;
                    }
                }
                max--;
                if(max == 0) {
                    count = 10;
                }
            }
            if(countOfPrint < 10) {
                s10Words = " ";
                return s10Words;
            }
            else {
                return s10Words;
            }
    }
}
