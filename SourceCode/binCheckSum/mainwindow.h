#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include <QProgressDialog>
#include <QTimer>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void updateProgressDialog(void);
private slots:
    void on_pushButton_checkSum_clicked();

    void on_pushButton_ChooseBinFile_clicked();

    int StringHexToInt(char ch);


private:
    Ui::MainWindow *ui;
    QString mFileInfo;
    int progressNow;
    int BinFileSize;
};
#endif // MAINWINDOW_H
