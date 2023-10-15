//
// Created by river on 10/8/23.
//

#ifndef MINIDB_DROP_RABLE_EXECUTOR_H
#define MINIDB_DROP_RABLE_EXECUTOR_H

#endif  // MINIDB_DROP_RABLE_EXECUTOR_H

#pragma once

#include "common/rc.h"

class SQLStageEvent;

/**
 * @brief 创建表的执行器
 * @ingroup Executor
 */
class DropTableExecutor
{
public:
           DropTableExecutor() = default;
  virtual ~DropTableExecutor() = default;

  RC execute(SQLStageEvent *sql_event);
};