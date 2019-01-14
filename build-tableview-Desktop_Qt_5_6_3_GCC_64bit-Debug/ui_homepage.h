/********************************************************************************
** Form generated from reading UI file 'homepage.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEPAGE_H
#define UI_HOMEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HomepageWidget
{
public:
    QLabel *label;

    void setupUi(QWidget *HomepageWidget)
    {
        if (HomepageWidget->objectName().isEmpty())
            HomepageWidget->setObjectName(QStringLiteral("HomepageWidget"));
        HomepageWidget->resize(1267, 714);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(HomepageWidget->sizePolicy().hasHeightForWidth());
        HomepageWidget->setSizePolicy(sizePolicy);
        HomepageWidget->setAutoFillBackground(false);
        label = new QLabel(HomepageWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 50, 300, 100));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMaximumSize(QSize(300, 100));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/rtr_image/realtime_robotics.png")));
        label->setScaledContents(true);

        retranslateUi(HomepageWidget);

        QMetaObject::connectSlotsByName(HomepageWidget);
    } // setupUi

    void retranslateUi(QWidget *HomepageWidget)
    {
        HomepageWidget->setWindowTitle(QApplication::translate("HomepageWidget", "Widget", Q_NULLPTR));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class HomepageWidget: public Ui_HomepageWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEPAGE_H
