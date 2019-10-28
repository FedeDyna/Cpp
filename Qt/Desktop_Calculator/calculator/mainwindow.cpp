#include "mainwindow.h"
#include "ui_mainwindow.h"

//#include <QDebug> // to test the connection between buttons

double firstNum; // global variable
bool userIsTypingSecondNumber = false; // to add two digits

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // associate a button press with calling the fuction
    connect(ui->pushButton_0, SIGNAL(released()),this,SLOT(digit_pressed())); // connect function, ui is a pointer to the user interface, it access all the labels ...
    connect(ui->pushButton_1, SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_2, SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_3, SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_4, SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_5, SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_6, SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_7, SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_8, SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_9, SIGNAL(released()),this,SLOT(digit_pressed()));
// connecting other buttons
    connect(ui->pushButton_plusminus, SIGNAL(released()),this,SLOT(unary_operation_pressed()));
    connect(ui->pushButton_percent, SIGNAL(released()),this,SLOT(unary_operation_pressed()));

    connect(ui->pushButton_add, SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_minus, SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_multiply, SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_divide, SIGNAL(released()),this,SLOT(binary_operation_pressed()));

    ui->pushButton_add->setCheckable(true); // to set the check
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_multiply->setCheckable(true);
    ui->pushButton_divide->setCheckable(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

// define the function definition
void MainWindow::digit_pressed()
{
//    qDebug() << "test"; // replacement of cout
    // to check which button is pressed
    QPushButton * button = (QPushButton*)sender();// sender return a pointer to Qpushbutton

    // to store the numbers
    double labelNumber;
    QString newLabel;

    // check flag to operations
    if (( ui->pushButton_add->isChecked() || ui->pushButton_divide->isChecked() ||
        ui->pushButton_multiply->isChecked() || ui->pushButton_minus->isChecked()) &&
            (!userIsTypingSecondNumber) )
    {
        labelNumber = button->text().toDouble(); // a new number stored in the double
        userIsTypingSecondNumber = true;
        // to avoid that 0.0 become 0 and I can't write 0.01
        newLabel = QString::number(labelNumber,'g',15); // static method to convert to a string. defult 6 digit
    }
    else
    {
        if (ui->label->text().contains('.') && button->text() == "0") // if it has a decimal and
        {
            newLabel = ui->label->text() + button->text();
        }
        else
        {
            labelNumber = (ui->label->text() + button->text()).toDouble();
            newLabel = QString::number(labelNumber,'g',15); // static method to convert to a string. defult 6 digit
        }
    }
    ui->label->setText(newLabel);
}

void MainWindow::on_pushButton_decimal_released()
{
    ui->label->setText(ui->label->text() + ".");
    // to avoid if the decimal is already there an if statmanet must be there
}


void MainWindow::unary_operation_pressed()
{

    QPushButton * button = (QPushButton*) sender(); // declare a button
    double labelNumber;
    QString newLabel;

    if (button->text() == "+/-")
    {
        labelNumber = ui->label->text().toDouble();
        labelNumber = labelNumber * -1; // to change sign
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
    }

    if (button->text() == "%")
    {
        labelNumber = ui->label->text().toDouble();
        labelNumber = labelNumber * 0.01; // to calculate the percent
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
    }

}

void MainWindow::on_pushButton_clear_released()
{
    // reset the variables in the code
    ui->pushButton_add->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_multiply->setChecked(false);
    ui->pushButton_divide->setChecked(false);

    userIsTypingSecondNumber = false;

    ui->label->setText("0");
}

void MainWindow::on_pushButton_equals_released()
{

    double labelNumber, secondNum;
    QString newLabel;

    // initialise secondNum
    secondNum = ui->label->text().toDouble(); // access the label, start from UI

    if (ui->pushButton_add->isChecked()) // to check which operation is selected
    {
        labelNumber = firstNum + secondNum;
        newLabel = QString::number(labelNumber,'g',15); // convert double to string
        ui->label->setText(newLabel);
        ui->pushButton_add->setChecked(false); // to uncheck the button after calculation
    }
    else if (ui->pushButton_minus->isChecked()) // to check which operation is selected
    {
        labelNumber = firstNum - secondNum;
        newLabel = QString::number(labelNumber,'g',15); // convert double to string
        ui->label->setText(newLabel);
        ui->pushButton_minus->setChecked(false); // to uncheck the button after calculation
    }
    else if (ui->pushButton_divide->isChecked()) // to check which operation is selected
    {
        labelNumber = firstNum / secondNum;
        newLabel = QString::number(labelNumber,'g',15); // convert double to string
        ui->label->setText(newLabel);
        ui->pushButton_divide->setChecked(false); // to uncheck the button after calculation
    }
    else if (ui->pushButton_multiply->isChecked()) // to check which operation is selected
    {
        labelNumber = firstNum * secondNum;
        newLabel = QString::number(labelNumber,'g',15); // convert double to string
        ui->label->setText(newLabel);
        ui->pushButton_multiply->setChecked(false); // to uncheck the button after calculation
    }

    userIsTypingSecondNumber = false;
}

void MainWindow::binary_operation_pressed()
{
    QPushButton * button = (QPushButton*) sender(); // declare a button

    // to check the number in the label

    firstNum = ui->label->text().toDouble();

    // and access it when we click equal

    button->setChecked(true); // set the check propriety to be true when a button is pressed, the propriery must be anable
}
