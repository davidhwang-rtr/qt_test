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
#include <QtWidgets/QFormLayout>
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
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit_fileName;
    QPushButton *pushButton_fileSelect;
    QPushButton *pushButton_fileNew;
    QFrame *frame_detail;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_7;
    QLabel *label_9;
    QLabel *label_5;
    QLabel *label_ip;
    QSpacerItem *verticalSpacer;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEdit_PackagePath;
    QLineEdit *lineEdit_RobotIp;
    QLabel *label_2;
    QLabel *label_4;
    QComboBox *comboBox_RobotType;
    QLabel *label_6;
    QComboBox *comboBox_Plate;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_connect;
    QTableWidget *tableSensor;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_5;
    QLabel *cameraView;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButton_home;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_calibration;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *ConfigWidget)
    {
        if (ConfigWidget->objectName().isEmpty())
            ConfigWidget->setObjectName(QStringLiteral("ConfigWidget"));
        ConfigWidget->resize(1902, 1961);
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
        label_3 = new QLabel(frame_robot);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_2->addWidget(label_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lineEdit_fileName = new QLineEdit(frame_robot);
        lineEdit_fileName->setObjectName(QStringLiteral("lineEdit_fileName"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lineEdit_fileName->sizePolicy().hasHeightForWidth());
        lineEdit_fileName->setSizePolicy(sizePolicy3);
        lineEdit_fileName->setMinimumSize(QSize(200, 0));

        horizontalLayout_3->addWidget(lineEdit_fileName);

        pushButton_fileSelect = new QPushButton(frame_robot);
        pushButton_fileSelect->setObjectName(QStringLiteral("pushButton_fileSelect"));
        pushButton_fileSelect->setMinimumSize(QSize(0, 0));
        pushButton_fileSelect->setMaximumSize(QSize(48, 25));

        horizontalLayout_3->addWidget(pushButton_fileSelect);

        pushButton_fileNew = new QPushButton(frame_robot);
        pushButton_fileNew->setObjectName(QStringLiteral("pushButton_fileNew"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(pushButton_fileNew->sizePolicy().hasHeightForWidth());
        pushButton_fileNew->setSizePolicy(sizePolicy4);
        pushButton_fileNew->setMinimumSize(QSize(50, 25));
        pushButton_fileNew->setMaximumSize(QSize(50, 24));
        pushButton_fileNew->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_3->addWidget(pushButton_fileNew);


        verticalLayout_2->addLayout(horizontalLayout_3);

        frame_detail = new QFrame(frame_robot);
        frame_detail->setObjectName(QStringLiteral("frame_detail"));
        frame_detail->setMinimumSize(QSize(0, 100));
        frame_detail->setFrameShape(QFrame::StyledPanel);
        frame_detail->setFrameShadow(QFrame::Raised);
        layoutWidget = new QWidget(frame_detail);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(70, 10, 331, 72));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        QFont font;
        font.setPointSize(9);
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_3->addWidget(label_7);

        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font);
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_3->addWidget(label_9);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_3->addWidget(label_5);

        label_ip = new QLabel(layoutWidget);
        label_ip->setObjectName(QStringLiteral("label_ip"));
        label_ip->setFont(font);
        label_ip->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_3->addWidget(label_ip);


        verticalLayout_2->addWidget(frame_detail);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(-1, 10, -1, 10);
        label = new QLabel(frame_robot);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEdit_PackagePath = new QLineEdit(frame_robot);
        lineEdit_PackagePath->setObjectName(QStringLiteral("lineEdit_PackagePath"));
        lineEdit_PackagePath->setFont(font);
        lineEdit_PackagePath->setFrame(false);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_PackagePath);

        lineEdit_RobotIp = new QLineEdit(frame_robot);
        lineEdit_RobotIp->setObjectName(QStringLiteral("lineEdit_RobotIp"));
        lineEdit_RobotIp->setFont(font);
        lineEdit_RobotIp->setFrame(false);

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_RobotIp);

        label_2 = new QLabel(frame_robot);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_4 = new QLabel(frame_robot);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        comboBox_RobotType = new QComboBox(frame_robot);
        comboBox_RobotType->setObjectName(QStringLiteral("comboBox_RobotType"));
        comboBox_RobotType->setFont(font);

        formLayout->setWidget(2, QFormLayout::FieldRole, comboBox_RobotType);

        label_6 = new QLabel(frame_robot);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_6);

        comboBox_Plate = new QComboBox(frame_robot);
        comboBox_Plate->setObjectName(QStringLiteral("comboBox_Plate"));
        comboBox_Plate->setFont(font);

        formLayout->setWidget(3, QFormLayout::FieldRole, comboBox_Plate);


        verticalLayout_2->addLayout(formLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        pushButton_connect = new QPushButton(frame_robot);
        pushButton_connect->setObjectName(QStringLiteral("pushButton_connect"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(pushButton_connect->sizePolicy().hasHeightForWidth());
        pushButton_connect->setSizePolicy(sizePolicy5);
        pushButton_connect->setMinimumSize(QSize(100, 51));
        pushButton_connect->setMaximumSize(QSize(100, 50));

        horizontalLayout_4->addWidget(pushButton_connect);


        verticalLayout_2->addLayout(horizontalLayout_4);


        horizontalLayout_2->addWidget(frame_robot);

        tableSensor = new QTableWidget(widget_RobotSensor);
        tableSensor->setObjectName(QStringLiteral("tableSensor"));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(tableSensor->sizePolicy().hasHeightForWidth());
        tableSensor->setSizePolicy(sizePolicy6);
        tableSensor->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
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
        horizontalLayout_5 = new QHBoxLayout(frame);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        cameraView = new QLabel(frame);
        cameraView->setObjectName(QStringLiteral("cameraView"));
        sizePolicy.setHeightForWidth(cameraView->sizePolicy().hasHeightForWidth());
        cameraView->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(cameraView);


        verticalLayout->addWidget(frame);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(-1, 5, -1, -1);
        pushButton_home = new QPushButton(ConfigWidget);
        pushButton_home->setObjectName(QStringLiteral("pushButton_home"));
        sizePolicy5.setHeightForWidth(pushButton_home->sizePolicy().hasHeightForWidth());
        pushButton_home->setSizePolicy(sizePolicy5);
        pushButton_home->setMinimumSize(QSize(150, 50));
        pushButton_home->setMaximumSize(QSize(150, 50));

        horizontalLayout_7->addWidget(pushButton_home);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);

        pushButton_calibration = new QPushButton(ConfigWidget);
        pushButton_calibration->setObjectName(QStringLiteral("pushButton_calibration"));
        sizePolicy5.setHeightForWidth(pushButton_calibration->sizePolicy().hasHeightForWidth());
        pushButton_calibration->setSizePolicy(sizePolicy5);
        pushButton_calibration->setMinimumSize(QSize(150, 50));
        pushButton_calibration->setMaximumSize(QSize(150, 50));

        horizontalLayout_7->addWidget(pushButton_calibration);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_7);


        retranslateUi(ConfigWidget);

        QMetaObject::connectSlotsByName(ConfigWidget);
    } // setupUi

    void retranslateUi(QWidget *ConfigWidget)
    {
        ConfigWidget->setWindowTitle(QApplication::translate("ConfigWidget", "Widget", Q_NULLPTR));
        label_3->setText(QApplication::translate("ConfigWidget", "Project File :", Q_NULLPTR));
        pushButton_fileSelect->setText(QApplication::translate("ConfigWidget", "...", Q_NULLPTR));
        pushButton_fileNew->setText(QApplication::translate("ConfigWidget", "New", Q_NULLPTR));
        label_7->setText(QApplication::translate("ConfigWidget", "Robot :", Q_NULLPTR));
        label_9->setText(QApplication::translate("ConfigWidget", "Plate :", Q_NULLPTR));
        label_5->setText(QApplication::translate("ConfigWidget", "Path :", Q_NULLPTR));
        label_ip->setText(QApplication::translate("ConfigWidget", "IP :", Q_NULLPTR));
        label->setText(QApplication::translate("ConfigWidget", "Urdf Path:", Q_NULLPTR));
        label_2->setText(QApplication::translate("ConfigWidget", "IP:", Q_NULLPTR));
        label_4->setText(QApplication::translate("ConfigWidget", "Robot:", Q_NULLPTR));
        label_6->setText(QApplication::translate("ConfigWidget", "Plate:", Q_NULLPTR));
        pushButton_connect->setText(QApplication::translate("ConfigWidget", "Connect", Q_NULLPTR));
        cameraView->setText(QApplication::translate("ConfigWidget", "...", Q_NULLPTR));
        pushButton_home->setText(QApplication::translate("ConfigWidget", "Home", Q_NULLPTR));
        pushButton_calibration->setText(QApplication::translate("ConfigWidget", "Calibrate All", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ConfigWidget: public Ui_ConfigWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
