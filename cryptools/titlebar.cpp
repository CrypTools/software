#include "titlebar.h"

titleBar::titleBar(QWidget *parent) : QWidget(parent)
{
    minimizeButton = new WindowButton(WindowButton::BUTTON_MINIMIZE, this);
    maximizeButton = new WindowButton(WindowButton::BUTTON_MAXIMIZE, this);
    closeButton    = new WindowButton(WindowButton::BUTTON_CLOSE   , this);
    unmaximizeButton = new WindowButton(WindowButton::BUTTON_SETTINGS, this);

    titleWidget = new QLabel("Titre", this);
    titleWidget->setAlignment(Qt::AlignCenter);

    titleWidget->setStyleSheet("color: #2361c4; font-family: Helvetica; font-weight: bold; font-size: 24px");
    titleWidget->show();

    separator = new QLabel(this);
    separator->setPixmap(QPixmap(":/Icons/title_bar_separator.png"));
    separator->move(0, 30);

    title_bar_icon = new QLabel(this);
    title_bar_icon->move(3,2);

    m_last_time = QTime();
    m_last_time.start();
}

void titleBar::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    minimizeButton->move(width()-90,0);
    maximizeButton->move(width()-60,0);
    unmaximizeButton->move(width()-60,0);
    closeButton   ->move(width()-30,0);
    titleWidget->resize(width()-115, 30);
}

void titleBar::changeTitle(QString title)
{
    titleWidget->setText(title);
}

void titleBar::mouseMoveEvent(QMouseEvent *event)
{
    if (maximizeButton->isHidden())
        emit unmaximizeButton->clicked();
    emit movement(event);
}

void titleBar::mousePressEvent(QMouseEvent *event)
{
    emit clickMouseSignal(event);
    if (m_last_time.elapsed() < 600){
        if (maximizeButton->isHidden())
            emit unmaximizeButton->clicked();
        else
            emit maximizeButton->clicked();
        return;
    }
    m_last_time.restart();
}

void titleBar::mouseReleaseEvent(QMouseEvent *event)
{
    emit releaseMouseSignal(event);
}

void titleBar::setIcon(QPixmap icon)
{
    title_bar_icon->setPixmap(icon.scaled(30, 30));
    title_bar_icon->resize(30, 30);
}
