#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "chambre.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QFileDialog>

#include <QSystemTrayIcon> // hedhiii notification
#include <QMenu>
#include <QAction>
#include <QIcon>
#include <QFile>
#include <QSqlError>

#include <QVBoxLayout>
#include <QListWidget>
#include<QTimer>


Chambre chambre;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupTrayIcon(); // Initialisation du tray icon

    ui->aff->setModel(chambre.afficher()); // Rafraîchir l'affichage
    afficherStatistiques();

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::setupTrayIcon() {
    // Créer un menu contextuel pour l'icône du tray
    trayIconMenu = new QMenu(this);

    // Créer une action pour quitter l'application
    QAction *quitAction = new QAction("Quitter", this);
    connect(quitAction, &QAction::triggered, this, &QWidget::close);
    trayIconMenu->addAction(quitAction);

    // Créer l'icône du tray
    trayIcon = new QSystemTrayIcon(this);

    // Définir l'icône (utiliser le chemin relatif à partir des ressources Qt)
    trayIcon->setIcon(QIcon("notif.png"));
    trayIcon->setContextMenu(trayIconMenu);

    // Afficher l'icône dans la barre des tâches
    trayIcon->show();
}
void MainWindow::showNotification(const QString &title, const QString &message)
{
    // Vérifier si l'icône du tray est activée et afficher la notification
    if (trayIcon->isVisible()) {
        trayIcon->showMessage(title, message, QSystemTrayIcon::Information, 3000);  // Durée en ms
    }
}


void MainWindow::on_ajouter_clicked()
{
    int nb_c = ui->nb_c->text().toInt();
    QString type_c = ui->type_c->currentText();
    int capacite = ui->capacite->text().toInt();
    QString status_d = ui->status_d->currentText();
    QString service = ui->service->currentText();
    QString status_n = ui->status_n->currentText();

    // Contrôle de saisie
    if (nb_c <= 0 || type_c.isEmpty() || capacite <= 0 || status_d.isEmpty() || service.isEmpty() || status_n.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs correctement.");
        return;
    }

    Chambre chambre;
    chambre.setNumero(nb_c);
    chambre.setType(type_c);
    chambre.setCapacite(capacite);
    chambre.setStatusD(status_d);
    chambre.setService(service);
    chambre.setStatusN(status_n);

    if (chambre.ajouter()) {
        QMessageBox::information(this, "Succès", "Chambre ajoutée avec succès.");
        ui->aff->setModel(chambre.afficher()); // Rafraîchir l'affichage
        afficherStatistiques();

    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout de la chambre.");
    }
}


void MainWindow::on_supprimer_clicked()
{
    int id = ui->supp->text().toInt();

    // Vérification si l'ID est valide
    if (id <= 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez saisir un ID valide.");
        return;
    }

    Chambre chambre;
    if (!chambre.existeId(id)) {
        QMessageBox::warning(this, "Erreur", "Cet ID n'existe pas.");
        return;
    }

    if (chambre.supprimer(id)) {
        QMessageBox::information(this, "Succès", "Chambre supprimée avec succès.");
        ui->aff->setModel(chambre.afficher()); // Rafraîchir l'affichage
        afficherStatistiques();

    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression de la chambre.");
    }
}



void MainWindow::on_annuler_clicked()
{
    ui->nb_c->clear();
    ui->capacite->clear();
    ui->type_c->setCurrentIndex(0);
    ui->status_d->setCurrentIndex(0);
    ui->service->setCurrentIndex(0);
    ui->status_n->setCurrentIndex(0);

    QMessageBox::information(this, "Réinitialisé", "Les champs ont été réinitialisés.");
}



void MainWindow::on_recuperer_clicked()
{
    int id = ui->id_m->text().toInt();

    // Vérification si l'ID est valide
    if (id <= 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez saisir un ID valide.");
        return;
    }

    Chambre chambre;
    if (!chambre.existeId(id)) {
        QMessageBox::warning(this, "Erreur", "Cet ID n'existe pas.");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT numero, type, capacite, status_d, service, status_n FROM chambre WHERE id = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        ui->nb_c2->setText(query.value(0).toString());
        ui->type_c2->setCurrentText(query.value(1).toString());
        ui->capacite_2->setText(query.value(2).toString());
        ui->status_d2->setCurrentText(query.value(3).toString());
        ui->service2->setCurrentText(query.value(4).toString());
        ui->status_n2->setCurrentText(query.value(5).toString());
        QMessageBox::information(this, "Succès", "Données récupérées avec succès.");
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la récupération des données.");
    }
}

