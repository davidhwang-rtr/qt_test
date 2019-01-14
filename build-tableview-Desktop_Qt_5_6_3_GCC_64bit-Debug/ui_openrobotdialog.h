/********************************************************************************
** Form generated from reading UI file 'openrobotdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENROBOTDIALOG_H
#define UI_OPENROBOTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OpenRobotDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton_openfile;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_create;
    QPushButton *pushButton_4;

    void setupUi(QDialog *OpenRobotDialog)
    {
        if (OpenRobotDialog->objectName().isEmpty())
            OpenRobotDialog->setObjectName(QStringLiteral("OpenRobotDialog"));
        OpenRobotDialog->resize(445, 129);
        verticalLayout = new QVBoxLayout(OpenRobotDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget = new QWidget(OpenRobotDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setEnabled(true);
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        pushButton_openfile = new QPushButton(widget);
        pushButton_openfile->setObjectName(QStringLiteral("pushButton_openfile"));
        pushButton_openfile->setMaximumSize(QSize(27, 27));

        horizontalLayout->addWidget(pushButton_openfile);


        verticalLayout->addWidget(widget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_create = new QPushButton(OpenRobotDialog);
        pushButton_create->setObjectName(QStringLiteral("pushButton_create"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_create->sizePolicy().hasHeightForWidth());
        pushButton_create->setSizePolicy(sizePolicy);
        pushButton_create->setMaximumSize(QSize(100, 50));

        horizontalLayout_2->addWidget(pushButton_create);

        pushButton_4 = new QPushButton(OpenRobotDialog);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);
        pushButton_4->setMaximumSize(QSize(100, 50));

        horizontalLayout_2->addWidget(pushButton_4);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(OpenRobotDialog);

        QMetaObject::connectSlotsByName(OpenRobotDialog);
    } // setupUi

    void retranslateUi(QDialog *OpenRobotDialog)
    {
        OpenRobotDialog->setWindowTitle(QApplication::translate("OpenRobotDialog", "OpenRobotDialog", Q_NULLPTR));
        label->setText(QApplication::translate("OpenRobotDialog", "Profile File", Q_NULLPTR));
        pushButton_openfile->setText(QApplication::translate("OpenRobotDialog", "...", Q_NULLPTR));
        pushButton_create->setText(QApplication::translate("OpenRobotDialog", "New", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("OpenRobotDialog", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class OpenRobotDialog: public Ui_OpenRobotDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENROBOTDIALOG_H
