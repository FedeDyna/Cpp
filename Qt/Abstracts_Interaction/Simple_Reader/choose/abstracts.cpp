#include "abstracts.h"
#include "ui_abstracts.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

abstracts::abstracts(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::abstracts)
{
    ui->setupUi(this);
}

abstracts::~abstracts()
{
    delete ui;
}

void abstracts::on_pushButton_clicked()
{    //getOpenFileName(this,title of file dialog,default folder to open, filter the type of files)
    QString filename = QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "/home",
                "All files (*.*);;Text File (*.txt);; PNG File (*.png);; Music File (*.mp3)"
                );

    QFile file( filename ); // this store the path of the file
    if (!file.open(QIODevice::ReadOnly) )
        QMessageBox::information(0, "info",file.errorString());

    QTextStream in(&file);

    ui->textBrowser->setText(in.readAll());


}
