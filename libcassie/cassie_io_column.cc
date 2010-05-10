/*
 * LibCassie
 * Copyright (C) 2010 Mina Naguib
 * All rights reserved.
 *
 * Use and distribution licensed under the BSD license. See
 * the COPYING file in the parent directory for full text.
 */

#include <libcassandra/cassandra_factory.h>
#include <libcassandra/cassandra.h>
#include <libcassandra/keyspace.h>

#include "cassie.h"
#include "cassie_column.h"
#include "cassie_blob.h"
#include "cassie_io_column.h"

namespace libcassie {

	using namespace std;
	using namespace libcassandra;

	extern "C" {

		int cassie_insert_column(
				cassie_t cassie,
				const char * keyspace,
				const char * column_family,
				const char * key,
				cassie_column_t column,
				cassie_consistency_level_t level
				) {

			Keyspace *key_space;
			string column_name(column->name->data, column->name->length);
			string value(column->value->data, column->value->length);

			try {
				key_space = cassie->cassandra->getKeyspace(keyspace, (org::apache::cassandra::ConsistencyLevel)level);
				key_space->insertColumn(key, column_family, column_name, value);
				return(1);
			}
			catch (org::apache::cassandra::InvalidRequestException &ire) {
				cassie_set_error(cassie, "Exception: %s", ire.why.c_str());
				return(0);
			}

		}


		cassie_column_t cassie_get_column(
				cassie_t cassie,
				const char * keyspace,
				const char * column_family,
				const char * key,
				const char * column_name,
				size_t column_name_len,
				cassie_consistency_level_t level
				) {

			Keyspace *key_space;

			try {
				key_space = cassie->cassandra->getKeyspace(keyspace, (org::apache::cassandra::ConsistencyLevel)level);
				string cn(column_name, column_name_len);
				org::apache::cassandra::Column cpp_column = key_space->getColumn(key, column_family, cn);
				return(cassie_column_convert(cassie, cpp_column));
			}
			catch (org::apache::cassandra::InvalidRequestException &ire) {
				cassie_set_error(cassie, "Exception: %s", ire.why.c_str());
				return(NULL);
			}
		}


		/* Sugar in case your column name and value are valid C-strings */
		int cassie_insert_column_value(
				cassie_t cassie,
				const char * keyspace,
				const char * column_family,
				const char * key,
				const char * column_name,
				const char * value,
				cassie_consistency_level_t level
				) {

			Keyspace *key_space;

			try {
				key_space = cassie->cassandra->getKeyspace(keyspace, (org::apache::cassandra::ConsistencyLevel)level);
				key_space->insertColumn(key, column_family, column_name, value);
				return(1);
			}
			catch (org::apache::cassandra::InvalidRequestException &ire) {
				cassie_set_error(cassie, "Exception: %s", ire.why.c_str());
				return(0);
			}

		}

		/* Sugar in case your column name and value are valid C-strings */
		char * cassie_get_column_value(
				cassie_t cassie,
				const char * keyspace,
				const char * column_family,
				const char * key,
				const char * column_name,
				cassie_consistency_level_t level
				) {

			Keyspace *key_space;

			try {
				key_space = cassie->cassandra->getKeyspace(keyspace, (org::apache::cassandra::ConsistencyLevel)level);
				string res = key_space->getColumnValue(key, column_family, column_name);
				return(strdup(res.c_str()));
			}
			catch (org::apache::cassandra::InvalidRequestException &ire) {
				cassie_set_error(cassie, "Exception: %s", ire.why.c_str());
				return(NULL);
			}
		}

	} // extern "C"

} // namespace libcassie
