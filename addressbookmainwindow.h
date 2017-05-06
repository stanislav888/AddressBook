#pragma once

#include <QMainWindow>
#include <QSortFilterProxyModel>
#include <QSqlDatabase>
#include "widgethelpers.h"

class QSqlTableModel;
class QLineEdit;

namespace Ui {
class AddressBookMainWindow;
}

class AddressBookMainWindow : public QMainWindow
{
	Q_OBJECT

	Ui::AddressBookMainWindow *ui;

	WidgetHelpers m_widgetHelpers;
	QSqlDatabase m_database;
	QSqlTableModel* m_personsModelPtr;
	QSortFilterProxyModel m_proxyModel;
	bool createDb( const QString& reason );
	bool openDb(const QString &path);
	void openExternalLink(const QLineEdit *edit);

public:
	explicit AddressBookMainWindow(QWidget *parent = 0);
	~AddressBookMainWindow();
	const static QString ADDRESS_TABLE_NAME;
	const static QString COUNTRY_NAME_COLUMN;
	const static QString COUNTRY_CODE_COLUMN;
	const static QString PERSONS_TABLE_NAME;
	const static QString ADDRESS_FK_COL_NAME;
	const static QString COUNTRY_FK_COL_NAME;

protected:
	void setAddress(const QVariant &newAddressId);

protected slots:
	void updateTable();

private slots:
	void on_newRecordButton_clicked();
	void on_deleteRecordButton_clicked();
	void updateForm();
	void on_changeAddressButton_clicked();
	void on_writeEmail_clicked();
	void on_makeCall_clicked();
	void on_deleteDbFileBtn_clicked();
	void fillTestData();
};
