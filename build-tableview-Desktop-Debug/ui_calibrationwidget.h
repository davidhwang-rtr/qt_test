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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
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
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;

    void setupUi(QWidget *CalWidget)
    {
        if (CalWidget->objectName().isEmpty())
            CalWidget->setObjectName(QStringLiteral("CalWidget"));
        CalWidget->resize(1901, 1961);
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
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_RobotSensor->sizePolicy().hasHeightForWidth());
        widget_RobotSensor->setSizePolicy(sizePolicy1);
        horizontalLayout_2 = new QHBoxLayout(widget_RobotSensor);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        tableView = new QTableView(widget_RobotSensor);
        tableView->setObjectName(QStringLiteral("tableView"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tableView->sizePolicy().hasHeightForWidth());
        tableView->setSizePolicy(sizePolicy2);
        tableView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setGridStyle(Qt::SolidLine);
        tableView->horizontalHeader()->setCascadingSectionResizes(false);
        tableView->horizontalHeader()->setStretchLastSection(false);
        tableView->verticalHeader()->setStretchLastSection(false);

        horizontalLayout_2->addWidget(tableView);


        verticalLayout->addWidget(widget_RobotSensor);

        frame = new QFrame(CalWidget);
        frame->setObjectName(QStringLiteral("frame"));
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        worldView = new QLabel(frame);
        worldView->setObjectName(QStringLiteral("worldView"));
        worldView->setFrameShape(QFrame::Box);
        worldView->setPixmap(QPixmap(QString::fromUtf8(":/images/rtr_image/worldview.png")));
        worldView->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(worldView);

        cameraView = new QLabel(frame);
        cameraView->setObjectName(QStringLiteral("cameraView"));
        sizePolicy1.setHeightForWidth(cameraView->sizePolicy().hasHeightForWidth());
        cameraView->setSizePolicy(sizePolicy1);
        cameraView->setFrameShape(QFrame::Box);
        cameraView->setPixmap(QPixmap(QString::fromUtf8(":/images/rtr_image/checker_board.png")));
        cameraView->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(cameraView);


        verticalLayout->addWidget(frame);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(20);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButton = new QPushButton(CalWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy3);
        pushButton->setMinimumSize(QSize(150, 50));
        pushButton->setMaximumSize(QSize(150, 50));

        horizontalLayout_3->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        pushButton_4 = new QPushButton(CalWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        sizePolicy3.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy3);
        pushButton_4->setMinimumSize(QSize(150, 50));
        pushButton_4->setMaximumSize(QSize(150, 50));

        horizontalLayout_3->addWidget(pushButton_4);

        pushButton_3 = new QPushButton(CalWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        sizePolicy3.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy3);
        pushButton_3->setMinimumSize(QSize(150, 50));
        pushButton_3->setMaximumSize(QSize(150, 50));

        horizontalLayout_3->addWidget(pushButton_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(CalWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy3.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy3);
        pushButton_2->setMinimumSize(QSize(150, 50));
        pushButton_2->setMaximumSize(QSize(150, 50));

        horizontalLayout_3->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 5);

        retranslateUi(CalWidget);

        QMetaObject::connectSlotsByName(CalWidget);
    } // setupUi

    void retranslateUi(QWidget *CalWidget)
    {
        CalWidget->setWindowTitle(QApplication::translate("CalWidget", "Widget", Q_NULLPTR));
        worldView->setText(QString());
        cameraView->setText(QString());
        pushButton->setText(QApplication::translate("CalWidget", "Setting", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("CalWidget", "Calibrate", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("CalWidget", "Save", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("CalWidget", "Exit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CalWidget: public Ui_CalWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALIBRATIONWIDGET_H
