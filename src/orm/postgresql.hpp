#pragma once
/**
* https://www.postgresql.org/docs/9.5/static/libpq-connect.html#LIBPQ-PARAMKEYWORDS
*/

#include "database.hpp"

#include <cstdlib>
#include <libpq-fe.h>

namespace aries {
namespace orm {
class PostgreSql : public orm::Driver {
public:
  PostgreSql(const char *host, int port, const char *name, const char *user,
             const char *password, const char *mode, uint timeout);
  ~PostgreSql();

  inline std::string name();
  std::vector<const char *> query(const char *sql,
                                  std::initializer_list<const char *> params);

private:
  void parse(PGresult *res, std::vector<const char *> &val);
  PGconn *db;
};
}
}
