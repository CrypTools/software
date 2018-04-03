#ifndef BOUTONS_H
#define BOUTONS_H

#include <QAbstractButton>
#include <QPixmap>
#include <QString>
#include <QLabel>

class CustomButton : public QAbstractButton
{
Q_OBJECT

public:

  enum ButtonState
  {
    STATE_NORMAL, STATE_HOVERED, STATE_CLICKED
  };
//THE PIXMAP NAME SHALL NOT CONTAIN THE EXTENSION
//EXAMPLE: IMAGE.png -> IMAGE
  CustomButton(int buttonWidth, int buttonHeight, QWidget *parent = 0, QString buttonText = 0, QString pixmapName = 0,
               Qt::Alignment alignement = Qt::AlignCenter, QString textStyleSheet = "");
  ~CustomButton();

protected:
  void resizeEvent      (QResizeEvent *event);
  void paintEvent       (QPaintEvent  *event);
  void enterEvent       (QEvent       *event);
  void leaveEvent       (QEvent       *event);
  void mousePressEvent  (QMouseEvent  *event);
  void mouseReleaseEvent(QMouseEvent  *event);

private:
  QString m_buttonText;
  QString m_pixmapName;
  int m_buttonWidth;
  int m_buttonHeight;
  Qt::Alignment m_alignement;
  QString m_textStyleSheet;
  QLabel *m_label;
  ButtonState m_State  ;
  QPixmap    *m_Normal ;
  QPixmap    *m_Hovered;
  QPixmap    *m_Clicked;

  void InitPixmaps();
  void InitButton();
};

#endif // BOUTONS_H
