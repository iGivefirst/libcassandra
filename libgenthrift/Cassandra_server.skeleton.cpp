// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "Cassandra.h"
#include <protocol/TBinaryProtocol.h>
#include <server/TSimpleServer.h>
#include <transport/TServerSocket.h>
#include <transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

using namespace org::apache::cassandra;

class CassandraHandler : virtual public CassandraIf {
 public:
  CassandraHandler() {
    // Your initialization goes here
  }

  void login(const std::string& keyspace, const AuthenticationRequest& auth_request) {
    // Your implementation goes here
    printf("login\n");
  }

  void get(ColumnOrSuperColumn& _return, const std::string& keyspace, const std::string& key, const ColumnPath& column_path, const ConsistencyLevel consistency_level) {
    // Your implementation goes here
    printf("get\n");
  }

  void get_slice(std::vector<ColumnOrSuperColumn> & _return, const std::string& keyspace, const std::string& key, const ColumnParent& column_parent, const SlicePredicate& predicate, const ConsistencyLevel consistency_level) {
    // Your implementation goes here
    printf("get_slice\n");
  }

  void multiget(std::map<std::string, ColumnOrSuperColumn> & _return, const std::string& keyspace, const std::vector<std::string> & keys, const ColumnPath& column_path, const ConsistencyLevel consistency_level) {
    // Your implementation goes here
    printf("multiget\n");
  }

  void multiget_slice(std::map<std::string, std::vector<ColumnOrSuperColumn> > & _return, const std::string& keyspace, const std::vector<std::string> & keys, const ColumnParent& column_parent, const SlicePredicate& predicate, const ConsistencyLevel consistency_level) {
    // Your implementation goes here
    printf("multiget_slice\n");
  }

  int32_t get_count(const std::string& keyspace, const std::string& key, const ColumnParent& column_parent, const ConsistencyLevel consistency_level) {
    // Your implementation goes here
    printf("get_count\n");
  }

  void get_range_slice(std::vector<KeySlice> & _return, const std::string& keyspace, const ColumnParent& column_parent, const SlicePredicate& predicate, const std::string& start_key, const std::string& finish_key, const int32_t row_count, const ConsistencyLevel consistency_level) {
    // Your implementation goes here
    printf("get_range_slice\n");
  }

  void get_range_slices(std::vector<KeySlice> & _return, const std::string& keyspace, const ColumnParent& column_parent, const SlicePredicate& predicate, const KeyRange& range, const ConsistencyLevel consistency_level) {
    // Your implementation goes here
    printf("get_range_slices\n");
  }

  void insert(const std::string& keyspace, const std::string& key, const ColumnPath& column_path, const std::string& value, const int64_t timestamp, const ConsistencyLevel consistency_level) {
    // Your implementation goes here
    printf("insert\n");
  }

  void batch_insert(const std::string& keyspace, const std::string& key, const std::map<std::string, std::vector<ColumnOrSuperColumn> > & cfmap, const ConsistencyLevel consistency_level) {
    // Your implementation goes here
    printf("batch_insert\n");
  }

  void remove(const std::string& keyspace, const std::string& key, const ColumnPath& column_path, const int64_t timestamp, const ConsistencyLevel consistency_level) {
    // Your implementation goes here
    printf("remove\n");
  }

  void batch_mutate(const std::string& keyspace, const std::map<std::string, std::map<std::string, std::vector<Mutation> > > & mutation_map, const ConsistencyLevel consistency_level) {
    // Your implementation goes here
    printf("batch_mutate\n");
  }

  void get_string_property(std::string& _return, const std::string& property) {
    // Your implementation goes here
    printf("get_string_property\n");
  }

  void get_string_list_property(std::vector<std::string> & _return, const std::string& property) {
    // Your implementation goes here
    printf("get_string_list_property\n");
  }

  void describe_keyspaces(std::set<std::string> & _return) {
    // Your implementation goes here
    printf("describe_keyspaces\n");
  }

  void describe_cluster_name(std::string& _return) {
    // Your implementation goes here
    printf("describe_cluster_name\n");
  }

  void describe_version(std::string& _return) {
    // Your implementation goes here
    printf("describe_version\n");
  }

  void describe_ring(std::vector<TokenRange> & _return, const std::string& keyspace) {
    // Your implementation goes here
    printf("describe_ring\n");
  }

  void describe_keyspace(std::map<std::string, std::map<std::string, std::string> > & _return, const std::string& keyspace) {
    // Your implementation goes here
    printf("describe_keyspace\n");
  }

  void describe_splits(std::vector<std::string> & _return, const std::string& start_token, const std::string& end_token, const int32_t keys_per_split) {
    // Your implementation goes here
    printf("describe_splits\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  shared_ptr<CassandraHandler> handler(new CassandraHandler());
  shared_ptr<TProcessor> processor(new CassandraProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

