#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "chambre.h"

#include <QSystemTrayIcon> // bibliotheque predéfinie et pour inserer icon
#include <QMenu>
#include <QAction>



QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ajouter_clicked();

    void on_Trie_clicked();

    void on_Rechercher_clicked();

    void on_pdf_clicked();

    void on_recuperer_clicked();

    void on_modifier_clicked();

    void on_supprimer_clicked();

    void on_annuler_clicked();

    void   afficherStatistiques();
    void showNotification(const QString &title, const QString &message);  // Déclaration de la fonction pour afficher la notification


    void on_verifier_chambre_clicked();

private:
    Ui::MainWindow *ui;
    Chambre c;
    QSystemTrayIcon *trayIcon;        // Déclaration de l'icône du tray
    QMenu *trayIconMenu;              // Déclaration du menu contextuel pour l'icône
    void setupTrayIcon();

    void showRoomDetails(const QStringList &details);

};
#endif // MAINWINDOW_H
