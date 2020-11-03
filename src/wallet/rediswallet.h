// Copyright (c) 2020 barrystyle
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_REDISWALLET_H
#define BITCOIN_REDISWALLET_H

#include <cstdlib>
#include <iostream>

#include "redis-cpp/stream.h"
#include "redis-cpp/execute.h"

class RedisWallet
{
private:
	std::shared_ptr<std::iostream> wallet_stream;

public:
	bool InitWallet();
	std::string ReadWallet(std::string keyname);
	void WriteWallet(std::string keyname, std::string keyval);
};

#endif // BITCOIN_REDISWALLET_H
