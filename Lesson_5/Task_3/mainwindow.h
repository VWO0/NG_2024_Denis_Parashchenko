#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void digits_numbers();
    void operation();
    void decimal();
    void clear();
    void equals();

private:
    Ui::MainWindow *ui;
    double firstNumber;
    QString currentOperator;
};
#endif // MAINWINDOW_H
