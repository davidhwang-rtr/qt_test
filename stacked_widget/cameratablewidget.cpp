#include "cameratablewidget.h"
#include "ui_widget.h"
#include "QPushButton"
#include "QHBoxLayout"
#include "QLabel"
#include <QDebug>

CameraTableWidget::CameraTableWidget(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Widget)
{
  ui->setupUi(this);

  int numCol = 4;
  int numRow = 3;
  ui->tableWidget->setRowCount(numRow);
  ui->tableWidget->setColumnCount(numCol);

  connect(ui->tableWidget, SIGNAL(itemClicked(QTableWidgetItem *)), this, SLOT(tableItemClicked(QTableWidgetItem *)));
  connect(ui->tableWidget, SIGNAL(cellClicked(int,int)), this, SLOT(tableCellClicked(int,int)));
    connect(ui->tableWidget, SIGNAL(cellPressed(int,int)), this, SLOT(tableCellPressed(int,int)));

    // table header


    // populate table

  for(int row=0 ; row< numRow; row++)
    {
        for(int col=0 ; col< numCol; col++)
          {
             if(col == 0) // icon. ToDo: another solution is to use delegate
              {
                QLabel *lbl_item = new QLabel(ui->tableWidget);
                QIcon icon(":/images/READY_ok.png");
                lbl_item ->setPixmap(icon.pixmap(QSize(48,48)));
                lbl_item ->setAlignment(Qt::AlignHCenter);
                ui->tableWidget->setCellWidget(row, col, lbl_item);
              }
              else if(col == 1)  // pushbutton
                {
                  QWidget* pWidget = new QWidget();
                  QPushButton* btn_edit = new QPushButton(ui->tableWidget);
                  btn_edit->setObjectName(QString("%1").arg(row));
                  connect(btn_edit, SIGNAL(clicked()), this,    SLOT(CellButtonClicked()));
                  btn_edit->setText("Position");
                  QHBoxLayout* pLayout = new QHBoxLayout(pWidget);
                  pLayout->addWidget(btn_edit);
                  pLayout->setAlignment(Qt::AlignCenter);
                  pLayout->setContentsMargins(0, 0, 0, 0);
                  pWidget->setLayout(pLayout);
                  ui->tableWidget->setCellWidget(row, col, pWidget);
                }
              else if(col == 2) // checkbox
                {
                  QTableWidgetItem *item2 = new QTableWidgetItem("Item2");
                  item2->setCheckState(Qt::Checked);
                  ui->tableWidget->setItem(row, col, item2);
                }
              else // qstring
                {
                  QTableWidgetItem *newItem = new QTableWidgetItem(tr("%1").arg(
                    (row+1)*(col+1)));
                  newItem->setFlags(newItem->flags() ^ Qt::ItemIsEditable);
                  ui->tableWidget->setItem(row, col, newItem);
                }
          }
    }
}

CameraTableWidget::~CameraTableWidget()
{
  delete ui;
}


// cell clicked

void CameraTableWidget::tableCellClicked(int row, int col)
{
  qDebug() << "Cell Clicked: Column:" << col << " Row:" << row;
}
//

void CameraTableWidget::tableItemClicked(QTableWidgetItem *item)
{
  int col = ui->tableWidget->currentColumn();
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


