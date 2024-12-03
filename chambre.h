#ifndef CHAMBRE_H
#define CHAMBRE_H

#include <QString>
#include <QSqlQueryModel>

#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSlice>
#include <QPieSeries>

class Chambre {
private:
    int id , numero;
    QString type, status_d, service, status_n;
    int capacite;

public:
    // Constructeurs
    Chambre();
    Chambre(int id, int numero, QString type, int capacite, QString status_d, QString service, QString status_n);

    // Getters
    int getId() const;
    int getNumero() const;
    QString getType() const;
    int getCapacite() const;
    QString getStatusD() const;
    QString getService() const;
    QString getStatusN() const;

    // Setters
    void setId(int id);
    void setNumero( int numero);
    void setType(const QString &type);
    void setCapacite(int capacite);
    void setStatusD(const QString &status_d);
    void setService(const QString &service);
    void setStatusN(const QString &status_n);

    // CRUD
    bool ajouter();
    bool supprimer(int id);
    bool modifier();
    QSqlQueryModel* afficher();

    // Fonctionnalités supplémentaires
    bool existeId(int id);

    // metiers simple
    QSqlQueryModel* rechercher(QString critere, QString valeur);
    QSqlQueryModel* trier(QString critere);
    QString genererContenuPDF();

    void genererPDF(const QString& fichierPDF);
    QPieSeries* statistiques();
};

#endif // CHAMBRE_H
