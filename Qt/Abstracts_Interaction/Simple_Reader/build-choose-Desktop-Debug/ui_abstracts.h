/********************************************************************************
** Form generated from reading UI file 'abstracts.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABSTRACTS_H
#define UI_ABSTRACTS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_abstracts
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QTextBrowser *textBrowser;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *abstracts)
    {
        if (abstracts->objectName().isEmpty())
            abstracts->setObjectName(QString::fromUtf8("abstracts"));
        abstracts->resize(410, 469);
        centralWidget = new QWidget(abstracts);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout->addWidget(textBrowser);

        abstracts->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(abstracts);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 410, 25));
        abstracts->setMenuBar(menuBar);
        mainToolBar = new QToolBar(abstracts);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        abstracts->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(abstracts);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        abstracts->setStatusBar(statusBar);

        retranslateUi(abstracts);

        QMetaObject::connectSlotsByName(abstracts);
    } // setupUi

    void retranslateUi(QMainWindow *abstracts)
    {
        abstracts->setWindowTitle(QApplication::translate("abstracts", "abstracts", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("abstracts", "OPEN FILE NAME", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class abstracts: public Ui_abstracts {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABSTRACTS_H