void MainWindow::on_modifier_clicked()
{
    int id = ui->id_m->text().toInt();
    int nb_c = ui->nb_c2->text().toInt();
    QString type_c = ui->type_c2->currentText();
    int capacite = ui->capacite_2->text().toInt();
    QString status_d = ui->status_d2->currentText();
    QString service = ui->service2->currentText();
    QString status_n = ui->status_n2->currentText();

    // Contrôle de saisie
    if (id <= 0 || nb_c <= 0 || type_c.isEmpty() || capacite <= 0 || status_d.isEmpty() || service.isEmpty() || status_n.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs correctement.");
        return;
    }

    Chambre chambre(id, nb_c, type_c, capacite, status_d, service, status_n);

    if (chambre.modifier()) {
        QMessageBox::information(this, "Succès", "Chambre modifiée avec succès.");
        ui->aff->setModel(chambre.afficher()); // Rafraîchir l'affichage
        afficherStatistiques();

    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification de la chambre.");
    }
}



void MainWindow::on_Trie_clicked()
{
    QString critere = ui->tri->currentText().trimmed().toLower();

    if (critere != "id" && critere != "numero") {
        QMessageBox::warning(this, "Erreur", "Critère de tri invalide. Choisissez 'id' ou 'numero'.");
        return;
    }

    QSqlQueryModel *model = c.trier(critere);
    ui->aff->setModel(model);
}
void MainWindow::on_Rechercher_clicked()
{
    QString critere = ui->rech->currentText();
    QString valeur = ui->valeur->text();


    QSqlQueryModel *model = c.rechercher(critere, valeur);
    ui->aff->setModel(model);
}


void MainWindow::on_pdf_clicked()
{
    // Ouvrir une boîte de dialogue pour choisir l'emplacement du fichier PDF
    QString fichierPDF = QFileDialog::getSaveFileName(this, "Enregistrer le PDF", "", "*.pdf");

    if (!fichierPDF.isEmpty()) {
        if (!fichierPDF.endsWith(".pdf", Qt::CaseInsensitive)) {
            fichierPDF += ".pdf";  // Ajouter l'extension si elle n'est pas fournie
        }

        // Générer le PDF à l'emplacement choisi
        c.genererPDF(fichierPDF);

        // Informer l'utilisateur que le PDF a été généré avec succès
        QMessageBox::information(this, "Succès", "Le PDF a été généré avec succès.");
    } else {
        // Si l'utilisateur annule l'opération
        QMessageBox::warning(this, "Annulé", "La génération du PDF a été annulée.");
    }
}



void MainWindow::afficherStatistiques() {
    // Récupérer la série de statistiques (pie chart)
    QPieSeries* series = c.statistiques();

    // Ajouter les pourcentages aux étiquettes des sections
    for (auto slice : series->slices()) {
        double percentage = slice->percentage() * 100; // Calculer le pourcentage
        slice->setLabel(QString("%1 (%2%)").arg(slice->label()).arg(percentage, 0, 'f', 1)); // Arrondir à une décimale
        slice->setLabelVisible(true); // Rendre les étiquettes visibles
    }

    // Ajouter des animations à la série
    QChart* chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des chambres par service");

    // Appliquer un thème et des animations pour rendre la présentation professionnelle
    chart->setAnimationOptions(QChart::AllAnimations);
    chart->legend()->setAlignment(Qt::AlignBottom); // Positionner la légende en bas
    chart->setTheme(QChart::ChartThemeLight); // Vous pouvez choisir un autre thème si vous préférez

    // Ajouter une transition fluide lorsqu'une section est survolée (ex. flèche / mise en relief)
    for (auto slice : series->slices()) {
        QObject::connect(slice, &QPieSlice::hovered, [=](bool hovered) {
            slice->setExploded(hovered); // "Exploser" la tranche quand elle est survolée
            slice->setLabelVisible(hovered); // Rendre l'étiquette toujours visible lors du survol
        });
    }

    // Créer un QChartView pour intégrer le QChart
    QChartView* chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing); // Améliorer le rendu

    // Créer une QGraphicsScene et ajouter le QChartView
    QGraphicsScene* scene = new QGraphicsScene(this);
    scene->addWidget(chartView);

    // Ajouter la scène dans le QGraphicsView (aff_stat)
    ui->stat->setScene(scene);

    // Ajuster la taille de la vue pour s'adapter dynamiquement
    chartView->resize(ui->stat->size());
    scene->setSceneRect(chartView->rect());
}

