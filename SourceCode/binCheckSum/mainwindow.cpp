#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_checkSum_clicked()
{
    QFile file(mFileInfo);

    BinFileSize = 0;
    progressNow = 0;
    QByteArray DataAllArray ;
    if(file.open(QIODevice::ReadOnly)){

        BinFileSize = file.size();
//      qDebug() << "Bin File Size = " << BinFileSize;
        DataAllArray.resize(BinFileSize);
        DataAllArray = file.readAll();
//      qDebug() << DataAllArray.toHex();
        QByteArray  mych = DataAllArray.toHex();

        unsigned int Totalsum= 0;
        unsigned char hb = 0;
        unsigned char lb = 0;
        for (int var = 0; var < BinFileSize*2; ++var) {
           if(mych[var] >= 97){
               mych[var] = mych[var] - 87;
           }else{
               mych[var] = mych[var] - 48;
           }
        }

        for (int var = 0; var < BinFileSize; ++var) {
            hb = mych[var*2]*16;
            lb = mych[var*2+1];
            Totalsum += hb + lb ;
        }
        //qDebug() << "check sum = " << Totalsum;
        QString str = QString::number(Totalsum,16);
        ui->textEdit_Sum->setText(str.toUpper());

    }else {
        QMessageBox mesg;
        mesg.critical(this,tr("Error"),tr("无法读取,请检查BIN文件路径!"));
    }



}

void MainWindow::on_pushButton_ChooseBinFile_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(
                           this,
                           tr("Select Bin file"),
                           "./",
                           tr("bin file(*.bin)"));
    if(fileName.isEmpty()){
        QMessageBox mesg;
        mesg.critical(this,tr("Error"),tr("打开Bin文件发生错误！"));
        return;
    }else{
        //qDebug()<< "path :" << fileName;
        ui->textEdit_binFileName->setText(fileName);
    }
    mFileInfo = fileName;


}

int MainWindow::StringHexToInt(char ch)
{
    int value = 0;

    if(ch >= '0' && ch <= '9'){

        value = ch - '0';

    }else if( ch >= 'A' && ch <= 'F'){

        value = ch - 'A' + 10;

    }else if( ch >= 'a' && ch <= 'f'){

        value = ch - 'a' + 10;

    }

    return value;

}

void MainWindow::updateProgressDialog()
{

}

