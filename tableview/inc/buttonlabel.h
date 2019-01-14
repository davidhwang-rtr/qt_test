#ifndef BUTTONLABEL_H
#define BUTTONLABEL_H


#include <QLabel>
#include <QWidget>
#include <Qt>

enum EventPassingType {PAGE_NAVIGATION, COMMAND_IN_PAGE, BEHAVIOR_IN_NAVIBAR};

class ButtonLabel : public QLabel {
    Q_OBJECT

public:
    explicit ButtonLabel(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    ~ButtonLabel();
    QString getDisplayName() const { return displayName_; }
    EventPassingType getPassingType() const { return eventPassingType_; }
    void setDisplayName(QString &name)  { displayName_ = name; }
    void setPassingType(EventPassingType &evt) { eventPassingType_ = evt; }
//  QSize sizeHint();

signals:
    void clicked(QString);

protected:
    void mousePressEvent(QMouseEvent* event);
    QString displayName_;
    EventPassingType eventPassingType_;
};

//class ButtonIconLabel : public ButtonLabel
//{
//  Q_OBJECT

//public:
//  explicit ButtonIconLabel(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
//  ~ButtonIconLabel();



//};

#endif // BUTTONLABEL_H
