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
    QLineEdit *lineEdit_sceneUrdf;
    QToolButton *toolButton_robotUrdfFile;
    QLabel *label_packagePath;
    QLabel *label_robotUrdf;
    QComboBox *comboBox_Plate;
    QLabel *label_fudicialPlate;
    QComboBox *comboBox_RobotType;
    QLabel *label_robotType;
    QToolButton *toolButton_sceneUrdfFile;
    QLineEdit *lineEdit_robotUrdf;
    QLineEdit *lineEdit_packagePath;
    QTextEdit *textEdit;
    QLineEdit *lineEdit_robotIp;
    QLabel *label_sceneUrdf;
    QLabel *label_description;
    QToolButton *toolButton_packagePath;
    QLabel *label_robotIp;
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
        lineEdit_sceneUrdf = new QLineEdit(CreateProfileDialog);
        lineEdit_sceneUrdf->setObjectName(QStringLiteral("lineEdit_sceneUrdf"));

        gridLayout->addWidget(lineEdit_sceneUrdf, 4, 1, 1, 1);

        toolButton_robotUrdfFile = new QToolButton(CreateProfileDialog);
        toolButton_robotUrdfFile->setObjectName(QStringLiteral("toolButton_robotUrdfFile"));

        gridLayout->addWidget(toolButton_robotUrdfFile, 2, 2, 1, 1);

        label_packagePath = new QLabel(CreateProfileDialog);
        label_packagePath->setObjectName(QStringLiteral("label_packagePath"));
        label_packagePath->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_packagePath, 3, 0, 1, 1);

        label_robotUrdf = new QLabel(CreateProfileDialog);
        label_robotUrdf->setObjectName(QStringLiteral("label_robotUrdf"));
        label_robotUrdf->setEnabled(true);

        gridLayout->addWidget(label_robotUrdf, 2, 0, 1, 1);

        comboBox_Plate = new QComboBox(CreateProfileDialog);
        comboBox_Plate->setObjectName(QStringLiteral("comboBox_Plate"));

        gridLayout->addWidget(comboBox_Plate, 5, 1, 1, 1);

        label_fudicialPlate = new QLabel(CreateProfileDialog);
        label_fudicialPlate->setObjectName(QStringLiteral("label_fudicialPlate"));

        gridLayout->addWidget(label_fudicialPlate, 5, 0, 1, 1);

        comboBox_RobotType = new QComboBox(CreateProfileDialog);
        comboBox_RobotType->setObjectName(QStringLiteral("comboBox_RobotType"));

        gridLayout->addWidget(comboBox_RobotType, 0, 1, 1, 2);

        label_robotType = new QLabel(CreateProfileDialog);
        label_robotType->setObjectName(QStringLiteral("label_robotType"));
        label_robotType->setEnabled(true);
        label_robotType->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_robotType, 0, 0, 1, 1);

        toolButton_sceneUrdfFile = new QToolButton(CreateProfileDialog);
        toolButton_sceneUrdfFile->setObjectName(QStringLiteral("toolButton_sceneUrdfFile"));

        gridLayout->addWidget(toolButton_sceneUrdfFile, 4, 2, 1, 1);

        lineEdit_robotUrdf = new QLineEdit(CreateProfileDialog);
        lineEdit_robotUrdf->setObjectName(QStringLiteral("lineEdit_robotUrdf"));

        gridLayout->addWidget(lineEdit_robotUrdf, 2, 1, 1, 1);

        lineEdit_packagePath = new QLineEdit(CreateProfileDialog);
        lineEdit_packagePath->setObjectName(QStringLiteral("lineEdit_packagePath"));

        gridLayout->addWidget(lineEdit_packagePath, 3, 1, 1, 1);

        textEdit = new QTextEdit(CreateProfileDialog);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        gridLayout->addWidget(textEdit, 6, 1, 1, 2);

        lineEdit_robotIp = new QLineEdit(CreateProfileDialog);
        lineEdit_robotIp->setObjectName(QStringLiteral("lineEdit_robotIp"));

        gridLayout->addWidget(lineEdit_robotIp, 1, 1, 1, 2);

        label_sceneUrdf = new QLabel(CreateProfileDialog);
        label_sceneUrdf->setObjectName(QStringLiteral("label_sceneUrdf"));
        label_sceneUrdf->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_sceneUrdf, 4, 0, 1, 1);

        label_description = new QLabel(CreateProfileDialog);
        label_description->setObjectName(QStringLiteral("label_description"));
        label_description->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);

        gridLayout->addWidget(label_description, 6, 0, 1, 1);

        toolButton_packagePath = new QToolButton(CreateProfileDialog);
        toolButton_packagePath->setObjectName(QStringLiteral("toolButton_packagePath"));

        gridLayout->addWidget(toolButton_packagePath, 3, 2, 1, 1);

        label_robotIp = new QLabel(CreateProfileDialog);
        label_robotIp->setObjectName(QStringLiteral("label_robotIp"));
        label_robotIp->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_robotIp, 1, 0, 1, 1);


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
        toolButton_robotUrdfFile->setText(QApplication::translate("CreateProfileDialog", "...", Q_NULLPTR));
        label_packagePath->setText(QApplication::translate("CreateProfileDialog", "Package Path", Q_NULLPTR));
        label_robotUrdf->setText(QApplication::translate("CreateProfileDialog", "Robot URDF", Q_NULLPTR));
        comboBox_Plate->clear();
        comboBox_Plate->insertItems(0, QStringList()
         << QApplication::translate("CreateProfileDialog", "Chessboard 1", Q_NULLPTR)
         << QApplication::translate("CreateProfileDialog", "Chessboard Big Size", Q_NULLPTR)
        );
        label_fudicialPlate->setText(QApplication::translate("CreateProfileDialog", "Fudicial Plate", Q_NULLPTR));
        comboBox_RobotType->clear();
        comboBox_RobotType->insertItems(0, QStringList()
         << QApplication::translate("CreateProfileDialog", "UR3", Q_NULLPTR)
         << QApplication::translate("CreateProfileDialog", "Universal Robotics 5", Q_NULLPTR)
         << QApplication::translate("CreateProfileDialog", "Custom", Q_NULLPTR)
         << QString()
        );
        label_robotType->setText(QApplication::translate("CreateProfileDialog", "Robot Type", Q_NULLPTR));
        toolButton_sceneUrdfFile->setText(QApplication::translate("CreateProfileDialog", "...", Q_NULLPTR));
        label_sceneUrdf->setText(QApplication::translate("CreateProfileDialog", "Scene URDF", Q_NULLPTR));
        label_description->setText(QApplication::translate("CreateProfileDialog", "Description", Q_NULLPTR));
        toolButton_packagePath->setText(QApplication::translate("CreateProfileDialog", "...", Q_NULLPTR));
        label_robotIp->setText(QApplication::translate("CreateProfileDialog", "IP Address", Q_NULLPTR));
        pushButton_cancel->setText(QApplication::translate("CreateProfileDialog", "Cancel", Q_NULLPTR));
        pushButton_save->setText(QApplication::translate("CreateProfileDialog", "Save", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CreateProfileDialog: public Ui_CreateProfileDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEPROFILEDIALOG_H
