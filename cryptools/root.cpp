#include "root.h"

root::root()
{
    setWindowTitle("cryptools");
    setMinimumWidth(300);
    setMinimumHeight(140);
    setCentralWidgetMargin(20, 20);
    setWindowIcon(QIcon(":/Icons/window_icon.png"));
    setTitleBarIcon(QPixmap(":/Icons/window_icon.png"));

    r_cWidget = new CoreWidget(this);

    setCentralWidget(r_cWidget);

}
