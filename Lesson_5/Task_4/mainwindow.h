#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QComboBox>
#include <QMap>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onSendButtonClicked(); // Slot for processing button clicks

private:
    Ui::MainWindow *ui;

    // Виджеты
    QLineEdit *enterData;
    QTextEdit *userData;
    QPushButton *sendData;
    QComboBox *selectLang;

    QMap<QString, QStringList> badWordsMap; // Dictionary of bad words

    QString filterText(const QString &text, const QString &language); // Method for filtering text
    void loadBadWords(const QString &language); // Method to load bad words from a file
};

#endif // MAINWINDOW_H
