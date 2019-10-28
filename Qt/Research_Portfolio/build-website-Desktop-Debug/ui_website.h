/********************************************************************************
** Form generated from reading UI file 'website.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEBSITE_H
#define UI_WEBSITE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_website
{
public:
    QWidget *centralWidget;
    QPushButton *kepler60;
    QPushButton *kepler30;
    QPushButton *kepler29;
    QPushButton *rem;
    QPushButton *bologna;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *website)
    {
        if (website->objectName().isEmpty())
            website->setObjectName(QString::fromUtf8("website"));
        website->resize(737, 489);
        centralWidget = new QWidget(website);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        kepler60 = new QPushButton(centralWidget);
        kepler60->setObjectName(QString::fromUtf8("kepler60"));
        kepler60->setGeometry(QRect(60, 100, 201, 51));
        kepler30 = new QPushButton(centralWidget);
        kepler30->setObjectName(QString::fromUtf8("kepler30"));
        kepler30->setGeometry(QRect(60, 160, 201, 51));
        kepler29 = new QPushButton(centralWidget);
        kepler29->setObjectName(QString::fromUtf8("kepler29"));
        kepler29->setGeometry(QRect(60, 220, 201, 51));
        rem = new QPushButton(centralWidget);
        rem->setObjectName(QString::fromUtf8("rem"));
        rem->setGeometry(QRect(60, 280, 201, 51));
        bologna = new QPushButton(centralWidget);
        bologna->setObjectName(QString::fromUtf8("bologna"));
        bologna->setGeometry(QRect(60, 340, 201, 51));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 20, 501, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("Abyssinica SIL"));
        font.setPointSize(22);
        label->setFont(font);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(330, 110, 331, 261));
        label_2->setPixmap(QPixmap(QString::fromUtf8("../figure2.png")));
        website->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(website);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 737, 25));
        website->setMenuBar(menuBar);
        mainToolBar = new QToolBar(website);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        website->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(website);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        website->setStatusBar(statusBar);

        retranslateUi(website);

        QMetaObject::connectSlotsByName(website);
    } // setupUi

    void retranslateUi(QMainWindow *website)
    {
        website->setWindowTitle(QApplication::translate("website", "website", 0, QApplication::UnicodeUTF8));
        kepler60->setText(QApplication::translate("website", "Kepler-60 : arXiv WebPage", 0, QApplication::UnicodeUTF8));
        kepler30->setText(QApplication::translate("website", "Kepler-30 : arXiv WebPage", 0, QApplication::UnicodeUTF8));
        kepler29->setText(QApplication::translate("website", "Kepler-29 : arXiv WebPage", 0, QApplication::UnicodeUTF8));
        rem->setText(QApplication::translate("website", "REM : arXiv WebPage", 0, QApplication::UnicodeUTF8));
        bologna->setText(QApplication::translate("website", "Physycom.com", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("website", "PORTFOLIO PANICHI FEDERICO", 0, QApplication::UnicodeUTF8));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class website: public Ui_website {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEBSITE_H