void MainWindow::on_verifier_chambre_clicked()
{
    QSqlQuery query;
    query.prepare("SELECT id, numero, type, capacite, status_d, service, status_n FROM chambre WHERE UPPER(TRIM(status_d)) = 'DISPONIBLE'");

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Échec de la vérification des chambres : " + query.lastError().text());
        return;
    }

    QStringList idsForNotification; // Pour la notification
    QStringList detailedInfo;       // Pour la fenêtre
    bool hasAvailableRooms = false;

    while (query.next()) {
        hasAvailableRooms = true;
        int id = query.value("id").toInt();
        QString numero = query.value("numero").toString();
        QString type = query.value("type").toString();
        int capacite = query.value("capacite").toInt();
        QString service = query.value("service").toString();

        // Ajouter l'ID à la notification (limité à 5 pour éviter la surcharge)
        if (idsForNotification.size() < 5) {
            idsForNotification << QString::number(id);
        }

        // Ajouter les détails complets
        QString detail = QString("ID: %1 | Numéro: %2 | Type: %3 | Capacité: %4 | Service: %5")
                             .arg(id)
                             .arg(numero)
                             .arg(type)
                             .arg(capacite)
                             .arg(service);
        detailedInfo << detail;
    }

    if (!hasAvailableRooms) {
        showNotification("Disponibilité des chambres", "Aucune chambre disponible actuellement.");
    } else {
        // Notification avec un résumé des IDs
        showNotification("Chambres disponibles",
                         QString("Chambres disponibles : %1").arg(idsForNotification.join(", ")) +
                             (detailedInfo.size() > 5 ? "\n(plus...)" : ""));

        // Afficher les détails dans une fenêtre
        showRoomDetails(detailedInfo);
    }
}
void MainWindow::showRoomDetails(const QStringList &details)
{
    // Créer un dialogue personnalisé
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("✨ Détails des chambres disponibles ✨");
    dialog->setStyleSheet("background-color: #2C2C2C; color: #FFFFFF; border-radius: 10px;");

    // Layout principal
    QVBoxLayout *mainLayout = new QVBoxLayout(dialog);

    // Titre avec style luxueux
    QLabel *title = new QLabel("🏨 Bienvenue aux Chambres 6 Étoiles");
    title->setAlignment(Qt::AlignCenter);
    title->setStyleSheet("font-size: 24px; font-weight: bold; color: #FFD700; margin: 20px 0;");
    mainLayout->addWidget(title);

    // Liste des détails avec style
    QListWidget *listWidget = new QListWidget(dialog);
    listWidget->setStyleSheet(
        "QListWidget {"
        "    background-color: #1E1E1E; border: none; border-radius: 10px; padding: 10px;"
        "    font-size: 16px; color: #FFFFFF;"
        "}"
        "QListWidget::item {"
        "    margin: 5px 0;"
        "}"
        "QListWidget::item:hover {"
        "    background-color: #FFD700; color: #2C2C2C;"
        "}"
        );

    // Ajouter les détails avec icône dorée
    QPixmap icon("gold_icon.png"); // Ajoutez une icône dans vos ressources
    foreach (const QString &detail, details) {
        QListWidgetItem *item = new QListWidgetItem(QIcon(icon), detail, listWidget);
        item->setSizeHint(QSize(0, 40)); // Ajustez la taille pour plus de visibilité
        listWidget->addItem(item);
    }

    mainLayout->addWidget(listWidget);

    // Animation : Faire apparaître chaque détail progressivement
    QTimer *timer = new QTimer(dialog);
    timer->setInterval(300); // 300ms par détail
    int index = 0;
    QObject::connect(timer, &QTimer::timeout, [=]() mutable {
        if (index < listWidget->count()) {
            listWidget->item(index)->setHidden(false);
            ++index;
        } else {
            timer->stop();
        }
    });
    timer->start();

    // Bouton pour fermer
    QPushButton *closeButton = new QPushButton("Fermer");
    closeButton->setStyleSheet(
        "QPushButton {"
        "    background-color: #FFD700; color: #2C2C2C; font-size: 16px; font-weight: bold; padding: 10px 20px;"
        "    border-radius: 5px; margin: 20px 0;"
        "}"
        "QPushButton:hover {"
        "    background-color: #FFC107;"
        "}"
        );
    connect(closeButton, &QPushButton::clicked, dialog, &QDialog::accept);
    mainLayout->addWidget(closeButton, 0, Qt::AlignCenter);

    dialog->setLayout(mainLayout);
    dialog->resize(600, 400); // Taille de la fenêtre
    dialog->exec();
}
