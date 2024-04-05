#include "CreateGroupWidget.h"
#include "pub.cache.h"
#include <qDebug>
#include <QDateTime>
#include <QTableWidgetItem>

#pragma execution_character_set("utf-8")

CreateGroupWgt::CreateGroupWgt(QWidget* parent)
	: QWidget(parent)
	, m_pUi(new Ui::CreateGroupWgt())
{
	m_pUi->setupUi(this);
	setSlots();

	/*m_pUi->MessageWindowLstWgt->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	m_pUi->MessageWindowLstWgt->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);*/

    // 设置列宽
    m_pUi->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // 设置整行选中
    m_pUi->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

    // 去除垂直表头
    m_pUi->tableWidget->verticalHeader()->setVisible(false);

    // 去除选中虚线框
    m_pUi->tableWidget->setFocusPolicy(Qt::NoFocus);

    // 禁止编辑
    m_pUi->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

CreateGroupWgt::~CreateGroupWgt()
{
	delete m_pUi;
}

void CreateGroupWgt::setSlots()
{
    connect(m_pUi->tableWidget, &QTableWidget::cellDoubleClicked, this, &CreateGroupWgt::on_tableWidget_cellClicked);
    connect(m_pUi->pushButton, &QPushButton::clicked, this, &CreateGroupWgt::onSendPb);
}

void CreateGroupWgt::getFriendship()
{
    // 清空表格
    m_pUi->tableWidget->clearContents();
    m_pUi->tableWidget->setRowCount(0);

	emit getFriendship_Message_Wgt();
}

void CreateGroupWgt::showFriendship(std::vector<User>& arrUser)
{
    m_arrFriend = arrUser;
    // 清空表格
    m_pUi->tableWidget->clearContents();
    m_pUi->tableWidget->setRowCount(0);

    // 添加项
    for (int i = 0; i < arrUser.size(); i++)
    {
        int curRow = m_pUi->tableWidget->rowCount();
        m_pUi->tableWidget->insertRow(curRow);
        m_pUi->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(i + 1)));
        m_pUi->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(arrUser[i].getName())));

        // 添加选择框
        QTableWidgetItem* check = new QTableWidgetItem();
        check->setCheckState(Qt::Unchecked);
        m_pUi->tableWidget->setItem(i, 0, check);

        // 元素居中
        //m_pUi->tableWidget->item(i, 0)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        //m_pUi->tableWidget->item(i, 1)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        //m_pUi->tableWidget->item(i, 2)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    }
}

void CreateGroupWgt::on_tableWidget_cellClicked(int row, int column)
{
    //判断选择状态
    if (m_pUi->tableWidget->item(row, 0)->checkState() == Qt::Checked)
    {
        //设置选择状态
        m_pUi->tableWidget->item(row, 0)->setCheckState(Qt::Unchecked);
    }
    else
    {
        m_pUi->tableWidget->item(row, 0)->setCheckState(Qt::Checked);
    }
}

void CreateGroupWgt::onSendPb()
{
    std::vector<User> friendSelected;
    QString groupName = m_pUi->lineEdit->text();
    int cnt = m_pUi->tableWidget->rowCount();
    for (int i = 0; i < cnt; ++i)
    {
        if (m_pUi->tableWidget->item(i, 0)->checkState() == Qt::Checked)
        {
            friendSelected.push_back(m_arrFriend[i]);
        }
    }
    emit createGroup_Message_Wgt(groupName, friendSelected);
}

void CreateGroupWgt::showCreateGroupAck()
{
    m_pCreateGroupAnsWgt = new CreateGroupAnsWgt;
    m_pCreateGroupAnsWgt->setWindowFlags(m_pCreateGroupAnsWgt->windowFlags() | Qt::Dialog);
    m_pCreateGroupAnsWgt->setWindowModality(Qt::ApplicationModal); // 阻塞除当前窗体之外的所有的窗体
    m_pCreateGroupAnsWgt->setWindowFlags(Qt::FramelessWindowHint | windowFlags());    // 去窗口边框
    m_pCreateGroupAnsWgt->setAns();

    m_pCreateGroupAnsWgt->show();
}
