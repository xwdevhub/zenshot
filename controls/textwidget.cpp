#include "textwidget.h"
#include "core/utils.h"
#include <QPainter>

TextWidget::TextWidget(QWidget *parent):QWidget(parent)
{
    m_textImpl = new TextWidgetImpl(this);
    m_textImpl->move(Utils::TextEdit_Padding_Horizontal,Utils::TextEdit_Padding_Vertical);
    connect(m_textImpl, SIGNAL(sizeChanged(QSize)), this, SLOT(onContentSizeChanged(QSize)));
}

void TextWidget::setTextColor(QColor color)
{
    m_textImpl->setTextColor(color);
}

void TextWidget::makeFocus()
{
    m_textImpl->setFocus();
}

QString TextWidget::text()
{
    return m_textImpl->toPlainText();
}

void TextWidget::setText(QString text)
{
    m_textImpl->setText(text);
}

void TextWidget::setFont(const QFont &f)
{
    m_textImpl->setFont(f);
}

void TextWidget::onContentSizeChanged(QSize size)
{
    this->setFixedSize(size.width()+Utils::TextEdit_Padding_Horizontal*2,
                       size.height()+Utils::TextEdit_Padding_Vertical*2);
}

void TextWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing,true);

    QSize mSize = size();
    QRect realRect(Utils::Handle_AntLine_Thicknes,
                   Utils::Handle_AntLine_Thicknes,
                   mSize.width()-Utils::Handle_AntLine_Thicknes*2,
                   mSize.height()-Utils::Handle_AntLine_Thicknes*2);

    QPen baseIndicator;
    baseIndicator.setColor(Utils::Handle_AntLine_SubColor);
    baseIndicator.setWidth(Utils::Handle_AntLine_Thicknes);

    painter.setPen(baseIndicator);
    painter.drawRect(realRect);

    QPen indicator;
    indicator.setColor(Utils::Handle_AntLine_Color);
    indicator.setWidth(Utils::Handle_AntLine_Thicknes);
    indicator.setStyle(Qt::DashLine);

    painter.setPen(indicator);
    painter.drawRect(realRect);
}
