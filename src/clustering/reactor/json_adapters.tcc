#ifndef  __CLUSTERING_REACTOR_JSON_ADAPTERS_TCC__
#define __CLUSTERING_REACTOR_JSON_ADAPTERS_TCC__

#include "http/json.hpp"
#include "clustering/reactor/json_adapters.hpp"

namespace reactor_business_card_details {
//json adapter for primary_when_safe
template <class protocol_t, class ctx_t>
typename json_adapter_if_t<ctx_t>::json_adapter_map_t get_json_subfields(primary_when_safe_t<protocol_t> *, const ctx_t &) {
    typename json_adapter_if_t<ctx_t>::json_adapter_map_t res;
    res["type"] = boost::shared_ptr<json_adapter_if_t<ctx_t> >(new json_temporary_adapter_t<std::string, ctx_t>("primary"));
    return res;
}

template <class protocol_t, class ctx_t>
cJSON *render_as_json(primary_when_safe_t<protocol_t> *target, const ctx_t &ctx) {
    return render_as_directory(target, ctx);
}

template <class protocol_t, class ctx_t>
void apply_json_to(cJSON *, primary_when_safe_t<protocol_t> *, const ctx_t &) {
    throw permission_denied_exc_t("Can't write to primary_when_safe_t objects.\n");
}

template <class protocol_t, class ctx_t>
void on_subfield_change(primary_when_safe_t<protocol_t> *, const ctx_t &) { }

//json adapter for primary
template <class protocol_t, class ctx_t>
typename json_adapter_if_t<ctx_t>::json_adapter_map_t get_json_subfields(primary_t<protocol_t> *, const ctx_t &) {
    typename json_adapter_if_t<ctx_t>::json_adapter_map_t res;
    res["type"] = boost::shared_ptr<json_adapter_if_t<ctx_t> >(new json_temporary_adapter_t<std::string, ctx_t>("primary"));
    //res["broadcaster"] = boost::shared_ptr<json_adapter_if_t<ctx_t> >(new json_adapter_t<broadcaster_business_card_t<protocol_t>, ctx_t>(&target->broadcaster));
    //res["replier"] = boost::shared_ptr<json_adapter_if_t<ctx_t> >(new json_adapter_t<boost::optional<replier_business_card_t<protocol_t> >, ctx_t>(&target->replier));
    return res;
}

template <class protocol_t, class ctx_t>
cJSON *render_as_json(primary_t<protocol_t> *target, const ctx_t &ctx) {
    return render_as_directory(target, ctx);
}

template <class protocol_t, class ctx_t>
void apply_json_to(cJSON *, primary_t<protocol_t> *, const ctx_t &) {
    throw permission_denied_exc_t("Can't write to primary_when_safe_t objects.\n");
}

template <class protocol_t, class ctx_t>
void on_subfield_change(primary_t<protocol_t> *, const ctx_t &) { }

//json adapter for secondary_up_to_date
template <class protocol_t, class ctx_t>
typename json_adapter_if_t<ctx_t>::json_adapter_map_t get_json_subfields(secondary_up_to_date_t<protocol_t> *target, const ctx_t &) {
    typename json_adapter_if_t<ctx_t>::json_adapter_map_t res;
    res["type"] = boost::shared_ptr<json_adapter_if_t<ctx_t> >(new json_temporary_adapter_t<std::string, ctx_t>("secondary_up_to_date"));
    res["branch_id"] = boost::shared_ptr<json_adapter_if_t<ctx_t> >(new json_adapter_t<branch_id_t, ctx_t>(&target->branch_id));
    //res["replier"] =   boost::shared_ptr<json_adapter_if_t<ctx_t> >(new json_adapter_t<replier_business_card_t<protocol_t>, ctx_t>(&target->replier));
    return res;
}

template <class protocol_t, class ctx_t>
cJSON *render_as_json(secondary_up_to_date_t<protocol_t> *target, const ctx_t &ctx) {
    return render_as_directory(target, ctx);
}

template <class protocol_t, class ctx_t>
void apply_json_to(cJSON *, secondary_up_to_date_t<protocol_t> *, const ctx_t &) {
    throw permission_denied_exc_t("Can't write to primary_safe_t objects.\n");
}

template <class protocol_t, class ctx_t>
void on_subfield_change(secondary_up_to_date_t<protocol_t> *, const ctx_t &) { }

//json adapter for secondary_without_primary
template <class protocol_t, class ctx_t>
typename json_adapter_if_t<ctx_t>::json_adapter_map_t get_json_subfields(secondary_without_primary_t<protocol_t> *, const ctx_t &) {
    typename json_adapter_if_t<ctx_t>::json_adapter_map_t res;
    res["type"] = boost::shared_ptr<json_adapter_if_t<ctx_t> >(new json_temporary_adapter_t<std::string, ctx_t>("secondary_without_primary"));
    //res["current_state"] = boost::shared_ptr<json_adapter_if_t<ctx_t> >(new json_adapter_t<region_map_t<protocol_t, version_range_t>, ctx_t>(&target->current_state));
    //res["backfiller"] = boost::shared_ptr<json_adapter_if_t<ctx_t> >(new json_adapter_t<backfiller_business_card_t<protocol_t>, ctx_t>(&target->backfiller));
    return res;
}

template <class protocol_t, class ctx_t>
cJSON *render_as_json(secondary_without_primary_t<protocol_t> *target, const ctx_t &ctx) {
    return render_as_directory(target, ctx);
}

template <class protocol_t, class ctx_t>
void apply_json_to(cJSON *, secondary_without_primary_t<protocol_t> *, const ctx_t &) {
    throw permission_denied_exc_t("Can't write to primary_when_safe_t objects.\n");
}

template <class protocol_t, class ctx_t>
void on_subfield_change(secondary_without_primary_t<protocol_t> *, const ctx_t &) { }

//json adapter for secondary_backfilling
template <class protocol_t, class ctx_t>
typename json_adapter_if_t<ctx_t>::json_adapter_map_t get_json_subfields(secondary_backfilling_t<protocol_t> *, const ctx_t &) {
    typename json_adapter_if_t<ctx_t>::json_adapter_map_t res;
    res["type"] = boost::shared_ptr<json_adapter_if_t<ctx_t> >(new json_temporary_adapter_t<std::string, ctx_t>("secondary_backfilling"));
    return res;
}

template <class protocol_t, class ctx_t>
cJSON *render_as_json(secondary_backfilling_t<protocol_t> *target, const ctx_t &ctx) {
    return render_as_directory(target, ctx);
}

template <class protocol_t, class ctx_t>
void apply_json_to(cJSON *, secondary_backfilling_t<protocol_t> *, const ctx_t &) {
    throw permission_denied_exc_t("Can't write to primary_when_safe_t objects.\n");
}

template <class protocol_t, class ctx_t>
void on_subfield_change(secondary_backfilling_t<protocol_t> *, const ctx_t &) { }

//json adapter for nothing_when_safe_t
template <class protocol_t, class ctx_t>
typename json_adapter_if_t<ctx_t>::json_adapter_map_t get_json_subfields(nothing_when_safe_t<protocol_t> *, const ctx_t &) {
    typename json_adapter_if_t<ctx_t>::json_adapter_map_t res;
    res["type"] = boost::shared_ptr<json_adapter_if_t<ctx_t> >(new json_temporary_adapter_t<std::string, ctx_t>("nothing_when_safe"));
    //res["current_state"] = boost::shared_ptr<json_adapter_if_t<ctx_t> >(new json_adapter_t<region_map_t<protocol_t, version_range_t>, ctx_t>(&target->current_state));
    //res["backfiller"] = boost::shared_ptr<json_adapter_if_t<ctx_t> >(new json_adapter_t<backfiller_business_card_t<protocol_t>, ctx_t>(&target->backfiller));
    return res;
}


template <class protocol_t, class ctx_t>
cJSON *render_as_json(nothing_when_safe_t<protocol_t> *target, const ctx_t &ctx) {
    return render_as_directory(target, ctx);
}

template <class protocol_t, class ctx_t>
void apply_json_to(cJSON *, nothing_when_safe_t<protocol_t> *, const ctx_t &) {
    throw permission_denied_exc_t("Can't write to nothing_when_safe_t objects.\n");
}

template <class protocol_t, class ctx_t>
void on_subfield_change(nothing_when_safe_t<protocol_t> *, const ctx_t &) { }

//json adapter for nothing_t
template <class protocol_t, class ctx_t>
typename json_adapter_if_t<ctx_t>::json_adapter_map_t get_json_subfields(nothing_t<protocol_t> *, const ctx_t &) {
    typename json_adapter_if_t<ctx_t>::json_adapter_map_t res;
    res["type"] = boost::shared_ptr<json_adapter_if_t<ctx_t> >(new json_temporary_adapter_t<std::string, ctx_t>("nothing"));
    return res;
}

template <class protocol_t, class ctx_t>
cJSON *render_as_json(nothing_t<protocol_t> *target, const ctx_t &ctx) {
    return render_as_directory(target, ctx);
}

template <class protocol_t, class ctx_t>
void apply_json_to(cJSON *, nothing_t<protocol_t> *, const ctx_t &) {
    throw permission_denied_exc_t("Can't write to nothing_t objects.\n");
}

template <class protocol_t, class ctx_t>
void on_subfield_change(nothing_t<protocol_t> *, const ctx_t &) { }

//json adapter for nothing_when_done_erasing_t
template <class protocol_t, class ctx_t>
typename json_adapter_if_t<ctx_t>::json_adapter_map_t get_json_subfields(nothing_when_done_erasing_t<protocol_t>*, const ctx_t &) {
    typename json_adapter_if_t<ctx_t>::json_adapter_map_t res;
    res["type"] = boost::shared_ptr<json_adapter_if_t<ctx_t> >(new json_temporary_adapter_t<std::string, ctx_t>("nothing_when_done_erasing"));
    return res;
}

template <class protocol_t, class ctx_t>
cJSON *render_as_json(nothing_when_done_erasing_t<protocol_t> *target, const ctx_t &ctx) {
    return render_as_directory(target, ctx);
}

template <class protocol_t, class ctx_t>
void apply_json_to(cJSON *, nothing_when_done_erasing_t<protocol_t> *, const ctx_t &) {
    throw permission_denied_exc_t("Can't write to nothing_when_done_erasing_t objects.\n");
}

template <class protocol_t, class ctx_t>
void on_subfield_change(nothing_when_done_erasing_t<protocol_t> *, const ctx_t &) { }
} //namespace reactor_business_card_details 

//json adapter for reactor_business_card_t
template <class protocol_t, class ctx_t>
typename json_adapter_if_t<ctx_t>::json_adapter_map_t get_json_subfields(reactor_business_card_t<protocol_t> *target, const ctx_t &) {
    typename json_adapter_if_t<ctx_t>::json_adapter_map_t res;
    res["activity_map"] = boost::shared_ptr<json_adapter_if_t<ctx_t> >(new json_adapter_t<typename reactor_business_card_t<protocol_t>::activity_map_t, ctx_t>(&target->activities));
    return res;
}

template <class protocol_t, class ctx_t>
cJSON *render_as_json(reactor_business_card_t<protocol_t> *target, const ctx_t &ctx) {
    return render_as_directory(target, ctx);
}

template <class protocol_t, class ctx_t>
void apply_json_to(cJSON *change, reactor_business_card_t<protocol_t> *target, const ctx_t &ctx) {
    apply_as_directory(change, target, ctx);
}

template <class protocol_t, class ctx_t>
void on_subfield_change(reactor_business_card_t<protocol_t> *, const ctx_t &) { }

#endif