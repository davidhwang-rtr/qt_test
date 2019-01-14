/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConfigWidget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_RobotSensor;
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame_robot;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QPushButton *pushButton_openfile;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_create;
    QPushButton *button_Connect;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_Plate;
    QComboBox *comboBox_Plate;
    QSpacerItem *verticalSpacer;
    QTableWidget *tableSensor;
    QFrame *frame;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *cameraView;
    QHBoxLayout *horizontalLayout_6;

    void setupUi(QWidget *ConfigWidget)
    {
        if (ConfigWidget->objectName().isEmpty())
            ConfigWidget->setObjectName(QStringLiteral("ConfigWidget"));
        ConfigWidget->resize(1025, 633);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ConfigWidget->sizePolicy().hasHeightForWidth());
        ConfigWidget->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(ConfigWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget_RobotSensor = new QWidget(ConfigWidget);
        widget_RobotSensor->setObjectName(QStringLiteral("widget_RobotSensor"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_RobotSensor->sizePolicy().hasHeightForWidth());
        widget_RobotSensor->setSizePolicy(sizePolicy1);
        horizontalLayout_2 = new QHBoxLayout(widget_RobotSensor);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        frame_robot = new QFrame(widget_RobotSensor);
        frame_robot->setObjectName(QStringLiteral("frame_robot"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(frame_robot->sizePolicy().hasHeightForWidth());
        frame_robot->setSizePolicy(sizePolicy2);
        frame_robot->setFrameShape(QFrame::NoFrame);
        frame_robot->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_robot);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(frame_robot);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEdit = new QLineEdit(frame_robot);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy3);

        horizontalLayout_3->addWidget(lineEdit);

        pushButton_openfile = new QPushButton(frame_robot);
        pushButton_openfile->setObjectName(QStringLiteral("pushButton_openfile"));
        pushButton_openfile->setMaximumSize(QSize(27, 27));

        horizontalLayout_3->addWidget(pushButton_openfile);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        pushButton_create = new QPushButton(frame_robot);
        pushButton_create->setObjectName(QStringLiteral("pushButton_create"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(pushButton_create->sizePolicy().hasHeightForWidth());
        pushButton_create->setSizePolicy(sizePolicy4);
        pushButton_create->setMinimumSize(QSize(100, 50));
        pushButton_create->setMaximumSize(QSize(100, 50));

        horizontalLayout_4->addWidget(pushButton_create);

        button_Connect = new QPushButton(frame_robot);
        button_Connect->setObjectName(QStringLiteral("button_Connect"));
        sizePolicy4.setHeightForWidth(button_Connect->sizePolicy().hasHeightForWidth());
        button_Connect->setSizePolicy(sizePolicy4);
        button_Connect->setMinimumSize(QSize(100, 51));
        button_Connect->setMaximumSize(QSize(100, 50));

        horizontalLayout_4->addWidget(button_Connect);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_Plate = new QLabel(frame_robot);
        label_Plate->setObjectName(QStringLiteral("label_Plate"));
        label_Plate->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_Plate);

        comboBox_Plate = new QComboBox(frame_robot);
        comboBox_Plate->setObjectName(QStringLiteral("comboBox_Plate"));
        sizePolicy1.setHeightForWidth(comboBox_Plate->sizePolicy().hasHeightForWidth());
        comboBox_Plate->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(comboBox_Plate);

        horizontalLayout_5->setStretch(1, 1);

        verticalLayout_2->addLayout(horizontalLayout_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_2->addWidget(frame_robot);

        tableSensor = new QTableWidget(widget_RobotSensor);
        tableSensor->setObjectName(QStringLiteral("tableSensor"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(tableSensor->sizePolicy().hasHeightForWidth());
        tableSensor->setSizePolicy(sizePolicy5);
        tableSensor->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableSensor->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        tableSensor->setEditTriggers(QAbstractItemView::CurrentChanged|QAbstractItemView::SelectedClicked);
        tableSensor->setSelectionMode(QAbstractItemView::SingleSelection);
        tableSensor->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableSensor->horizontalHeader()->setVisible(false);
        tableSensor->horizontalHeader()->setMinimumSectionSize(60);
        tableSensor->verticalHeader()->setVisible(false);
        tableSensor->verticalHeader()->setDefaultSectionSize(50);
        tableSensor->verticalHeader()->setHighlightSections(false);
        tableSensor->verticalHeader()->setMinimumSectionSize(50);

        horizontalLayout_2->addWidget(tableSensor);

        horizontalLayout_2->setStretch(1, 1);

        verticalLayout->addWidget(widget_RobotSensor);

        frame = new QFrame(ConfigWidget);
        frame->setObjectName(QStringLiteral("frame"));
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayoutWidget = new QWidget(frame);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 1001, 321));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(10, 10, 10, 10);
        cameraView = new QLabel(horizontalLayoutWidget);
        cameraView->setObjectName(QStringLiteral("cameraView"));

        horizontalLayout->addWidget(cameraView);


        verticalLayout->addWidget(frame);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));

        verticalLayout->addLayout(horizontalLayout_6);


        retranslateUi(ConfigWidget);

        QMetaObject::connectSlotsByName(ConfigWidget);
    } // setupUi

    void retranslateUi(QWidget *ConfigWidget)
    {
        ConfigWidget->setWindowTitle(QApplication::translate("ConfigWidget", "Widget", Q_NULLPTR));
        label_3->setText(QApplication::translate("ConfigWidget", "Profile File", Q_NULLPTR));
        pushButton_openfile->setText(QApplication::translate("ConfigWidget", "...", Q_NULLPTR));
        pushButton_create->setText(QApplication::translate("ConfigWidget", "New", Q_NULLPTR));
        button_Connect->setText(QApplication::translate("ConfigWidget", "Open", Q_NULLPTR));
        label_Plate->setText(QApplication::translate("ConfigWidget", "Plate Selection", Q_NULLPTR));
        comboBox_Plate->clear();
        comboBox_Plate->insertItems(0, QStringList()
         << QApplication::translate("ConfigWidget", "RTR_UR3_CHESSBOARD_1", Q_NULLPTR)
         << QApplication::translate("ConfigWidget", "RTR_UR3_CHESSBOARD_2", Q_NULLPTR)
        );
        cameraView->setText(QApplication::translate("ConfigWidget", "...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ConfigWidget: public Ui_ConfigWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
