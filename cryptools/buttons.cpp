#include "buttons.h"

#include <QPainter>
#include <QMouseEvent>

WindowButton::WindowButton(ButtonType type, QWidget *parent) : QAbstractButton(parent),
  m_Type   (type        ),
  m_State  (STATE_NORMAL),
  m_Normal (NULL        ),
  m_Hovered(NULL        ),
  m_Clicked(NULL        )
{
  setAttribute(Qt::WA_TranslucentBackground);
}

WindowButton::~WindowButton()
{
  if(m_Normal  != NULL) delete m_Normal ;
  if(m_Hovered != NULL) delete m_Hovered;
  if(m_Clicked != NULL) delete m_Clicked;
}

void WindowButton::resizeEvent(QResizeEvent *event)
{
  Q_UNUSED(event);

  InitPixmaps();
}

void WindowButton::paintEvent(QPaintEvent  *event)
{
  Q_UNUSED(event);

  QPainter painter(this);

  if(isEnabled())
  {
    switch(m_State)
    {
    case STATE_NORMAL:
      if(m_Normal  != NULL) painter.drawPixmap(0, 0, *m_Normal );
      break;
    case STATE_HOVERED:
      if(m_Hovered != NULL) painter.drawPixmap(0, 0, *m_Hovered);
      break;
    case STATE_CLICKED:
      if(m_Clicked != NULL) painter.drawPixmap(0, 0, *m_Clicked);
      break;
    }
  }
  else
  {
    if(m_Normal != NULL) painter.drawPixmap(0, 0, *m_Normal);
  }
}

void WindowButton::enterEvent(QEvent *event)
{
  Q_UNUSED(event);

  m_State = STATE_HOVERED;

  update();
}

void WindowButton::leaveEvent(QEvent *event)
{
  Q_UNUSED(event);

  m_State = STATE_NORMAL;

  update();
}

void WindowButton::mousePressEvent(QMouseEvent *event)
{
  QAbstractButton::mousePressEvent(event);

  m_State = STATE_CLICKED;

  update();
}

void WindowButton::mouseReleaseEvent(QMouseEvent *event)
{
  QAbstractButton::mouseReleaseEvent(event);

  if(underMouse()) m_State = STATE_NORMAL;
  else             m_State = STATE_NORMAL;

  update();
}

void WindowButton::InitPixmaps()
{
  // Delete previous button
  if(m_Normal  != NULL) delete m_Normal ;
  if(m_Hovered != NULL) delete m_Hovered;
  if(m_Clicked != NULL) delete m_Clicked;

  m_Normal  = new QPixmap(size());
  m_Hovered = new QPixmap(size());
  m_Clicked = new QPixmap(size());

  m_Normal ->fill(Qt::transparent);
  m_Hovered->fill(Qt::transparent);
  m_Clicked->fill(Qt::transparent);

  switch(m_Type)
  {
  case BUTTON_MINIMIZE:
    InitMinimize();
    break;
  case BUTTON_MAXIMIZE:
    InitMaximize();
    break;
  case BUTTON_CLOSE:
    InitClose();
    break;
  case BUTTON_SETTINGS:
    InitSettings();
      break;
  }
}

void WindowButton::InitMinimize()
{
  /****************************/
  *m_Normal  = QPixmap(":/Icons/minimize.png");
  /********** Hovered **********/
  *m_Hovered = QPixmap(":/Icons/minimize_hover.png");
  /*****************************/

  /********** Clicked **********/
  *m_Clicked = QPixmap(":/Icons/minimize_click.png");
  /*****************************/
}

void WindowButton::InitMaximize()
{
  *m_Normal = QPixmap(":/Icons/maximize.png");
  *m_Hovered = QPixmap(":/Icons/maximize_hover.png");
  *m_Clicked = QPixmap(":/Icons/maximize_click.png");
}

void WindowButton::InitClose()
{
  *m_Normal = QPixmap(":/Icons/close.png");
  *m_Hovered = QPixmap(":/Icons/close_hover.png");
  *m_Clicked = QPixmap(":/Icons/close_click.png");
}

void WindowButton::InitSettings()
{
  *m_Normal = QPixmap(":/Icons/unmaximize.png");
  *m_Hovered = QPixmap(":/Icons/unmaximize_hover.png");
  *m_Clicked = QPixmap(":/Icons/unmaximize_click.png");
  resize(30,30);
}
