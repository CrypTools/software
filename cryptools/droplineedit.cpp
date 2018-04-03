#include "droplineedit.h"

DropLineEdit::DropLineEdit(QWidget *parent) :
    QLineEdit(parent)
{
    setAcceptDrops(true);
    this->setReadOnly(true);
    this->setStyleSheet("QLineEdit { border: 2px solid gray ; border-radius: 8px ; padding: 0 6px }");
}

DropLineEdit::~DropLineEdit()
{
    if(!mFileName){
        delete mFileName;
    }
}

// **************************************** PROTECTED METHODS **************************************** //

void DropLineEdit::dragEnterEvent(QDragEnterEvent *event){
    this->setStyleSheet("QLineEdit { border: 3px solid black ; border-radius: 8px ; padding: 0 6px }");
    event->accept();
}
void DropLineEdit::dragLeaveEvent(QDragLeaveEvent *event){
    this->setStyleSheet("QLineEdit { border: 2px solid gray ; border-radius: 8px ; padding: 0 6px }");
    event->accept();
}

void DropLineEdit::dropEvent(QDropEvent *event){
    // Get the data. If multiple files are dropped, take only the first one and fetch save its info
    QList<QUrl> list = event->mimeData()->urls();
    QFileInfo * fileInfo = new QFileInfo(list.at(0).toLocalFile());

    qDebug() << fileInfo->absoluteFilePath();
    mFileName = new QString(fileInfo->absoluteFilePath());

    this->setText(fileInfo->fileName());
    this->setStyleSheet("QLineEdit { border: 2px solid gray ; border-radius: 8px ; padding: 0 6px }");
    event->accept();
}
