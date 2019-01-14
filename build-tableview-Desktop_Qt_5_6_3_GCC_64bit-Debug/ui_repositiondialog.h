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
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog_Reposition
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QFrame *frame_camera;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_camera;
    QLabel *label_view;
    QLabel *label_status;
    QFrame *frame_robot;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Dialog_Reposition)
    {
        if (Dialog_Reposition->objectName().isEmpty())
            Dialog_Reposition->setObjectName(QStringLiteral("Dialog_Reposition"));
        Dialog_Reposition->resize(764, 413);
        verticalLayoutWidget = new QWidget(Dialog_Reposition);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 20, 721, 371));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        frame_camera = new QFrame(verticalLayoutWidget);
        frame_camera->setObjectName(QStringLiteral("frame_camera"));
        frame_camera->setFrameShape(QFrame::NoFrame);
        frame_camera->setFrameShadow(QFrame::Raised);
        verticalLayoutWidget_2 = new QWidget(frame_camera);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(9, 10, 341, 321));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_camera = new QLabel(verticalLayoutWidget_2);
        label_camera->setObjectName(QStringLiteral("label_camera"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_camera->sizePolicy().hasHeightForWidth());
        label_camera->setSizePolicy(sizePolicy);
        label_camera->setMaximumSize(QSize(16777215, 30));

        verticalLayout_2->addWidget(label_camera);

        label_view = new QLabel(verticalLayoutWidget_2);
        label_view->setObjectName(QStringLiteral("label_view"));

        verticalLayout_2->addWidget(label_view);

        label_status = new QLabel(verticalLayoutWidget_2);
        label_status->setObjectName(QStringLiteral("label_status"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_status->sizePolicy().hasHeightForWidth());
        label_status->setSizePolicy(sizePolicy1);
        label_status->setMaximumSize(QSize(16777215, 30));

        verticalLayout_2->addWidget(label_status);


        horizontalLayout->addWidget(frame_camera);

        frame_robot = new QFrame(verticalLayoutWidget);
        frame_robot->setObjectName(QStringLiteral("frame_robot"));
        frame_robot->setFrameShape(QFrame::StyledPanel);
        frame_robot->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(frame_robot);


        verticalLayout->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(verticalLayoutWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(Dialog_Reposition);

        QMetaObject::connectSlotsByName(Dialog_Reposition);
    } // setupUi

    void retranslateUi(QDialog *Dialog_Reposition)
    {
        Dialog_Reposition->setWindowTitle(QApplication::translate("Dialog_Reposition", "Reposition Camera", Q_NULLPTR));
        label_camera->setText(QApplication::translate("Dialog_Reposition", "+X Camera", Q_NULLPTR));
        label_view->setText(QString());
        label_status->setText(QApplication::translate("Dialog_Reposition", "Status: ", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog_Reposition: public Ui_Dialog_Reposition {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPOSITIONDIALOG_H
