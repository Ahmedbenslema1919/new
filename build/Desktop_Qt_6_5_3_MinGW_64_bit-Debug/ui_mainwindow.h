/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox;
    QGroupBox *groupBox_4;
    QLineEdit *nb_c;
    QComboBox *type_c;
    QLabel *label_8;
    QLineEdit *capacite;
    QComboBox *status_d;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_7;
    QLabel *label_9;
    QLabel *label_10;
    QComboBox *service;
    QComboBox *status_n;
    QPushButton *annuler;
    QPushButton *ajouter;
    QWidget *tab_2;
    QTableView *aff;
    QLineEdit *supp;
    QPushButton *supprimer;
    QPushButton *Trie;
    QComboBox *tri;
    QLineEdit *valeur;
    QPushButton *Rechercher;
    QPushButton *pdf;
    QComboBox *rech;
    QPushButton *verifier_chambre;
    QWidget *tab_3;
    QGroupBox *groupBox_2;
    QPushButton *modifier;
    QGroupBox *groupBox_3;
    QLineEdit *nb_c2;
    QComboBox *type_c2;
    QLineEdit *capacite_2;
    QComboBox *status_d2;
    QComboBox *service2;
    QComboBox *status_n2;
    QLabel *label_19;
    QLabel *label_18;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLineEdit *id_m;
    QPushButton *recuperer;
    QWidget *tab_4;
    QGraphicsView *stat;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1221, 885);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(10, 10, 1261, 601));
        QFont font;
        font.setBold(true);
        tabWidget->setFont(font);
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        tab = new QWidget();
        tab->setObjectName("tab");
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 20, 1141, 511));
        groupBox->setStyleSheet(QString::fromUtf8(""));
        groupBox_4 = new QGroupBox(groupBox);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(10, 20, 1151, 521));
        groupBox_4->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    background: qlineargradient(\n"
"        spread:pad, \n"
"        x1:0, y1:0, x2:1, y2:1, \n"
"        stop:0 #CEBEA7,   \n"
"        stop:0.25 #8F959A,\n"
"        stop:0.5 #4B667B,  \n"
"        stop:0.75 #3B4672, \n"
"        stop:1 #22223B     \n"
"    );\n"
"    color: #F2E9E4;\n"
"    border: 2px solid #22223B;\n"
"    border-radius: 10px; \n"
"    margin-top: 15px;\n"
"}"));
        nb_c = new QLineEdit(groupBox_4);
        nb_c->setObjectName("nb_c");
        nb_c->setGeometry(QRect(380, 140, 113, 28));
        type_c = new QComboBox(groupBox_4);
        type_c->addItem(QString());
        type_c->addItem(QString());
        type_c->addItem(QString());
        type_c->setObjectName("type_c");
        type_c->setGeometry(QRect(390, 200, 91, 28));
        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(200, 210, 151, 20));
        capacite = new QLineEdit(groupBox_4);
        capacite->setObjectName("capacite");
        capacite->setGeometry(QRect(370, 280, 113, 28));
        status_d = new QComboBox(groupBox_4);
        status_d->addItem(QString());
        status_d->addItem(QString());
        status_d->setObjectName("status_d");
        status_d->setGeometry(QRect(380, 370, 101, 28));
        label_11 = new QLabel(groupBox_4);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(680, 200, 141, 20));
        label_12 = new QLabel(groupBox_4);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(680, 140, 141, 20));
        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(190, 140, 171, 20));
        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(220, 290, 63, 20));
        label_10 = new QLabel(groupBox_4);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(180, 370, 161, 20));
        service = new QComboBox(groupBox_4);
        service->addItem(QString());
        service->addItem(QString());
        service->addItem(QString());
        service->addItem(QString());
        service->addItem(QString());
        service->setObjectName("service");
        service->setGeometry(QRect(830, 140, 101, 28));
        status_n = new QComboBox(groupBox_4);
        status_n->addItem(QString());
        status_n->addItem(QString());
        status_n->setObjectName("status_n");
        status_n->setGeometry(QRect(840, 200, 81, 28));
        annuler = new QPushButton(groupBox_4);
        annuler->setObjectName("annuler");
        annuler->setGeometry(QRect(900, 410, 101, 61));
        ajouter = new QPushButton(groupBox_4);
        ajouter->setObjectName("ajouter");
        ajouter->setGeometry(QRect(900, 340, 101, 61));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        aff = new QTableView(tab_2);
        aff->setObjectName("aff");
        aff->setGeometry(QRect(10, 10, 1191, 511));
        supp = new QLineEdit(tab_2);
        supp->setObjectName("supp");
        supp->setGeometry(QRect(100, 330, 113, 28));
        supprimer = new QPushButton(tab_2);
        supprimer->setObjectName("supprimer");
        supprimer->setGeometry(QRect(120, 370, 83, 29));
        Trie = new QPushButton(tab_2);
        Trie->setObjectName("Trie");
        Trie->setGeometry(QRect(260, 370, 93, 29));
        tri = new QComboBox(tab_2);
        tri->addItem(QString());
        tri->addItem(QString());
        tri->setObjectName("tri");
        tri->setGeometry(QRect(250, 330, 131, 26));
        valeur = new QLineEdit(tab_2);
        valeur->setObjectName("valeur");
        valeur->setGeometry(QRect(440, 330, 113, 26));
        Rechercher = new QPushButton(tab_2);
        Rechercher->setObjectName("Rechercher");
        Rechercher->setGeometry(QRect(510, 370, 101, 29));
        pdf = new QPushButton(tab_2);
        pdf->setObjectName("pdf");
        pdf->setGeometry(QRect(990, 400, 101, 51));
        rech = new QComboBox(tab_2);
        rech->addItem(QString());
        rech->addItem(QString());
        rech->addItem(QString());
        rech->setObjectName("rech");
        rech->setGeometry(QRect(570, 330, 131, 26));
        verifier_chambre = new QPushButton(tab_2);
        verifier_chambre->setObjectName("verifier_chambre");
        verifier_chambre->setGeometry(QRect(1050, 20, 131, 51));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        groupBox_2 = new QGroupBox(tab_3);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(10, 10, 1141, 511));
        groupBox_2->setStyleSheet(QString::fromUtf8(""));
        modifier = new QPushButton(groupBox_2);
        modifier->setObjectName("modifier");
        modifier->setGeometry(QRect(890, 350, 131, 71));
        groupBox_3 = new QGroupBox(groupBox_2);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(10, 20, 1141, 491));
        groupBox_3->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    background: qlineargradient(\n"
"        spread:pad, \n"
"        x1:0, y1:0, x2:1, y2:1, \n"
"        stop:0 #CEBEA7,   \n"
"        stop:0.25 #8F959A,\n"
"        stop:0.5 #4B667B,  \n"
"        stop:0.75 #3B4672, \n"
"        stop:1 #22223B     \n"
"    );\n"
"    color: #F2E9E4;\n"
"    border: 2px solid #22223B;\n"
"    border-radius: 10px; \n"
"    margin-top: 15px;\n"
"}"));
        nb_c2 = new QLineEdit(groupBox_3);
        nb_c2->setObjectName("nb_c2");
        nb_c2->setGeometry(QRect(330, 150, 113, 28));
        type_c2 = new QComboBox(groupBox_3);
        type_c2->addItem(QString());
        type_c2->addItem(QString());
        type_c2->addItem(QString());
        type_c2->setObjectName("type_c2");
        type_c2->setGeometry(QRect(340, 210, 91, 28));
        capacite_2 = new QLineEdit(groupBox_3);
        capacite_2->setObjectName("capacite_2");
        capacite_2->setGeometry(QRect(330, 290, 113, 28));
        status_d2 = new QComboBox(groupBox_3);
        status_d2->addItem(QString());
        status_d2->addItem(QString());
        status_d2->setObjectName("status_d2");
        status_d2->setGeometry(QRect(330, 380, 101, 28));
        service2 = new QComboBox(groupBox_3);
        service2->addItem(QString());
        service2->addItem(QString());
        service2->addItem(QString());
        service2->addItem(QString());
        service2->addItem(QString());
        service2->setObjectName("service2");
        service2->setGeometry(QRect(650, 160, 101, 28));
        status_n2 = new QComboBox(groupBox_3);
        status_n2->addItem(QString());
        status_n2->addItem(QString());
        status_n2->setObjectName("status_n2");
        status_n2->setGeometry(QRect(670, 230, 91, 28));
        label_19 = new QLabel(groupBox_3);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(510, 230, 141, 20));
        label_18 = new QLabel(groupBox_3);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(510, 160, 121, 20));
        label_13 = new QLabel(groupBox_3);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(40, 60, 91, 20));
        label_14 = new QLabel(groupBox_3);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(130, 150, 171, 20));
        label_15 = new QLabel(groupBox_3);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(160, 210, 121, 20));
        label_16 = new QLabel(groupBox_3);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(200, 300, 63, 20));
        label_17 = new QLabel(groupBox_3);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(140, 390, 161, 20));
        id_m = new QLineEdit(groupBox_3);
        id_m->setObjectName("id_m");
        id_m->setGeometry(QRect(130, 80, 113, 28));
        recuperer = new QPushButton(groupBox_3);
        recuperer->setObjectName("recuperer");
        recuperer->setGeometry(QRect(280, 80, 83, 29));
        groupBox_3->raise();
        modifier->raise();
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        stat = new QGraphicsView(tab_4);
        stat->setObjectName("stat");
        stat->setGeometry(QRect(40, 10, 1131, 511));
        tabWidget->addTab(tab_4, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1221, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
#if QT_CONFIG(whatsthis)
        tabWidget->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>supprimer</p><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "saisir donn\303\251es du chambre", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "GroupBox", nullptr));
        type_c->setItemText(0, QCoreApplication::translate("MainWindow", "standard", nullptr));
        type_c->setItemText(1, QCoreApplication::translate("MainWindow", "deluxe", nullptr));
        type_c->setItemText(2, QCoreApplication::translate("MainWindow", "suite", nullptr));

        label_8->setText(QCoreApplication::translate("MainWindow", "Type de chambre", nullptr));
        status_d->setItemText(0, QCoreApplication::translate("MainWindow", "Disponible ", nullptr));
        status_d->setItemText(1, QCoreApplication::translate("MainWindow", "Non disponible", nullptr));

        label_11->setText(QCoreApplication::translate("MainWindow", "Status de nettoyage", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Services inclus", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Num\303\251ro de la chambre", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "capacite", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Status de disponibilit\303\251", nullptr));
        service->setItemText(0, QCoreApplication::translate("MainWindow", "TV", nullptr));
        service->setItemText(1, QCoreApplication::translate("MainWindow", "WIFI", nullptr));
        service->setItemText(2, QCoreApplication::translate("MainWindow", "MINIBAR", nullptr));
        service->setItemText(3, QCoreApplication::translate("MainWindow", "Coffre fort", nullptr));
        service->setItemText(4, QCoreApplication::translate("MainWindow", "Machine \303\240 caf\303\251/th\303\251", nullptr));

        status_n->setItemText(0, QCoreApplication::translate("MainWindow", "nettoye", nullptr));
        status_n->setItemText(1, QCoreApplication::translate("MainWindow", "Non nettoye", nullptr));

        annuler->setText(QCoreApplication::translate("MainWindow", "ANNULER", nullptr));
        ajouter->setText(QCoreApplication::translate("MainWindow", "AJOUTER", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "AJOUTER", nullptr));
        supprimer->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        Trie->setText(QCoreApplication::translate("MainWindow", "Trie", nullptr));
        tri->setItemText(0, QCoreApplication::translate("MainWindow", "id", nullptr));
        tri->setItemText(1, QCoreApplication::translate("MainWindow", "numero", nullptr));

        Rechercher->setText(QCoreApplication::translate("MainWindow", "Rechercher", nullptr));
        pdf->setText(QCoreApplication::translate("MainWindow", "PDF", nullptr));
        rech->setItemText(0, QCoreApplication::translate("MainWindow", "id", nullptr));
        rech->setItemText(1, QCoreApplication::translate("MainWindow", "numero", nullptr));
        rech->setItemText(2, QCoreApplication::translate("MainWindow", "service", nullptr));

        verifier_chambre->setText(QCoreApplication::translate("MainWindow", "Verifer Chambres", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "AFFICHER", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "nouvelles donn\303\251es du chambre", nullptr));
        modifier->setText(QCoreApplication::translate("MainWindow", "MODIFIER", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "GroupBox", nullptr));
        type_c2->setItemText(0, QCoreApplication::translate("MainWindow", "standard", nullptr));
        type_c2->setItemText(1, QCoreApplication::translate("MainWindow", "deluxe", nullptr));
        type_c2->setItemText(2, QCoreApplication::translate("MainWindow", "suite", nullptr));

        status_d2->setItemText(0, QCoreApplication::translate("MainWindow", "Disponible ", nullptr));
        status_d2->setItemText(1, QCoreApplication::translate("MainWindow", "Non disponible", nullptr));

        service2->setItemText(0, QCoreApplication::translate("MainWindow", "TV", nullptr));
        service2->setItemText(1, QCoreApplication::translate("MainWindow", "WIFI", nullptr));
        service2->setItemText(2, QCoreApplication::translate("MainWindow", "MINIBAR", nullptr));
        service2->setItemText(3, QCoreApplication::translate("MainWindow", "Coffre fort", nullptr));
        service2->setItemText(4, QCoreApplication::translate("MainWindow", "Machine \303\240 caf\303\251/th\303\251", nullptr));

        status_n2->setItemText(0, QCoreApplication::translate("MainWindow", "nettoye", nullptr));
        status_n2->setItemText(1, QCoreApplication::translate("MainWindow", "Non nettoye", nullptr));

        label_19->setText(QCoreApplication::translate("MainWindow", "Status de nettoyage", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Services inclus", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "ID chambre", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Numero de la chambre", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Type de chambre", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Capacit\303\251", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Status de disponibilit\303\251", nullptr));
        recuperer->setText(QCoreApplication::translate("MainWindow", "R\303\251cuperer", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "MODIFIER", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "STATISTIQUE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
