/********************************************************************************
** Form generated from reading UI file 'repositiondialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPOSITIONDIALOG_H
#define UI_REPOSITIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog_Reposition
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_camera;
    QHBoxLayout *horizontalLayout_status;
    QLabel *label_status;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QFrame *frame_camera;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_view;
    QFrame *frame_robot;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_button;
    QPushButton *pushButton_accept;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_skip;
    QPushButton *pushButton_cancel;
    QPushButton *pushButton_continue;

    void setupUi(QDialog *Dialog_Reposition)
    {
        if (Dialog_Reposition->objectName().isEmpty())
            Dialog_Reposition->setObjectName(QStringLiteral("Dialog_Reposition"));
        Dialog_Reposition->resize(1200, 900);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Dialog_Reposition->sizePolicy().hasHeightForWidth());
        Dialog_Reposition->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(Dialog_Reposition);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_camera = new QLabel(Dialog_Reposition);
        label_camera->setObjectName(QStringLiteral("label_camera"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_camera->sizePolicy().hasHeightForWidth());
        label_camera->setSizePolicy(sizePolicy1);
        label_camera->setMaximumSize(QSize(16777215, 30));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_camera->setFont(font);

        verticalLayout->addWidget(label_camera);

        horizontalLayout_status = new QHBoxLayout();
        horizontalLayout_status->setSpacing(10);
        horizontalLayout_status->setObjectName(QStringLiteral("horizontalLayout_status"));
        horizontalLayout_status->setContentsMargins(-1, 0, -1, -1);
        label_status = new QLabel(Dialog_Reposition);
        label_status->setObjectName(QStringLiteral("label_status"));

        horizontalLayout_status->addWidget(label_status);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_status->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_status);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(15);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        frame_camera = new QFrame(Dialog_Reposition);
        frame_camera->setObjectName(QStringLiteral("frame_camera"));
        frame_camera->setFrameShape(QFrame::NoFrame);
        frame_camera->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_camera);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_view = new QLabel(frame_camera);
        label_view->setObjectName(QStringLiteral("label_view"));
        label_view->setFrameShape(QFrame::Box);

        verticalLayout_3->addWidget(label_view);


        horizontalLayout->addWidget(frame_camera);

        frame_robot = new QFrame(Dialog_Reposition);
        frame_robot->setObjectName(QStringLiteral("frame_robot"));
        frame_robot->setFrameShape(QFrame::NoFrame);
        frame_robot->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_robot);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);

        horizontalLayout->addWidget(frame_robot);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_button = new QHBoxLayout();
        horizontalLayout_button->setSpacing(6);
        horizontalLayout_button->setObjectName(QStringLiteral("horizontalLayout_button"));
        horizontalLayout_button->setContentsMargins(0, -1, 10, -1);
        pushButton_accept = new QPushButton(Dialog_Reposition);
        pushButton_accept->setObjectName(QStringLiteral("pushButton_accept"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_accept->sizePolicy().hasHeightForWidth());
        pushButton_accept->setSizePolicy(sizePolicy2);
        pushButton_accept->setMinimumSize(QSize(150, 50));
        pushButton_accept->setMaximumSize(QSize(150, 50));

        horizontalLayout_button->addWidget(pushButton_accept);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_button->addItem(horizontalSpacer);

        pushButton_skip = new QPushButton(Dialog_Reposition);
        pushButton_skip->setObjectName(QStringLiteral("pushButton_skip"));
        pushButton_skip->setMinimumSize(QSize(150, 50));
        pushButton_skip->setMaximumSize(QSize(150, 50));

        horizontalLayout_button->addWidget(pushButton_skip);

        pushButton_cancel = new QPushButton(Dialog_Reposition);
        pushButton_cancel->setObjectName(QStringLiteral("pushButton_cancel"));
        sizePolicy2.setHeightForWidth(pushButton_cancel->sizePolicy().hasHeightForWidth());
        pushButton_cancel->setSizePolicy(sizePolicy2);
        pushButton_cancel->setMinimumSize(QSize(150, 50));

        horizontalLayout_button->addWidget(pushButton_cancel);

        pushButton_continue = new QPushButton(Dialog_Reposition);
        pushButton_continue->setObjectName(QStringLiteral("pushButton_continue"));
        pushButton_continue->setMinimumSize(QSize(150, 50));
        pushButton_continue->setMaximumSize(QSize(150, 50));

        horizontalLayout_button->addWidget(pushButton_continue);


        verticalLayout->addLayout(horizontalLayout_button);

        verticalLayout->setStretch(2, 1);

        retranslateUi(Dialog_Reposition);

        QMetaObject::connectSlotsByName(Dialog_Reposition);
    } // setupUi

    void retranslateUi(QDialog *Dialog_Reposition)
    {
        Dialog_Reposition->setWindowTitle(QApplication::translate("Dialog_Reposition", "Reposition Camera", Q_NULLPTR));
        label_camera->setText(QApplication::translate("Dialog_Reposition", "+X Camera", Q_NULLPTR));
        label_status->setText(QApplication::translate("Dialog_Reposition", "TextLabel", Q_NULLPTR));
        label_view->setText(QString());
        pushButton_accept->setText(QApplication::translate("Dialog_Reposition", "Accept", Q_NULLPTR));
        pushButton_skip->setText(QApplication::translate("Dialog_Reposition", "Skip", Q_NULLPTR));
        pushButton_cancel->setText(QApplication::translate("Dialog_Reposition", "Cancel", Q_NULLPTR));
        pushButton_continue->setText(QApplication::translate("Dialog_Reposition", "Continue", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog_Reposition: public Ui_Dialog_Reposition {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPOSITIONDIALOG_H
