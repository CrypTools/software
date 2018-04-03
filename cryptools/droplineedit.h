#ifndef DROPLINEEDIT_H
#define DROPLINEEDIT_H
//USED FOR DROPPING FILES IN A LINE EDIT
#include <QLineEdit>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QFileInfo>
#include <QString>
#include <QDebug>


class DropLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit DropLineEdit(QWidget *parent = 0);
    ~DropLineEdit();

protected:
    virtual void dragEnterEvent(QDragEnterEvent *event);
    virtual void dropEvent(QDropEvent *event);
    virtual void dragLeaveEvent(QDragLeaveEvent *event);

signals:

public slots:

private:

    QString * mFileName;

};

#endif // DROPLINEEDIT_H
