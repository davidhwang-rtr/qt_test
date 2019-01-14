/********************************************************************************
** Form generated from reading UI file 'createprofiledialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEPROFILEDIALOG_H
#define UI_CREATEPROFILEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CreateProfileDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_PackagePath;
    QLabel *label_3;
    QToolButton *toolButton_3;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_RobotIp;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *label_RobotType;
    QLineEdit *lineEdit_PackagePath;
    QToolButton *toolButton_2;
    QSpacerItem *verticalSpacer;
    QComboBox *comboBox_RobotType;
    QToolButton *toolButton_5;
    QLineEdit *lineEdit_3;
    QLabel *label_RobotIp;
    QLabel *label_6;
    QLineEdit *lineEdit_4;
    QToolButton *toolButton_4;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_cancel;
    QPushButton *pushButton_save;

    void setupUi(QDialog *CreateProfileDialog)
    {
        if (CreateProfileDialog->objectName().isEmpty())
            CreateProfileDialog->setObjectName(QStringLiteral("CreateProfileDialog"));
        CreateProfileDialog->resize(433, 470);
        CreateProfileDialog->setModal(true);
        verticalLayout = new QVBoxLayout(CreateProfileDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_PackagePath = new QLabel(CreateProfileDialog);
        label_PackagePath->setObjectName(QStringLiteral("label_PackagePath"));
        label_PackagePath->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_PackagePath, 5, 0, 1, 1);

        label_3 = new QLabel(CreateProfileDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        toolButton_3 = new QToolButton(CreateProfileDialog);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));

        gridLayout->addWidget(toolButton_3, 6, 2, 1, 1);

        lineEdit_2 = new QLineEdit(CreateProfileDialog);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 6, 1, 1, 1);

        lineEdit_RobotIp = new QLineEdit(CreateProfileDialog);
        lineEdit_RobotIp->setObjectName(QStringLiteral("lineEdit_RobotIp"));

        gridLayout->addWidget(lineEdit_RobotIp, 3, 1, 1, 2);

        label_4 = new QLabel(CreateProfileDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);

        gridLayout->addWidget(label_4, 7, 0, 1, 1);

        label_2 = new QLabel(CreateProfileDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 6, 0, 1, 1);

        label_RobotType = new QLabel(CreateProfileDialog);
        label_RobotType->setObjectName(QStringLiteral("label_RobotType"));
        label_RobotType->setEnabled(true);
        label_RobotType->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_RobotType, 2, 0, 1, 1);

        lineEdit_PackagePath = new QLineEdit(CreateProfileDialog);
        lineEdit_PackagePath->setObjectName(QStringLiteral("lineEdit_PackagePath"));

        gridLayout->addWidget(lineEdit_PackagePath, 5, 1, 1, 1);

        toolButton_2 = new QToolButton(CreateProfileDialog);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));

        gridLayout->addWidget(toolButton_2, 5, 2, 1, 1);

        verticalSpacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 1, 1, 1);

        comboBox_RobotType = new QComboBox(CreateProfileDialog);
        comboBox_RobotType->setObjectName(QStringLiteral("comboBox_RobotType"));

        gridLayout->addWidget(comboBox_RobotType, 2, 1, 1, 2);

        toolButton_5 = new QToolButton(CreateProfileDialog);
        toolButton_5->setObjectName(QStringLiteral("toolButton_5"));

        gridLayout->addWidget(toolButton_5, 0, 2, 1, 1);

        lineEdit_3 = new QLineEdit(CreateProfileDialog);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        gridLayout->addWidget(lineEdit_3, 0, 1, 1, 1);

        label_RobotIp = new QLabel(CreateProfileDialog);
        label_RobotIp->setObjectName(QStringLiteral("label_RobotIp"));
        label_RobotIp->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_RobotIp, 3, 0, 1, 1);

        label_6 = new QLabel(CreateProfileDialog);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 4, 0, 1, 1);

        lineEdit_4 = new QLineEdit(CreateProfileDialog);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        gridLayout->addWidget(lineEdit_4, 4, 1, 1, 1);

        toolButton_4 = new QToolButton(CreateProfileDialog);
        toolButton_4->setObjectName(QStringLiteral("toolButton_4"));

        gridLayout->addWidget(toolButton_4, 4, 2, 1, 1);

        textEdit = new QTextEdit(CreateProfileDialog);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        gridLayout->addWidget(textEdit, 7, 1, 1, 2);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_cancel = new QPushButton(CreateProfileDialog);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_cancel->sizePolicy().hasHeightForWidth());
        pushButton_cancel->setSizePolicy(sizePolicy);
        pushButton_cancel->setMinimumSize(QSize(100, 50));
        pushButton_cancel->setMaximumSize(QSize(100, 50));

        horizontalLayout->addWidget(pushButton_cancel);

        pushButton_save = new QPushButton(CreateProfileDialog);
        pushButton_save->setObjectName(QStringLiteral("pushButton_save"));
        sizePolicy.setHeightForWidth(pushButton_save->sizePolicy().hasHeightForWidth());
        pushButton_save->setSizePolicy(sizePolicy);
        pushButton_save->setMinimumSize(QSize(100, 50));
        pushButton_save->setMaximumSize(QSize(100, 50));

        horizontalLayout->addWidget(pushButton_save);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(CreateProfileDialog);

        QMetaObject::connectSlotsByName(CreateProfileDialog);
    } // setupUi

    void retranslateUi(QDialog *CreateProfileDialog)
    {
        CreateProfileDialog->setWindowTitle(QApplication::translate("CreateProfileDialog", "Create Robot Profile", Q_NULLPTR));
        label_PackagePath->setText(QApplication::translate("CreateProfileDialog", "Package Path", Q_NULLPTR));
        label_3->setText(QApplication::translate("CreateProfileDialog", "File Name", Q_NULLPTR));
        toolButton_3->setText(QApplication::translate("CreateProfileDialog", "...", Q_NULLPTR));
        label_4->setText(QApplication::translate("CreateProfileDialog", "Description", Q_NULLPTR));
        label_2->setText(QApplication::translate("CreateProfileDialog", "Scene URDF", Q_NULLPTR));
        label_RobotType->setText(QApplication::translate("CreateProfileDialog", "Robot Type", Q_NULLPTR));
        toolButton_2->setText(QApplication::translate("CreateProfileDialog", "...", Q_NULLPTR));
        comboBox_RobotType->clear();
        comboBox_RobotType->insertItems(0, QStringList()
         << QApplication::translate("CreateProfileDialog", "UR3", Q_NULLPTR)
         << QApplication::translate("CreateProfileDialog", "Universal Robotics 5", Q_NULLPTR)
         << QApplication::translate("CreateProfileDialog", "Custom", Q_NULLPTR)
         << QString()
        );
        toolButton_5->setText(QApplication::translate("CreateProfileDialog", "...", Q_NULLPTR));
        label_RobotIp->setText(QApplication::translate("CreateProfileDialog", "IP Address", Q_NULLPTR));
        label_6->setText(QApplication::translate("CreateProfileDialog", "Robot URDF", Q_NULLPTR));
        toolButton_4->setText(QApplication::translate("CreateProfileDialog", "...", Q_NULLPTR));
        pushButton_cancel->setText(QApplication::translate("CreateProfileDialog", "Cancel", Q_NULLPTR));
        pushButton_save->setText(QApplication::translate("CreateProfileDialog", "Save", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CreateProfileDialog: public Ui_CreateProfileDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEPROFILEDIALOG_H
