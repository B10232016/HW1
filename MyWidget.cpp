#include "MyWidget.h"

#include <iostream>
#include <QString>
#include <QStringList>

#include "Caesar.h"
#include "Monoalphabetic.h"
#include "Playfair.h"
#include "Autokey.h"
#include "Transposition.h"
#include "Product.h"

QString noSpace(QString str){
    QString qstr = "";

    for(int i = 0; i < str.length(); i++){
        if(str.at(i) != ' '){
            qstr = qstr + str.at(i);
        }
    }

    return qstr;
}

QString toCapital(QString str){
    QString str1 = noSpace(str);
    QString qstr = "";

    for(int i = 0; i < str1.length(); i++){
        if(i % 5 == 0 && i != 0){
            qstr = qstr + " ";
        }
        qstr = qstr + str1.at(i);
    }

    qstr = qstr.toUpper();

    return qstr;
}

void MyWidget::encryptBtnClicked(){
    if(cipherCombo->currentIndex() == 0){

        Caesar temp(noSpace(inputLine->text()).toStdString());
        temp.getkey(keyLine->text().toInt());
        outputLine->setText(toCapital(QString::fromStdString(temp.encrypt())));

    }else if(cipherCombo->currentIndex() == 1){

        Monoalphabetic temp(noSpace(inputLine->text()).toStdString());
        temp.get_key(noSpace(keyLine->text()).toStdString());
        std::cout << noSpace(keyLine->text()).toStdString();
        outputLine->setText(toCapital(QString::fromStdString(temp.encrypt())));

    }else if(cipherCombo->currentIndex() == 2){

        Playfair temp(noSpace(inputLine->text()).toStdString());
        temp.get_key(keyLine->text().toStdString());
        outputLine->setText(toCapital(QString::fromStdString(temp.encrypt())));

    }else if(cipherCombo->currentIndex() == 3){

        Autokey temp(noSpace(inputLine->text()).toStdString());
        temp.get_key(keyLine->text().toStdString());
        outputLine->setText(toCapital(QString::fromStdString(temp.encrypt())));

    }else if(cipherCombo->currentIndex() == 4){

        Transposition temp(noSpace(inputLine->text()).toStdString());
        QStringList sList = keyLine->text().split(" ");
        int *ptr = new int[sList.length()];
        for(int i = 0; i < sList.length(); i++){
            ptr[i] = sList.at(i).toInt();
        }
        temp.get_key(ptr,sList.length());
        outputLine->setText(toCapital(QString::fromStdString(temp.encrypt())));

    }else if(cipherCombo->currentIndex() == 5){

        Product temp(noSpace(inputLine->text()).toStdString());
        QStringList sList = keyLine->text().split(" ");
        int *ptr = new int[sList.length()];
        for(int i = 0; i < sList.length(); i++){
            ptr[i] = sList.at(i).toInt();
        }
        temp.get_key(ptr,sList.length());
        outputLine->setText(toCapital(QString::fromStdString(temp.encrypt())));

    }
}

void MyWidget::decryptBtnClicked(){
    if(cipherCombo->currentIndex() == 0){

        Caesar temp(noSpace(inputLine->text()).toStdString());
        temp.getkey(keyLine->text().toInt());
        outputLine->setText(toCapital(QString::fromStdString(temp.decrypt())));

    }else if(cipherCombo->currentIndex() == 1){
        //need to be modify
        Monoalphabetic temp(noSpace(inputLine->text()).toStdString());
        temp.get_key(noSpace(keyLine->text()).toStdString());
        outputLine->setText(toCapital(QString::fromStdString(temp.decrypt())));

    }else if(cipherCombo->currentIndex() == 2){

        Playfair temp(noSpace(inputLine->text()).toStdString());
        temp.get_key(keyLine->text().toStdString());
        outputLine->setText(toCapital(QString::fromStdString(temp.decrypt())));

    }else if(cipherCombo->currentIndex() == 3){

        Autokey temp(noSpace(inputLine->text()).toStdString());
        temp.get_key(keyLine->text().toStdString());
        outputLine->setText(toCapital(QString::fromStdString(temp.decrypt())));

    }else if(cipherCombo->currentIndex() == 4){

        Transposition temp(noSpace(inputLine->text()).toStdString());
        QStringList sList = keyLine->text().split(" ");

        int *ptr = new int[sList.length()];
        for(int i = 0; i < sList.length(); i++){
            ptr[i] = sList.at(i).toInt();
        }
        temp.get_key(ptr,sList.length());
        outputLine->setText(toCapital(QString::fromStdString(temp.decrypt())));

    }else if(cipherCombo->currentIndex() == 5){

        Product temp(noSpace(inputLine->text()).toStdString());
        QStringList sList = keyLine->text().split(" ");

        int *ptr = new int[sList.length()];
        for(int i = 0; i < sList.length(); i++){
            ptr[i] = sList.at(i).toInt();
        }
        temp.get_key(ptr,sList.length());
        outputLine->setText(toCapital(QString::fromStdString(temp.decrypt())));

    }
}

MyWidget::MyWidget(QWidget *parent) : QWidget(parent){
    setFixedSize(650,280);

    inputLabel = new QLabel(tr("Input:"),this);
    inputLabel->setGeometry(20,20,60,40);

    inputLine = new QLineEdit(this);
    inputLine->setGeometry(90,20,540,40);

    cipherLabel = new QLabel(tr("Method:"),this);
    cipherLabel->setGeometry(20,70,60,40);

    cipherCombo = new QComboBox(this);
    cipherCombo->setGeometry(90,70,540,40);
    cipherCombo->insertItem(0,"Caesar cipher");
    cipherCombo->insertItem(1,"Monoalphabetic cipher");
    cipherCombo->insertItem(2,"Playfair cipher");
    cipherCombo->insertItem(3,"Vernam proposed the autokey system");
    cipherCombo->insertItem(4,"Row transposition");
    cipherCombo->insertItem(5,"Product cipher");

    keyLabel = new QLabel(tr("Key:"),this);
    keyLabel->setGeometry(20,120,60,40);

    keyLine = new QLineEdit(this);
    keyLine->setGeometry(90,120,540,40);

    outputLabel = new QLabel(tr("Output:"),this);
    outputLabel->setGeometry(20,170,60,30);

    outputLine = new QLineEdit(this);
    outputLine->setGeometry(90,170,540,40);
    outputLine->setReadOnly(true);

    encryptBtn = new QPushButton(tr("Encrypt"),this);
    encryptBtn->setGeometry(20,220,300,40);
    connect(encryptBtn,SIGNAL(clicked()),this,SLOT(encryptBtnClicked()));

    decryptBtn = new QPushButton(tr("Decrypt"),this);
    decryptBtn->setGeometry(330,220,300,40);
    connect(decryptBtn,SIGNAL(clicked()),this,SLOT(decryptBtnClicked()));
}

/*
Need to be done:
Monoalphabetic cipher(encrypt) -> if key has the same letters
Autokey(decrypt) -> not correct
Product(decrypt) -> not correct
ui(maybe)
*/
