#include "browthermainwindow.h"
#include <QApplication>
#include <iostream>
#include <QVBoxLayout>

BrotherMainWindow::BrotherMainWindow(QWidget *parent) : QMainWindow(parent)
{
    initActions();
    initMenuFichier();
    initMenuNav();
    initNavToolBar();

    onglets = new QTabWidget;
    this->setCentralWidget(onglets);
    onglets->setTabsClosable(true);
    newTab();
}

void BrotherMainWindow::newTab()
{

    QWidget *tabWindowWidget = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout;
    QWebView *webView= new QWebView();
    layout->addWidget(webView);
    tabWindowWidget->setLayout(layout);

    onglets->addTab(tabWindowWidget, "blank");
    if(getCurrentPage() == NULL)
    {
        std::cerr << "NO PAGE ATTACHED\n";
    }
    connect(onglets, SIGNAL(tabCloseRequested(int)), this, SLOT(killTab(int)));

}

void BrotherMainWindow::killTab()
{
    onglets->removeTab(onglets->currentIndex());
}

void BrotherMainWindow::killTab(int index)
{
    onglets->removeTab(index);
}

void BrotherMainWindow::searchPage()
{
    std::cerr << barreAdresse->text().toStdString() <<std::endl;
    QUrl newUrl(barreAdresse->text(),QUrl::StrictMode);
    newUrl.resolved(newUrl);

    getCurrentPage()->load(QUrl(barreAdresse->text(),QUrl::StrictMode));
}



void BrotherMainWindow::initMenuFichier()
{
    menuFichier = menuBar()->addMenu("Fichier");
    menuFichier->addAction(actionNewTab  );
    menuFichier->addAction(actionKillTab );
    menuFichier->addAction(actionQuitter );
    connect(actionQuitter, SIGNAL(triggered(bool)), qApp, SLOT(quit()));
    connect(actionNewTab, SIGNAL(triggered(bool)), this, SLOT(newTab()));
    connect(actionKillTab, SIGNAL(triggered(bool)), this, SLOT(killTab()));
}

void BrotherMainWindow::initMenuNav()
{
    menuNavigation = menuBar()->addMenu("Navigation");
    menuNavigation->addAction(actionRefresh         );
    menuNavigation->addAction(actionPrecedent       );
    menuNavigation->addAction(actionSuivant         );
    menuNavigation->addAction(actionStop            );
    menuNavigation->addAction(actionHome            );
    menuNavigation->addAction(actionGo              );

}

void BrotherMainWindow::initNavToolBar()
{
    navToolBar = addToolBar("Navigation");
    navToolBar->addAction(actionRefresh     );
    navToolBar->addAction(actionPrecedent   );
    navToolBar->addAction(actionSuivant     );
    navToolBar->addAction(actionStop        );
    navToolBar->addAction(actionHome        );
    navToolBar->addWidget(barreAdresse      );
    navToolBar->addAction(actionGo          );
}

void BrotherMainWindow::initActions()
{
    actionGo          = new QAction(QIcon("../icons/go.png" ) ,"Go"        ,this);
    actionRefresh     = new QAction(QIcon("../icons/actu.png"),"Rafraichir",this);
    actionPrecedent   = new QAction(QIcon("../icons/prec.png"),"Précédent" ,this);
    actionSuivant     = new QAction(QIcon("../icons/suiv.png"),"Suivant"   ,this);
    actionStop        = new QAction(QIcon("../icons/stop.png"),"Stop"      ,this);
    actionHome        = new QAction(QIcon("../icons/home.png"),"Home"      ,this);
    actionNewTab      = new QAction("Nouvel onglet"           ,this);
    actionKillTab     = new QAction("Supprimer onglet"        ,this);
    actionQuitter     = new QAction("Quitter"                 ,this);
    barreAdresse      = new QLineEdit();

    connect(actionGo    , SIGNAL(triggered(bool)), this, SLOT(searchPage()));
    connect(barreAdresse, SIGNAL(returnPressed()), this, SLOT(searchPage()));

}

QWebView *BrotherMainWindow::getCurrentPage()
{
    return onglets->currentWidget()->findChild<QWebView *>();
}

QTabWidget* BrotherMainWindow::getCurrentTab()
{
    return dynamic_cast<QTabWidget*>(onglets->currentWidget());
}

