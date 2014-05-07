#ifndef FENPRINCIPALE_H
#define FENPRINCIPALE_H

#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <vector>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QDateEdit>
#include <QDate>
#include <QTextEdit>

class fenPrincipale: public QWidget
{
    Q_OBJECT

    public:
    fenPrincipale();   //le constructeur

    public slots:
    void OkCommentaires(bool);
    void appelerFenetre();

    private:
    QGroupBox *m_def;
    QPushButton *m_generer;
    QPushButton *m_quitter;
    QLineEdit *m_magicien;
    QCheckBox *m_case1;
    QCheckBox *m_case2;
    QCheckBox *m_case3;
    QHBoxLayout *m_boxBoutons;
    QFormLayout *m_form;
    QVBoxLayout *m_box;
    QGroupBox *m_cases;
    QVBoxLayout *m_boxCases;
    QGroupBox *m_autres;
    QCheckBox *m_commentaires;
    QFormLayout *m_plus;
    QLineEdit *m_auteur;
    QDateEdit *m_date;
    QTextEdit *m_blocTexte;
    QLineEdit *m_mere;
};


#endif // FENPRINCIPALE_H
