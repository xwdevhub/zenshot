#ifndef ZTSETTING_LIST_H_
#define ZTSETTING_LIST_H_

#include "ui_zentaosettinglist.h"

#include "ztsettinglistitem.h"

#include "usrmetatype.h"

#include <QListWidget>

class ZTSettingList : public QWidget {
	Q_OBJECT

public:
	ZTSettingList(QWidget* parent);
	~ZTSettingList() {}

signals:
	void AddConfigItem(string_ptr name, string_ptr url, string_ptr usr, string_ptr pass);
	void SaveSiteListConfig();
	void CurrentRowSelected(string_ptr name, string_ptr url, string_ptr usr, string_ptr pass);
	void SaveSiteConfig();

private slots:
	void OnRealRemoveItem(ZTSettingListItem* w);
	void OnAddConfigItem(string_ptr name, string_ptr url, string_ptr usr, string_ptr pass);
	void OnSaveSiteListConfig();
	void OncurrentRowChanged(int index);
	void OnSaveSiteConfig();

protected:
	virtual void paintEvent(QPaintEvent* event) override;
	virtual void showEvent(QShowEvent* event) override;
	virtual void hideEvent(QHideEvent* event) override;
	virtual void closeEvent(QCloseEvent* event) override;

private:
	void InitUI();
	void SetupUI();
	void SetupSignal();

	QListWidgetItem* FindHiddenItem();

private:
	Ui::zentaosettinglist ui;

	QListWidget* m_listWidget;
}; // ZTSettingList

#endif // ZTSETTING_LIST_H_