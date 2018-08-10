#ifndef CATEGORY_H
#define CATEGORY_H

#include <QString>
#include <QLabel>
#include <QVBoxLayout>
#include <QDebug>

#include <memory>

class Category : public QWidget {
    Q_OBJECT
private:
    QLabel* a_lblName;
    QVBoxLayout* a_layoutMain;

//bouton.setToolTip("Texte d'aide")
//.setCursor(Qt::PointingHandCursor);

public:
    Category(QString name);
    ~Category();

    QVBoxLayout* getLayout() { return a_layoutMain;}
};

#endif // CATEGORY_H
