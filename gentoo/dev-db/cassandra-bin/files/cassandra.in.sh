
# The directory where Cassandra's configs live (required)
CASSANDRA_CONF=/etc/cassandra

CASSANDRA_HOME=/usr/share/cassandra-bin

# The java classpath (required)
if [ -n "$CLASSPATH" ]; then
    CLASSPATH=$CLASSPATH:$CASSANDRA_CONF
else
    CLASSPATH=$CASSANDRA_CONF
fi

for jar in /usr/share/cassandra-bin/lib/*.jar; do
    CLASSPATH=$CLASSPATH:$jar
done

#for jar in /usr/share/cassandra-bin/*.jar; do
#    CLASSPATH=$CLASSPATH:$jar
#done
