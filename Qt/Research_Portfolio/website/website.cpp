#include "website.h"
#include "ui_website.h"
#include <QDesktopServices>
#include <QUrl>
#include <QPixmap>


website::website(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::website)
{
    ui->setupUi(this);
    QPixmap pix("/home/fede/AVID/C++/Qt/Research_Portfolio/figure1.png");
    int w = ui->label_2->width();
    int h = ui->label_2->height();

    ui->label_2->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

website::~website()
{
    delete ui;
}

void website::on_kepler60_clicked()
{
    QString link="https://arxiv.org/abs/1510.02776";
    QDesktopServices::openUrl(QUrl(link));
}
void website::on_kepler30_clicked()
{
    QString link="https://arxiv.org/abs/1707.04962";
    QDesktopServices::openUrl(QUrl(link));
}
void website::on_kepler29_clicked()
{
    QString link="https://arxiv.org/abs/1609.09135";
    QDesktopServices::openUrl(QUrl(link));
}
void website::on_rem_clicked()
{
    QString link="https://arxiv.org/abs/1703.10596";
    QDesktopServices::openUrl(QUrl(link));
}
void website::on_bologna_clicked()
{
    QString link="http://www.physycom.unibo.it/index.php";
    QDesktopServices::openUrl(QUrl(link));
}


void website::on_pdf_k60_clicked()
{
    QString pathline="/home/fede/AVID/C++/Qt/Research_Portfolio/pdfs/kepler60.pdf";
    QDesktopServices::openUrl(QUrl(pathline));
}

void website::on_pdf_k30_clicked()
{
    QString pathline="/home/fede/AVID/C++/Qt/Research_Portfolio/pdfs/kepler30.pdf";
    QDesktopServices::openUrl(QUrl(pathline));
}

void website::on_pdf_k29_clicked()
{
    QString pathline="/home/fede/AVID/C++/Qt/Research_Portfolio/pdfs/kepler29.pdf";
    QDesktopServices::openUrl(QUrl(pathline));
}

void website::on_pdf_rem_clicked()
{
    QString pathline="/home/fede/AVID/C++/Qt/Research_Portfolio/pdfs/rem.pdf";
    QDesktopServices::openUrl(QUrl(pathline));
}
