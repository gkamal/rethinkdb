#ifndef __REPLICATION_SLAVE_HPP__
#define __REPLICATION_SLAVE_HPP__

#include "replication/protocol.hpp"
#include "server/cmd_args.hpp"
#include "store.hpp"
#include "failover.hpp"

#define INITIAL_TIMEOUT  100//initial time we wait reconnect to the master server on failure
#define TIMEOUT_GROWTH_FACTOR   2 //every failed reconnect the timeoute increase by this factor


namespace replication {


struct slave_t :
    public home_thread_mixin_t,
    public store_t,
    public failover_callback_t,
    public message_callback_t
{
public:
    slave_t(store_t *, replication_config_t);
    ~slave_t();

private:
    store_t *internal_store;
    replication_config_t config;
    tcp_conn_t *conn;
    message_parser_t parser;
    failover_t failover;

public:
    /* store_t interface. */

    get_result_t get(store_key_t *key);
    get_result_t get_cas(store_key_t *key);
    set_result_t set(store_key_t *key, data_provider_t *data, mcflags_t flags, exptime_t exptime);
    set_result_t add(store_key_t *key, data_provider_t *data, mcflags_t flags, exptime_t exptime);
    set_result_t replace(store_key_t *key, data_provider_t *data, mcflags_t flags, exptime_t exptime);
    set_result_t cas(store_key_t *key, data_provider_t *data, mcflags_t flags, exptime_t exptime, cas_t unique);
    incr_decr_result_t incr(store_key_t *key, unsigned long long amount);
    incr_decr_result_t decr(store_key_t *key, unsigned long long amount);
    append_prepend_result_t append(store_key_t *key, data_provider_t *data);
    append_prepend_result_t prepend(store_key_t *key, data_provider_t *data);
    delete_result_t delete_key(store_key_t *key);

public:
    /* message_callback_t interface */
    void hello(boost::scoped_ptr<hello_message_t>& message);
    void send(boost::scoped_ptr<backfill_message_t>& message);
    void send(boost::scoped_ptr<announce_message_t>& message);
    void send(boost::scoped_ptr<set_message_t>& message);
    void send(boost::scoped_ptr<append_message_t>& message);
    void send(boost::scoped_ptr<prepend_message_t>& message);
    void send(boost::scoped_ptr<nop_message_t>& message);
    void send(boost::scoped_ptr<ack_message_t>& message);
    void send(boost::scoped_ptr<shutting_down_message_t>& message);
    void send(boost::scoped_ptr<goodbye_message_t>& message);
    void conn_closed();
    
public:
    /* failover callback */
    void on_failure();
    void on_resume();

private:
    /* state for failover */
    bool respond_to_queries;
    long timeout; /* ms to wait before trying to reconnect */

    static void reconnect_timer_callback(void *ctx);
    timer_token_t *timer_token;
};

}  // namespace replication




#endif  // __REPLICATION_SLAVE_HPP__