#include "custombutton.h"

#include <QPainter>
#include <QMouseEvent>

CustomButton::CustomButton(int buttonWidth, int buttonHeight, QWidget *parent, QString buttonText, QString pixmapName,
                           Qt::Alignment alignement, QString textStyleSheet) : QAbstractButton(parent),
  m_buttonText(buttonText),
  m_pixmapName(pixmapName),
  m_buttonWidth(buttonWidth),
  m_buttonHeight(buttonHeight),
  m_alignement(alignement),
  m_textStyleSheet(textStyleSheet),
  m_State  (STATE_NORMAL),
  m_Normal (NULL        ),
  m_Hovered(NULL        ),
  m_Clicked(NULL        )
{
  setAttribute(Qt::WA_TranslucentBackground);

  m_label = new QLabel(m_buttonText, this);
  m_label->setAlignment(m_alignement);
  if(!m_textStyleSheet.isEmpty())
      m_label->setStyleSheet(m_textStyleSheet);
}

CustomButton::~CustomButton()
{
  if(m_Normal  != NULL) delete m_Normal ;
  if(m_Hovered != NULL) delete m_Hovered;
  if(m_Clicked != NULL) delete m_Clicked;
}

void CustomButton::resizeEvent(QResizeEvent *event)
{
  Q_UNUSED(event);

  m_label->resize(m_buttonWidth, m_buttonHeight);
  InitPixmaps();
}

void CustomButton::paintEvent(QPaintEvent  *event)
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

void CustomButton::enterEvent(QEvent *event)
{
  Q_UNUSED(event);

  m_State = STATE_HOVERED;

  update();
}

void CustomButton::leaveEvent(QEvent *event)
{
  Q_UNUSED(event);

  m_State = STATE_NORMAL;

  update();
}

void CustomButton::mousePressEvent(QMouseEvent *event)
{
  QAbstractButton::mousePressEvent(event);

  m_State = STATE_CLICKED;

  update();
}

void CustomButton::mouseReleaseEvent(QMouseEvent *event)
{
  QAbstractButton::mouseReleaseEvent(event);

  if(underMouse()) m_State = STATE_HOVERED;
  else             m_State = STATE_NORMAL;

  update();
}

void CustomButton::InitPixmaps()
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

  InitButton();
}

void CustomButton::InitButton()
{
    *m_Normal = QPixmap(m_pixmapName+".png").scaled(m_buttonWidth, m_buttonHeight);
    *m_Hovered = QPixmap(m_pixmapName+"_hover.png").scaled(m_buttonWidth, m_buttonHeight);
    *m_Clicked = QPixmap(m_pixmapName+"_click.png").scaled(m_buttonWidth, m_buttonHeight);

    resize(m_buttonWidth, m_buttonHeight);
}
