#include <QFileDialog>
#include "setupdialog.h"
#include "ui_setupdialog.h"

#if (QT_VERSION >= QT_VERSION_CHECK(5, 4, 0))
	#include <QStandardPaths>
#endif

SetupDialog::SetupDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::SetupDialog)
{
	ui->setupUi(this);
}

SetupDialog::~SetupDialog()
{
	delete ui;
}

void SetupDialog::on_browseButton_clicked()
{
	QString appDataFolder;

#if (QT_VERSION >= QT_VERSION_CHECK(5, 4, 0))
	 appDataFolder = QStandardPaths::writableLocation( QStandardPaths::AppDataLocation );
#endif

	QString result = QFileDialog::getSaveFileName( this, "Choose DB file location"
								  , m_selectedFile.isEmpty() ? appDataFolder : m_selectedFile
															   , "*.sqlite" );
	ui->pathEdit->setText( result );
}

QString SetupDialog::selectedFile() const
{
	return ui->pathEdit->text();
}

void SetupDialog::setReasonText(const QString &reason)
{
	ui->reasonLabel->setText( reason );
}

