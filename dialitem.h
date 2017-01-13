#ifndef DIALITEM_H
#define DIALITEM_H

#include <QQuickPaintedItem>

class DialItem : public QQuickPaintedItem
{
    Q_OBJECT

    Q_PROPERTY(int startAngle READ getStartAngle WRITE setStartAngle NOTIFY startAngleChanged)
    Q_PROPERTY(qreal spanAngle READ getSpanAngle WRITE setSpanAngle NOTIFY spanAngleChanged)
    Q_PROPERTY(int dialWidth READ getDialWidth WRITE setDialWidth NOTIFY dialWidthChanged)
    Q_PROPERTY(QColor dialColor READ getDialColor WRITE setDialColor NOTIFY dialColorChanged)
public:
    DialItem(QQuickItem *parent = 0);
    void paint(QPainter *painter);

    int getStartAngle() {return m_StartAngle;}
    qreal getSpanAngle() {return m_SpanAngle;}
    int getDialWidth() {return m_DialWidth;}
    QColor getDialColor() {return m_DialColor;}

    void setStartAngle(int angle) {m_StartAngle = angle; this->update();}
    void setSpanAngle(qreal angle) {m_SpanAngle = angle; this->update();}
    void setDialWidth(int angle) {m_DialWidth = angle; this->update();}
    void setDialColor(QColor color) {m_DialColor = color; this->update();}

signals:
    void startAngleChanged();
    void spanAngleChanged();
    void dialWidthChanged();
    void dialColorChanged();

public slots:

private:
    int m_StartAngle;
    qreal m_SpanAngle;
    int m_DialWidth;
    QColor m_DialColor;
};

#endif // DIALITEM_H
