#ifndef WGET_H
#define WGET_H

#include <QMainWindow>
#include <QProcess>

extern QString dir;

QT_BEGIN_NAMESPACE
namespace Ui { class wget; }
QT_END_NAMESPACE

class wget : public QMainWindow
{
    Q_OBJECT

public:
    wget(QWidget *parent = nullptr);
    ~wget();

private slots:
    void on_pushButton_Download_clicked();
    void on_checkBox_Select_All_clicked();
    void on_checkBox_Select_File_Location_clicked();

    void on_checkBox_Select_File_clicked();

private:
    Ui::wget *ui;

};
#endif // WGET_H
