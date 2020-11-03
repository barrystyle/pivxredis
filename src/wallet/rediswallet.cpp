// Copyright (c) 2020 barrystyle
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "wallet/rediswallet.h"

bool RedisWallet::InitWallet() {
	wallet_stream = rediscpp::make_stream("localhost", "6379");
	if (!wallet_stream) return false;
	return true;
}

void RedisWallet::WriteWallet(std::string keyname, std::string keyvalue) {
	rediscpp::execute(*wallet_stream, "set", keyname, keyvalue, "ex", "60");
}

std::string RedisWallet::ReadWallet(std::string keyname) {
	return rediscpp::execute(*wallet_stream, "get", keyname);
}
