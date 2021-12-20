#ifndef LOCATORCOMMAND_H
#define LOCATORCOMMAND_H

#include "core/command.h"
#include "core/locator.h"

#include <QPoint>

/**
 * @class : LocatorCommand
 * @brief : 定位器命令定义
 * @note  : 回退到旧的位置，重新恢复到新的位置
 */
class LocatorCommand : public Command
{
public:
    explicit LocatorCommand(Workspace *workspace,Locator *locator,QPoint oldPosition, QPoint newPosition);

    void undo();
    void redo();

private:
    QPoint m_oldPosition;    //旧的位置
    QPoint m_newPosition;    //新的位置

    Locator *m_locator; 
};

#endif // LOCATORCOMMAND_H
