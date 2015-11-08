#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

#include <iostream>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include "Caesar.h"
class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = 0);

    QLabel *inputLabel;
    QLabel *cipherLabel;
    QLabel *keyLabel;
    QLabel *outputLabel;

    QLineEdit *inputLine;
    QLineEdit *keyLine;
    QLineEdit *outputLine;

    QComboBox *cipherCombo;

    QPushButton *encryptBtn;
    QPushButton *decryptBtn;

private slots:
    void encryptBtnClicked();
    void decryptBtnClicked();
};

#endif // MYWIDGET_H
