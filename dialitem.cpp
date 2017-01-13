#include <QTime>
#include <QPainter>

#include "dialitem.h"

#define PI 3.14159265

DialItem::DialItem(QQuickItem *parent)
    : QQuickPaintedItem(parent)
{
    m_StartAngle = 0;
    m_SpanAngle = 180;
    m_DialWidth = 4;
    m_DialColor = QColor(0, 0, 0);
    connect(this, SIGNAL(startAngleChanged()), this, SLOT(update()));
    connect(this, SIGNAL(spanAngleChanged()), this, SLOT(update()));
    connect(this, SIGNAL(dialWidthChanged()), this, SLOT(update()));
    connect(this, SIGNAL(dialColorChanged()), this, SLOT(update()));
}

void DialItem::paint(QPainter *painter)
{
    QRectF rect = this->boundingRect();
    painter->setRenderHint(QPainter::Antialiasing);
    QPen pen = painter->pen();
    pen.setColor(Qt::black);

    //Draw outer dial
    painter->save();
    pen.setWidth(m_DialWidth);
    pen.setColor(m_DialColor);
    painter->setPen(pen);
    double startAngle = -90 - m_StartAngle;
    double spanAngle = 0 - m_SpanAngle;
    qreal offset = m_DialWidth / 2;
    painter->drawArc(rect.adjusted(offset, offset, -offset, -offset), startAngle * 16, spanAngle * 16);
    painter->restore();

    //Draw major ticks
    painter->save();
    pen.setWidth(4);
    painter->translate(width() / 2, height() / 2);
    painter->rotate(-startAngle);
    painter->setPen(pen);
    qreal angleStep = m_SpanAngle / 10;
    for(int i = 0; i < 11; ++i)
    {
        painter->drawLine(rect.width()/2 - 30, 0, rect.width()/2 - 2, 0);
        painter->rotate(angleStep);
    }
    painter->translate(-width() / 2, -height() / 2);
    painter->restore();

    //Draw minor ticks
    painter->save();
    pen.setWidth(2);
    painter->translate(width() / 2, height() / 2);
    painter->rotate(-startAngle);
    painter->setPen(pen);
    int minorTicks = 8* 10;
    qreal angleStepMin = m_SpanAngle / minorTicks;
    for(int i = 0; i < minorTicks; ++i)
    {
        painter->drawLine(rect.width()/2 - 15, 0, rect.width()/2 - 2, 0);
        painter->rotate(angleStepMin);
    }
    painter->translate(-width() / 2, -height() / 2);
    painter->restore();

    //Draw numbers
    painter->save();
    pen.setColor(Qt::white);
    painter->setPen(pen);
    const int radius = rect.width()/2 - 45;
    QFontMetrics fontMat(painter->font());
    QString numbr;
    for (double i = 0; i <= m_SpanAngle; i += m_SpanAngle/10)
    {
        QPoint p(rect.center().x() + radius * cos(-90-i * PI / 180.0), rect.center().y() - radius * sin(-90-i * PI / 180.0));
        numbr = QString::number(i);
        QRect bound = fontMat.boundingRect(numbr);
        painter->drawText(QPointF((p.x() - bound.width()/2), (p.y() + bound.height()/2)), numbr);
    }
    painter->restore();
}
