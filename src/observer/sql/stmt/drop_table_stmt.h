//
// Created by river on 10/8/23.
//

#ifndef MINIDB_DROP_TABLE_STMT_H
#define MINIDB_DROP_TABLE_STMT_H

#endif  // MINIDB_DROP_TABLE_STMT_H
#pragma once

#include <string>
#include <vector>

#include "sql/stmt/stmt.h"

class Db;

/**
 * @brief 表示删除表的语句
 * @ingroup Statement
 * @details 虽然解析成了stmt，但是与原始的SQL解析后的数据也差不多
 */
class DropTableStmt : public Stmt
{
public:
  DropTableStmt(const std::string &table_name)
      : table_name_(table_name)
  {}
  virtual ~DropTableStmt() = default;

  StmtType type() const override { return StmtType::DROP_TABLE; }

  const std::string &table_name() const { return table_name_; }

  static RC drop(Db *db, const DropTableSqlNode &drop_table, Stmt *&stmt);

private:
  std::string table_name_;
};