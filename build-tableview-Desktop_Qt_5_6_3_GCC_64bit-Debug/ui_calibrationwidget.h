/********************************************************************************
** Form generated from reading UI file 'calibrationwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALIBRATIONWIDGET_H
#define UI_CALIBRATIONWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CalWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_RobotSensor;
    QHBoxLayout *horizontalLayout_2;
    QTableView *tableView;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QLabel *worldView;
    QLabel *cameraView;

    void setupUi(QWidget *CalWidget)
    {
        if (CalWidget->objectName().isEmpty())
            CalWidget->setObjectName(QStringLiteral("CalWidget"));
        CalWidget->resize(1526, 775);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CalWidget->sizePolicy().hasHeightForWidth());
        CalWidget->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(CalWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        widget_RobotSensor = new QWidget(CalWidget);
        widget_RobotSensor->setObjectName(QStringLiteral("widget_RobotSensor"));
        horizontalLayout_2 = new QHBoxLayout(widget_RobotSensor);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        tableView = new QTableView(widget_RobotSensor);
        tableView->setObjectName(QStringLiteral("tableView"));

        horizontalLayout_2->addWidget(tableView);


        verticalLayout->addWidget(widget_RobotSensor);

        frame = new QFrame(CalWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        worldView = new QLabel(frame);
        worldView->setObjectName(QStringLiteral("worldView"));
        worldView->setPixmap(QPixmap(QString::fromUtf8(":/images/rtr_image/worldview.png")));

        horizontalLayout->addWidget(worldView);

        cameraView = new QLabel(frame);
        cameraView->setObjectName(QStringLiteral("cameraView"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(cameraView->sizePolicy().hasHeightForWidth());
        cameraView->setSizePolicy(sizePolicy1);
        cameraView->setFrameShape(QFrame::Box);
        cameraView->setPixmap(QPixmap(QString::fromUtf8(":/images/rtr_image/checker_board.png")));

        horizontalLayout->addWidget(cameraView);


        verticalLayout->addWidget(frame);


        retranslateUi(CalWidget);

        QMetaObject::connectSlotsByName(CalWidget);
    } // setupUi

    void retranslateUi(QWidget *CalWidget)
    {
        CalWidget->setWindowTitle(QApplication::translate("CalWidget", "Widget", Q_NULLPTR));
        worldView->setText(QString());
        cameraView->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CalWidget: public Ui_CalWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALIBRATIONWIDGET_H
