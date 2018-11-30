#ifndef BUTTONLABEL_H
#define BUTTONLABEL_H


#include <QLabel>
#include <QWidget>
#include <Qt>

class ButtonLabel : public QLabel {
    Q_OBJECT

public:
    explicit ButtonLabel(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    ~ButtonLabel();

//  QSize sizeHint();

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent* event);

};

//class ButtonIconLabel : public ButtonLabel
//{
//  Q_OBJECT

//public:
//  explicit ButtonIconLabel(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
//  ~ButtonIconLabel();



//};

#endif // BUTTONLABEL_H
