#ifndef BOUTONS_H
#define BOUTONS_H

#include <QAbstractButton>
#include <QPixmap>

class WindowButton : public QAbstractButton
{
Q_OBJECT

public:
  enum ButtonType
  {
    BUTTON_MINIMIZE, BUTTON_MAXIMIZE, BUTTON_CLOSE, BUTTON_SETTINGS
  };

  enum ButtonState
  {
    STATE_NORMAL, STATE_HOVERED, STATE_CLICKED
  };

  WindowButton(ButtonType type, QWidget *parent = 0);
  ~WindowButton();

protected:
  void resizeEvent      (QResizeEvent *event);
  void paintEvent       (QPaintEvent  *event);
  void enterEvent       (QEvent       *event);
  void leaveEvent       (QEvent       *event);
  void mousePressEvent  (QMouseEvent  *event);
  void mouseReleaseEvent(QMouseEvent  *event);

private:
  ButtonType  m_Type   ;
  ButtonState m_State  ;
  QPixmap    *m_Normal ;
  QPixmap    *m_Hovered;
  QPixmap    *m_Clicked;

  void InitPixmaps ();
  void InitMinimize();
  void InitMaximize();
  void InitClose   ();
  void InitSettings();
};

#endif // BOUTONS_H
