#include <Rcpp.h>

#include "getdns/getdns.h"
#include "getdns/getdns_extra.h"

using namespace Rcpp;

#define TRANSPORT_UDP "udp"
#define TRANSPORT_TCP "tcp"
#define TRANSPORT_PIPELINE "pipeline"
#define TRANSPORT_TLS_KEEPOPEN "tls"
#define TRANSPORT_TLS_TCP_KEEPOPEN "dns-over-tls"
#define RESOLUTION_STUB "stub"
#define RESOLUTION_REC "rec"

static void print_response(struct getdns_dict * response) {
	char *dict_str = getdns_pretty_print_dict(response);
	if (dict_str) {
		Rcout << "The packet %s" << dict_str << std::endl;
		free(dict_str);
	}
}

//' @export
// [[Rcpp::export]]
void getdns_test() {

	const char *transport = "udp";
	const char *resolution = "stub";

	struct getdns_context *this_context = NULL;
	getdns_return_t context_create_return = getdns_context_create(&this_context, 1);

	getdns_context_set_resolution_type(this_context, GETDNS_RESOLUTION_STUB);
	getdns_context_set_dns_transport(this_context, GETDNS_TRANSPORT_TCP_ONLY);

	struct getdns_dict *response = NULL;
	getdns_return_t ret;

	ret = getdns_address_sync(this_context, "www.google.com", NULL, &response);
	print_response(response);
	getdns_dict_destroy(response);

	ret = getdns_service_sync(this_context, "_xmpp-client._tcp.jabber.com.", NULL, &response);
	print_response(response);
	getdns_dict_destroy(response);

	ret = getdns_general_sync(this_context, "www.google.com", GETDNS_RRTYPE_A, NULL, &response);
	print_response(response);
	getdns_dict_destroy(response);

	getdns_context_destroy(this_context);

}

