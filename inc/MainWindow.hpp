#ifndef __MAINWINDOW_HPP__
#define __MAINWINDOW_HPP__

#include <QtGui>
#include <map>

#include "Data.hpp"
#include "Database.hpp"
#include "Exceptions.hpp"
#include "Series.hpp"
#include "ui_MainWindow.h"


class MainWindow : public QMainWindow
{
Q_OBJECT

Q_PROPERTY(QObject* series READ getSeries NOTIFY seriesChanged)
Q_PROPERTY(QObject* viewSessionModel READ getViewSessions NOTIFY viewSessionsChanged)
Q_PROPERTY(QObject* history READ getHistory NOTIFY historyChanged)

signals:
    void viewSessionsChanged();
    void historyChanged();
    void seriesChanged();

public:
  MainWindow();

  int         GetValidSeriesRow();
  int         GetSeriesRow() const { return GetSeriesIndex().row(); }
  QString     GetSelectedSeriesName() const;
  QString     GetSelectedSeriesName(const QModelIndex& index) const;
  int         GetSeriesID() const {return seriesList_.record(GetSeriesRow()).value("id").toInt();}
  QModelIndex GetSeriesIndex() const { return ui_.tableView_series->currentIndex(); }

  QObject*    getSeries(){ return activeSeries_; }
  QObject*    getViewSessions();
  QObject*    getHistory();

  QSqlTableModel& getSeriesModel(){ return seriesList_; }

  //int        GetSessionRow() { return GetSessionIndex().row(); }
  //ViewSessionID GetSessionID() { return ViewSessionID(sessionList_.record(GetSessionRow()).value("id").toInt()); }
  //QModelIndex GetSessionIndex() { return ui_.tableView_sessions->currentIndex(); }
  
  //Episode::Index GetLastViewedEpisode() const;
  void       SelectSeries(SeriesID id);

public slots:
  void OnSeriesSelected(const QModelIndex& index);
  void SelectViewSession(ViewSessionIndex id);

  void AddSeries();
  void RemoveSeries();
  void AddViewSession();
  void RemoveViewSession();
  void ViewEpisode();
  void ViewNextEpisode();
  void MarkNextEpisodeViewed();

  void ShowSeriesSettings();
  void RefreshEpisodesList();
  
private:
  //EpisodeList::DirectoryList GetDirectoryList() const;
        Series* GetActiveSeries();
  const Series* GetActiveSeries() const;
  bool CheckSingleSelectedSeries();
  bool CheckSingleViewSessionSelected();

  void WarnSelectViewSession();

private:
  Ui_MainWindow ui_;

  std::map<QString, Series::Ptr> seriesMap_;
  Series* activeSeries_ = {};

  QSqlTableModel seriesList_;
};


#endif // __MAINWINDOW_HPP__