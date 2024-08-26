#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->num_0, &QPushButton::clicked, this, &MainWindow::digits_numbers);
    connect(ui->num_1, &QPushButton::clicked, this, &MainWindow::digits_numbers);
    connect(ui->num_2, &QPushButton::clicked, this, &MainWindow::digits_numbers);
    connect(ui->num_3, &QPushButton::clicked, this, &MainWindow::digits_numbers);
    connect(ui->num_4, &QPushButton::clicked, this, &MainWindow::digits_numbers);
    connect(ui->num_5, &QPushButton::clicked, this, &MainWindow::digits_numbers);
    connect(ui->num_6, &QPushButton::clicked, this, &MainWindow::digits_numbers);
    connect(ui->num_7, &QPushButton::clicked, this, &MainWindow::digits_numbers);
    connect(ui->num_8, &QPushButton::clicked, this, &MainWindow::digits_numbers);
    connect(ui->num_9, &QPushButton::clicked, this, &MainWindow::digits_numbers);

    connect(ui->op_add, &QPushButton::clicked, this, &MainWindow::operation);
    connect(ui->op_subtract, &QPushButton::clicked, this, &MainWindow::operation);
    connect(ui->op_multiply, &QPushButton::clicked, this, &MainWindow::operation);
    connect(ui->op_divide, &QPushButton::clicked, this, &MainWindow::operation);
    connect(ui->op_decimal, &QPushButton::clicked, this, &MainWindow::decimal);
    connect(ui->op_clear, &QPushButton::clicked, this, &MainWindow::clear);
    connect(ui->op_equals, &QPushButton::clicked, this, &MainWindow::equals);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    QString buttonText = button->text();
    QString currentText = ui->result->text();

    if (currentText == "0" && buttonText != ".") {
        currentText = buttonText;
    } else {
        currentText += buttonText;
    }

    ui->result->setText(currentText);
}

void MainWindow::operation()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    QString op = button->text();
    firstNumber = ui->result->text().toDouble();
    currentOperator = op;
    ui->result->setText("0");
}

void MainWindow::decimal()
{
    QString currentText = ui->result->text();
    if (!currentText.contains('.')) {
        ui->result->setText(currentText + ".");
    }
}

void MainWindow::clear()
{
    ui->result->setText("0");
    firstNumber = 0;
    currentOperator.clear();
}

void MainWindow::equals()
{
    double secondNumber = ui->result->text().toDouble();
    double result = 0;

    if (currentOperator == "+") {
        result = firstNumber + secondNumber;
    } else if (currentOperator == "-") {
        result = firstNumber - secondNumber;
    } else if (currentOperator == "*") {
        result = firstNumber * secondNumber;
    } else if (currentOperator == "/") {
        if (secondNumber != 0) {
            result = firstNumber / secondNumber;
        } else {
            // Handle division by zero error
            ui->result->setText("Error");
            return;
        }
    }

    ui->result->setText(QString::number(result));
    firstNumber = result;
    currentOperator.clear();
}
