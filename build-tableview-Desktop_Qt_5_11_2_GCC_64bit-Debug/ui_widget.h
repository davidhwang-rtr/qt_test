/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConfigWidget
{
public:
    QPushButton *pushButton_Calibrate;
    QSplitter *splitter;
    QWidget *widget_RobotSensor;
    QTableWidget *tableWidget_Sensor;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QComboBox *comboBox_RobotType;
    QLabel *label_RobotIp;
    QLabel *label_RobotType;
    QLineEdit *lineEdit_PackagePath;
    QComboBox *comboBox_Plate;
    QLabel *label_Plate;
    QLabel *label_PackagePath;
    QToolButton *button_PacakgePath;
    QLineEdit *lineEdit_RobotIp;
    QPushButton *button_Connect;
    QFrame *frame;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_ThreeDView;
    QWidget *widget_CameraView;

    void setupUi(QWidget *ConfigWidget)
    {
        if (ConfigWidget->objectName().isEmpty())
            ConfigWidget->setObjectName(QStringLiteral("ConfigWidget"));
        ConfigWidget->resize(904, 768);
        pushButton_Calibrate = new QPushButton(ConfigWidget);
        pushButton_Calibrate->setObjectName(QStringLiteral("pushButton_Calibrate"));
        pushButton_Calibrate->setGeometry(QRect(770, 710, 120, 50));
        splitter = new QSplitter(ConfigWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(0, 0, 904, 701));
        splitter->setOrientation(Qt::Vertical);
        widget_RobotSensor = new QWidget(splitter);
        widget_RobotSensor->setObjectName(QStringLiteral("widget_RobotSensor"));
        tableWidget_Sensor = new QTableWidget(widget_RobotSensor);
        tableWidget_Sensor->setObjectName(QStringLiteral("tableWidget_Sensor"));
        tableWidget_Sensor->setGeometry(QRect(10, 85, 884, 341));
        tableWidget_Sensor->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget_Sensor->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        tableWidget_Sensor->setEditTriggers(QAbstractItemView::CurrentChanged|QAbstractItemView::DoubleClicked|QAbstractItemView::SelectedClicked);
        tableWidget_Sensor->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget_Sensor->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget_Sensor->horizontalHeader()->setVisible(false);
        tableWidget_Sensor->verticalHeader()->setVisible(false);
        tableWidget_Sensor->verticalHeader()->setDefaultSectionSize(50);
        tableWidget_Sensor->verticalHeader()->setMinimumSectionSize(50);
        groupBox = new QGroupBox(widget_RobotSensor);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, -15, 781, 91));
        groupBox->setStyleSheet(QStringLiteral("#QGroupBox{padding-top:15px; margin-top:-20px}"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        comboBox_RobotType = new QComboBox(groupBox);
        comboBox_RobotType->addItem(QString());
        comboBox_RobotType->addItem(QString());
        comboBox_RobotType->addItem(QString());
        comboBox_RobotType->setObjectName(QStringLiteral("comboBox_RobotType"));

        gridLayout->addWidget(comboBox_RobotType, 0, 1, 1, 1);

        label_RobotIp = new QLabel(groupBox);
        label_RobotIp->setObjectName(QStringLiteral("label_RobotIp"));
        label_RobotIp->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_RobotIp, 2, 3, 1, 1);

        label_RobotType = new QLabel(groupBox);
        label_RobotType->setObjectName(QStringLiteral("label_RobotType"));
        label_RobotType->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_RobotType, 0, 0, 1, 1);

        lineEdit_PackagePath = new QLineEdit(groupBox);
        lineEdit_PackagePath->setObjectName(QStringLiteral("lineEdit_PackagePath"));

        gridLayout->addWidget(lineEdit_PackagePath, 0, 4, 1, 1);

        comboBox_Plate = new QComboBox(groupBox);
        comboBox_Plate->addItem(QString());
        comboBox_Plate->addItem(QString());
        comboBox_Plate->setObjectName(QStringLiteral("comboBox_Plate"));

        gridLayout->addWidget(comboBox_Plate, 2, 1, 1, 1);

        label_Plate = new QLabel(groupBox);
        label_Plate->setObjectName(QStringLiteral("label_Plate"));
        label_Plate->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_Plate, 2, 0, 1, 1);

        label_PackagePath = new QLabel(groupBox);
        label_PackagePath->setObjectName(QStringLiteral("label_PackagePath"));
        label_PackagePath->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_PackagePath, 0, 3, 1, 1);

        button_PacakgePath = new QToolButton(groupBox);
        button_PacakgePath->setObjectName(QStringLiteral("button_PacakgePath"));

        gridLayout->addWidget(button_PacakgePath, 0, 5, 1, 1);

        lineEdit_RobotIp = new QLineEdit(groupBox);
        lineEdit_RobotIp->setObjectName(QStringLiteral("lineEdit_RobotIp"));

        gridLayout->addWidget(lineEdit_RobotIp, 2, 4, 1, 2);

        gridLayout->setColumnStretch(0, 2);
        gridLayout->setColumnStretch(1, 5);
        gridLayout->setColumnStretch(3, 2);
        gridLayout->setColumnStretch(4, 5);
        gridLayout->setColumnStretch(5, 1);
        button_Connect = new QPushButton(widget_RobotSensor);
        button_Connect->setObjectName(QStringLiteral("button_Connect"));
        button_Connect->setGeometry(QRect(800, 10, 89, 61));
        splitter->addWidget(widget_RobotSensor);
        frame = new QFrame(splitter);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayoutWidget = new QWidget(frame);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 901, 351));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(10, 10, 10, 10);
        widget_ThreeDView = new QWidget(horizontalLayoutWidget);
        widget_ThreeDView->setObjectName(QStringLiteral("widget_ThreeDView"));

        horizontalLayout->addWidget(widget_ThreeDView);

        widget_CameraView = new QWidget(horizontalLayoutWidget);
        widget_CameraView->setObjectName(QStringLiteral("widget_CameraView"));

        horizontalLayout->addWidget(widget_CameraView);

        splitter->addWidget(frame);

        retranslateUi(ConfigWidget);

        QMetaObject::connectSlotsByName(ConfigWidget);
    } // setupUi

    void retranslateUi(QWidget *ConfigWidget)
    {
        ConfigWidget->setWindowTitle(QApplication::translate("ConfigWidget", "Widget", nullptr));
        pushButton_Calibrate->setText(QApplication::translate("ConfigWidget", "Calibrate", nullptr));
        groupBox->setTitle(QString());
        comboBox_RobotType->setItemText(0, QApplication::translate("ConfigWidget", "UR3", nullptr));
        comboBox_RobotType->setItemText(1, QApplication::translate("ConfigWidget", "Universal Robotics 5", nullptr));
        comboBox_RobotType->setItemText(2, QString());

        label_RobotIp->setText(QApplication::translate("ConfigWidget", "IP Address", nullptr));
        label_RobotType->setText(QApplication::translate("ConfigWidget", "Robot Type", nullptr));
        comboBox_Plate->setItemText(0, QApplication::translate("ConfigWidget", "RTR_UR3_CHESSBOARD_1", nullptr));
        comboBox_Plate->setItemText(1, QApplication::translate("ConfigWidget", "RTR_UR3_CHESSBOARD_2", nullptr));

        label_Plate->setText(QApplication::translate("ConfigWidget", "Plate Selection", nullptr));
        label_PackagePath->setText(QApplication::translate("ConfigWidget", "Package Path", nullptr));
        button_PacakgePath->setText(QApplication::translate("ConfigWidget", "...", nullptr));
        button_Connect->setText(QApplication::translate("ConfigWidget", "Connect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConfigWidget: public Ui_ConfigWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
