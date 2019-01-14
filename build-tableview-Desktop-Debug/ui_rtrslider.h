/********************************************************************************
** Form generated from reading UI file 'rtrslider.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RTRSLIDER_H
#define UI_RTRSLIDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RTRSlider
{
public:
    QSlider *horizontalSlider;
    QLabel *minLabel;
    QLabel *maxLabel;
    QLineEdit *lineEdit;
    QLabel *fieldName;
    QPushButton *coarseNeg;
    QPushButton *finePos;
    QPushButton *coarsePos;
    QPushButton *fineNeg;

    void setupUi(QWidget *RTRSlider)
    {
        if (RTRSlider->objectName().isEmpty())
            RTRSlider->setObjectName(QStringLiteral("RTRSlider"));
        RTRSlider->resize(494, 90);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(RTRSlider->sizePolicy().hasHeightForWidth());
        RTRSlider->setSizePolicy(sizePolicy);
        RTRSlider->setMinimumSize(QSize(494, 90));
        RTRSlider->setBaseSize(QSize(400, 62));
        horizontalSlider = new QSlider(RTRSlider);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(120, 20, 161, 61));
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setInvertedAppearance(false);
        horizontalSlider->setTickPosition(QSlider::NoTicks);
        minLabel = new QLabel(RTRSlider);
        minLabel->setObjectName(QStringLiteral("minLabel"));
        minLabel->setGeometry(QRect(110, 60, 60, 17));
        minLabel->setTextFormat(Qt::PlainText);
        maxLabel = new QLabel(RTRSlider);
        maxLabel->setObjectName(QStringLiteral("maxLabel"));
        maxLabel->setGeometry(QRect(240, 60, 60, 17));
        maxLabel->setTextFormat(Qt::PlainText);
        maxLabel->setAlignment(Qt::AlignCenter);
        lineEdit = new QLineEdit(RTRSlider);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(310, 40, 61, 25));
        lineEdit->setMaxLength(32766);
        fieldName = new QLabel(RTRSlider);
        fieldName->setObjectName(QStringLiteral("fieldName"));
        fieldName->setGeometry(QRect(130, 10, 141, 41));
        fieldName->setAlignment(Qt::AlignCenter);
        coarseNeg = new QPushButton(RTRSlider);
        coarseNeg->setObjectName(QStringLiteral("coarseNeg"));
        coarseNeg->setGeometry(QRect(10, 40, 41, 25));
        finePos = new QPushButton(RTRSlider);
        finePos->setObjectName(QStringLiteral("finePos"));
        finePos->setGeometry(QRect(390, 40, 41, 25));
        coarsePos = new QPushButton(RTRSlider);
        coarsePos->setObjectName(QStringLiteral("coarsePos"));
        coarsePos->setGeometry(QRect(440, 40, 41, 25));
        fineNeg = new QPushButton(RTRSlider);
        fineNeg->setObjectName(QStringLiteral("fineNeg"));
        fineNeg->setGeometry(QRect(60, 40, 41, 25));
        minLabel->raise();
        maxLabel->raise();
        lineEdit->raise();
        fieldName->raise();
        horizontalSlider->raise();
        coarseNeg->raise();
        finePos->raise();
        coarsePos->raise();
        fineNeg->raise();

        retranslateUi(RTRSlider);

        QMetaObject::connectSlotsByName(RTRSlider);
    } // setupUi

    void retranslateUi(QWidget *RTRSlider)
    {
        RTRSlider->setWindowTitle(QApplication::translate("RTRSlider", "Form", Q_NULLPTR));
        minLabel->setText(QApplication::translate("RTRSlider", "min", Q_NULLPTR));
        maxLabel->setText(QApplication::translate("RTRSlider", "max", Q_NULLPTR));
        fieldName->setText(QApplication::translate("RTRSlider", "JointName", Q_NULLPTR));
        coarseNeg->setText(QApplication::translate("RTRSlider", "-10", Q_NULLPTR));
        finePos->setText(QApplication::translate("RTRSlider", "+1", Q_NULLPTR));
        coarsePos->setText(QApplication::translate("RTRSlider", "+10", Q_NULLPTR));
        fineNeg->setText(QApplication::translate("RTRSlider", "-1", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RTRSlider: public Ui_RTRSlider {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RTRSLIDER_H
