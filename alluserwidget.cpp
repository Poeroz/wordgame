#include "alluserwidget.h"
#include "ui_alluserwidget.h"

allUserWidget::allUserWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::allUserWidget) {
    ui->setupUi(this);
    showPlayerTable(QString("role = %1").arg(PLAYER));
}

allUserWidget::~allUserWidget() {
    delete ui;
}

void allUserWidget::sortByColumn(int col) {
    QSqlTableModel *pMode = dynamic_cast<QSqlTableModel *>(ui->tableView->model());
    bool ascending = (ui->tableView->horizontalHeader()->sortIndicatorSection()==col
                      && ui->tableView->horizontalHeader()->sortIndicatorOrder()==Qt::DescendingOrder);
    Qt::SortOrder order = ascending ? Qt::AscendingOrder : Qt::DescendingOrder;
    pMode->sort(col, order);
}

void allUserWidget::showPlayerTable(QString str) {
    qDebug() << str;
    QSqlDatabase userdb = QSqlDatabase::database("userConnect");
    if (!userdb.open()) {
        qDebug() << "not open!";
    }
    else {
        QSqlTableModel *pModel = new QSqlTableModel(this, userdb);
        pModel->setTable("user");
        pModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
        pModel->setFilter(str);
        pModel->select();
        pModel->removeColumn(QUESTIONCNT);
        pModel->removeColumn(ROLE);
        pModel->removeColumn(PASSWORD);
        pModel->removeColumn(USERNAME);
        pModel->setHeaderData(0, Qt::Horizontal, "昵称");
        pModel->setHeaderData(1, Qt::Horizontal, "等级");
        pModel->setHeaderData(2, Qt::Horizontal, "已闯关卡数");
        pModel->setHeaderData(3, Qt::Horizontal, "经验值");
        pModel->sort(0, Qt::AscendingOrder);

        ui->tableView->setModel(pModel);
        ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        ui->tableView->setSelectionBehavior(QAbstractItemView::QAbstractItemView::SelectRows);
        ui->tableView->verticalHeader()->hide();
        ui->tableView->horizontalHeader()->setSectionsClickable(true);
        connect(ui->tableView->horizontalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(sortByColumn(int)));
    }
}

void allUserWidget::showQuestionerTable(QString str) {
    qDebug() << str;
    QSqlDatabase userdb = QSqlDatabase::database("userConnect");
    if (!userdb.open()) {
        qDebug() << "not open!";
    }
    else {
        QSqlTableModel *pModel = new QSqlTableModel(this, userdb);
        pModel->setTable("user");
        pModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
        pModel->setFilter(str);
        pModel->select();
        pModel->removeColumn(EXPERIENCE);
        pModel->removeColumn(LEVELCNT);
        pModel->removeColumn(ROLE);
        pModel->removeColumn(PASSWORD);
        pModel->removeColumn(USERNAME);
        pModel->setHeaderData(0, Qt::Horizontal, "昵称");
        pModel->setHeaderData(1, Qt::Horizontal, "等级");
        pModel->setHeaderData(2, Qt::Horizontal, "出题数");
        pModel->sort(0, Qt::AscendingOrder);

        ui->tableView->setModel(pModel);
        ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        ui->tableView->setSelectionBehavior(QAbstractItemView::QAbstractItemView::SelectRows);
        ui->tableView->verticalHeader()->hide();
        ui->tableView->horizontalHeader()->setSectionsClickable(true);
        connect(ui->tableView->horizontalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(sortByColumn(int)));
    }
}

void allUserWidget::on_playerBtn_clicked() {
    showPlayerTable(QString("role = %1").arg(PLAYER));
}

void allUserWidget::on_questionerBtn_clicked() {
    showQuestionerTable(QString("role = %1").arg(QUESTIONER));
}

void allUserWidget::playerReceiveData(QString str) {
    showPlayerTable(str);
}

void allUserWidget::questionerReceiveData(QString str) {
    showQuestionerTable(str);
}

void allUserWidget::on_filterBtn_clicked() {
    QRadioButton* btn = qobject_cast<QRadioButton*>(ui->buttonGroup->checkedButton());
    QString roleName = btn->objectName();
    bool role;
    if (!QString::compare(roleName, "playerBtn")) {
        role = PLAYER;
    }
    else {
        role = QUESTIONER;
    }
    if (role == PLAYER) {
        playerFilterDialog *dlg = new playerFilterDialog;
        connect(dlg, SIGNAL(playerSendData(QString)), this, SLOT(playerReceiveData(QString)));
        dlg->exec();
    }
    else {
        questionerFilterDialog *dlg = new questionerFilterDialog;
        connect(dlg, SIGNAL(questionerSendData(QString)), this, SLOT(questionerReceiveData(QString)));
        dlg->exec();
    }
}

void allUserWidget::on_seeAllBtn_clicked() {
    QRadioButton* btn = qobject_cast<QRadioButton*>(ui->buttonGroup->checkedButton());
    QString roleName = btn->objectName();
    bool role;
    if (!QString::compare(roleName, "playerBtn")) {
        role = PLAYER;
    }
    else {
        role = QUESTIONER;
    }
    if (role == PLAYER) {
        showPlayerTable(QString("role = %1").arg(PLAYER));
    }
    else {
        showQuestionerTable(QString("role = %1").arg(QUESTIONER));
    }
}
