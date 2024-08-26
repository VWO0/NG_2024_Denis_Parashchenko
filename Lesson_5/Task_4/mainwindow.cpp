#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFile>
#include <QTextStream>
#include <QDebug> // For using qWarning()

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create widgets
    enterData = new QLineEdit(this);
    userData = new QTextEdit(this);
    userData->setReadOnly(true);
    sendData = new QPushButton("Send", this);
    selectLang = new QComboBox(this);

    // Populate combo box with languages
    selectLang->addItems({"French", "Portuguese", "German", "Romanian", "Greek",
                          "Russian", "Hungarian", "Simplified Chinese", "Indonesian",
                          "Spanish", "Italian", "Swedish", "Japanese", "Traditional Chinese",
                          "Korean", "Thai", "Latin American Spanish", "Turkish",
                          "Norwegian", "Ukrainian", "Polish", "Vietnamese"});

    // Setup layout
    QVBoxLayout *mainLayout = new QVBoxLayout;
    QHBoxLayout *inputLayout = new QHBoxLayout;

    // Add widgets to layout
    inputLayout->addWidget(enterData);
    inputLayout->addWidget(sendData);
    mainLayout->addWidget(userData);
    mainLayout->addWidget(selectLang);
    mainLayout->addLayout(inputLayout);

    // Set the main layout in the central widget
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    // Connect button signal to slot
    connect(sendData, &QPushButton::clicked, this, &MainWindow::onSendButtonClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onSendButtonClicked() {
    QString text = enterData->text();
    QString language = selectLang->currentText();
    QString filteredText = filterText(text, language);
    userData->append(filteredText);
    enterData->clear();
}

QString MainWindow::filterText(const QString &text, const QString &language) {
    loadBadWords(language);
    QString result = text;
    QStringList badWords = badWordsMap.value(language);
    for (const QString &badWord : badWords) {
        result.replace(badWord, "X_X", Qt::CaseInsensitive);
    }
    return result;
}

void MainWindow::loadBadWords(const QString &language) {
    if (badWordsMap.contains(language)) {
        return; // Words are already loaded
    }

    QString fileName = QString("bad_words/filter_profanity_%1.txt").arg(language.toLower());
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        // qWarning() << "Failed to open file:" << fileName; // Commented out error output
        return;
    }

    QTextStream in(&file);
    QStringList badWords;
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (!line.isEmpty()) {
            badWords.append(line);
        }
    }
    file.close();

    badWordsMap.insert(language, badWords);
}
