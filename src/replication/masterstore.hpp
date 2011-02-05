#ifndef __REPLICATION_MASTERSTORE_HPP__
#define __REPLICATION_MASTERSTORE_HPP__

#include "store.hpp"
#include "arch/arch.hpp"
#include "concurrency/mutex.hpp"
#include "containers/thick_list.hpp"
#include "replication/net_structs.hpp"

namespace replication {

class masterstore_exc_t : public std::runtime_error {
public:
    masterstore_exc_t(const char *wat) : std::runtime_error(wat) { }
};


class masterstore_t : public home_thread_mixin_t {
public:
    masterstore_t() { }

    bool has_slave() { return slave_ != NULL; }
    void add_slave(tcp_conn_t *conn);

    void hello();

    void get_cas(store_key_t *key, castime_t castime);

    void set(store_key_t *key, data_provider_t *data, mcflags_t flags, exptime_t exptime, castime_t castime);
    void add(store_key_t *key, data_provider_t *data, mcflags_t flags, exptime_t exptime, castime_t castime);
    void replace(store_key_t *key, data_provider_t *data, mcflags_t flags, exptime_t exptime, castime_t castime);
    void cas(store_key_t *key, data_provider_t *data, mcflags_t flags, exptime_t exptime, cas_t unique, castime_t castime);
    void incr(store_key_t *key, uint64_t amount, castime_t castime);
    void decr(store_key_t *key, uint64_t amount, castime_t castime);
    void append(store_key_t *key, data_provider_t *data, castime_t castime);
    void prepend(store_key_t *key, data_provider_t *data, castime_t castime);
    void delete_key(store_key_t *key);



private:
    // Spawns a coroutine.
    void send_data_with_ident(data_provider_t *data, uint32_t ident);

    template <class net_struct_type>
    void setlike(int msgcode, store_key_t *key, data_provider_t *data, mcflags_t flags, exptime_t exptime, castime_t castime);

    template <class net_struct_type>
    void stereotypical(int msgcode, store_key_t *key, data_provider_t *data, net_struct_type netstruct);


    mutex_t message_contiguity_;
    tcp_conn_t *slave_;
    thick_list<data_provider_t *, uint32_t> sources_;

    DISABLE_COPYING(masterstore_t);
};





}  // namespace replication

#endif  // __REPLICATION_MASTERSTORE_HPP__