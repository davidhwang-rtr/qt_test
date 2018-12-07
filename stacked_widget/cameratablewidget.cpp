#include "cameratablewidget.h"
#include "QPushButton"
#include "QHBoxLayout"
#include "QLabel"
#include <QDebug>

CameraTableWidget::CameraTableWidget(QWidget *widget) :
  QWidget(widget)
{
//  ui->setupUi(this);

  QMetaObject::connectSlotsByName(widget);

  // setup UI
  tableWidget_Robot = new QTableWidget(widget);
  tableWidget_Robot->setObjectName(QStringLiteral("tableWidget_Robot"));
  tableWidget_Robot->setGeometry(QRect(90, 61, 521, 291));

  int numCol = 4;
  int numRow = 3;
  tableWidget_Robot->setRowCount(numRow);
  tableWidget_Robot->setColumnCount(numCol);

  connect(tableWidget_Robot, SIGNAL(itemClicked(QTableWidgetItem *)), this, SLOT(tableItemClicked(QTableWidgetItem *)));
  connect(tableWidget_Robot, SIGNAL(cellClicked(int,int)), this, SLOT(tableCellClicked(int,int)));
  connect(tableWidget_Robot, SIGNAL(cellPressed(int,int)), this, SLOT(tableCellPressed(int,int)));

    // table header


    // populate table

  for(int row=0 ; row< numRow; row++)
    {
        for(int col=0 ; col< numCol; col++)
          {
             if(col == 0) // icon. ToDo: another solution is to use delegate
              {
                QLabel *lbl_item = new QLabel(tableWidget_Robot);
                QIcon icon(":/images/icon/READY_ok.png");
                lbl_item ->setPixmap(icon.pixmap(QSize(48,48)));
                lbl_item ->setAlignment(Qt::AlignHCenter);
                tableWidget_Robot->setCellWidget(row, col, lbl_item);
              }
              else if(col == 1)  // pushbutton
                {
                  QWidget* pWidget = new QWidget();
                  QPushButton* btn_edit = new QPushButton(tableWidget_Robot);
                  btn_edit->setObjectName(QString("%1").arg(row));
                  connect(btn_edit, SIGNAL(clicked()), this,    SLOT(CellButtonClicked()));
                  btn_edit->setText("Position");
                  QHBoxLayout* pLayout = new QHBoxLayout(pWidget);
                  pLayout->addWidget(btn_edit);
                  pLayout->setAlignment(Qt::AlignCenter);
                  pLayout->setContentsMargins(0, 0, 0, 0);
                  pWidget->setLayout(pLayout);
                  tableWidget_Robot->setCellWidget(row, col, pWidget);
                }
              else if(col == 2) // checkbox
                {
                  QTableWidgetItem *item2 = new QTableWidgetItem("Item2");
                  item2->setCheckState(Qt::Checked);
                  tableWidget_Robot->setItem(row, col, item2);
                }
              else // qstring
                {
                  QTableWidgetItem *newItem = new QTableWidgetItem(tr("%1").arg(
                    (row+1)*(col+1)));
                  newItem->setFlags(newItem->flags() ^ Qt::ItemIsEditable);
                  tableWidget_Robot->setItem(row, col, newItem);
                }
          }
    }
}

CameraTableWidget::~CameraTableWidget()
{

}


// cell clicked

void CameraTableWidget::tableCellClicked(int row, int col)
{
  qDebug() << "Cell Clicked: Column:" << col << " Row:" << row;
}
//

void CameraTableWidget::tableItemClicked(QTableWidgetItem *item)
{
  int col = tableWidget_Robot->currentColumn();
  qDebug() << "Current Column" << col;
}
// row cl

void CameraTableWidget::tableCellPressed(int row, int col)
{
  qDebug() << "Cell Activated: Column:" << col << " Row:" << row;
}

void CameraTableWidget::CellButtonClicked()
{

 //   by this line I can get the sender of signal
 QPushButton *pb = qobject_cast<QPushButton *>(QObject::sender());

 int row = pb->objectName().toInt();
   qDebug() << "Button clicked: row:" << row;
}


// table clicked


