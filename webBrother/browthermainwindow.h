#ifndef BROWTHERMAINWINDOW_H
#define BROWTHERMAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QLineEdit>
#include <QMenu>
#include <QProgressBar>
#include <QToolBar>
#include <QMenuBar>
#include <QMenu>
#include <QIcon>
#include <QtWebKitWidgets>
#include <QTabWidget>


class BrotherMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit BrotherMainWindow(QWidget *parent = 0);


signals:

public slots:
    void newTab();
    void killTab();
    void killTab(int index);
    void searchPage();

private :
    //navigation
    QAction *actionGo;
    QAction *actionRefresh;
    QAction *actionPrecedent;
    QAction *actionSuivant;
    QAction *actionStop;
    QAction *actionHome;

    //onglets, fenetre
    QAction *actionNewTab;
    QAction *actionKillTab;
    QAction *actionQuitter;

    //page principale :
    QTabWidget *onglets;

    //barre d'adresse
    QLineEdit *barreAdresse;

    //menus :
    QMenu *menuFichier;
    QMenu *menuNavigation;
    QMenu *menuApropos;

    //barre de progression
    QProgressBar *chargement;

    //toolBar
    QToolBar *navToolBar;

    //fonction d'initialisation
    void initMenuFichier();
    void initMenuNav();
    void initNavToolBar();
    void initActions();

    QTabWidget *getCurrentTab();
    QWebView *getCurrentPage();
};

#endif // BROWTHERMAINWINDOW_H
