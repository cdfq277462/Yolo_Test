#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_clicked()
{
    // open camera
    CamThread = new cameraThread();
    connect(CamThread, SIGNAL(framesReady(QImage,QImage)), this, SLOT(updateFrames(QImage,QImage)));
    CamThread->start();

}

void Dialog::updateFrames(QImage rgb, QImage depth)
{
    ui->label->setPixmap(QPixmap::fromImage(rgb));
}
