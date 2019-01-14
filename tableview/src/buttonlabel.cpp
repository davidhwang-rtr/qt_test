#include "buttonlabel.h"
#include <QSize>

ButtonLabel::ButtonLabel(QWidget* parent, Qt::WindowFlags f) : QLabel(parent, f) {
  QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  sizePolicy.setHorizontalStretch(0);
  sizePolicy.setVerticalStretch(0);
  //  sizePolicy.setHeightForWidth(this->sizePolicy().hasHeightForWidth());
  setSizePolicy(sizePolicy);
  setMinimumSize(QSize(100, 50));
  setStyleSheet(
      QLatin1String("background-color: rgb(85, 87, 83);\n"
                    "color: rgb(255, 255, 255);"));
  setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
}

ButtonLabel::~ButtonLabel() {}

void ButtonLabel::mousePressEvent(QMouseEvent* event) {
  emit clicked(text());

  QLabel::mousePressEvent(event);
}
