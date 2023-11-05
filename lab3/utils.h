#pragma once

#ifndef UTILS_H
#define UTILS_H

#include <fstream>

#include "json.hpp"

namespace utils {
	/// <summary>
	/// give_me_json() receives a file to read, loads and parses it as JSON.
	/// </summary>
	/// <param name="filename">JSON file to be read in.</param>
	/// <returns>a JSON node based on the file's contents.</returns>
	inline json::JSON give_me_json(const char* filename) {
		std::ifstream input_stream(filename);
		const std::string str((std::istreambuf_iterator<char>(input_stream)), std::istreambuf_iterator<char>());
		return json::JSON::Load(str);
	}

	inline void error_msg(const char* msg) {
		std::cerr << "ERROR: " << msg << std::endl;
	}
}

#endif