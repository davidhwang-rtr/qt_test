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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HomepageWidget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_calibration;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *HomepageWidget)
    {
        if (HomepageWidget->objectName().isEmpty())
            HomepageWidget->setObjectName(QStringLiteral("HomepageWidget"));
        HomepageWidget->resize(1902, 1961);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(HomepageWidget->sizePolicy().hasHeightForWidth());
        HomepageWidget->setSizePolicy(sizePolicy);
        HomepageWidget->setAutoFillBackground(false);
        verticalLayout = new QVBoxLayout(HomepageWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(HomepageWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMaximumSize(QSize(300, 100));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/rtr_image/realtime_robotics narrow transparent.png")));
        label->setScaledContents(true);

        verticalLayout->addWidget(label);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        verticalLayout->addItem(verticalSpacer);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(20);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_4 = new QLabel(HomepageWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setMinimumSize(QSize(200, 200));
        label_4->setMaximumSize(QSize(400, 400));
        QFont font;
        font.setPointSize(14);
        label_4->setFont(font);
        label_4->setFrameShape(QFrame::Box);
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 0, 3, 1, 1);

        label_3 = new QLabel(HomepageWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMinimumSize(QSize(200, 200));
        label_3->setMaximumSize(QSize(400, 400));
        QFont font1;
        font1.setPointSize(13);
        label_3->setFont(font1);
        label_3->setFrameShape(QFrame::Box);
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 5, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        pushButton_calibration = new QPushButton(HomepageWidget);
        pushButton_calibration->setObjectName(QStringLiteral("pushButton_calibration"));
        sizePolicy.setHeightForWidth(pushButton_calibration->sizePolicy().hasHeightForWidth());
        pushButton_calibration->setSizePolicy(sizePolicy);
        pushButton_calibration->setMinimumSize(QSize(200, 200));
        pushButton_calibration->setMaximumSize(QSize(400, 400));
        pushButton_calibration->setFont(font);
        pushButton_calibration->setFlat(false);

        gridLayout->addWidget(pushButton_calibration, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        retranslateUi(HomepageWidget);

        QMetaObject::connectSlotsByName(HomepageWidget);
    } // setupUi

    void retranslateUi(QWidget *HomepageWidget)
    {
        HomepageWidget->setWindowTitle(QApplication::translate("HomepageWidget", "RTR Tool", Q_NULLPTR));
        label->setText(QString());
        label_4->setText(QApplication::translate("HomepageWidget", "Tool Kit", Q_NULLPTR));
        label_3->setText(QApplication::translate("HomepageWidget", "3D View", Q_NULLPTR));
        pushButton_calibration->setText(QApplication::translate("HomepageWidget", "Camera\n"
"Calibration", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class HomepageWidget: public Ui_HomepageWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEPAGE_H
