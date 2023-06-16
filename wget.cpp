#include "wget.h"
#include "ui_wget.h"
#include <QDebug>
#include <QStandardPaths>
#include <QCoreApplication>
#include <QProcess>
#include <QMessageBox>
#include <QString>
#include <QStringList>
#include <QDir>
#include <QFileDialog>

wget::wget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::wget)
{
    ui->setupUi(this);
}

wget::~wget()
{
    delete ui;
}

void wget::on_pushButton_Download_clicked()
{
    ui->pushButton_Download->setEnabled(false);
    if(ui->checkBox_Select_All->isChecked()){
        for(int i=0; i<=9; i++){
            QStringList link;
            link << ui->lineEdit_IP->text()+ ui->comboBox_File_Names->itemText(i);
            QProcess wget;
            wget.start("C:/Windows/System32/wget.exe", link);
            if(wget.waitForFinished()){
                    QMessageBox::information(this,"BİLGİ","İndirme Başarılı. " + ui->comboBox_File_Names->itemText(i), "Tamam");
            }
            else{
                QMessageBox::critical(this,"DİKKAT","İndirme başarısız.","Tamam");
            }
        }
        on_checkBox_Select_All_clicked();
    }

    else if(ui->checkBox_Select_File_Location->isChecked()){
        QStringList link;
        link << ui->lineEdit_IP->text();
        QProcess wget;
        wget.start("C:/Windows/System32/wget.exe", link);
        if(wget.waitForFinished()){
                QMessageBox::information(this,"BİLGİ","İndirme Başarılı. " + ui->lineEdit_IP->text(), "Tamam");
        }
        else{
            QMessageBox::critical(this,"DİKKAT","İndirme başarısız.","Tamam");
        }
        on_checkBox_Select_File_Location_clicked();
    }

    else if(ui->checkBox_Select_File->isChecked()){
        QStringList link;
        link << ui->lineEdit_IP->text()+ ui->comboBox_File_Names->currentText();
        QProcess wget;
        wget.start("C:/Windows/System32/wget.exe", link);
        if(wget.waitForFinished()){
                QMessageBox::information(this,"BİLGİ","İndirme Başarılı. " + ui->comboBox_File_Names->currentText(), "Tamam");
        }
        else{
            QMessageBox::critical(this,"DİKKAT","İndirme başarısız.","Tamam");
        }
        on_checkBox_Select_All_clicked();
    }
    ui->pushButton_Download->setEnabled(true);
    ui->lineEdit_IP->clear();
}

void wget::on_checkBox_Select_All_clicked()
{
    ui->comboBox_File_Names->clear();
    ui->comboBox_File_Names->addItem("/Logs/MertSerialUpdateLogger.txt");
    ui->comboBox_File_Names->addItem("/Logs/logger.txt");
    ui->comboBox_File_Names->addItem("/Logs/logger2.txt");
    ui->comboBox_File_Names->addItem("/Logs/logger2_port1.txt");
    ui->comboBox_File_Names->addItem("/Logs/logger2_port2.txt");
    ui->comboBox_File_Names->addItem("/Logs/logger2_port3.txt");
    ui->comboBox_File_Names->addItem("/Logs/logger_port1.txt");
    ui->comboBox_File_Names->addItem("/Logs/logger_port2.txt");
    ui->comboBox_File_Names->addItem("/Logs/logger_port3.txt");
    ui->comboBox_File_Names->addItem("/Logs/logger_port4.txt");
    ui->label_IP->setText("Enter IP Address");
    ui->lineEdit_IP->clear();
}

void wget::on_checkBox_Select_File_Location_clicked()
{
    ui->label_IP->setText("Enter File Location");
    ui->lineEdit_IP->clear();
    ui->comboBox_File_Names->clear();
}

void wget::on_checkBox_Select_File_clicked()
{
    ui->comboBox_File_Names->clear();
    ui->comboBox_File_Names->addItem("/Logs/MertSerialUpdateLogger.txt");
    ui->comboBox_File_Names->addItem("/Logs/logger.txt");
    ui->comboBox_File_Names->addItem("/Logs/logger2.txt");
    ui->comboBox_File_Names->addItem("/Logs/logger2_port1.txt");
    ui->comboBox_File_Names->addItem("/Logs/logger2_port2.txt");
    ui->comboBox_File_Names->addItem("/Logs/logger2_port3.txt");
    ui->comboBox_File_Names->addItem("/Logs/logger_port1.txt");
    ui->comboBox_File_Names->addItem("/Logs/logger_port2.txt");
    ui->comboBox_File_Names->addItem("/Logs/logger_port3.txt");
    ui->comboBox_File_Names->addItem("/Logs/logger_port4.txt");
    ui->label_IP->setText("Enter IP Address");
    ui->lineEdit_IP->clear();
}

