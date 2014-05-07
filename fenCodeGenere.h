#ifndef FENCODEGENERE_H
#define FENCODEGENERE_H

#include <QApplication>
#include <QDialog>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QPushButton>

class fenGeneree: public QDialog
{
    public:
    fenGeneree();

    public slots:

    private:
    QTextEdit *m_texte;
    QVBoxLayout *m_layout;
    QPushButton *m_fermer;
};


#endif // FENCODEGENERE_H
